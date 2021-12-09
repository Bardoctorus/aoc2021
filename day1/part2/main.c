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
	for(i = 0; i < count-2; i++)
	{
		int threecount = input[i]+input[i+1]+input[i+2];
		// switch this to get the sum of the first three and assign it to previous
		if (i==0)
		{
			previous = threecount;
			printf("First pass, no comparison, previous is now %d\n", threecount);
			continue;
		}
		//This is where you add the next for loop but you are too tired. Something something the 
		//sum of the next three compared to previous and using that to increment increases 
		if(threecount > previous)
		{
			increases+=1;
			printf("%d is an increase on %d, increases are now %d\n", threecount, previous, increases);
		}
		else
		{
			printf("%d is not an increase on %d, moving on\n", threecount, previous);
		}
		previous = threecount;
		//handle the last case if its not a three
	}
	printf("\n\n\n");
	printf("All the increases captain: %d\n\n", increases);
	fclose(fp);

	return 0;
}

