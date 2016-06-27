/**
*Program name: cis27Spring2013KachiLauLab6Ex1.c
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

FractionAddrKL createFractionKL(void);
FractionNodeAddrKL createFractionNodeKL(FractionAddrKL);

//void printFractionListAtNodeNumber(FractionListKL, int);

void insertFractionFirst(FractionListKL*,
						FractionNodeAddrKL); 
void insertFractionAfter(FractionListKL*,
						FractionNodeAddrKL, int); 
void insertFractionLast(struct FractionNodeKL**,
						struct FractionNodeKL*);

int swapFractionList1KL(FractionListKL*, int, int m);
int swapFractionList2KL(FractionListKL*, int, int m);

void mainMenu(FractionListKL);
void displaymainMenu(void);
void insertingMenu(FractionListKL);
void swappingMenu(FractionListKL);

void displayListKL(FractionListKL);
int getLengthKL(FractionListKL);
int isEmptyKL(FractionListKL);

void displayinfo(void);

int main() {
	struct FractionKL* frPtr;
	struct FractionNodeKL* nodeAdr;
	FractionListKL myList = 0;
	int n;
	int m;
	//FractionListKL myList = 0;

	displayinfo();
	
	mainMenu(myList);
	
	free(myList);

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

void insertFractionAfter(FractionListKL* myList,
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

void insertFractionAt(FractionListKL* myList,
						FractionNodeAddrKL nodeAdr,
						int nodeNumber) {

	FractionNodeAddrKL prevNodeAdr = *myList;
	int position = nodeNumber;

	while(position > 1) {
		prevNodeAdr = prevNodeAdr->next;
		position--;
	}

	nodeAdr->next = prevNodeAdr->next;
	prevNodeAdr->next = nodeAdr;

	return;
}


void insertFractionLast(FractionListKL* myList,
						FractionNodeAddrKL insertnode) {

	FractionNodeAddrKL nodePtr;

	if (*myList == 0) {
		*myList = insertnode; //if have none node, it will insert current node in the list
	} else {
		nodePtr = *myList;

		while(nodePtr->next) { //keep looping to the last node
			nodePtr = nodePtr->next;
		}

		nodePtr->next = insertnode; //last node address is the inset node
	}

	return;
}

int swapFractionList1KL(FractionListKL* myList, int n, int m) {

	FractionNodeAddrKL nPtr;
	FractionNodeAddrKL mPtr;

	FractionNodeAddrKL nPrev;
	FractionNodeAddrKL mPrev;

	FractionNodeAddrKL nAfter;
	FractionNodeAddrKL mAfter;

	FractionNodeAddrKL tempPtr;

	int position;
	int check = n - m;
	int temp = 0;

	if(check < 0) {
		check = -check;
	}

	if(n > m) {
		temp = n;
		n = m;
		m = temp;
	}

	//n
	tempPtr = *myList;
	position = n - 1;
	while(position > 1) {
		tempPtr = tempPtr->next;
		position--;
	} 
	
	if(n == 1) {
		nPrev = *myList;
		nPtr = *myList;
	} else {
		nPrev = tempPtr;
		nPtr = nPrev->next;
	}
	
	nAfter = nPtr->next;
	

	//m
	tempPtr = *myList;
	position = m - 1;
	while(position > 1) {
		tempPtr = tempPtr->next;
		position--;
	} 
	
	if(m == 1) {
		mPrev = *myList;
		nPtr = *myList;
	} else {
		mPrev = tempPtr;
		mPtr = mPrev->next;
	}
	mAfter = mPtr->next;

	if(check != 1) {
		if(n != 1) {
			nPtr->next = mAfter;
			mPtr->next = nAfter;
			nPrev->next = mPtr;
			mPrev->next = nPtr;
		} else {
			nPtr->next = mAfter;
			mPtr->next = nAfter;
			*myList = mPtr;
			mPrev->next = nPtr;
		}
	} else {
		if(n != 1) {
			nPtr->next = mAfter;
			mPtr->next = nPtr;
			nPrev->next = mPtr;
		} else {
			nPtr->next = mAfter;
			mPtr->next = nPtr;
			*myList = mPtr;
		}
	}

	return 1;
}

int swapFractionList2KL(FractionListKL* myList, int n, int m) {
	
	FractionNodeAddrKL* nAfter = 0;
	FractionNodeAddrKL* mAfter = 0;

	FractionNodeAddrKL* nPtr = 0;
	FractionNodeAddrKL* mPtr = 0;

	FractionNodeAddrKL* nPrev = 0;
	FractionNodeAddrKL* mPrev = 0;

	FractionNodeAddrKL tempPtr;
	FractionNodeAddrKL tempNode = 0;

	int position;
	int check = n - m;
	int temp = 0;
	
	if(check < 0) {
		check = -check;
	}
	
	if(n > m) {
		temp = n;
		n = m;
		m = temp;
	}

	//n
	tempPtr = *myList;
	position = n - 1;
	while(position > 1) {
		tempPtr =  tempPtr->next;
		position--;
	} 

	if(n == 1) {
		nPrev = *myList;
		nPtr = myList;
		nAfter = &tempPtr->next;
	} else {
		nPrev = tempPtr;
		nPtr = &tempPtr->next;
		nAfter = &tempPtr->next->next;
	}

	//m
	tempPtr = *myList;
	position = m - 1;
	while(position > 1) {
		tempPtr =  tempPtr->next;
		position--;
	} 

	if(m == 1) {
		mPrev = *myList;
		mPtr = myList;
		mAfter = &tempPtr->next;
	} else {
		mPrev = tempPtr;
		mPtr = &tempPtr->next;
		mAfter = &tempPtr->next->next;
	}

	if(check != 1) {
		tempNode = *nAfter;	
		*nAfter = *mAfter;
		*mAfter = tempNode;
		tempNode = *nPtr;
		*nPtr = *mPtr;
		*mPtr = tempNode;
	} else {
		tempNode = *nAfter;
		*nAfter = *mAfter;
		*mAfter = *nPtr;
		*nPtr = tempNode;
	}
			
	return 1;
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
				printf("\n\tEMPTY LIST ...\n");
			}

			break;

		case 2:

			insertingMenu(myList);

			break;

		case 3:

			swappingMenu(myList);

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
		"\n* 3. swapping\t\t\t *"\
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
	int x = 0;
	int option;

	do {
		i = getLengthKL(myList);
		ok = isEmptyKL(myList);

		printf("\n\t***********************"\
		"\n\t*   Inserting Menu    *"\
		"\n\t* 1. As first node    *"\
		"\n\t* 2. After #%d node    *"\
		"\n\t* 3. At #? node       *"\
		"\n\t* 4. As last node     *"\
		"\n\t* 5. Displaying\t      *"\
		"\n\t* 6. Quit\t      *"\
		"\n\t***********************\n", i);

		printf("\tSelect an option(1, 2, 3, 4, 5 or 6): ");

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
				insertFractionAfter(&myList, nodeAdr, i);
				i++;
			} else {
				printf("\n\tYou don't have the first node yet!\n");
			}

			break;

		case 3:

			if(ok) {
				printf("\n\tInsert position# : ");
				scanf("%d", &x);

				while(x < 0) {
					printf("\n\tInsert position# : ");
					scanf("%d", &x);
				}

				if(i < x) {
					printf("\n\tYou entered invalid position!\n");
				} else {
				frPtr = createFractionKL();
				nodeAdr = createFractionNodeKL(frPtr);
				insertFractionAt(&myList, nodeAdr, x);
				}

			} else {
				printf("\n\tYou don't have the first node yet!\n");
			}
			
			break;

		case 4:
			
			frPtr = createFractionKL();
			nodeAdr = createFractionNodeKL(frPtr);
			insertFractionLast(&myList, nodeAdr);
			
			break;

		case 5:

			if(ok) { 
				printf("\n\tFractionList: %p\n\n\tLength: %d\n",
					myList, getLengthKL(myList));

				displayListKL(myList);

			} else {
				printf("\n\tYou haven't create any Node Yet!\n");
			}
			
			break;

		case 6:

			mainMenu(myList);

			break;

		default:
			//Wrong option
			printf("\n\tWRONG OPTION!\n");
		}

	} while (option != 6);

	return;
}

void swappingMenu(FractionListKL myList) {

	int option;
	int nodeNumber = 0;
	int ok;
	int n, m;
	int i;
	int counter = 0;

	do {
		i = getLengthKL(myList);
		ok = isEmptyKL(myList);

		printf("\n\t***********************"\
		"\n\t*   Swapping Menu     *"\
		"\n\t* 1. Version #1       *"\
		"\n\t* 2. Version #2       *"\
		"\n\t* 3. Displaying       *"\
		"\n\t* 4. Quit\t      *"\
		"\n\t***********************\n");

		printf("\tSelect an option(1, 2 or 3): ");

		scanf("%d", &option);

		switch(option) {

		case 1:
			if(ok) {
				printf("\n\tEnter n: ");
				scanf("%d", &n);
				printf("\n\tEnter m: ");
				scanf("%d", &m);

				if((i < m) || (i < n)) {
					printf("\n\tYou entered invalid position!\n");
				} else {
					while (n == m) {
					printf("\n\tYou entered same position\n\tPlease re-Enter\n");
					printf("\n\tEnter n: ");
					scanf("%d", &n);
					printf("\n\tEnter m: ");
					scanf("%d", &m);
					}
					counter += swapFractionList1KL(&myList, n, m);
				}
			} else {
				printf("\n\tThe List is empty!\n");
			}

			break;

		case 2:
			if(ok) {
				printf("\n\tEnter n: "); 
				scanf("%d", &n);
				printf("\n\tEnter m: ");
				scanf("%d", &m);
				if((i < m) || (i < n)) {
					printf("\n\tYou entered invalid position!\n");
				} else {
					while (n == m) {
					printf("\n\tYou entered same position\n\tPlease re-Enter\n");
					printf("\n\tEnter n: ");
					scanf("%d", &n);
					printf("\n\tEnter m: ");
					scanf("%d", &m);
					}

					counter += swapFractionList2KL(&myList, n, m);
				}
			} else {
				printf("\n\tThe List is empty!\n");
			}

			break;

		case 3:

			displayListKL(myList);

			break;

		case 4:

			printf("\n\tTotal Swapped: %d times\n", counter);
			mainMenu(myList);

			break;

		default:
			//Wrong option
			printf("\n\tWRONG OPTION!\n");
		}

	} while (option != 4);

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

	"\n  Assignment Number:  Lab 06,"\
	
	"\n\t\t      Coding Assignment -- Exercise #1"\

	"\n  Written by:\t      KaChiLau"\

	"\n  Due Date:\t      March 21, 2013\n");

	return;
}

/*OUTPUT
Assignment Information --
  Assignment Number:  Lab 06,
                      Coding Assignment -- Exercise #1
  Written by:         KaChiLau
  Due Date:           March 21, 2013

**********************************
* LINKED LIST MENU: FRACTION     *
* 1. Displaying current list     *
* 2. Inserting                   *
* 3. swapping                    *
* 4. Quit                        *
**********************************
Select an option(1, 2, 3 or 4): 5

  You should not be in this class!

**********************************
* LINKED LIST MENU: FRACTION     *
* 1. Displaying current list     *
* 2. Inserting                   *
* 3. swapping                    *
* 4. Quit                        *
**********************************
Select an option(1, 2, 3 or 4): 1

        EMPTY LIST ...

**********************************
* LINKED LIST MENU: FRACTION     *
* 1. Displaying current list     *
* 2. Inserting                   *
* 3. swapping                    *
* 4. Quit                        *
**********************************
Select an option(1, 2, 3 or 4): 2

        ***********************
        *   Inserting Menu    *
        * 1. As first node    *
        * 2. After #0 node    *
        * 3. At #? node       *
        * 4. As last node     *
        * 5. Displaying       *
        * 6. Quit             *
        ***********************
        Select an option(1, 2, 3, 4, 5 or 6): 1

        Enter an Fraction-

        Num: 3

        Non-negative Denom: 4

        ***********************
        *   Inserting Menu    *
        * 1. As first node    *
        * 2. After #1 node    *
        * 3. At #? node       *
        * 4. As last node     *
        * 5. Displaying       *
        * 6. Quit             *
        ***********************
        Select an option(1, 2, 3, 4, 5 or 6): 2

        Enter an Fraction-

        Num: 5

        Non-negative Denom: 12

        ***********************
        *   Inserting Menu    *
        * 1. As first node    *
        * 2. After #2 node    *
        * 3. At #? node       *
        * 4. As last node     *
        * 5. Displaying       *
        * 6. Quit             *
        ***********************
        Select an option(1, 2, 3, 4, 5 or 6): 3

        Insert position# : 2

        Enter an Fraction-

        Num: -3

        Non-negative Denom: 7

        ***********************
        *   Inserting Menu    *
        * 1. As first node    *
        * 2. After #3 node    *
        * 3. At #? node       *
        * 4. As last node     *
        * 5. Displaying       *
        * 6. Quit             *
        ***********************
        Select an option(1, 2, 3, 4, 5 or 6): 3

        Insert position# : 4

        You entered invalid position!

        ***********************
        *   Inserting Menu    *
        * 1. As first node    *
        * 2. After #3 node    *
        * 3. At #? node       *
        * 4. As last node     *
        * 5. Displaying       *
        * 6. Quit             *
        ***********************
        Select an option(1, 2, 3, 4, 5 or 6): 9

        WRONG OPTION!

        ***********************
        *   Inserting Menu    *
        * 1. As first node    *
        * 2. After #3 node    *
        * 3. At #? node       *
        * 4. As last node     *
        * 5. Displaying       *
        * 6. Quit             *
        ***********************
        Select an option(1, 2, 3, 4, 5 or 6): 4

        Enter an Fraction-

        Num: 4

        Non-negative Denom: 9

        ***********************
        *   Inserting Menu    *
        * 1. As first node    *
        * 2. After #4 node    *
        * 3. At #? node       *
        * 4. As last node     *
        * 5. Displaying       *
        * 6. Quit             *
        ***********************
        Select an option(1, 2, 3, 4, 5 or 6): 5

        FractionList: 00334010

        Length: 4

        Node: 1 Address: 00334010
        Num: 3
        denom: 4
        Next: 00334080


        Node: 2 Address: 00334080
        Num: 5
        denom: 12
        Next: 003340F0


        Node: 3 Address: 003340F0
        Num: -3
        denom: 7
        Next: 00334160


        Node: 4 Address: 00334160
        Num: 4
        denom: 9
        Next: 00000000


        ***********************
        *   Inserting Menu    *
        * 1. As first node    *
        * 2. After #4 node    *
        * 3. At #? node       *
        * 4. As last node     *
        * 5. Displaying       *
        * 6. Quit             *
        ***********************
        Select an option(1, 2, 3, 4, 5 or 6): 6

**********************************
* LINKED LIST MENU: FRACTION     *
* 1. Displaying current list     *
* 2. Inserting                   *
* 3. swapping                    *
* 4. Quit                        *
**********************************
Select an option(1, 2, 3 or 4): 3

        ***********************
        *   Swapping Menu     *
        * 1. Version #1       *
        * 2. Version #2       *
        * 3. Displaying       *
        * 4. Quit             *
        ***********************
        Select an option(1, 2 or 3): 1

        Enter n: 1

        Enter m: 2

        ***********************
        *   Swapping Menu     *
        * 1. Version #1       *
        * 2. Version #2       *
        * 3. Displaying       *
        * 4. Quit             *
        ***********************
        Select an option(1, 2 or 3): 2

        Enter n: 3

        Enter m: 4

        ***********************
        *   Swapping Menu     *
        * 1. Version #1       *
        * 2. Version #2       *
        * 3. Displaying       *
        * 4. Quit             *
        ***********************
        Select an option(1, 2 or 3): 4

        Total Swapped: 2 times

**********************************
* LINKED LIST MENU: FRACTION     *
* 1. Displaying current list     *
* 2. Inserting                   *
* 3. swapping                    *
* 4. Quit                        *
**********************************
Select an option(1, 2, 3 or 4): 1

        Node: 1 Address: 00334080
        Num: 5
        denom: 12
        Next: 00334010


        Node: 2 Address: 00334010
        Num: 3
        denom: 4
        Next: 00334160


        Node: 3 Address: 00334160
        Num: 4
        denom: 9
        Next: 003340F0


        Node: 4 Address: 003340F0
        Num: -3
        denom: 7
        Next: 00000000


**********************************
* LINKED LIST MENU: FRACTION     *
* 1. Displaying current list     *
* 2. Inserting                   *
* 3. swapping                    *
* 4. Quit                        *
**********************************
Select an option(1, 2, 3 or 4): 4

  You MUST have been comfortable and enjoying the work


**********************************
* LINKED LIST MENU: FRACTION     *
* 1. Displaying current list     *
* 2. Inserting                   *
* 3. swapping                    *
* 4. Quit                        *
**********************************
Select an option(1, 2, 3 or 4): 4

  You MUST have been comfortable and enjoying the work


**********************************
* LINKED LIST MENU: FRACTION     *
* 1. Displaying current list     *
* 2. Inserting                   *
* 3. swapping                    *
* 4. Quit                        *
**********************************
Select an option(1, 2, 3 or 4): 4

  You MUST have been comfortable and enjoying the work

Press any key to continue . . .
*/