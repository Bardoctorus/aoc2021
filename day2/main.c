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
	if(argc > 1)
	{
		printf("hello, %s!\n", argv[1]);
	}
	else
	{
		printf("meeeep\n");
	}
	return 0;
}

