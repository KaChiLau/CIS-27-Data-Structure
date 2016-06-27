/**
 *Program Name: cis27Spring2013FranciscoAguilarLab4Ex1.c
 *Discussion:   Lab #4 
 *Writen By:    Francisco Aguilar 
 *Date:         02/28/2013
 */

#include <stdio.h>  

typedef struct {
  int num;
  int denom ;
} FractionFranciscoAguilar;

// funtion prototype
void displayClassInfoFranciscoAguilar(void); 
void menu(void);
void getFractionFranciscoAguilar(FractionFranciscoAguilar*);
FractionFranciscoAguilar* multiplyFractionFranciscoAguilar(FractionFranciscoAguilar*, FractionFranciscoAguilar*);
void PrintFranciscoAguilar(FractionFranciscoAguilar*);


int main() {
   
  displayClassInfoFranciscoAguilar();
  menu();
  
  return 0;
}

void menu(void) {
  int option;
  FractionFranciscoAguilar frac1;
  FractionFranciscoAguilar frac2;
  FractionFranciscoAguilar* res;
  do { 
    printf("\n\t***********************MENU***********************"
		       "\n\t* (1) Calling getFractionFranciscoAguilar()      *"
		       "\n\t* (2) Calling addFractionFranciscoAguilar()      *"
		       "\n\t* (3) Calling subtractFractionFranciscoAguilar() *"
           "\n\t* (4) Calling multypliFractionFranciscoAguilar() *"
           "\n\t* (5) Calling divideFractionFranciscoAguilar()   *"
		       "\n\t* (6) Quit                                       *"
		       "\n\t**************************************************");
    printf("\n\tEnter your option (1, to 6): ");
    scanf("%d", &option);
    
    switch (option) {
    case 1:
      getFractionFranciscoAguilar(&frac1);
      getFractionFranciscoAguilar(&frac2);
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      res = multiplyFractionFranciscoAguilar(&frac1, &frac2);
      break;
    case 5:
      PrintFranciscoAguilar(res);
      break;
    case 6:
      printf("\n\tHave fun ...\n");
      break;
    default:
      printf("\n\tWRONG OPTION!\n\n");
    }
  } 
  while (option != 6);
  
  return;
}

void getFractionFranciscoAguilar(FractionFranciscoAguilar* ptrFrac) {
  
  printf("\n\tPlease enter your Fraction:\n ");
  printf("\tEnter the Numerator: ");
  scanf("%d", &ptrFrac->num);
  printf("\tEnter the Denominator: ");
  scanf("%d", &ptrFrac->denom);
  
  return;
}

FractionFranciscoAguilar* multiplyFractionFranciscoAguilar(FractionFranciscoAguilar* pFrac1, FractionFranciscoAguilar* pFrac2) {
  
  FractionFranciscoAguilar* finalFrac;

  finalFrac->num = pFrac1->num * pFrac2->num;
  finalFrac->denom = pFrac1->denom * pFrac2->denom;

  return finalFrac;
}

void PrintFranciscoAguilar(FractionFranciscoAguilar* finalFrac) {

  printf("\n numerator %d :\n", finalFrac->num);
  printf("\n Denominator %d :\n", finalFrac->denom);

  return;
}


void displayClassInfoFranciscoAguilar() {
     printf( "CIS27 - Data Structures\n"
             "Laney College\n"
             "Francisco Aguilar\n"
             "Spring 2013\n\n"
             
             "Assignment Information --\n"
             "  Assignment Number: Lab 4,\n"
             "                     Coding Assignment -- Exercise #1\n"
             "  Written by:        Francisco Aguilar\n"
             "  Submitted Date:    02/28/2013\n\n");
     return;
}

/* OUTPUT
*/

