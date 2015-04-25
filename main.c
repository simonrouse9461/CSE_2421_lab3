/*
 * NAME:  Chuhan Feng
 * DATE:  Feb 15, 2015
 * CLASS: CSE 2421, T/TH 8:00AM
 * ID:    0x05194445
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "integer.h"
#define true 1
#define false 0
#define TESTMODE 0		// test mode switch (1 = ON, 0 = OFF)
#if TESTMODE			// test mode logic
	#define TEST	
#else
	#define TEST if (1) ; else 
#endif

int main(void)
{
	/*
	 * initiate variables
	 */
	imint integer_1 = {NULL};
	imint integer_2 = {NULL};
	char dig;
	char operator;
	
	/*
	 * read in first integer
	 */
	for (scanf("%c", &dig); dig != '\n'; scanf("%c", &dig)) {
		TEST printf("%c", dig);
		int temp = toDigit(dig);
		TEST printf("%i", temp);
		push(&integer_1, temp);
	}
	TEST printf("\n");

	/*
	 * read in second integer
	 */
	for (scanf("%c", &dig); dig != '\n'; scanf("%c", &dig)) {
		TEST printf("%c", dig);
		int temp = toDigit(dig);
		TEST printf("%i", temp);
		push(&integer_2, temp);
	}
	TEST printf("\n");
	
	/*
	 * read in operator
	 */
	scanf("%c", &operator);

	TEST printf("\nfinish reading in\n");
	TEST printii(integer_1);	
	TEST printii(integer_2);	
	TEST printf("%c\n", operator);

	/*
	 * calculate
	 */
	if (operator == '+') {printii(add(integer_1, integer_2));}
	if (operator == '-') {printii(sub(integer_1, integer_2));}
	
	/*
	 * clean memory
	 */
	freeii(integer_1);
	freeii(integer_2);
	return 0;
}
