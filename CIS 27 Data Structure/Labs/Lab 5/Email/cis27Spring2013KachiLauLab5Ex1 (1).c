/**
*Program name: cis27Spring2013KachiLauLab5Ex1.c
*Dicussion:    lab5Ex1
*Written By:   KachiLau
*Date:         3/14/13
*/

#include <stdio.h>
#include <stdlib.h>

struct FractionKL { 
	int num;
	int denom;
};


struct FractionNodeKL {
	struct FractionKL data;
	struct FractionNodeKL* next;
};

typedef struct FractionKL* FractionAddrKL; 
typedef struct FractionNodeKL* FractionNodeAddrKL;
typedef struct FractionNodeKL* FractionListKL;

struct FractionKL* createFractionKL(void);
FractionNodeAddrKL createFractionNodeKL(FractionAddrKL);

//void printFractionListAtNodeNumber(FractionListKL, int);

void insertFractionFirst(FractionListKL*,
						FractionNodeAddrKL); 
void insertFractionAt(FractionListKL*,
						FractionNodeAddrKL, int); 
void insertFractionLast(struct FractionNodeKL**,
						struct FractionNodeKL*);

void removeFractionFirst(FractionListKL*); 
void removeFractionAt(FractionListKL*, int); 
void removeFractionLast(FractionListKL*, int);

void mainMenu(FractionListKL);
void displaymainMenu(void);
void insertingMenu(FractionListKL);
void removingMenu(FractionListKL);

void displayListKL(FractionListKL);
int getLengthKL(FractionListKL);
int isEmptyKL(FractionListKL);

void displayinfo(void);

int main() {

	FractionListKL myList = 0;

	displayinfo();

	mainMenu(myList);
	
	free(myList);

	return 0;
}

struct FractionKL* createFractionKL() { 
	struct FractionKL* frPtr;

	frPtr = (struct FractionKL*) 
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
//create fractionNode
FractionNodeAddrKL createFractionNodeKL(FractionAddrKL frAddr) {
	FractionNodeAddrKL frNodePtr;
	
	frNodePtr = (FractionNodeAddrKL)
		malloc(sizeof(struct FractionNodeKL)); 

	frNodePtr->data = *frAddr; 

	frNodePtr->next = 0; 

	return frNodePtr;
}

void insertFractionFirst(FractionListKL* listAdr,
						FractionNodeAddrKL nodeAdr) {

	nodeAdr->next = *listAdr;
	*listAdr = nodeAdr;

	return;
}

void insertFractionAt(FractionListKL* myList,
						FractionNodeAddrKL nodeAdr,
						int nodeNumber) {

	FractionNodeAddrKL prevNodeAdr = *myList;
	int position = nodeNumber;

	while(position > 1) {
		prevNodeAdr = prevNodeAdr->next;
		position--;
	}

	prevNodeAdr->next = nodeAdr;

	return;
}

void insertFractionLast(struct FractionNodeKL** myList,
						struct FractionNodeKL* nodeAddress) {
	
	struct FractionNodeKL* nodePtr;

	if (*myList == 0) {
		*myList = nodeAddress;
	} else {
		nodePtr = *myList;

		while(nodePtr->next) {
			nodePtr = nodePtr->next;
		}

		nodePtr->next = nodeAddress;
	}

	return;
}

void removeFractionFirst(FractionListKL* myList) {

	if(myList == 0) {
		printf("\tEmpty list...\n");
	} else {
		*myList = (*myList)->next;
	}

	return;
}

void removeFractionAt(FractionListKL* myList,
						int nodeNumber) {
	
	FractionNodeAddrKL prevNodeAdr;
	FractionNodeAddrKL removeNode;
	FractionNodeAddrKL tempPtr;
	int position;
	
	tempPtr = *myList;
	position = nodeNumber - 1;
	while(position > 1) {
		tempPtr = tempPtr->next;
		position--;
	}
	
	prevNodeAdr = tempPtr;
	removeNode = prevNodeAdr->next;

	tempPtr = removeNode->next;

	prevNodeAdr->next = tempPtr;
	
	return;
}

void removeFractionLast(FractionListKL* myList,
						int nodeNumber) {

	FractionNodeAddrKL prevNodeAdr;
	FractionNodeAddrKL removeNode;
	FractionNodeAddrKL tempPtr;

	int position;

	tempPtr = *myList;
	position = nodeNumber - 1;
	while(position > 1) {
		tempPtr = tempPtr->next;
		position--;
	}
	
	prevNodeAdr = tempPtr;
	removeNode = prevNodeAdr->next;
	prevNodeAdr->next = 0;

	return;
}

void mainMenu(FractionListKL myList) {

	int option;
	int ok;

	do {

		ok = isEmptyKL(myList);

		displaymainMenu();

		scanf("%d", &option);

		switch(option) {

		case 1:

			if(ok) {
				displayListKL(myList); 
			} else {
				printf("\nEMPTY LIST ...\n");
			}

			break;

		case 2:

			insertingMenu(myList);

			break;

		case 3:

			if(ok) {
				removingMenu(myList);
			} else {
				printf("\nThe List do not have any node"\
					"to be remove!\n");
			}

			break;

		case 4:

			printf("\n  You MUST have been comfortable"\
				" and enjoying the work\n\n");

			break;

		default:
			//Wrong option
			printf("\n  You should not be in this class!\n");
		}

	} while (option != 4);

	return;
}

void displaymainMenu() {
	
	printf("\n**********************************"\
		"\n* LINKED LIST MENU: FRACTION\t *"\
		"\n* 1. Displaying current list\t *"\
		"\n* 2. Inserting\t\t\t *"\
		"\n* 3. Removing\t\t\t *"\
		"\n* 4. Quit\t\t\t *"\
		"\n**********************************\n");

	printf("Select an option(1, 2, 3 or 4): ");
	return;
}

void insertingMenu(FractionListKL myList) {

	struct FractionKL* frPtr;
	struct FractionNodeKL* nodeAdr;
	int ok;
	int i;
	int option;

	do {
		i = getLengthKL(myList);
		ok = isEmptyKL(myList);

		printf("\n\t***********************"\
		"\n\t*   Inserting Menu    *"\
		"\n\t* 1. As first node    *"\
		"\n\t* 2. After #%d node    *"\
		"\n\t* 3. As last node     *"\
		"\n\t* 4. Displaying\t      *"\
		"\n\t* 5. Quit\t      *"\
		"\n\t***********************\n", i);

		printf("\tSelect an option(1, 2, 3, 4 or 5): ");

		scanf("%d", &option);

		switch(option) {

		case 1:
			//FirstNode
			frPtr = createFractionKL();
			nodeAdr = createFractionNodeKL(frPtr);
			insertFractionFirst(&myList, nodeAdr);
			break;

		case 2:

			if(ok) {
				frPtr = createFractionKL();
				nodeAdr = createFractionNodeKL(frPtr);
				insertFractionAt(&myList, nodeAdr, i);
				i++;
			} else {
				printf("\n\tYou don't have the first node yet!\n");
			}

			break;

		case 3:
			
			frPtr = createFractionKL();
			nodeAdr = createFractionNodeKL(frPtr);
			insertFractionLast(&myList, nodeAdr);
			
			break;

		case 4:

			if(ok) { 
				printf("\n\tFractionList: %p\n\n\tLength: %d\n",
					myList, getLengthKL(myList));

				displayListKL(myList);

			} else {
				printf("\n\tYou haven't create any Node Yet!\n");
			}
			
			break;

		case 5:

			mainMenu(myList);

			break;

		default:
			//Wrong option
			printf("\n\tWRONG OPTION!\n");
		}

	} while (option != 5);

	return;
}

void removingMenu(FractionListKL myList) {

	int option;
	int nodeNumber = 0;
	int ok;

	do {

		ok = isEmptyKL(myList);

		printf("\n\t***********************"\
		"\n\t*   Removing Menu     *"\
		"\n\t* 1. First node       *"\
		"\n\t* 2.  #?  node        *"\
		"\n\t* 3. Last node        *"\
		"\n\t* 4. Displaying\t      *"\
		"\n\t* 5. Quit\t      *"\
		"\n\t***********************\n");

		printf("\tSelect an option(1, 2, 3, 4 or 5): ");

		scanf("%d", &option);

		switch(option) {

		case 1:

			removeFractionFirst(&myList); 
			
			break;

		case 2:

			printf("\n\tPlease enter the node you want to remove: ");
			scanf("%d", &nodeNumber);
			removeFractionAt(&myList, nodeNumber); 
			//get error when mylist have one node only 
			break;

		case 3:

			nodeNumber = getLengthKL(myList);
			removeFractionLast(&myList, nodeNumber);
			//get error when mylist have one node only 
			break;

		case 4:

			if(ok) { 
				printf("\n\tFractionList: %p\n\n\tLength: %d\n",
					myList, getLengthKL(myList));

				displayListKL(myList);

			} else {
				printf("\n\tYou haven't create any Node Yet!\n");
			}

			break;

		case 5:

			mainMenu(myList);

			break;

		default:
			//Wrong option
			printf("\n\tWRONG OPTION!\n");
		}

	} while (option != 5);

	return;
}

int getLengthKL(FractionListKL myList) {

	FractionNodeAddrKL tempPtr = myList;
	int i;

	i = 0;
	while(tempPtr) {
		tempPtr = tempPtr->next;
		i++;
	}

	return i;
}

void displayListKL(FractionListKL myList) {

	FractionNodeAddrKL nodeAddr = myList;
	int number;

	number = 0;
	while(nodeAddr) {
		number++;

		printf("\n\tNode: %d\tAddress: %p"\
		"\n\tNum: %d\n\tdenom: %d\n\tNext: %p\n\n", 
		number, nodeAddr, nodeAddr->data.num, nodeAddr->data.denom,
		nodeAddr->next);

		nodeAddr = nodeAddr->next;
	} 

	return;
}

int isEmptyKL(FractionListKL myList) {
	int i;

	if(myList) {
		i = 1;
	} else {
		i = 0;
	}

	return i;
}

void displayinfo() {

	printf("CIS 27 - Data Structures"\

	"\nLaney College"\

	"\nKaChiLau"\

	"\nSpring 2013"\

	"\n\nAssignment Information --"\

	"\n  Assignment Number:  Lab 05,"\
	
	"\n\t\t      Coding Assignment -- Exercise #1"\

	"\n  Written by:\t      KaChiLau"\

	"\n  Due Date:\t      March 14, 2013\n");

	return;
}

/*COMMENT
I don't know why,
after I did the inserts & removes node
and when I try to quit from the mainmenu,
I need to press 3 times to be able to quit
(look at the bottom part of my output)

but when I just quit after complie,
it will not happen

*/

/*OUTPUT
CIS 27 - Data Structures
Laney College
KaChiLau
Spring 2013

Assignment Information --
  Assignment Number:  Lab 05,
                      Coding Assignment -- Exercise #1
  Written by:         KaChiLau
  Due Date:           March 14, 2013

**********************************
* LINKED LIST MENU: FRACTION     *
* 1. Displaying current list     *
* 2. Inserting                   *
* 3. Removing                    *
* 4. Quit                        *
**********************************
Select an option(1, 2, 3 or 4): 5

  You should not be in this class!

**********************************
* LINKED LIST MENU: FRACTION     *
* 1. Displaying current list     *
* 2. Inserting                   *
* 3. Removing                    *
* 4. Quit                        *
**********************************
Select an option(1, 2, 3 or 4): 1

EMPTY LIST ...

**********************************
* LINKED LIST MENU: FRACTION     *
* 1. Displaying current list     *
* 2. Inserting                   *
* 3. Removing                    *
* 4. Quit                        *
**********************************
Select an option(1, 2, 3 or 4): 2

        ***********************
        *   Inserting Menu    *
        * 1. As first node    *
        * 2. After #0 node    *
        * 3. As last node     *
        * 4. Displaying       *
        * 5. Quit             *
        ***********************
        Select an option(1, 2, 3, 4 or 5): 1

        Enter an Fraction-

        Num: 3

        Non-negative Denom: 4

        ***********************
        *   Inserting Menu    *
        * 1. As first node    *
        * 2. After #1 node    *
        * 3. As last node     *
        * 4. Displaying       *
        * 5. Quit             *
        ***********************
        Select an option(1, 2, 3, 4 or 5): 2

        Enter an Fraction-

        Num: 5

        Non-negative Denom: 12

        ***********************
        *   Inserting Menu    *
        * 1. As first node    *
        * 2. After #2 node    *
        * 3. As last node     *
        * 4. Displaying       *
        * 5. Quit             *
        ***********************
        Select an option(1, 2, 3, 4 or 5): 3

        Enter an Fraction-

        Num: -3

        Non-negative Denom: 7

        ***********************
        *   Inserting Menu    *
        * 1. As first node    *
        * 2. After #3 node    *
        * 3. As last node     *
        * 4. Displaying       *
        * 5. Quit             *
        ***********************
        Select an option(1, 2, 3, 4 or 5): 1

        Enter an Fraction-

        Num: 5

        Non-negative Denom: 101

        ***********************
        *   Inserting Menu    *
        * 1. As first node    *
        * 2. After #4 node    *
        * 3. As last node     *
        * 4. Displaying       *
        * 5. Quit             *
        ***********************
        Select an option(1, 2, 3, 4 or 5): 3

        Enter an Fraction-

        Num: 2

        Non-negative Denom: 11

        ***********************
        *   Inserting Menu    *
        * 1. As first node    *
        * 2. After #5 node    *
        * 3. As last node     *
        * 4. Displaying       *
        * 5. Quit             *
        ***********************
        Select an option(1, 2, 3, 4 or 5): 4

        FractionList: 00884160

        Length: 5

        Node: 1 Address: 00884160
        Num: 5
        denom: 101
        Next: 00884010


        Node: 2 Address: 00884010
        Num: 3
        denom: 4
        Next: 00884080


        Node: 3 Address: 00884080
        Num: 5
        denom: 12
        Next: 008840F0


        Node: 4 Address: 008840F0
        Num: -3
        denom: 7
        Next: 008841D0


        Node: 5 Address: 008841D0
        Num: 2
        denom: 11
        Next: 00000000


        ***********************
        *   Inserting Menu    *
        * 1. As first node    *
        * 2. After #5 node    *
        * 3. As last node     *
        * 4. Displaying       *
        * 5. Quit             *
        ***********************
        Select an option(1, 2, 3, 4 or 5): 5

**********************************
* LINKED LIST MENU: FRACTION     *
* 1. Displaying current list     *
* 2. Inserting                   *
* 3. Removing                    *
* 4. Quit                        *
**********************************
Select an option(1, 2, 3 or 4): 3

        ***********************
        *   Removing Menu     *
        * 1. First node       *
        * 2.  #?  node        *
        * 3. Last node        *
        * 4. Displaying       *
        * 5. Quit             *
        ***********************
        Select an option(1, 2, 3, 4 or 5): 1

        ***********************
        *   Removing Menu     *
        * 1. First node       *
        * 2.  #?  node        *
        * 3. Last node        *
        * 4. Displaying       *
        * 5. Quit             *
        ***********************
        Select an option(1, 2, 3, 4 or 5): 2

        Please enter the node you want to remove: 4

        ***********************
        *   Removing Menu     *
        * 1. First node       *
        * 2.  #?  node        *
        * 3. Last node        *
        * 4. Displaying       *
        * 5. Quit             *
        ***********************
        Select an option(1, 2, 3, 4 or 5): 4

        FractionList: 00884160

        Length: 3

        Node: 1 Address: 00884160
        Num: 3
        denom: 4
        Next: 00884080


        Node: 2 Address: 00884080
        Num: 5
        denom: 12
        Next: 008840F0


        Node: 3 Address: 008840F0
        Num: -3
        denom: 7
        Next: 00000000


        ***********************
        *   Removing Menu     *
        * 1. First node       *
        * 2.  #?  node        *
        * 3. Last node        *
        * 4. Displaying       *
        * 5. Quit             *
        ***********************
        Select an option(1, 2, 3, 4 or 5): 5

**********************************
* LINKED LIST MENU: FRACTION     *
* 1. Displaying current list     *
* 2. Inserting                   *
* 3. Removing                    *
* 4. Quit                        *
**********************************
Select an option(1, 2, 3 or 4): 4

  You MUST have been comfortableand enjoying the work


**********************************
* LINKED LIST MENU: FRACTION     *
* 1. Displaying current list     *
* 2. Inserting                   *
* 3. Removing                    *
* 4. Quit                        *
**********************************
Select an option(1, 2, 3 or 4): 4

  You MUST have been comfortableand enjoying the work


**********************************
* LINKED LIST MENU: FRACTION     *
* 1. Displaying current list     *
* 2. Inserting                   *
* 3. Removing                    *
* 4. Quit                        *
**********************************
Select an option(1, 2, 3 or 4): 4

  You MUST have been comfortableand enjoying the work

Press any key to continue . . .

*/