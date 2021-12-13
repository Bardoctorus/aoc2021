
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ctoi(int i)
{
	return i-'0';
}
int main(int argc,char ** argv) 
{
	if(argc < 2)
	{
		printf("Need a filename arg\n");
		exit(-1);
	}
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
	char gamma[64];
//	char epsilon[64];
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

	for (int k = 0; k < strlen(str)-1; k++)
	{
		//TODO Change this shit before the real thing the 12 is hardcoded.
		for (int l = 0; l < 12; l++)
		{
			if((inputs[l][k] - '0') == 0)
			{
				zeros++;
			}	
			else if((inputs[l][k] - '0') == 1)
			{
				ones++;		
			}
			printf("inputs[%d][%d] is %d\n",k,l,(inputs[l][k] - '0'));
			
		}
		int result = (ones>zeros);
		gamma[k] = (result+'0');
		printf("ones is %d, zeros is %d, result is %d,Gamma[%d] = %d\n",ones,zeros,result,k, result);
		ones = 0;
		zeros = 0;
		printf("gamma[%d] is %c\n",k,(gamma[k]));
	}
	printf("Gamma in full: %s\n\n",&gamma[0]);
	fclose(fp);
	return 0;
}

