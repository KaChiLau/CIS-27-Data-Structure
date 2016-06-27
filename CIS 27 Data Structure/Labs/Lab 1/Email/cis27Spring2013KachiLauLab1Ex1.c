/**
*Program name: cis27Spring2013KachiLauLab1Ex1.c
*Dicussion:    lab1Ex1
*Written By:   KachiLau
*/

#include <stdio.h>

//Function Prototypes
void menu01(void); 

void displayMenu(void);

void displayinfo(void);

int getNumDigitKaChilau(int);

int main() {

	displayinfo();

	menu01();

	return 0;
}

//Function definitions

void displayinfo() {

	printf("CIS 27 - Data Structures"\

	"\nLaney College"\

	"\nKaChiLau"\

	"\nSpring 2013"\

	"\n\nAssignment Information --"\

	"\n  Assignment Number:  Lab 1,"\
	
	"\n\t\t      Coding Assignment -- Exercise #1"\

	"\n  Written by:\t      KaChiLau"\

	"\n  Due Date:\t      January 31, 2013\n");

	return;
}

void displayMenu() {
	
	printf("\n************************************"\
		"\n*\t\tMenu\t\t   *"\
		"\n* 1) Calling getNumDigitKaChiLau() *"\
		"\n* 2) Quit\t\t\t   *"\
		"\n************************************\n");

	printf("Enter an option(1 or 2): ");
	return;
}

int getNumDigitKaChilau(int arg) {
	
	int temp = 0;

	do {
		arg /= 10;
		temp++;
	} while (arg);

	return temp;
}

void menu01() {

	int option;
	int data;

	do {

		displayMenu();
		scanf("%d", &option);

		switch(option) {

		case 1:
			//Calling in an function
			printf("\n  Enter an integer: ");
			scanf("%d", &data);
			printf("  Calling getNumDigitKaChilau() - "\
				"\n    %d has %d digits\n",data, getNumDigitKaChilau(data));
			break;

		case 2:
			//Quit
			printf("\n    Have fun yet!\n\n");
			break;

		default:
			//Wrong option
			printf("\n    WRONG OPTION!\n");
		}

	} while (option != 2);

	return;
}

/*OUTPUT
CIS 27 - Data Structures
Laney College
KaChiLau
Spring 2013

Assignment Information --
  Assignment Number:  Lab 1,
                      Coding Assignment -- Exercise #1
  Written by:         KaChiLau
  Due Date:           January 31, 2013

************************************
*               Menu               *
* 1) Calling getNumDigitKaChiLau() *
* 2) Quit                          *
************************************
Enter an option(1 or 2): 4

    WRONG OPTION!

************************************
*               Menu               *
* 1) Calling getNumDigitKaChiLau() *
* 2) Quit                          *
************************************
Enter an option(1 or 2): 1

  Enter an integer: 3287401
  Calling getNumDigitKaChilau() -
    3287401 has 7 digits

************************************
*               Menu               *
* 1) Calling getNumDigitKaChiLau() *
* 2) Quit                          *
************************************
Enter an option(1 or 2): 1

  Enter an integer: -12345
  Calling getNumDigitKaChilau() -
    -12345 has 5 digits

************************************
*               Menu               *
* 1) Calling getNumDigitKaChiLau() *
* 2) Quit                          *
************************************
Enter an option(1 or 2): -2

    WRONG OPTION!

************************************
*               Menu               *
* 1) Calling getNumDigitKaChiLau() *
* 2) Quit                          *
************************************
Enter an option(1 or 2): 2

    Have fun yet!

Press any key to continue . . .

*/