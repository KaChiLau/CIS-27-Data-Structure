/**
 *Program Name: cis27Program001Prep.c
 *Discussion:   Are you sure?
 */

struct Fraction {
  int num;
  int denom;
};

//int[] foo1(void); //invalid

int* foo2(int[]); //valid


//int[] foo3(int[]); //invalid


int** foo4(int*); //valid


int** foo5(int**); //valid


struct Fraction* foo6(int*, int*);


struct Fraction* foo7(struct Fraction*);


int main() {

	return 0;
}