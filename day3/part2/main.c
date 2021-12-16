
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//DECS_________________________________
int ctoi(int i);
int binToDec(int n);
void arrayShifter(char * array, int sigBit);
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
	char gamma[64];
	char epsilon[64];
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
//	printf("counter is %d\n",counter);
//
//COUNTING BITS
//
//
//Here we are stepping through counting bits
//once we count them we get a result variable.
//using this result variable we need to walk through the input again, keeping the significant bit entries and discarding others
//if memory is cheap, we just make a new array each time
// actually thats whack you just need two new arrays
	for (int k = 0; k < strlen(str)-1; k++)
	{
		for (int l = 0; l < counter+1; l++)
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
		// TODO step through input[][] again keeping track of which ones to keep, and which ones to ditch
		// maybe the best way to do it is:
		//  - for [0][x] Go until find first 0 
		//  - forward once - if its a !0 (this is DANGER, handle \o) copy it to first 0 position, else keep going
		//  - do this once for every element in the array.
		//  - go through and put an '\0' at the new end.
		//  - repeat for [1][x] and happy days? riiight?!? 
		//  - if it works, do teh exact same thing in reverse for the one that nees a 0. Make a function that can do either as an arg.
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
