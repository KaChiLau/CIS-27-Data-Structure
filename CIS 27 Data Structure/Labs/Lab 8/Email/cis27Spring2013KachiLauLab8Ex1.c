/**
*Program name: cis27Spring2013KachiLauLab8Ex1.c
*Dicussion:    lab5Ex1
*Written By:   KachiLau
*Date:         4/18/13
*/

#include <stdio.h>
#include <stdlib.h>

struct FractionKL { 
	int num;
	int denom;
};

struct PolyTermKL {
	int expo;
	struct FractionKL coeff;
};

typedef struct PolyTermKL* PolyTermAdrKL;

struct PolyNodeKL {
	PolyTermAdrKL dataPtr;
	struct PolyNodeKL* next;
};

typedef struct FractionKL* FractionAddrKL; 
typedef struct PolyNodeKL* PolyNodeAdrKL;
typedef struct PolyNodeKL* PolyListKL;
typedef PolyListKL* PolyListAdrKL;

FractionAddrKL createFractionKL(void);
PolyNodeAdrKL createPolyNodeKL(void);

void displayFraction(PolyNodeAdrKL, PolyListAdrKL);
int printPolyKL(PolyListAdrKL);
void printGeneral(PolyNodeAdrKL);
void printPrintEqual1(PolyNodeAdrKL);
void printPrintEqual0(PolyNodeAdrKL);

int insertPolyNodeKL(PolyListKL*, PolyNodeAdrKL);
void insertFirst(PolyListKL*, PolyNodeAdrKL);
int Update(PolyListKL*, PolyNodeAdrKL);
void insertAfter(PolyListKL*, PolyNodeAdrKL);

PolyNodeAdrKL polyNodeAddition(PolyNodeAdrKL, PolyNodeAdrKL);
PolyNodeAdrKL polyNodeMultiply(PolyNodeAdrKL, PolyNodeAdrKL);

PolyListAdrKL addPolyKL(PolyListAdrKL, PolyListAdrKL);
PolyListAdrKL multiplyPolyKL(PolyListAdrKL, PolyListAdrKL);

void menuPolyKL(void);

void freeList(PolyListAdrKL);

void displayinfo(void);

int main() {

	displayinfo();

	menuPolyKL();

	return 0;
}

FractionAddrKL createFractionKL() { 
	FractionAddrKL frPtr;

	frPtr = (FractionAddrKL) 
		malloc(sizeof(struct FractionKL));
	
	printf("\tEnter an Fraction- \n\n\tNum: ");
	scanf("%d", &frPtr->num);
	printf("\tNon-negative Denom: ");
	scanf("%d", &frPtr->denom);
	
	while(frPtr->denom == 0) {
		printf("\n\tDenominator cannot be 0"\
			"\n\tPlease re-enter the Denom: ");
		scanf("%d", &frPtr->denom);
	}

	if(frPtr->denom < 0) {
		frPtr->num = -frPtr->num;
		frPtr->denom = -frPtr->denom;
	}

	return frPtr;
}

PolyNodeAdrKL createPolyNodeKL() {
	PolyNodeAdrKL polyNodePtr;
	int exponet = 0;
	
	printf("\n\tPlease Enter expoent: ");
	scanf("%d", &exponet);

	polyNodePtr = (PolyNodeAdrKL)malloc(sizeof(struct PolyNodeKL)); 
	polyNodePtr->dataPtr = (PolyTermAdrKL)malloc(sizeof(struct PolyTermKL));
	
	while(exponet < 0) {
		printf("\nYou have entered a negative expoent "
			"\nPlease Re-enter an non-negative expoent: ");

		scanf("%d", &exponet);
	}

	polyNodePtr->dataPtr->coeff = *createFractionKL();
	polyNodePtr->dataPtr->expo = exponet;
	polyNodePtr->next = 0;
	
	return polyNodePtr;
}

void displayFraction(PolyNodeAdrKL nodeAdr, PolyListAdrKL myList) {

	if(nodeAdr == *myList) {
		printf("\n\n\t");
	}

	if(nodeAdr) {
		if(*myList != nodeAdr) {
			if(nodeAdr->dataPtr->coeff.num < 0) {
				printf(" - ");
				//nodeAdr->dataPtr->coeff.num  = -nodeAdr->dataPtr->coeff.num;
				if(nodeAdr->dataPtr->expo > 1) {
					printGeneral(nodeAdr);
				} else if (nodeAdr->dataPtr->expo == 1) {
					printPrintEqual1(nodeAdr);
				} else if (nodeAdr->dataPtr->expo == 0) {
					printPrintEqual0(nodeAdr);
				}
			} else {
				printf(" + ");
				if(nodeAdr->dataPtr->expo > 1) {
					printGeneral(nodeAdr);
				} else if (nodeAdr->dataPtr->expo == 1) {
					printPrintEqual1(nodeAdr);
				} else if (nodeAdr->dataPtr->expo == 0) {
					printPrintEqual0(nodeAdr);
				}
			}
		} else {
			if(nodeAdr->dataPtr->expo > 1) {
				printGeneral(nodeAdr);
				} else if (nodeAdr->dataPtr->expo == 1) {
					printPrintEqual1(nodeAdr);
				} else if (nodeAdr->dataPtr->expo == 0) {
					printPrintEqual0(nodeAdr);
				}
		}
		
	}

	return;
}

void printGeneral(PolyNodeAdrKL nodeAdr) {
	printf("%d/%dx%d", nodeAdr->dataPtr->coeff.num, 
		nodeAdr->dataPtr->coeff.denom,
		nodeAdr->dataPtr->expo);
	return;
}
void printPrintEqual1(PolyNodeAdrKL nodeAdr) {
	printf("%d/%dx", nodeAdr->dataPtr->coeff.num, 
		nodeAdr->dataPtr->coeff.denom);
	return;
}
void printPrintEqual0(PolyNodeAdrKL nodeAdr) {
	printf("%d/%d",nodeAdr->dataPtr->coeff.num, 
		nodeAdr->dataPtr->coeff.denom);
	return;
}

int printPolyKL(PolyListAdrKL myList) {

	PolyNodeAdrKL nodeAddr = *myList;

	if(*myList == 0) {
		printf("\n\tNo polynomial to be displayed!\n");
	} else {
		while(nodeAddr) {
			displayFraction(nodeAddr, myList);
			nodeAddr = nodeAddr->next;
		}
	}

	return 1;
}

int insertPolyNodeKL(PolyListKL* myList, PolyNodeAdrKL nodeAdr) { //nodeAdr = currentnode
	
	PolyNodeAdrKL tempPtr = 0;
	int count = 0;

	tempPtr =*myList;
	if((*myList == 0) || (nodeAdr->dataPtr->expo > tempPtr->dataPtr->expo)) {
		insertFirst(myList, nodeAdr);
	} else {
		if(nodeAdr->dataPtr->expo <= tempPtr->dataPtr->expo) {
			count = Update(myList, nodeAdr);
		}
		if(count == 0) {
			insertAfter(myList, nodeAdr);
		}
	}
	return 1;
}

PolyNodeAdrKL polyNodeMultiply(PolyNodeAdrKL nodeAdr, PolyNodeAdrKL tempAdr) {
	PolyNodeAdrKL times;
	int nodeN = nodeAdr->dataPtr->coeff.num;
	int nodeD = nodeAdr->dataPtr->coeff.denom;
	int expoN = nodeAdr->dataPtr->expo;
	int tempN = tempAdr->dataPtr->coeff.num;
	int tempD = tempAdr->dataPtr->coeff.denom;
	int expoT = tempAdr->dataPtr->expo;
	int temp = 0;

	times = (PolyNodeAdrKL)malloc(sizeof(struct PolyNodeKL)); 
	times->dataPtr = (PolyTermAdrKL)malloc(sizeof(struct PolyTermKL));

	times->dataPtr->coeff.num = nodeN * tempN; 

	times->dataPtr->coeff.denom = nodeD * tempD;

	times->dataPtr->expo = expoN + expoT;
	

	return times;
}

PolyNodeAdrKL polyNodeAddition(PolyNodeAdrKL nodeAdr, PolyNodeAdrKL tempAdr) {
	PolyNodeAdrKL sum;

	int nodeN = nodeAdr->dataPtr->coeff.num;
	int nodeD = nodeAdr->dataPtr->coeff.denom;
	int tempN = tempAdr->dataPtr->coeff.num;
	int tempD = tempAdr->dataPtr->coeff.denom;
	int expo = nodeAdr->dataPtr->expo;

	sum = (PolyNodeAdrKL)malloc(sizeof(struct PolyNodeKL)); 
	sum->dataPtr = (PolyTermAdrKL)malloc(sizeof(struct PolyTermKL));

	sum->dataPtr->coeff.num = (nodeN * tempD) + (nodeD * tempN); 

	sum->dataPtr->coeff.denom = (nodeD * tempD);

	sum->dataPtr->expo = expo;

	return sum;
}

void insertFirst(PolyListKL* myList, PolyNodeAdrKL nodeAdr) {
	nodeAdr->next = *myList;
	*myList = nodeAdr;
	return;
}

int Update(PolyListKL* myList, PolyNodeAdrKL nodeAdr) {
	PolyNodeAdrKL tempPtr = *myList;
	PolyNodeAdrKL sum;
	int count = 0;

	sum = (PolyNodeAdrKL)malloc(sizeof(struct PolyNodeKL)); 
	sum->dataPtr = (PolyTermAdrKL)malloc(sizeof(struct PolyTermKL));

	while(tempPtr){
		if(nodeAdr->dataPtr->expo == tempPtr->dataPtr->expo) {
			sum = polyNodeAddition(nodeAdr, tempPtr);
			tempPtr->dataPtr = sum->dataPtr;
			count = 1;
		}
		tempPtr = tempPtr->next;
	}

	return count;
}

void insertAfter(PolyListKL* myList, PolyNodeAdrKL nodeAdr) {
	PolyNodeAdrKL prev = 0;
	PolyNodeAdrKL tempPtr = 0;
	int stop = 1;

	tempPtr = *myList;
	while(tempPtr && stop != 0) {
		if(nodeAdr->dataPtr->expo > tempPtr->dataPtr->expo) {
			stop = 0;
		}
		if(stop != 0) {
		prev = tempPtr;
		tempPtr = tempPtr->next;
		}
	}
	prev->next = nodeAdr;
	nodeAdr->next = tempPtr;

	return;
}

PolyListAdrKL addPolyKL(PolyListAdrKL one, PolyListAdrKL two) {

	PolyListKL temp1 = 0;
	PolyListKL temp2 = 0;
	PolyListKL temp3 = 0;
	PolyListKL tempR = 0;

	temp1 = (PolyNodeAdrKL)malloc(sizeof(struct PolyNodeKL)); 
	temp1->dataPtr = (PolyTermAdrKL)malloc(sizeof(struct PolyTermKL));

	temp2 = (PolyNodeAdrKL)malloc(sizeof(struct PolyNodeKL)); 
	temp2->dataPtr = (PolyTermAdrKL)malloc(sizeof(struct PolyTermKL));

	tempR = (PolyNodeAdrKL)malloc(sizeof(struct PolyNodeKL)); 
	tempR->dataPtr = (PolyTermAdrKL)malloc(sizeof(struct PolyTermKL));

	temp1 = *one;
	temp2 = *two;
	tempR = 0;
	while(temp1) {
		temp3 = (PolyNodeAdrKL)malloc(sizeof(struct PolyNodeKL)); 
		temp3->dataPtr = (PolyTermAdrKL)malloc(sizeof(struct PolyTermKL));
		temp3->dataPtr = temp1->dataPtr;
		insertPolyNodeKL(&tempR, temp3);
		temp1 = temp1->next;
	}

	while(temp2) {
		temp3 = (PolyNodeAdrKL)malloc(sizeof(struct PolyNodeKL)); 
		temp3->dataPtr = (PolyTermAdrKL)malloc(sizeof(struct PolyTermKL));
		temp3->dataPtr = temp2->dataPtr;
		insertPolyNodeKL(&tempR, temp3);
		temp2 = temp2->next;
	}

	return &tempR;	
}

PolyListAdrKL multiplyPolyKL(PolyListAdrKL one, PolyListAdrKL two) {
	PolyListKL temp1 = 0;
	PolyListKL temp2 = 0;
	PolyListKL temp3 = 0;
	PolyListKL tempR = 0;

	temp1 = (PolyNodeAdrKL)malloc(sizeof(struct PolyNodeKL)); 
	temp1->dataPtr = (PolyTermAdrKL)malloc(sizeof(struct PolyTermKL));

	temp2 = (PolyNodeAdrKL)malloc(sizeof(struct PolyNodeKL)); 
	temp2->dataPtr = (PolyTermAdrKL)malloc(sizeof(struct PolyTermKL));

	tempR = (PolyNodeAdrKL)malloc(sizeof(struct PolyNodeKL)); 
	tempR->dataPtr = (PolyTermAdrKL)malloc(sizeof(struct PolyTermKL));

	temp1 = *one;
	temp2 = *two;
	tempR = 0;

	while(temp1) {
		temp2 = *two;
		while(temp2){
			temp3 = (PolyNodeAdrKL)malloc(sizeof(struct PolyNodeKL)); 
			temp3->dataPtr = (PolyTermAdrKL)malloc(sizeof(struct PolyTermKL));
			temp3->dataPtr = temp1->dataPtr;
			temp3 = polyNodeMultiply(temp3, temp2);
			insertPolyNodeKL(&tempR, temp3);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}

	return &tempR;	
}

void menuPolyKL(void) {
	PolyListKL polyOne = 0;
	PolyListKL polyTwo = 0;
	PolyListKL polyResult = 0;
	PolyNodeAdrKL nodeAdr;
	int option = 0;
	int option2 = 0;
	int option3 = 0;
	int check = 0;
	int check2 = 0;

	do {
		printf("\n\t******************************"\
		"\n\t*    POLYNOMIAL OPERATIONS   *"\
		"\n\t* 1. Creating polynomials    *"\
		"\n\t* 2. Adding polynomials      *"\
		"\n\t* 3. Multiplying polynomials *"\
		"\n\t* 4. Displaying polynomials  *"\
		"\n\t* 5. clearing polynomials    *"\
		"\n\t* 6. Quit\t\t     *"\
		"\n\t******************************\n");

		printf("\tSelect an option(1 through 6): ");

		scanf("%d", &option);

		switch(option) {

		case 1:
			printf("\n\t******************************"\
			"\n\t*   Enter Two Polynomials    *"\
			"\n\t* 1. 1st poly\t\t     *"\
			"\n\t* 2. 2nd poly\t\t     *"\
			"\n\t******************************\n");

			printf("\tSelect an option(1 or 2): ");

			scanf("%d", &option2);

			if(option2 == 1) {
				nodeAdr = createPolyNodeKL();
				insertPolyNodeKL(&polyOne, nodeAdr);
			} else if (option2 == 2) {
				nodeAdr = createPolyNodeKL();
				insertPolyNodeKL(&polyTwo, nodeAdr);
			} else {
				printf("\n\tWRONG OPTION\n");
			}

			break;

		case 2:
			polyResult = *addPolyKL(&polyOne, &polyTwo);
			check = 1;
			break;

		case 3:
			polyResult = *multiplyPolyKL(&polyOne, &polyTwo);
			check = 2;
			break;

		case 4:
			printf("\n\tFor 1st Polynomial");
			printPolyKL(&polyOne);
			printf("\n\tFor 2nd Polynomial");
			printPolyKL(&polyTwo);

			if(check == 1) {
				printf("\n\t--Addition--");
			} else if (check == 2) {
				printf("\n\t--Multiply--");
			}
				printPolyKL(&polyResult);
			break;

		case 5:
			printf("\n\t******************************"\
			"\n\t*    Free Two Polynomials    *"\
			"\n\t* 1. 1st poly\t\t     *"\
			"\n\t* 2. 2nd poly\t\t     *"\
			"\n\t* 3. Result\t\t     *"\
			"\n\t******************************\n");

			printf("\tSelect an option(1, 2 or 3): ");

			scanf("%d", &option3);

			if(option3 == 1) {
				freeList(&polyOne);
			} else if (option3 == 2) {
				freeList(&polyTwo);
			} else if (option3 == 3){
				freeList(&polyResult);
			} else {
				printf("\n\tWRONG OPTION\n");
			}
			break;

		case 6:
			printf("\n\tHave Fun......\n");
			break;

		default:
			//Wrong option
			printf("\n\tyou should not be in this class\n");
		}

	} while (option != 6);

	return;
}

void freeList(PolyListAdrKL myList) {

	while(*myList) {
		(*myList)->dataPtr = 0;
		*myList = (*myList)->next;
	} 

	return;
}

void displayinfo() {

	printf("CIS 27 - Data Structures"\

	"\nLaney College"\

	"\nKaChiLau"\

	"\nSpring 2013"\

	"\n\nAssignment Information --"\

	"\n  Assignment Number:  Lab 08,"\
	
	"\n\t\t      Coding Assignment -- Exercise #1"\

	"\n  Written by:\t      KaChiLau"\

	"\n  Due Date:\t      April 23, 2013\n");

	return;
}
/*
For the addition, I think 
(1/1x2 + 3/4x + 5/12) + (1/1x4 – 3/7x2 + 4/9x + 2/11)
is  1/1x4 + 4/7x2 + 43/36x + 79/132
because 1/1x2 > -3/7x2
so answer should be positive
*/

/*CIS 27 - Data Structures
Laney College
KaChiLau
Spring 2013

Assignment Information --
  Assignment Number:  Lab 08,
                      Coding Assignment -- Exercise #1
  Written by:         KaChiLau
  Due Date:           April 23, 2013

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 7

        you should not be in this class

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 4

        For 1st Polynomial
        No polynomial to be displayed!

        For 2nd Polynomial
        No polynomial to be displayed!

        No polynomial to be displayed!

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 1

        ******************************
        *   Enter Two Polynomials    *
        * 1. 1st poly                *
        * 2. 2nd poly                *
        ******************************
        Select an option(1 or 2): 1

        Please Enter expoent: 0
        Enter an Fraction-

        Num: 5
        Non-negative Denom: 12

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 1

        ******************************
        *   Enter Two Polynomials    *
        * 1. 1st poly                *
        * 2. 2nd poly                *
        ******************************
        Select an option(1 or 2): 1

        Please Enter expoent: 1
        Enter an Fraction-

        Num: 3
        Non-negative Denom: 4

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 1

        ******************************
        *   Enter Two Polynomials    *
        * 1. 1st poly                *
        * 2. 2nd poly                *
        ******************************
        Select an option(1 or 2): 1

        Please Enter expoent: 2
        Enter an Fraction-

        Num: 1
        Non-negative Denom: 1

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 1

        ******************************
        *   Enter Two Polynomials    *
        * 1. 1st poly                *
        * 2. 2nd poly                *
        ******************************
        Select an option(1 or 2): 2

        Please Enter expoent: 4
        Enter an Fraction-

        Num: 1
        Non-negative Denom: 1

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 1

        ******************************
        *   Enter Two Polynomials    *
        * 1. 1st poly                *
        * 2. 2nd poly                *
        ******************************
        Select an option(1 or 2): 2

        Please Enter expoent: 2
        Enter an Fraction-

        Num: -3
        Non-negative Denom: 7

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 1

        ******************************
        *   Enter Two Polynomials    *
        * 1. 1st poly                *
        * 2. 2nd poly                *
        ******************************
        Select an option(1 or 2): 2

        Please Enter expoent: 1
        Enter an Fraction-

        Num: 4
        Non-negative Denom: 9

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 1

        ******************************
        *   Enter Two Polynomials    *
        * 1. 1st poly                *
        * 2. 2nd poly                *
        ******************************
        Select an option(1 or 2): 2

        Please Enter expoent: 0
        Enter an Fraction-

        Num: 2
        Non-negative Denom: 11

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 4

        For 1st Polynomial

        1/1x2 + 3/4x + 5/12
        For 2nd Polynomial

        1/1x4 - -3/7x2 + 4/9x + 2/11
        No polynomial to be displayed!

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 2

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 4

        For 1st Polynomial

        1/1x2 + 3/4x + 5/12
        For 2nd Polynomial

        1/1x4 - -3/7x2 + 4/9x + 2/11
        --Addition--

        1/1x4 + 4/7x2 + 43/36x + 79/132
        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 3

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 4

        For 1st Polynomial

        1/1x2 + 3/4x + 5/12
        For 2nd Polynomial

        1/1x4 - -3/7x2 + 4/9x + 2/11
        --Multiply--

        1/1x6 + 3/4x5 - -1/84x4 + 31/252x3 + 11196/33264x2 + 1528/4752x + 10/132

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 5

        ******************************
        *    Free Two Polynomials    *
        * 1. 1st poly                *
        * 2. 2nd poly                *
        * 3. Result                  *
        ******************************
        Select an option(1, 2 or 3): 1

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 5

        ******************************
        *    Free Two Polynomials    *
        * 1. 1st poly                *
        * 2. 2nd poly                *
        * 3. Result                  *
        ******************************
        Select an option(1, 2 or 3): 2

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 4

        For 1st Polynomial
        No polynomial to be displayed!

        For 2nd Polynomial
        No polynomial to be displayed!

        --Multiply--

        1/1x6 + 3/4x5 - -1/84x4 + 31/252x3 + 11196/33264x2 + 1528/4752x + 10/132

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 5

        ******************************
        *    Free Two Polynomials    *
        * 1. 1st poly                *
        * 2. 2nd poly                *
        * 3. Result                  *
        ******************************
        Select an option(1, 2 or 3): 3

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 4

        For 1st Polynomial
        No polynomial to be displayed!

        For 2nd Polynomial
        No polynomial to be displayed!

        --Multiply--
        No polynomial to be displayed!

        ******************************
        *    POLYNOMIAL OPERATIONS   *
        * 1. Creating polynomials    *
        * 2. Adding polynomials      *
        * 3. Multiplying polynomials *
        * 4. Displaying polynomials  *
        * 5. clearing polynomials    *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 6

        Have Fun......
Press any key to continue . . .
*/