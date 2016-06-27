/**
*Program name: cis27Spring2013KachiLauLab3Ex1.c
*Dicussion:    lab3 Ex1
*Written By:   KachiLau
*Date:         2/14/13
*/

#include <stdio.h>

typedef struct {
	int num;
	int denom;

} FractionKachiLau;


void divideByKachiLau(void);
int powerIntKachiLau(void);
double powerdoubleKachiLau(void);
int power(int, int);
void menu01(void);
void displaymenu(void);
void displayinfo(void);
void print(FractionKachiLau);
FractionKachiLau powerFractionKachiLau(void);
FractionKachiLau Powerf(FractionKachiLau, FractionKachiLau);

int main() {

	displayinfo();

	menu01();

	return 0;
}

void divideByKachiLau() {
	
	int m;
	int n;

	printf("Enter an integer: ");
	scanf("%d", &m);

	while(m == 0) {
		printf("\nDenom cannot be ZERO"\
			"\nPlease re-Enter an integer: ");
		scanf("%d", &m);
	}

	for(n = 0; n < 10;n++) {
		printf("%d / %d is %d\n", n, m, n / m);
	}

	return;
}

int powerIntKachiLau() {
	int i;
	int iValue;
	int n;
	int total;

	printf("Enter an integer: ");
	scanf("%d", &iValue);

	printf("Enter an power: ");
	scanf("%d", &n);
	
	while(n < 0) {
		printf("\nPlease enter an positive Power: ");
		scanf("%d", &n);
	} 

	total = power(n, iValue);

	printf("%d to the power of %d is: ",
		iValue ,n);

	return total;
}

double powerDoubleKachiLau() {
	int i ;
	double dValue;
	int n;
	double total;

	printf("Enter an double integer: ");
	scanf("%lf", &dValue);

	printf("Enter an power: ");
	scanf("%d", &n);
	
	while(n < 0) {
		printf("\nPlease enter an positive Power: ");
		scanf("%d", &n);
	} 

	if(n) {
		total = dValue;
		i = 0;
		while(i < n - 1) {
			total *= dValue;
			i++;
		}
	} else {
		total = 1;
	}

	printf("%.2f to the power of %d is: ",
		dValue ,n);

	return total;
}

FractionKachiLau powerFractionKachiLau() {

	FractionKachiLau frA;
	FractionKachiLau total;
	int n;

	printf("Enter an Fraction --\n\n");
	printf("Num: ");
	scanf("%d", &frA.num);
	printf("Denom: ");
	scanf("%d", &frA.denom);

	while(frA.denom == 0) {
		printf("\nDenominator cannot be 0"\
			"\nPlease re-enter the Denom: ");
		scanf("%d", &frA.denom);
	}

	printf("\nEnter an power: ");
	scanf("%d", &n);

	while(n < 0) {
		printf("\nPlease enter an positive Power: ");
		scanf("%d", &n);
	}

	total.num = power(n, frA.num);
	total.denom = power(n, frA.denom); 

	return total;
}

void displayMenu() {
	
	printf("\n**********************************"\
		"\n*\t\tMenu\t\t *"\
		"\n* 1) divideByKachiLau()\t\t *"\
		"\n* 2) powerIntKachiLau()\t\t *"\
		"\n* 3) powerDoubleKachiLau()\t *"\
		"\n* 4) powerFractionKachiLau()\t *"\
		"\n* 5) Quit\t\t\t *"\
		"\n**********************************\n");

	printf("Enter an option(1, 2, 3, 4 or 5): ");
	return;
}

void menu01() {

	int option;

	do {

		displayMenu();

		scanf("%d", &option);

		switch(option) {

		case 1:
			//Calling in an function
			printf("\nCalling divideByKachiLau() --\n");
			divideByKachiLau();
			break;

		case 2:
			printf("\nCalling powerIntKachiLau() --\n");

			printf("%d\n", powerIntKachiLau());

			break;

		case 3:
			//Error
			printf("\nCalling powerDoubleKachiLau() --\n");

			printf("%.2f\n", powerDoubleKachiLau());

			break;

		case 4:
			printf("\nCalling powerFractionKachiLau() --\n");
			print(powerFractionKachiLau());
			break;

		case 5:
			//Quit
			printf("\n      Have fun ...\n\n");
			break;

		default:
			//Wrong option
			printf("\n        WRONG OPTION!\n");
		}

	} while (option != 5);

	return;
}

int power(int n, int Value) {
	int total;
	int i;

	if(n) {
		total = Value;
		i = 0;
		while(i < n - 1) {
			total *= Value;
			i++;
		}
	} else {
		total = 1;
	}

	return total;
}

void print(FractionKachiLau arg) {

	printf("\nThe Fraction after powered: \nNum: %d\n"\
		"Denom: %d\n", arg.num, arg.denom);

	return;
}

void displayinfo() {

	printf("CIS 27 - Data Structures"\

	"\nLaney College"\

	"\nKaChiLau"\

	"\nSpring 2013"\

	"\n\nAssignment Information --"\

	"\n  Assignment Number:  Lab 03,"\
	
	"\n\t\t      Coding Assignment -- Exercise #1"\

	"\n  Written by:\t      KaChiLau"\

	"\n  Due Date:\t      February 14, 2013\n");

	return;
}

/*OUTPUT

CIS 27 - Data Structures
Laney College
KaChiLau
Spring 2013

Assignment Information --
  Assignment Number:  Lab 03,
                      Coding Assignment -- Exercise #1
  Written by:         KaChiLau
  Due Date:           February 14, 2013

**********************************
*               Menu             *
* 1) divideByKachiLau()          *
* 2) powerIntKachiLau()          *
* 3) powerDoubleKachiLau()       *
* 4) powerFractionKachiLau()     *
* 5) Quit                        *
**********************************
Enter an option(1, 2, 3, 4 or 5): 6

        WRONG OPTION!

**********************************
*               Menu             *
* 1) divideByKachiLau()          *
* 2) powerIntKachiLau()          *
* 3) powerDoubleKachiLau()       *
* 4) powerFractionKachiLau()     *
* 5) Quit                        *
**********************************
Enter an option(1, 2, 3, 4 or 5): 1

Calling divideByKachiLau() --
Enter an integer: 3
0 / 3 is 0
1 / 3 is 0
2 / 3 is 0
3 / 3 is 1
4 / 3 is 1
5 / 3 is 1
6 / 3 is 2
7 / 3 is 2
8 / 3 is 2
9 / 3 is 3

**********************************
*               Menu             *
* 1) divideByKachiLau()          *
* 2) powerIntKachiLau()          *
* 3) powerDoubleKachiLau()       *
* 4) powerFractionKachiLau()     *
* 5) Quit                        *
**********************************
Enter an option(1, 2, 3, 4 or 5): 2

Calling powerIntKachiLau() --
Enter an integer: 2
Enter an power: 4
2 to the power of 4 is: 16

**********************************
*               Menu             *
* 1) divideByKachiLau()          *
* 2) powerIntKachiLau()          *
* 3) powerDoubleKachiLau()       *
* 4) powerFractionKachiLau()     *
* 5) Quit                        *
**********************************
Enter an option(1, 2, 3, 4 or 5): 2

Calling powerIntKachiLau() --
Enter an integer: 1
Enter an power: 0
1 to the power of 0 is: 1

**********************************
*               Menu             *
* 1) divideByKachiLau()          *
* 2) powerIntKachiLau()          *
* 3) powerDoubleKachiLau()       *
* 4) powerFractionKachiLau()     *
* 5) Quit                        *
**********************************
Enter an option(1, 2, 3, 4 or 5): 3

Calling powerDoubleKachiLau() --
Enter an double integer: 3.36
Enter an power: 3
3.36 to the power of 3 is: 37.93

**********************************
*               Menu             *
* 1) divideByKachiLau()          *
* 2) powerIntKachiLau()          *
* 3) powerDoubleKachiLau()       *
* 4) powerFractionKachiLau()     *
* 5) Quit                        *
**********************************
Enter an option(1, 2, 3, 4 or 5): 3

Calling powerDoubleKachiLau() --
Enter an double integer: 0.00
Enter an power: 0
0.00 to the power of 0 is: 1.00

**********************************
*               Menu             *
* 1) divideByKachiLau()          *
* 2) powerIntKachiLau()          *
* 3) powerDoubleKachiLau()       *
* 4) powerFractionKachiLau()     *
* 5) Quit                        *
**********************************
Enter an option(1, 2, 3, 4 or 5): 4

Calling powerFractionKachiLau() --
Enter an Fraction --

Num: 3
Denom: 1

Enter an power: 3

The Fraction after powered:
Num: 27
Denom: 1

**********************************
*               Menu             *
* 1) divideByKachiLau()          *
* 2) powerIntKachiLau()          *
* 3) powerDoubleKachiLau()       *
* 4) powerFractionKachiLau()     *
* 5) Quit                        *
**********************************
Enter an option(1, 2, 3, 4 or 5): 4

Calling powerFractionKachiLau() --
Enter an Fraction --

Num: 5
Denom: 0

Denominator cannot be 0
Please re-enter the Denom: 0

Denominator cannot be 0
Please re-enter the Denom: 1

Enter an power: 3

The Fraction after powered:
Num: 125
Denom: 1

**********************************
*               Menu             *
* 1) divideByKachiLau()          *
* 2) powerIntKachiLau()          *
* 3) powerDoubleKachiLau()       *
* 4) powerFractionKachiLau()     *
* 5) Quit                        *
**********************************
Enter an option(1, 2, 3, 4 or 5): 4

Calling powerFractionKachiLau() --
Enter an Fraction --

Num: -5
Denom: 7

Enter an power: 4

The Fraction after powered:
Num: 625
Denom: 2401

**********************************
*               Menu             *
* 1) divideByKachiLau()          *
* 2) powerIntKachiLau()          *
* 3) powerDoubleKachiLau()       *
* 4) powerFractionKachiLau()     *
* 5) Quit                        *
**********************************
Enter an option(1, 2, 3, 4 or 5): 4

Calling powerFractionKachiLau() --
Enter an Fraction --

Num: -3
Denom: 1

Enter an power: 3

The Fraction after powered:
Num: -27
Denom: 1

**********************************
*               Menu             *
* 1) divideByKachiLau()          *
* 2) powerIntKachiLau()          *
* 3) powerDoubleKachiLau()       *
* 4) powerFractionKachiLau()     *
* 5) Quit                        *
**********************************
Enter an option(1, 2, 3, 4 or 5): 5

      Have fun ...

Press any key to continue . . .
*/