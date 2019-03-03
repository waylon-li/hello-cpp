/*************************************************************************
	> File Name: mysqrt.cpp
	> Author: waylon
	> Mail: waylon_li@ghotmail.com 
	> Created Time: 2019年03月03日 星期日 18时38分04秒
 ************************************************************************/
#include <math.h>
#include "config.h"

double mysqrt(double input)
{
	//if we have both log and exp then use them
#if defined(HAVE_LOG) && defined(HAVE_EXP)
	return exp(log(input)*0.5);
#else
	return sqrt(input);
#endif
}

