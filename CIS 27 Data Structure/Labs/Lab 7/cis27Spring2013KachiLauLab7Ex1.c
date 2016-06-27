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
/*
typedef PolyTermKL* PolyTermAdrKL;

struct PolyNodeKL {
	PolyTermAdrKL* dataPtr;
	struct PolyNodeKL* next;
};
*/

struct PolyNodeKL {
	struct PolyTermKL* dataPtr;
	struct PolyNodeKL* next;
};

typedef struct FractionKL* FractionAddrKL;
typedef struct PolyNodeKL* PolyNodeAdrKL;
typedef struct PolyNodeKL* PolyListKL;

typedef PolyListKL* PolyListAdrKL;

PolyNodeAdrKL createPolyNodeKL(void);
struct PolyTermKL* createPolyTermKL(void);

//int insertPolyNodeKL(PolyListAdrKL*, PolyNodeAdrKL);
int insertPolyNodeKL(PolyListKL*, PolyNodeAdrKL);//done
PolyNodeAdrKL searchPolyNodeKL(PolyListAdrKL, struct PolyTermKL);//done
int getPolyOrderKL(PolyListAdrKL);//done
int printPolyKL(PolyListAdrKL); //done
void menuPolyKL(PolyListAdrKL);
void displayFraction(struct PolyNodeKL*); //done
PolyNodeAdrKL polyAddition(PolyNodeAdrKL, PolyNodeAdrKL);//done
void displayinfo(void);

int main() {
	PolyListKL myList = 0;

	displayinfo();
	menuPolyKL(&myList);

	return 0;
}

PolyNodeAdrKL createPolyNodeKL() {

	FractionAddrKL frPtr;
	PolyNodeAdrKL polyNodePtr;
	int exponet = 0;

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

	printf("\n\tPlease Enter expoent: ");
	scanf("%d", &exponet);

	polyNodePtr = (PolyNodeAdrKL)malloc(sizeof(struct PolyNodeKL)); 
	polyNodePtr->dataPtr = (struct PolyTermKL*)malloc( sizeof(struct PolyTermKL )) ;
	
	polyNodePtr->dataPtr->coeff = *frPtr;
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

int insertPolyNodeKL(PolyListKL* myList, PolyNodeAdrKL nodeAdr) { //nodeAdr = currentnode
	
	PolyNodeAdrKL tempPtr = 0;
	PolyNodeAdrKL sum = 0;
	int count = 0;

	sum = (PolyNodeAdrKL)malloc(sizeof(struct PolyNodeKL)); 
	sum->dataPtr = (struct PolyTermKL*)malloc( sizeof(struct PolyTermKL )) ;

	tempPtr =*myList;
	if(*myList == 0) {
		nodeAdr->next = *myList;
		*myList = nodeAdr;
	} else if(*myList) {
		if(nodeAdr->dataPtr->expo <= tempPtr->dataPtr->expo) {
			while(tempPtr){
				if(nodeAdr->dataPtr->expo == tempPtr->dataPtr->expo) {
				sum = polyAddition(nodeAdr, tempPtr);
				tempPtr->dataPtr = sum->dataPtr;
				count = 1;
				}
				tempPtr = tempPtr->next;
			}
			if(count == 0) {
				tempPtr =*myList;
				while(tempPtr->next) {
				tempPtr = tempPtr->next;
				}
				tempPtr->next = nodeAdr;
			}
		} else if (nodeAdr->dataPtr->expo > tempPtr->dataPtr->expo) {
			nodeAdr->next = *myList;
			*myList = nodeAdr;
		}
	}
	return 1;
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

PolyNodeAdrKL searchPolyNodeKL(PolyListAdrKL myList, struct PolyTermKL polyTerm) {

	PolyNodeAdrKL nodeAdr = *myList;
	PolyNodeAdrKL tempPtr = 0;
	int count = 0;

	if(*myList == 0) {
		printf("\n\tEMPTY LIST...\n");
	} else if(*myList) {
		while(nodeAdr) {
			if((nodeAdr->dataPtr->expo == polyTerm.expo) 
				&& (nodeAdr->dataPtr->coeff.num == polyTerm.coeff.num)
				&& (nodeAdr->dataPtr->coeff.denom == polyTerm.coeff.denom)) {
				tempPtr = nodeAdr;
				count = 1;
			}
			nodeAdr = nodeAdr->next;
		}

		if(count == 0) {
		printf("\n\tThere have no match for you node!\n");
		tempPtr = 0;
		}
	}

	return tempPtr;
}

PolyNodeAdrKL polyAddition(PolyNodeAdrKL nodeAdr, PolyNodeAdrKL tempAdr) {
	PolyNodeAdrKL sum = 0;
	int node = nodeAdr->dataPtr->expo;
	int temp = tempAdr->dataPtr->expo;

	sum = (PolyNodeAdrKL)malloc(sizeof(struct PolyNodeKL)); 
	sum->dataPtr = (struct PolyTermKL*)malloc( sizeof(struct PolyTermKL )) ;

	sum->dataPtr->coeff.num = ((nodeAdr->dataPtr->coeff.num) 
		* (tempAdr->dataPtr->coeff.denom)) + ((tempAdr->dataPtr->coeff.denom
		* nodeAdr->dataPtr->coeff.denom));

	sum->dataPtr->coeff.denom = ((nodeAdr->dataPtr->coeff.denom) 
		* (tempAdr->dataPtr->coeff.denom));
	
	if(node == temp) {
		sum->dataPtr->expo = node;
	}

	return sum;
}

struct PolyTermKL* createPolyTermKL() {
	struct PolyTermKL* polyTerm;
	FractionAddrKL frPtr;
	int exponet = 0;

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

	printf("\n\tPlease Enter expoent: ");
	scanf("%d", &exponet);

	polyTerm = (struct PolyTermKL*)malloc(sizeof(struct PolyTermKL));

	polyTerm->coeff = *frPtr;
	polyTerm->expo = exponet;

	return polyTerm;
}

void menuPolyKL(PolyListAdrKL myList) {

	PolyNodeAdrKL nodeAdr;
	struct PolyTermKL* termAdr;
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
				termAdr = createPolyTermKL();
				nodeAdr = searchPolyNodeKL(myList, *termAdr);
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
/*COMMENT
I cannot use the PolyTermAdrKL in the Node,
so I changed it to struct polyTerm* dataPointer
*/

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
        Select an option(1, 2, 3, 4, or 5): 4

        No polynomial to be displayed!

        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 1

        Enter an Fraction-

        Num: 1

        Non-negative Denom: 1

        Please Enter expoent: 2

        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 1

        Enter an Fraction-

        Num: 3

        Non-negative Denom: 4

        Please Enter expoent: 1

        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 1

        Enter an Fraction-

        Num: 5

        Non-negative Denom: 12

        Please Enter expoent: 0

        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 4

        Expo: 2 Address: 007D4010
        Num: 1
        denom: 1
        Next: 007D4128


        Expo: 1 Address: 007D4128
        Num: 3
        denom: 4
        Next: 007D4240


        Expo: 0 Address: 007D4240
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

        Expo: 2 Address: 007D4010
        Num: 1
        denom: 1
        Next: 007D4128


        Expo: 1 Address: 007D4128
        Num: 3
        denom: 4
        Next: 007D4240


        Expo: 0 Address: 007D4240
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

        Enter an Fraction-

        Num: 3

        Non-negative Denom: 4

        Please Enter expoent: 1

        Expo: 1 Address: 007D4128
        Num: 3
        denom: 4
        Next: 007D4240


        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 1

        Enter an Fraction-

        Num: 2

        Non-negative Denom: 2

        Please Enter expoent: 2

        ******************************
        *       POLYNOMIAL Menu      *
        * 1. Creating polynomail     *
        * 2. Searching for node      *
        * 3. geting poly order       *
        * 4. Displaying poly         *
        * 5. Quit                    *
        ******************************
        Select an option(1, 2, 3, 4, or 5): 4

        Expo: 2 Address: 007D4010
        Num: 4
        denom: 2
        Next: 007D4128


        Expo: 1 Address: 007D4128
        Num: 3
        denom: 4
        Next: 007D4240


        Expo: 0 Address: 007D4240
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