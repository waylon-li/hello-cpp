/*************************************************************************
	> File Name: tutorial.cpp
	> Author: waylon
	> Mail: waylon_li@ghotmail.com 
	> Created Time: 2019年03月03日 星期日 17时58分35秒
 ************************************************************************/
//求平方根
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "config.h"
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main(int argc, char **argv)
{
	if(argc < 2){
		fprintf(stdout, "%s Version %d.%d\n",
				argv[0],
				Tutorial_VERSION_MAJOR,
				Tutorial_VERSION_MINOR);
		fprintf(stdout, "Usage:%s number\n", argv[0]);
		return 1;
	}

	double inputValue = atof(argv[1]);
#ifdef USE_MYMATH
	double outputValue = mysqrt(inputValue);
#else
	double outputValue = sqrt(inputValue);
#endif

	fprintf(stdout, "The square root of %g is %g\n",
			inputValue, outputValue);
	return 0;
}

