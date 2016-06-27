/**
*Program name: cis27Spring2013KachiLauLab4Ex1.c
*Dicussion:    lab4 Ex1
*Written By:   KachiLau
*Date:         2/28/13
*/

#include <stdio.h>
#include <stdlib.h>

struct FractionKachiLau{
	int num;
	int denom;
};

struct FractionKachiLau* addFractionKachiLau(
 struct FractionKachiLau*, 
 struct FractionKachiLau*);

struct FractionKachiLau* subtractFractionKachiLau(
 struct FractionKachiLau*,
 struct FractionKachiLau*);

struct FractionKachiLau* multiplyFractionKachiLau(
 struct FractionKachiLau*, 
 struct FractionKachiLau*);

struct FractionKachiLau* divideFractionKachiLau(
 struct FractionKachiLau*,
 struct FractionKachiLau*);

struct FractionKachiLau* reduce(struct FractionKachiLau*);

int gcd(struct FractionKachiLau*);

void init(struct FractionKachiLau*);

void menu01(void);

void displaymenu(void);

void displayinfo(void);

void print(const struct FractionKachiLau*);

int main() {

	displayinfo();

	menu01();

	return 0;
}

void init(struct FractionKachiLau* arg) {

	printf("\nEnter an Fraction --\n");
	printf("Num: ");
	scanf("%d", &arg->num);
	printf("Denom: ");
	scanf("%d", &arg->denom);

	while(arg->denom == 0) {
		printf("\nDenominator cannot be 0"\
			"\nPlease re-enter the Denom: ");
		scanf("%d", &arg->denom);
	}

	if(arg->denom < 0) {
		arg->num = -arg->num;
		arg->denom = -arg->denom;
	}

	return;
}


void print(const struct FractionKachiLau* frPtr) {

	printf("\nNum: %d\n"\
		"Denom: %d\n", frPtr->num, frPtr->denom);

	return;
}


struct FractionKachiLau* addFractionKachiLau(struct FractionKachiLau* frA, struct FractionKachiLau* frB) {
	
	struct FractionKachiLau* frPtr;
	
	frPtr = (struct FractionKachiLau*) malloc(sizeof(struct FractionKachiLau));
  
	frPtr->num = (frA->num * frB->denom) + (frB->num * frA->denom);
	
	frPtr->denom = (frA->denom * frB->denom);

	frPtr = reduce(frPtr);

	return frPtr;
}

struct FractionKachiLau* subtractFractionKachiLau(struct FractionKachiLau* frA, struct FractionKachiLau* frB) {
	
	struct FractionKachiLau* frPtr;
	
	frPtr = (struct FractionKachiLau*) malloc(sizeof(struct FractionKachiLau));
  
	frPtr->num = (frA->num * frB->denom) - (frB->num * frA->denom);
	
	frPtr->denom = (frA->denom * frB->denom);

	frPtr = reduce(frPtr);

	return frPtr;
}

struct FractionKachiLau* multiplyFractionKachiLau(struct FractionKachiLau* frA, struct FractionKachiLau* frB) {
	
	struct FractionKachiLau* frPtr;
	
	frPtr = (struct FractionKachiLau*) malloc(sizeof(struct FractionKachiLau));
  
	frPtr->num = (frA->num * frB->num);
	
	frPtr->denom = (frA->denom * frB->denom);

	frPtr = reduce(frPtr);

	return frPtr;
}

struct FractionKachiLau* divideFractionKachiLau(struct FractionKachiLau* frA, struct FractionKachiLau* frB) {
	
	struct FractionKachiLau* frPtr;
	
	frPtr = (struct FractionKachiLau*) malloc(sizeof(struct FractionKachiLau));
  
	frPtr->num = (frA->num * frB->denom);
	
	frPtr->denom = (frA->denom * frB->num);

	frPtr = reduce(frPtr);

	return frPtr;
}

struct FractionKachiLau* reduce(struct FractionKachiLau* frPtr) {

	int simplify = gcd(frPtr);
 
	frPtr->num = frPtr->num / simplify;
 
	frPtr->denom = frPtr->denom / simplify;

	return frPtr;
}

int gcd(struct FractionKachiLau* frPtr) {

	int gcd = 1;
	int f = 0;

	if(frPtr->num > 0) {

		if (frPtr->num < frPtr->denom) {
			gcd = frPtr->num; 
		}else{
			gcd = frPtr->denom;
		}

		while (gcd > 1 && !f) {
			if (frPtr->num % gcd == 0 && frPtr->denom % gcd == 0) {
				f = 1;
			}else{
				gcd--;
			}
		}
	}
	return gcd;
}

void displayMenu() {
	
	printf("\n**********************************"\
		"\n*\t\tMenu\t\t *"\
		"\n* 1) init()\t\t\t *"\
		"\n* 2) addFractionKachiLau()\t *"\
		"\n* 3) subtractFractionKachiLau()\t *"\
		"\n* 4) multiplyFractionKachiLau()\t *"\
		"\n* 5) divideFractionKachiLau()\t *"\
		"\n* 6) print()\t\t\t *"\
		"\n* 7) Quit\t\t\t *"\
		"\n**********************************\n");

	printf("Enter an option(1 - 7): ");
	return;
}

void menu01() {

	struct FractionKachiLau frA;
	struct FractionKachiLau frB;
	struct FractionKachiLau* frPtr;
	int option;
	int ok = 0;

	do {

		displayMenu();

		scanf("%d", &option);

		switch(option) {

		case 1:
			//Calling in an function
			printf("\nCalling init() --\n");

			init(&frA);
			init(&frB);
			ok = 1;

			break;

		case 2:
			printf("\nCalling addFractionKachiLau() --\n");

			if(ok == 1) {
				frPtr = addFractionKachiLau(&frA, &frB);
			} else {
				printf("\nYOU NEED TO INITALIZE THE FRACTION!\n");
			}

			break;

		case 3:
			//Error
			printf("\nCalling subtractFractionKachiLau() --\n");

			if(ok == 1) {
				frPtr = subtractFractionKachiLau(&frA, &frB);
			} else {
				printf("\nYOU NEED TO INITALIZE THE FRACTION!\n");
			}

			break;

		case 4:
			printf("\nCalling multiplyFractionKachiLau() --\n");

			if(ok == 1) {
				frPtr = multiplyFractionKachiLau(&frA, &frB);
			} else {
				printf("\nYOU NEED TO INITALIZE THE FRACTION!\n");
			}
			break;

		case 5:
			printf("\nCalling divideFractionKachiLau() --\n");

			if(ok == 1) {
				frPtr = divideFractionKachiLau(&frA, &frB);
			} else {
				printf("\nYOU NEED TO INITALIZE THE FRACTION!\n");
			}

			break;

		case 6:
			printf("\nCalling print() --\n");

			if(ok == 1) {
				print(frPtr);
			} else {
				printf("\nYOU NEED TO INITALIZE THE FRACTION!\n");
			}

			break;

		case 7:
			//Quit
			printf("\n      Have fun ...\n\n");

			break;

		default:
			//Wrong option
			printf("\n        WRONG OPTION!\n");
		}

	} while (option != 7);

	free(frPtr);

	return;
}

void displayinfo() {

	printf("CIS 27 - Data Structures"\

	"\nLaney College"\

	"\nKaChiLau"\

	"\nSpring 2013"\

	"\n\nAssignment Information --"\

	"\n  Assignment Number:  Lab 04,"\
	
	"\n\t\t      Coding Assignment -- Exercise #1"\

	"\n  Written by:\t      KaChiLau"\

	"\n  Due Date:\t      February 28, 2013\n");

	return;
}

/*OUTPUT
CIS 27 - Data Structures
Laney College
KaChiLau
Spring 2013

Assignment Information --
  Assignment Number:  Lab 04,
                      Coding Assignment -- Exercise #1
  Written by:         KaChiLau
  Due Date:           February 28, 2013

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): -1

        WRONG OPTION!

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): 6

Calling print() --

YOU NEED TO INITALIZE THE FRACTION!

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): 1

Calling init() --

Enter an Fraction --
Num: 3
Denom: 4

Enter an Fraction --
Num: 5
Denom: 12

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): 2

Calling addFractionKachiLau() --

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): 6

Calling print() --

Num: 7
Denom: 6

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): 1

Calling init() --

Enter an Fraction --
Num: -3
Denom: 7

Enter an Fraction --
Num: 4
Denom: 9

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): 3

Calling subtractFractionKachiLau() --

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): 6

Calling print() --

Num: -55
Denom: 63

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): 1

Calling init() --

Enter an Fraction --
Num: 2
Denom: 11

Enter an Fraction --
Num: 5
Denom: 101

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): 4

Calling multiplyFractionKachiLau() --

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): 6

Calling print() --

Num: 10
Denom: 1111

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): 5

Calling divideFractionKachiLau() --

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): 6

Calling print() --

Num: 202
Denom: 55

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): 1

Calling init() --

Enter an Fraction --
Num: 6
Denom: 17

Enter an Fraction --
Num: -8
Denom: 15

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): 5

Calling divideFractionKachiLau() --

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): 6

Calling print() --

Num: 0
Denom: 1

**********************************
*               Menu             *
* 1) init()                      *
* 2) addFractionKachiLau()       *
* 3) subtractFractionKachiLau()  *
* 4) multiplyFractionKachiLau()  *
* 5) divideFractionKachiLau()    *
* 6) print()                     *
* 7) Quit                        *
**********************************
Enter an option(1 - 7): 7

      Have fun ...

*/