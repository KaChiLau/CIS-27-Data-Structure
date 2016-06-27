/**
*Program name: cis27Spring2013KachiLauLab7Ex1.c
*Dicussion:    lab5Ex1
*Written By:   KachiLau
*Date:         4/02/13
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

FractionAddrKL createFractionKL();
PolyNodeAdrKL createPolyNodeKL(void);

PolyNodeAdrKL searchPolyNodeKL(PolyListAdrKL);
int getPolyOrderKL(PolyListAdrKL);
int printPolyKL(PolyListAdrKL); 

void menuPolyKL(PolyListAdrKL);
void displayFraction(struct PolyNodeKL*);
void displayinfo(void);

int insertPolyNodeKL(PolyListKL*, PolyNodeAdrKL);
void insertFirst(PolyListKL*, PolyNodeAdrKL);
int Update(PolyListKL*, PolyNodeAdrKL);
void insertAfter(PolyListKL*, PolyNodeAdrKL);
PolyNodeAdrKL polyNodeAddition(PolyNodeAdrKL, PolyNodeAdrKL);

int main() {
	PolyListKL myList = 0;

	displayinfo();
	menuPolyKL(&myList);

	return 0;
}

FractionAddrKL createFractionKL() { 
	FractionAddrKL frPtr;

	frPtr = (FractionAddrKL) 
		malloc(sizeof(struct FractionKL));

	printf("\n\tEnter an Fraction- \n\n\tNum: ");
	scanf("%d", &frPtr->num);
	printf("\n\tNon-negative Denom: ");
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
	polyNodePtr->dataPtr = (struct PolyTermKL*)malloc( sizeof(struct PolyTermKL));
	
	polyNodePtr->dataPtr->coeff = *createFractionKL();
	polyNodePtr->dataPtr->expo = exponet;
	polyNodePtr->next = 0;

	return polyNodePtr;
}

void displayFraction(struct PolyNodeKL* nodeAdr) {

	if(nodeAdr) {
		printf("\n\tExpo: %d\tAddress: %p"\
			"\n\tNum: %d\n\tdenom: %d\n\tNext: %p\n\n", 
			nodeAdr->dataPtr->expo, nodeAdr, nodeAdr->dataPtr->coeff.num,
			nodeAdr->dataPtr->coeff.denom,
			nodeAdr->next);
	} 
	return;
}

int printPolyKL(PolyListAdrKL myList) {

	PolyNodeAdrKL nodeAddr = *myList;

	if(*myList == 0) {
		printf("\n\tNo polynomial to be displayed!\n");
	} else {
		while(nodeAddr) {
			displayFraction(nodeAddr);
			nodeAddr = nodeAddr->next;
		}
	}

	return 1;
}

int getPolyOrderKL(PolyListAdrKL myList) {
	int count = 0;
	PolyNodeAdrKL nodeAddr = *myList;

	while(nodeAddr) {
		nodeAddr = nodeAddr->next;
		count++;
	} 

	return count;
}

PolyNodeAdrKL searchPolyNodeKL(PolyListAdrKL myList) {

	PolyNodeAdrKL nodeAdr = *myList;
	PolyNodeAdrKL tempPtr = 0;
	int count = 0;
	int expo = 0;

	printf("\tPlease Enter an exponet: ");
	scanf("%d", &expo);

	if(*myList == 0) {
		printf("\n\tEMPTY LIST...\n");
	} else if(*myList) {
		nodeAdr = *myList;
		while(nodeAdr) {
			if(nodeAdr->dataPtr->expo == expo) {
				tempPtr = nodeAdr;
				count = 1;
			}
			nodeAdr = nodeAdr->next;
		}
	}

	if(count == 0) {
		printf("\n\tThere have no match for you node!\n");
		tempPtr = 0;
	}

	return tempPtr;
}

void menuPolyKL(PolyListAdrKL myList) {

	PolyNodeAdrKL nodeAdr;
	int option = 0;

	do {

		printf("\n\t******************************"\
		"\n\t*       POLYNOMIAL Menu      *"\
		"\n\t* 1. Creating polynomail     *"\
		"\n\t* 2. Searching for node      *"\
		"\n\t* 3. geting poly order       *"\
		"\n\t* 4. Displaying poly         *"\
		"\n\t* 5. Quit\t\t     *"\
		"\n\t******************************\n");

		printf("\tSelect an option(1, 2, 3, 4, or 5): ");

		scanf("%d", &option);

		switch(option) {

		case 1:
			nodeAdr = createPolyNodeKL();
			insertPolyNodeKL(myList, nodeAdr);

			break;

		case 2:
			nodeAdr = searchPolyNodeKL(myList);
			displayFraction(nodeAdr);
			break;

		case 3:
			printPolyKL(myList);
			printf("\n\tHow many orders: %d\n",
				getPolyOrderKL(myList));
			break;

		case 4:
			printPolyKL(myList);
			break;

		case 5:
			printf("\n\tHave Fun......\n");
			break;

		default:
			//Wrong option
			printf("\n\tyou should not be in this class\n");
		}

	} while (option != 5);

	return;
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

	//tempPtr->next = nodeAdr;

	return;
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

void displayinfo() {

	printf("CIS 27 - Data Structures"\

	"\nLaney College"\

	"\nKaChiLau"\

	"\nSpring 2013"\

	"\n\nAssignment Information --"\

	"\n  Assignment Number:  Lab 07,"\
	
	"\n\t\t      Coding Assignment -- Exercise #1"\

	"\n  Written by:\t      KaChiLau"\

	"\n  Due Date:\t      April 2, 2013\n");

	return;
}

/*OUTPUT
CIS 27 - Data Structures
Laney College
KaChiLau
Spring 2013

Assignment Information --
  Assignment Number:  Lab 07,
                      Coding Assignment -- Exercise #1
  Written by:         KaChiLau
  Due Date:           April 2, 2013

        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 6

        you should not be in this class

        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 7

        you should not be in this class

        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 1

        Please Enter expoent: 2

        Enter an Fraction-

        Num: 1

        Non-negative Denom: 1

        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 1

        Please Enter expoent: 1

        Enter an Fraction-

        Num: 3

        Non-negative Denom: 4

        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 1

        Please Enter expoent: 0

        Enter an Fraction-

        Num: 5

        Non-negative Denom: 12

        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 4

        Expo: 2 Address: 00693FD8
        Num: 1
        denom: 1
        Next: 00694080


        Expo: 1 Address: 00694080
        Num: 3
        denom: 4
        Next: 00694198


        Expo: 0 Address: 00694198
        Num: 5
        denom: 12
        Next: 00000000


        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 3

        Expo: 2 Address: 00693FD8
        Num: 1
        denom: 1
        Next: 00694080


        Expo: 1 Address: 00694080
        Num: 3
        denom: 4
        Next: 00694198


        Expo: 0 Address: 00694198
        Num: 5
        denom: 12
        Next: 00000000


        How many orders: 3

        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 2
        Please Enter an exponet: 1

        Expo: 1 Address: 00694080
        Num: 3
        denom: 4
        Next: 00694198


        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 1

        Please Enter expoent: 2

        Enter an Fraction-

        Num: 2

        Non-negative Denom: 2

        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 4

        Expo: 2 Address: 00693FD8
        Num: 4
        denom: 2
        Next: 00694080


        Expo: 1 Address: 00694080
        Num: 3
        denom: 4
        Next: 00694198


        Expo: 0 Address: 00694198
        Num: 5
        denom: 12
        Next: 00000000


        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 5

        Have Fun......
*/