
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

	int horizontal=0;
	int depth=0;
	int aim =0;
	while (fgets(str, 100, fp))
	{
		//create pointers to move through the input and assign it to a word
		char *p = &str[0];
		char *pw = &word[0];
		while(*p != ' ')
		{
			*(pw++) = *(p++);
		}
		//increment the pointer to move over the whitespace
		p++;
		//add terminator to word
		*pw = '\0';
		printf("word is: %s\n", word);
		//THIS WILL ONLY WORK FOR SINGLE DIGIT NUMBERS
		// TODO fix this ^
		while (*p != '\n')
		{
			number = atoi(p++);
		}
		printf("number is: %d\n", number);	
		
		// TODO scrcmp the word with the possible inputs
		// TODO add the numbers to the horiz and depth totals
		if(strcmp(word, "forward") == 0)
		{
			horizontal+=number;
			depth += aim * number;

		}
		else if (strcmp(word, "down") == 0)
		{
			aim+=number;
		}
		else if (strcmp(word, "up") == 0)
		{
			aim-=number;
		}
		else
		{
			printf("Aint no one meant to get here SON\n");
		}

		// TODO multiply them to get the answer
			
	}
		int answer = horizontal * depth;
		printf("Horizontal (%d) * Depth (%d) = %d\n", horizontal, depth, answer);
	

	fclose(fp);



	return 0;
}

