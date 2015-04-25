/*
 * NAME:  Chuhan Feng
 * DATE:  Feb 15, 2015
 * CLASS: CSE 2421, T/TH 8:00AM
 * ID:    0x05194445
 */
 
#include <stdlib.h>
#include <stdio.h>
#include "integer.h"
#define true 1
#define false 0
#define TESTMODE 0		// test mode switch (1 = ON, 0 = OFF)
#if TESTMODE			// test mode logic
	#define TEST	
#else
	#define TEST if (1) ; else 
#endif

void reverse(imint*);

void elim_lead_0(imint*);

void push_no_filter(imint*, int);

void assign(imint * integer, int digits[]) {
	digit * curr;
	int i;
	integer->first = NULL; 
	for (i = 0; i < sizeof(digits); i++) {
		curr = (digit *) malloc(sizeof(digit));
		curr->val = digits[i];
		curr->next = integer->first;
		integer->first = curr;
	}
}

void push(imint * integer, int i) {
	if (integer->first || i) {
		digit * new = (digit *) malloc(sizeof(digit));
		new->val = i;
		new->next = integer->first;
		integer->first = new;
		TEST printf("%i pushed\n", i);
	}
}

imint add(imint a, imint b) {
	imint sum = {NULL};
	int carry_over = 0;
	digit * head_a = a.first;
	digit * head_b = b.first;
	while (head_a || head_b) {
		int adig = head_a ? head_a->val : 0;
		int bdig = head_b ? head_b->val : 0;
		int dig = adig + bdig + carry_over;
		carry_over = dig / 10;
		dig %= 10;
		push_no_filter(&sum, dig);
		if (head_a) {head_a = head_a->next;}
		if (head_b) {head_b = head_b->next;}
	}
	if (carry_over) {
		push_no_filter(&sum, carry_over);
	}
	reverse(&sum);
	return sum;
}

imint sub(imint a, imint b) {
	imint sum = {NULL};
	int borrow = 0;
	digit * head_a = a.first;
	digit * head_b = b.first;
	while (head_a || head_b) {
		int adig = head_a ? head_a->val : 0;
		int bdig = head_b ? head_b->val : 0;
		int dig = adig - bdig - borrow;
		borrow = (9 - dig) / 10;
		dig = (dig + 10) % 10;
		push_no_filter(&sum, dig);
		if (head_a) {head_a = head_a->next;}
		if (head_b) {head_b = head_b->next;}
	}
	if (borrow) {
		return sub(b, a);
	}
	elim_lead_0(&sum);
	reverse(&sum);
	return sum;
}

void printii(imint integer) {
	reverse(&integer);
	digit * head = integer.first;
	while (head) {
		printf("%i", head->val);
		head = head->next;
	}
	printf("\n");
	reverse(&integer);
}

void freeii(imint integer) {
	while (integer.first) {
		digit * temp = integer.first;
		integer.first = integer.first->next;
		free(temp);
	}
}

void reverse(imint * integer) {
	imint temp = {NULL};
	digit * head = integer->first;
	while (head) {
		push_no_filter(&temp, head->val);
		head = head->next;
	}
	integer->first = temp.first;
}

void elim_lead_0(imint * integer) {
	digit * head = NULL;
	for (head = integer->first; !(integer->first->val); head = integer->first) {
		integer->first = integer->first->next;
		free(head);
	}
}

void push_no_filter(imint * integer, int i) {
	digit * new = (digit *) malloc(sizeof(digit));
	new->val = i;
	new->next = integer->first;
	integer->first = new;
	TEST printf("%i pushed\n", i);
}
