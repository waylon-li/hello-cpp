cmake_minimum_required(VERSION 3.8)
project(Tutorial)

# The version number
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
configure_file(
		"${PROJECT_SOURCE_DIR}/config.h.in"
		"${PROJECT_BINARY_DIR}/config.h"
		)

# add the binary tree to the seatch path for include files
include_directories("${PROJECT_BINARY_DIR}")


# should we use our own math functions?
option(USE_MYMATH "Use tutorial provided matn implementation" ON)

#add the MathFunctions library?
if(USE_MYMATH)
	include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
	add_subdirectory(MathFunctions)
	set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif(USE_MYMATH) 

# add the executable
add_executable(Tutorial tutorial.cpp)
target_link_libraries(Tutorial ${EXTRA_LIBS})

#add the install targets
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h"
		DESTINATION include)


include(CTest)

#does the appliction run
add_test(TutorialRuns Tutorial 25)

#does it sqrt of 25
add_test(TutorialComp25 Tutorial 25)
set_tests_properties(TutorialComp25 PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")

# does it handle negative numbers
add_test (TutorialNegative Tutorial -25)
set_tests_properties (TutorialNegative PROPERTIES PASS_REGULAR_EXPRESSION "-25 is -nan")
	
# does it handle small numbers
add_test (TutorialSmall Tutorial 0.0001)
set_tests_properties (TutorialSmall PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01")
	
# does the usage message work?
add_test (TutorialUsage Tutorial)
set_tests_properties (TutorialUsage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")


# does this system provide the log and exp functions?
# include(CheckFunctionExists)
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists(log HAVE_LOF)
check_function_exists(exp HAVE_EXP)


#build a cpack driver installer package
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE
		"${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include(CPack)

