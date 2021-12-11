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
#include <string.h>

int main(int argc,char ** argv) 
{
	if(argc < 1)
		exit(-1);
	char * filename = argv[1];
	FILE *fp;
	fp = fopen(filename, "r");
	char str[100];

	while (fgets(str, 100, fp))
	{
		int len = strlen(str);
		printf("len is %d\n", len);
		for (int x = len-1; x >= 0 ; x--)
		{
			if(strcmp(&str[x]," ") !=0 && strcmp(&str[x],"\n") !=0)			{

				printf("character %d is: %s",x, &str[x]);
			}
			else if(strcmp(&str[x]," ") ==0)
			{
				printf("Whitespace detected at %d\n", len);
			}	
			else if(strcmp(&str[x],"\n") ==0)
			{

				printf("newline detected at %d\n", len);


			}			
			else
			{
				printf("Unknown detected\n");
			}
		}
	}
	
	fclose(fp);
	return 0;
}

