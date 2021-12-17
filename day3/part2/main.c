
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//DECS_________________________________

int sigBitAtPosition(char * input, int step, int offset);
//MAIN___________________________________
int main(int argc,char ** argv) 
{
	//ARGS HANDLING
	if(argc < 2)
	{
		printf("Need a filename arg\n");
		exit(-1);
	}
	//VARS
	char * filename = argv[1];
	FILE *fp;
	fp = fopen(filename, "r");
	if (fp==NULL)
	{
		printf("File is fucky no bueno for you\n");
		exit (-1);

	}	
	char str[100];
	char * pstr = &str[0];
	char inputs[1001][64];
	int counter = 0;
	int ones = 0;
	int zeros = 0;
//INPUT
	while (fgets(str, 100, fp))
	{
		for(int i = 0; i < strlen(str); i ++)
		{
			if(i == strlen(str)-1)
			{
				inputs[counter][i] = '\0';
			}
			else
			{
				inputs[counter][i] = *(pstr++);
			}
		}
		pstr = &str[0];
		counter++;
	}
	sigBitAtPosition(inputs[0],strlen(str),0);
	for (int k = 0; k < strlen(str)-1; k++)
	{
		for (int l = 0; l < counter; l++)
		{
			//printf("Value at inputs[%d][%d] by pointer: %c\n",l,k,*(inputs[l]+1));
			if((inputs[l][k] - '0') == 0)
			{
				zeros++;
			}	
			else if((inputs[l][k] - '0') == 1)
			{
				ones++;		
			}
		}
//		int result = (ones>zeros);
		ones = 0;
		zeros = 0;
	}
	fclose(fp);
	return 0;
}
//FUNCS_________________________________________
int sigBitAtPosition(char * input, int step,int offset)
{
	int x = 0;
	while(input[x] != '\0')
	{
		printf("char here: %c\n",*(&input[x]+offset+1));
		x+=step;
	}
	return 0;
}	
