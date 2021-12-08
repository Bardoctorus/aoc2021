/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/08/2021 04:32:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian Buckley (IMB), 
 *   Organization:  https://github.com/Bardoctorus
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void getInput(int *inArr);

int main()
{
	
	int input[2001];
	int count = 0;
	char * linefromfile;
	size_t sizefromfile;
	ssize_t read;
	FILE * fp;
	fp = fopen("./input.txt", "r");
	if (fp == NULL)
		exit(-1);
	while ((read = getline(&linefromfile, &sizefromfile, fp)) !=-1){
//		printf("reading line length %zu\n", read);
//		printf("%s\n",linefromfile);
		input[count] = atoi(linefromfile);
		printf("input position %d is %d\n", count, input[count]);
		count+=1;
	}

	fclose(fp);

	return 0;
}
