/*
 * NAME:  Chuhan Feng
 * DATE:  Feb 15, 2015
 * CLASS: CSE 2421, T/TH 8:00AM
 * ID:    0x05194445
 */

#define toDigit(c) (c-'0')	// macro function

typedef struct node {
        int val;
        struct node * next;
} digit;
 
typedef struct {
        digit * first;
} imint;

void assign(imint*, int[]); 

void push(imint*, int);

imint add(imint, imint);

imint sub(imint, imint);

void printii(imint);

void freeii(imint);
