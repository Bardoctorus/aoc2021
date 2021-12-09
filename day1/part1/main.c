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


int main(int argc,char ** argv) 
{
	if(argc < 1)
		exit(-1);
	char * filename = argv[1];	
	int input[2001];
	int count = 0;
	char * linefromfile;
	size_t sizefromfile;
	ssize_t read;
	FILE * fp;
	fp = fopen(filename, "r");
	if (fp == NULL)
		exit(-1);
	while ((read = getline(&linefromfile, &sizefromfile, fp)) !=-1){
		input[count] = atoi(linefromfile);
		printf("input position %d is %d\n", count, input[count]);
		count+=1;
	}
	
	int increases = 0;
	int previous = 0;
	int i;
	for(i = 0; i < count; i++)
	{
		if (i==0)
		{
			previous = input[i];
			printf("First pass, no comparison, previous is now %d\n", input[i]);
			continue;
		}
		if(input[i] > previous)
		{
			increases+=1;
			printf("%d is an increase on %d, increases are now %d\n", input[i], previous, increases);
		}
		else
		{
			printf("%d is not an increase on %d, moving on\n", input[i], previous);
		}
		previous = input [i];
	}
	printf("\n\n\n");
	printf("All the increases captain: %d\n\n", increases);
	fclose(fp);

	return 0;
}

