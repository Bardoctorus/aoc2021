
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//DECS_________________________________
int ctoi(int i);
int binToDec(int n);
//MAIN___________________________________
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
	char epsilon[64];
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
		for (int l = 0; l < 1000; l++)
		{
			if((inputs[l][k] - '0') == 0)
			{
				zeros++;
			}	
			else if((inputs[l][k] - '0') == 1)
			{
				ones++;		
			}
//			printf("inputs[%d][%d] is %d\n",k,l,(inputs[l][k] - '0'));
		}
		int result = (ones>zeros);
		gamma[k] = (result+'0');
		epsilon[k] = (!result + '0');
//		printf("ones is %d, zeros is %d, result is %d,Gamma[%d] = %d\n",ones,zeros,result,k, result);
		ones = 0;
		zeros = 0;
//		printf("gamma[%d] is %c\n",k,(gamma[k]));
	}
	gamma[strlen(str)-1] = '\0';
	epsilon[strlen(str)-1] = '\0';
	printf("Gamma in full:START %s END\n\n",gamma);
	printf("Epsilon in full:START %s END\n\n",epsilon);
	char *endptr;
	long int gamInt =strtol(gamma,&endptr,2);
	long int epInt = strtol(epsilon,&endptr, 2);
	printf("gamint = %ld, epint %ld\n", gamInt,epInt);
//	printf("Gamma bintodec:  %d, Epsilon bin2dec: %d\n",binToDec(gamInt),binToDec(epInt));
	int power =gamInt * epInt;
	printf("Final power reading: %d\n",power);
	fclose(fp);
	return 0;
}
//FUNCS_________________________________________
int ctoi(int i)
{
	return i-'0';
}

int binToDec(int n)
{
	int dec_val = 0;

	int base = 1;

	int temp = n;

	while (temp) 
	{
		int last = temp % 10;
		temp = temp/10;

		dec_val += last * base;
		base  = base * 2;
	}
	return dec_val;
}
