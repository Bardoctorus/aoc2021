
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
	if (fp==NULL) exit (-1);
	char str[100];
	int binaryInput[9999];	
	int *p2i = &binaryInput[0];
	while (fgets(str, 100, fp))
	{
		*(p2i++) = atoi(str);
	}
	for (int i = 0; i < 5 ; i++)
	{
		printf("Int array position %d is %d", i, binaryInput[i]);
	}

	

	fclose(fp);



	return 0;
}

