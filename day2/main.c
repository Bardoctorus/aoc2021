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


	char word[100];
	int number = 0;
	while (fgets(str, 100, fp))
	{
		int len = strlen(str);
		printf("len is %d\n", len);
		for (int x = 0; x < len ; x++)
		{
			if (str[x] != ' ')
			{
				word[x] = str[x];
			}
					


			
			
	//		if(str[x]!=' ' && strcmp(&str[x],"\n") !=0)			
	//		{
	//			printf("character %d is: %c\n",x, str[x]);
	//		}
	//		else if(str[x]==' ')
	//		{
	//			printf("Whitespace detected at %d\n", len);
	//		}	
	//		else if(str[x]=='\n')
	//		{
	//			printf("newline detected at %d\n", len);
	//		}			
	//		else
	//		{
	//			printf("Unknown detected\n");
	//		}
		} 
	}
	
	fclose(fp);
	return 0;
}

