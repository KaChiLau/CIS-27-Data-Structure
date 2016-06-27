/**
*Program name: cis27Spring2013KachiLauLab2Ex1.c
*Dicussion:    whatever ...
*Written By:   KachiLau
*Date:         2/07/13
*/

#include <stdio.h>
//#include <cstdlib>

void extractLargestDigitKachiLau(void);
void displayInfoKachiLau(void);
void largestOccurrence(int[]);
void smallestOccurrence(int[]);
void menu01(void);
void displaymenu(void);
void displayinfo(void);

int main() {
	
	displayinfo();

	menu01();

	return 0;
}

void displayMenu() {
	
	printf("\n    ************************************"\
		"\n    *\t\tMenu\t\t       *"\
		"\n    * 1) extractLargestDigitKachiLau() *"\
		"\n    * 2) displayInfoKachiLau()\t       *"\
		"\n    * 3) Quit\t\t\t       *"\
		"\n    ************************************\n");

	printf("    Enter an option(1, 2 or 3): ");
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
			printf("\n      Calling extractLargestDigitKachiLau() --\n");
			extractLargestDigitKachiLau();
			break;

		case 2:
			printf("\n      Calling displayDigitInfoKachiLau() --\n");
			displayInfoKachiLau();
			break;

		case 3:
			//Quit
			printf("\n      Have fun ...\n\n");
			break;

		default:
			//Wrong option
			printf("\n        WRONG OPTION!\n");
		}

	} while (option != 3);

	return;
}

void extractLargestDigitKachiLau() {
	int numInt;
	int* iPtr;
	int i;
	int largest = 0;
	int temp;
	int x;

	printf("\tHow many integers (to be worked on)? ");
	scanf("%d", &numInt);

	iPtr = (int*) malloc(numInt * sizeof(int));

	for(i = 0; i < numInt; i++) {
		printf("\t  Enter integer #%d: ", i + 1);
		scanf("%d", (iPtr + i));

		temp = *(iPtr + i);

		if(temp < 0) {
			temp = -temp;
		}

		while (temp != 0) {

			x = (temp % 10);

			if(x > largest) {
				largest = x;
			}

			temp /= 10;
		}
		temp = 0;

	}

	printf("\n\tThe largest digit is %d\n", largest);
	printf("\tDigit %d can be found in:\n", largest);
	for(i = 0; i < numInt; i++) {
		temp = *(iPtr + i);
		if(temp < 0) {
			temp = -temp;
		}
		while(temp != 0) {
			x = (temp % 10);
			if(largest == x) {
				printf("\t  %d\n", *(iPtr + i));
				temp = 0;
			}
			temp /= 10;
		}
	}
	return;
}

void displayInfoKachiLau() {
	//if digit is not there, it would not displaying
	int numInt;
	int* iPtr;
	int i;
	int ary[10] = {0};
	int temp = 0;
	int x;
	
	printf("       How many integers (to be worked on)? ");
	scanf("%d", &numInt);

	iPtr = (int*) malloc(numInt * sizeof(int));

	for(i = 0; i < numInt; i++) {
		printf("\t  Enter integer #%d: ", i + 1);
		scanf("%d", (iPtr + i));

		temp = *(iPtr + i);

		if(temp < 0) {
			temp = -temp;
		}
		while(temp != 0) {
			for(x = 0; x < 10; x++) {
				if((x) == temp % 10) {
					ary[x]++;
				}
			}
			temp /= 10;
		}
	}

	printf("\n       Occurrence of all existing  digits --\n");
	for(i = 0; i < 10; i++) {
		if(ary[i] > 0) {
			printf("\tDigit %d : %d\n", i, ary[i]);
		}
	}
	
	printf("\n      Occurrence of all existing EVEN digits --\n");
	for(i = 0; i < 10; i += 2) {
		if(ary[i] > 0) {
			printf("\tDigit %d : %d\n", i, ary[i]);
		}
	}

	largestOccurrence(ary);
	smallestOccurrence(ary);

	return;
}

void largestOccurrence(int ary[]) {
	int largestO = 0;
	int i;

	printf("\n      The even digit(s) that has/have the largest occurrence -\n");
	for(i = 0; i < 10; i += 2) {
		if(ary[i]) {
			if(ary[i] > largestO) {
				largestO = ary[i];
			}
		}
	}

	for(i = 0; i < 10; i += 2) {
		if(ary[i] == largestO) {
			printf("\t%d\n", i);
		}
	}
	printf("      And the number of occurrence(s) : %d\n", largestO);

	return;
}

void smallestOccurrence(int ary[]) {
	int smallestO = 10;
	int i;

	printf("\n      The even digit(s) that has/have the smallest occurrence -\n");
	for(i = 0; i < 10; i += 2) {
		if(ary[i]) {
			if(ary[i] < smallestO) {
				smallestO = ary[i];
			}
		}
	}
	 
	for(i = 0; i < 10; i += 2) {
		if(ary[i] == smallestO) {
			printf("\t%d\n", i);
		}
	}
	printf("      And the number of occurrence(s) : %d\n", smallestO);


	return;
}

void displayinfo() {

	printf("CIS 27 - Data Structures"\

	"\nLaney College"\

	"\nKaChiLau"\

	"\nSpring 2013"\

	"\n\nAssignment Information --"\

	"\n  Assignment Number:  Lab 02,"\
	
	"\n\t\t      Coding Assignment -- Exercise #1"\

	"\n  Written by:\t      KaChiLau"\

	"\n  Due Date:\t      February 7, 2013\n");

	return;
}
/*OUTPUT
CIS 27 - Data Structures
Laney College
KaChiLau
Spring 2013

Assignment Information --
  Assignment Number:  Lab 02,
                      Coding Assignment -- Exercise #1
  Written by:         KaChiLau
  Due Date:           February 7, 2013

    ************************************
    *           Menu                   *
    * 1) extractLargestDigitKachiLau() *
    * 2) displayInfoKachiLau()         *
    * 3) Quit                          *
    ************************************
    Enter an option(1, 2 or 3): 4

        WRONG OPTION!

    ************************************
    *           Menu                   *
    * 1) extractLargestDigitKachiLau() *
    * 2) displayInfoKachiLau()         *
    * 3) Quit                          *
    ************************************
    Enter an option(1, 2 or 3): 1

      Calling extractLargestDigitKachiLau() --
        How many integers (to be worked on)? 2
          Enter integer #1: 1230476
          Enter integer #2: 10034850

        The largest digit is 8
        Digit 8 can be found in:
          10034850

    ************************************
    *           Menu                   *
    * 1) extractLargestDigitKachiLau() *
    * 2) displayInfoKachiLau()         *
    * 3) Quit                          *
    ************************************
    Enter an option(1, 2 or 3): 1

      Calling extractLargestDigitKachiLau() --
        How many integers (to be worked on)? 3
          Enter integer #1: 1230476
          Enter integer #2: 10034950
          Enter integer #3: 9023497

        The largest digit is 9
        Digit 9 can be found in:
          10034950
          9023497

    ************************************
    *           Menu                   *
    * 1) extractLargestDigitKachiLau() *
    * 2) displayInfoKachiLau()         *
    * 3) Quit                          *
    ************************************
    Enter an option(1, 2 or 3): 2

      Calling displayDigitInfoKachiLau() --
       How many integers (to be worked on)? 2
          Enter integer #1: 1230476
          Enter integer #2: 10034850

       Occurrence of all existing  digits --
        Digit 0 : 4
        Digit 1 : 2
        Digit 2 : 1
        Digit 3 : 2
        Digit 4 : 2
        Digit 5 : 1
        Digit 6 : 1
        Digit 7 : 1
        Digit 8 : 1

      Occurrence of all existing EVEN digits --
        Digit 0 : 4
        Digit 2 : 1
        Digit 4 : 2
        Digit 6 : 1
        Digit 8 : 1

      The even digit(s) that has/have the largest occurrence -
        0
      And the number of occurrence(s) : 4

      The even digit(s) that has/have the smallest occurrence -
        2
        6
        8
      And the number of occurrence(s) : 1

    ************************************
    *           Menu                   *
    * 1) extractLargestDigitKachiLau() *
    * 2) displayInfoKachiLau()         *
    * 3) Quit                          *
    ************************************
    Enter an option(1, 2 or 3): 2

      Calling displayDigitInfoKachiLau() --
       How many integers (to be worked on)? 3
          Enter integer #1: 1230476
          Enter integer #2: 10434950
          Enter integer #3: 9023497

       Occurrence of all existing  digits --
        Digit 0 : 4
        Digit 1 : 2
        Digit 2 : 2
        Digit 3 : 3
        Digit 4 : 4
        Digit 5 : 1
        Digit 6 : 1
        Digit 7 : 2
        Digit 9 : 3

      Occurrence of all existing EVEN digits --
        Digit 0 : 4
        Digit 2 : 2
        Digit 4 : 4
        Digit 6 : 1

      The even digit(s) that has/have the largest occurrence -
        0
        4
      And the number of occurrence(s) : 4

      The even digit(s) that has/have the smallest occurrence -
        6
      And the number of occurrence(s) : 1

    ************************************
    *           Menu                   *
    * 1) extractLargestDigitKachiLau() *
    * 2) displayInfoKachiLau()         *
    * 3) Quit                          *
    ************************************
    Enter an option(1, 2 or 3): 3

      Have fun ...

Press any key to continue . . .

*/