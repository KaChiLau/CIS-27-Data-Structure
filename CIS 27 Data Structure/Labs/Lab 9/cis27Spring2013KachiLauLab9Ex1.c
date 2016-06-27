/**
*Program name: cis27Spring2013KachiLauLab9Ex1.c
*Dicussion:    lab9Ex1
*Written By:   KachiLau
*/

#include <stdio.h>
#include <stdlib.h>

struct FractionKL { 
	int num;
	int denom;
};

typedef struct FractionKL* FractionAddrKL; 

typedef struct TreeInt* TreePtr;
typedef struct TreeInt* NodePtr;

struct TreeInt {
	struct FractionKL iValue;
	struct TreeInt* left;
	struct TreeInt* right;
};

typedef struct stackhead* stack; 

struct stackhead {
	TreePtr top;
	stack next;
};

FractionAddrKL createFractionKL(void);
NodePtr createNodeKL(void);
//NodePtr createNodeKL(int, int);
//FractionAddrKL createFractionKL(int, int);

void displayTree(TreePtr);
void displayNode(NodePtr);

NodePtr getSmallestFractionBSTYKL(TreePtr*);

void insertFractionBSTKL(TreePtr*, NodePtr);

NodePtr searchFractionBSTKL(TreePtr*, FractionAddrKL);

void push(TreePtr, stack*);
void pop(stack*);
int isEmpty(stack);
void empty(stack); 

void displayFractionInorderBSTKL(TreePtr);
void displayFractionpreorderBSTKL(TreePtr);
void displayFractionpostorderBSTKL(TreePtr);

void removeFractionBSTKL(FractionAddrKL, NodePtr);

void displaymenu(void);
void displayorder(void);
void displayinfo(void);

int main() {
	displayinfo();
	displaymenu();
	return 0;
}

//FractionAddrKL createFractionKL(int x, int y) { 
FractionAddrKL createFractionKL() { 
	FractionAddrKL frPtr;

	frPtr = (FractionAddrKL) 
		malloc(sizeof(struct FractionKL));
	
	printf("\tEnter an Fraction- \n\n\tNum: ");
	scanf("%d", &frPtr->num);
	printf("\tNon-negative Denom: ");
	scanf("%d", &frPtr->denom);
	
	//frPtr->num = x;
	//frPtr->denom = y;

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
//NodePtr createNodeKL(int x, int y) {
NodePtr createNodeKL() {
	NodePtr node;
	int exponet = 0;

	node = (NodePtr)malloc(sizeof(struct TreeInt)); 

	node->iValue = *createFractionKL();
	//node->iValue = *createFractionKL(x, y);
	node->left = 0;
	node->right = 0;
	
	return node;
}

void displayNode(NodePtr node) {

	if(node) {
		printf("\n\tAddress: %p"\
				"\n\tFraction %d/%d\n\tleft: %p\n\tright: %p\n\n", 
				node, node->iValue.num, node->iValue.denom,
				node->left, node->right);
	} else {
		printf("\tNo fraction to be display\n");
	}

	return;
}



void insertFractionBSTKL(TreePtr* mytree, NodePtr node) {
	NodePtr newNode, temp;
	int nodeR, tempR = 0;
	int stop = 1;
	/*
	newNode = (NodePtr) malloc(sizeof(struct TreeInt));
	newNode->iValue = node->iValue;
	newNode->left = newNode->right = 0;
	*/
	if(*mytree) {
		temp = *mytree;
		while((temp) && (stop)) {
			nodeR = node->iValue.num / node->iValue.denom;
			tempR = temp->iValue.num / temp->iValue.denom;

			if(nodeR < tempR) {

				if(temp->left) {
					temp = temp->left;
				} else {
					temp->left = node;
					stop = 0;
				}

			} else if(nodeR > tempR) {

				if(temp->right) {
					temp = temp->right;
				} else {
					temp->right = node;
					stop = 0;
				}

			} else {
				printf("\nDuplicate value found!\n");
				stop = 0;
			}
		}
	} else {
		*mytree = node;
	}

	return;
}

NodePtr getSmallestFractionBSTYKL(TreePtr* mytree) {
	NodePtr node, temp;
	temp = *mytree;
	while(temp->left) {
		temp = temp->left;
		node = temp;
	}

	return node;
}

NodePtr searchFractionBSTKL(TreePtr* mytree, FractionAddrKL fraction) {

	NodePtr temp;
	NodePtr prev;
	int tempR, nodeR, stop = 0;

	temp = *mytree;
	prev = 0;
	while((temp) && (stop != 1)) {
		nodeR = (*fraction).num / (*fraction).denom;
		tempR = temp->iValue.num / temp->iValue.denom;
		if(tempR == nodeR) {
			stop = 1;
		} else if(tempR > nodeR) {
			prev = temp;
			temp = temp->left;
		} else if(tempR < nodeR) {
			prev = temp;
			temp = temp->right;
		} else {
			printf("\nNone of the node can match your fraction\n");
		}
	}

	return prev;
}

//do search first
void removeFractionBSTKL(FractionAddrKL fraction, NodePtr node) {
	int r, f, count, count2, stop = 0;
	NodePtr nodeR, temp, newNode, prev = 0;
	count = 0;
	nodeR = 0;
	temp = 0;
	newNode = 0;

	r = (*fraction).num / (*fraction).denom;
	f = node->iValue.num / node->iValue.denom;
	if(f > r) {
		newNode = node->left;
		count2 = 1;
	} else if(f < r) {
		newNode = prev->right;
		count2 = 2;
	}

	if(newNode->right) {
		nodeR = newNode->right;
	}

	if(newNode->left) {
		temp = newNode->left;
		newNode = temp;
	} else if(newNode->right) {
		temp = newNode->right;
		newNode = temp;
	}

	if(nodeR){
		newNode->right = nodeR;
	} 

	if(count2 == 1) {
		node->left = newNode;
	} else if(count2 == 2) {
		node->right = newNode;
	}

	return;
}

void push(TreePtr mytree, stack* stks) {

	stack temp = *stks;
	stack node = (stack)malloc(sizeof(struct stackhead));
	node->top = (TreePtr)malloc(sizeof(struct TreeInt));

	node->top = mytree;
	node->next = 0;

	if(*stks) {
		node->next = *stks;
		*stks = node;
	} else {
		*stks = node;
	}

	return;
}

void pop(stack* stks) {

	stack node = *stks;

	*stks = node->next;

	free(node);

	return;
}

int isEmpty(stack stks) {
	int e = 0;
	if(stks->top) {
		e = 0;
	} else {
		e = 1;
	}
	return e;
}

void empty(stack stks) {
	stks->top = 0;
	return;
}

void displayFractionInorderBSTKL(TreePtr mytree) {
	stack temp = 0;
	NodePtr current = mytree;

	while(current || temp) {
		if(current != 0) {
			push(current, &temp);
			current = current->left;
		} else {
			current = temp->top;
			pop(&temp);
			displayNode(current);
			current = current->right;
		}
	}

	return;
}
void displayFractionpreorderBSTKL(TreePtr mytree) {
	stack temp = 0;
	NodePtr current = mytree;

	while(current || temp) {
		if(current != 0) {
			displayNode(current);
			push(current, &temp);
			current = current->left;
		} else {
			current = temp->top;
			pop(&temp);
			current = current->right;
		}
	}
	return;
}
void displayFractionpostorderBSTKL(TreePtr mytree) {
	stack temp = 0;
	stack tempf = 0;
	NodePtr current = mytree;
	push(current, &temp);

	while(temp) {
		current = temp->top;
		push(current, &tempf);
		pop(&temp);

		if(current->left) 
			push(current->left, &temp);
		
		if(current->right)
			push(current->right, &temp);
	}

	while(tempf) {
		displayNode(tempf->top);
		pop(&tempf);
	}

	return;
}

void displaymenu(void) {
	TreePtr mytree = 0;
	FractionAddrKL frac;
	NodePtr node;
	int r, f = 0;
	int option = 0;
	int option2 = 0;
	

	do {
		printf("\n\t******************************"\
		"\n\t*		Menu	     *"\
		"\n\t* 1. insertFraction   	     *"\
		"\n\t* 2. display		     *"\
		"\n\t* 3. search		     *"\
		"\n\t* 4. remove		     *"\
		"\n\t* 5. displaysmallest	     *"\
		"\n\t* 6. Quit\t\t     *"\
		"\n\t******************************\n");

		printf("\tSelect an option(1 through 6): ");

		scanf("%d", &option);

		switch(option) {

		case 1:
			node = createNodeKL();
			insertFractionBSTKL(&mytree, node);
			break;

		case 2:
			do {
				displayorder();
				scanf("%d", &option2);
				switch(option2) {
				case 1:
					printf("\tFor Inorder: \n\n");
					displayFractionInorderBSTKL(mytree);
					break;
				case 2:
					printf("\tFor Preorder: \n\n");
					displayFractionpreorderBSTKL(mytree);
				break;

				case 3:
					printf("\tFor Postorder: \n\n");
					displayFractionpostorderBSTKL(mytree);
					break;

				case 4:
					printf("\tReturn to mainmenu");
					break;

				default:
				//Wrong option
				printf("\n\tyou should not be in this class\n");

				}

			} while(option2 != 4);

			break;

		case 3:
			printf("\tFor search: \n\n");
			frac = createFractionKL();
			r = mytree->iValue.num / mytree->iValue.denom;
			f = frac->num / frac->denom;
			node = searchFractionBSTKL(&mytree, frac);
			if(r == f) {
				displayNode(mytree);
			} else if(r > f) {
				displayNode(node->left);
			} else if(r < f) {
				displayNode(node->right);
			}
			break;

		case 4:
			
			break;

		case 5:
			printf("\tFor smallest: \n\n");
			node = getSmallestFractionBSTYKL(&mytree);
			displayNode(node);
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

void displayorder() {
	printf("\n\t******************************"\
		"\n\t*		Menu	     *"\
		"\n\t* 1. Inorder		     *"\
		"\n\t* 2. preorder		     *"\
		"\n\t* 3. postorder		     *"\
		"\n\t* 4. quit		     *"\
		"\n\t******************************\n");

	printf("\tSelect an option(1 through 4): ");

	return;
}

void displayinfo() {

	printf("CIS 27 - Data Structures"\

	"\nLaney College"\

	"\nKaChiLau"\

	"\nSpring 2013"\

	"\n\nAssignment Information --"\

	"\n  Assignment Number:  Lab 09,"\
	
	"\n\t\t      Coding Assignment -- Exercise #1"\

	"\n  Written by:\t      KaChiLau"\

	"\n  Due Date:\t      May 14, 2013\n");

	return;
}

/*OUTPUT
CIS 27 - Data Structures
Laney College
KaChiLau
Spring 2013

Assignment Information --
  Assignment Number:  Lab 09,
                      Coding Assignment -- Exercise #1
  Written by:         KaChiLau
  Due Date:           May 14, 2013

        ******************************
        *               Menu         *
        * 1. insertFraction          *
        * 2. display                 *
        * 3. search                  *
        * 4. remove                  *
        * 5. displaysmallest         *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 1
        Enter an Fraction-

        Num: 50
        Non-negative Denom: 1

        ******************************
        *               Menu         *
        * 1. insertFraction          *
        * 2. display                 *
        * 3. search                  *
        * 4. remove                  *
        * 5. displaysmallest         *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 1
        Enter an Fraction-

        Num: 25
        Non-negative Denom: 1

        ******************************
        *               Menu         *
        * 1. insertFraction          *
        * 2. display                 *
        * 3. search                  *
        * 4. remove                  *
        * 5. displaysmallest         *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 1
        Enter an Fraction-

        Num: 75
        Non-negative Denom: 1

        ******************************
        *               Menu         *
        * 1. insertFraction          *
        * 2. display                 *
        * 3. search                  *
        * 4. remove                  *
        * 5. displaysmallest         *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 1
        Enter an Fraction-

        Num: 10
        Non-negative Denom: 1

        ******************************
        *               Menu         *
        * 1. insertFraction          *
        * 2. display                 *
        * 3. search                  *
        * 4. remove                  *
        * 5. displaysmallest         *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 1
        Enter an Fraction-

        Num: 4
        Non-negative Denom: 1

        ******************************
        *               Menu         *
        * 1. insertFraction          *
        * 2. display                 *
        * 3. search                  *
        * 4. remove                  *
        * 5. displaysmallest         *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 1
        Enter an Fraction-

        Num: 65
        Non-negative Denom: 1

        ******************************
        *               Menu         *
        * 1. insertFraction          *
        * 2. display                 *
        * 3. search                  *
        * 4. remove                  *
        * 5. displaysmallest         *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 2

        ******************************
        *               Menu         *
        * 1. Inorder                 *
        * 2. preorder                *
        * 3. postorder               *
        * 4. quit                    *
        ******************************
        Select an option(1 through 4): 1
        For Inorder:


        Address: 001441B8
        Fraction 4/1
        left: 00000000
        right: 00000000


        Address: 00144140
        Fraction 10/1
        left: 001441B8
        right: 00000000


        Address: 00144050
        Fraction 25/1
        left: 00144140
        right: 00000000


        Address: 00143FD8
        Fraction 50/1
        left: 00144050
        right: 001440C8


        Address: 00144230
        Fraction 65/1
        left: 00000000
        right: 00000000


        Address: 001440C8
        Fraction 75/1
        left: 00144230
        right: 00000000


        ******************************
        *               Menu         *
        * 1. Inorder                 *
        * 2. preorder                *
        * 3. postorder               *
        * 4. quit                    *
        ******************************
        Select an option(1 through 4): 2
        For Preorder:


        Address: 00143FD8
        Fraction 50/1
        left: 00144050
        right: 001440C8


        Address: 00144050
        Fraction 25/1
        left: 00144140
        right: 00000000


        Address: 00144140
        Fraction 10/1
        left: 001441B8
        right: 00000000


        Address: 001441B8
        Fraction 4/1
        left: 00000000
        right: 00000000


        Address: 001440C8
        Fraction 75/1
        left: 00144230
        right: 00000000


        Address: 00144230
        Fraction 65/1
        left: 00000000
        right: 00000000


        ******************************
        *               Menu         *
        * 1. Inorder                 *
        * 2. preorder                *
        * 3. postorder               *
        * 4. quit                    *
        ******************************
        Select an option(1 through 4): 3
        For Postorder:


        Address: 001441B8
        Fraction 4/1
        left: 00000000
        right: 00000000


        Address: 00144140
        Fraction 10/1
        left: 001441B8
        right: 00000000


        Address: 00144050
        Fraction 25/1
        left: 00144140
        right: 00000000


        Address: 00144230
        Fraction 65/1
        left: 00000000
        right: 00000000


        Address: 001440C8
        Fraction 75/1
        left: 00144230
        right: 00000000


        Address: 00143FD8
        Fraction 50/1
        left: 00144050
        right: 001440C8


        ******************************
        *               Menu         *
        * 1. Inorder                 *
        * 2. preorder                *
        * 3. postorder               *
        * 4. quit                    *
        ******************************
        Select an option(1 through 4): 4
        Return to mainmenu
        ******************************
        *               Menu         *
        * 1. insertFraction          *
        * 2. display                 *
        * 3. search                  *
        * 4. remove                  *
        * 5. displaysmallest         *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 3
        For search:

        Enter an Fraction-

        Num: 3
        Non-negative Denom: 1
        No fraction to be display

        ******************************
        *               Menu         *
        * 1. insertFraction          *
        * 2. display                 *
        * 3. search                  *
        * 4. remove                  *
        * 5. displaysmallest         *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 3
        For search:

        Enter an Fraction-

        Num: 25
        Non-negative Denom: 1

        Address: 00144050
        Fraction 25/1
        left: 00144140
        right: 00000000


        ******************************
        *               Menu         *
        * 1. insertFraction          *
        * 2. display                 *
        * 3. search                  *
        * 4. remove                  *
        * 5. displaysmallest         *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 5
        For smallest:


        Address: 001441B8
        Fraction 4/1
        left: 00000000
        right: 00000000


        ******************************
        *               Menu         *
        * 1. insertFraction          *
        * 2. display                 *
        * 3. search                  *
        * 4. remove                  *
        * 5. displaysmallest         *
        * 6. Quit                    *
        ******************************
        Select an option(1 through 6): 6

        Have Fun......


*/