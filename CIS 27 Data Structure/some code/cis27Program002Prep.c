/**
 *Program Name:  cis27Program002Prep.c
 *Written By:    Do you like it?
 */

#include <stdio.h>

int main () {
  char cAry1[ 81 ]; 
char cAry2[ ] = "CIS 26"; char cAry3[ ] = {'C', 'I', 'S', ' ', '2', '6', '\0'};

printf( "\nEnter a string: \n\t" );
gets( cAry1 );
printf( "\nValue stored in cAry1\n\t" );
puts( cAry1 );

printf( "-------------------------");
  
printf( "\nOriginal value stored in cAry2\n\t" );
puts( cAry2 );
printf( "\nEnter a string: \n\t" );
gets( cAry2 );
printf( "\nValue stored in cAry2\n\t" );
puts( cAry2 );

printf( "-------------------------");

printf( "\nOriginal value stored in cAry3\n\t" );
puts( cAry3 );
printf( "\nEnter a string: \n\t" );
gets( cAry3 );
printf( "\nValue stored in cAry3\n\t" );
puts( cAry3 );

printf( "--------------------------------------\n");

printf("scanf: ");
gets (cAry3); //scanf

printf("printf: ");
puts (cAry3); //printf

  return 0; 
}
