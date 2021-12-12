
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
	char *pstr = &str[0];
	int ones = 0;
	int zeros = 0;
	char gamma[64];
//	char epsilon[64];
	while (fgets(str, 100, fp))
	{
		//This is all a mess. The principle is sound but the implementation is whack.
		int len = strlen(str);
		for (int i=0;i<len;i++)
		{
			char c = *pstr;

			printf("char c is %c\n",c);
			int p = ctoi(c);
			printf("int p is %d\n",p);
			if(p == 1)
			{
				ones++;
				printf("one detected, there are now %d ones\n",ones);
			}	
			else
			{
				zeros++;
				printf("Zero detected, there are now %d zeros\n", zeros);
			}
			gamma[i] = (ones>zeros);
			printf("Gamma[%d] is %d\n",i, gamma[i]);
			
		}
		ones=0;
		zeros=0;
		pstr++;
	}
	printf("Gamma is: ");
	for (int i = 0; i < strlen(gamma); i++)
	{
		printf("%c ",gamma[i]);
	}	
	printf("\n");

	fclose(fp);



	return 0;
}

