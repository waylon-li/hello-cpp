/*************************************************************************
	> File Name: MakeTable.cpp
	> Author: waylon
	> Mail: waylon_li@ghotmail.com 
	> Created Time: 2019年03月03日 星期日 20时31分06秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	int i;
	double result;

	//make sure we have enough arguments
	if(argc <2){
		return 1;
	}

	//open the output file
	FILE *fout = fopen(argv[1], "w");
	if(!fout)
		return 1;

	//create a source file with a table of square roots
	fprintf(fout, "double sqrtTable[] = {\n");
	for(i = 0; i < 10; ++i){
		result = sqrt(static_cast<double>(i));
		fprintf(fout, "%g,\n", result);
	}

	//close the table with a zero
	fprintf(fout, "0};\n");
	fclose(fout);

	return 0;
}

