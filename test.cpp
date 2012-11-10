/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012/09/22 18时29分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int main(int argc, const char *argv[])
{
    printf("int: %d; char: %d; short: %d; long: %d; float: %d; double: %d;\n", (int)sizeof(int), (int)sizeof(char), (int)sizeof(short), (int)sizeof(long), (int)sizeof(float), (int)sizeof(double));
    printf("void *: %d; short *: %d; int *: %d; long *: %d; float *: %d; double *: %d\n", (int)sizeof(void *), (int)sizeof(short *), (int)sizeof(int *), (int)sizeof(long *), (int)sizeof(float *), (int)sizeof(double *));
	return 0;
}
