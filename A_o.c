#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VERBOSE 0

void print_array(int vector[], int N){
  int i=0;
  printf("vector[%d] = {", N);
  for (; i < N; i++){
    printf("%d, ", vector[i]);
  }
  printf("}\n");
}

/**********************************************
 Select sort */
int select_sort(int vector[], int N){
  int i, iMin, j, aux, operations=0;
  for (j = 0; j < N; j++) {
    iMin = j;
    for (i = j+1; i < N; i++) {
      operations++;
      if (vector[i] < vector[iMin]) {
	iMin = i;
      }
    }
    aux = vector[j];
    vector[j] = vector[iMin];
    vector[iMin] = aux;
  }
  return(operations);
}


/**********************************************
   ordene()
   Code written collaborativelly by students, starting from 
   Eduardo's "seed" (messy)
   Igor's algorithm (had problems with repeated numbers),
   Danilo's (both) modification.
   Teo's modification: added a "break". 
   A ideia é a mesma que a do select sort:
   para cada elemento i, insira ele na posição onde
   ele deveria ficar. A diferença é que a ordenação
   é feita à esquerda do elemento i, enquanto
   que no select sort isso é feito à direita de i.
*/
int ordene(int vector[], int N){
  int i, j, aux, operations=0;
  for(i=1; i<N; i++){
    for(j=0; j<i; j++){ /* note the j<i */
      operations++;
      if (vector[i] < vector[j]){ 
	aux=vector[j];
	vector[j]=vector[i];
	vector[i]=aux;
	/* break; */
      }
    }
  }
  return(operations);
}

/**********************************************/
int bubble_sort(int vector[], int N){
  int i=0, j, fez_troca=1, aux, operations=0;
  while (fez_troca) {
    fez_troca = 0;
    for (i = 0; i < N-1; i++) {
      operations++;
      if (vector[i] > vector[i + 1]) {
	aux = vector[i];
	vector[i] = vector[i + 1];
	vector[i + 1] = aux;
	fez_troca = 1;
      }
    }
  }  
  return(operations);
}



/**********************************************
   insertion_sort()
   https://en.wikipedia.org/wiki/Insertion_sort 
*/
int insertion_sort(int vector[], int N){
  
  int i, j, aux, operations=0;
   
  for(i=1; i<N; i++){
    aux = vector[i];
    j = i-1;
    while((j>=0) && (vector[j]>aux)){      
      vector[j+1] = vector[j];
      j--;
      operations++;
    }
    vector[j+1] = aux;
  }
  return operations;
}


/**********************************************
 Merge sort

   Left  source half is A[ iBegin:iMiddle-1].
   Right source half is A[iMiddle:iEnd-1   ].
   Result is            B[ iBegin:iEnd-1   ]. */
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[], int *operations)
{
    int i = iBegin, j = iMiddle;
    
    // While there are elements in the left or right runs...
    for (int k = iBegin; k < iEnd; k++) {
      (*operations)++;
      // If left run head exists and is <= existing right run head.
      if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
	B[k] = A[i];
	i = i + 1;
      } else {
	B[k] = A[j];
	j = j + 1;    
      }
    }
}


/* Sort the given run of array A[] using array B[] as a source.
   iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set). */
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[], int *operations)
{
  (*operations)++;
  if(iEnd - iBegin < 2)  // if run size == 1
    return;              //   consider it sorted
  
  // split the run longer than 1 item into halves
  int iMiddle = (iEnd + iBegin) / 2;          // iMiddle = mid point
  // recursively sort both runs from array A[] into B[]
  TopDownSplitMerge(A, iBegin,  iMiddle, B, operations);  // sort the left  run
  TopDownSplitMerge(A, iMiddle,    iEnd, B, operations);  // sort the right run
  // merge the resulting runs from array B[] into A[]
  TopDownMerge(B, iBegin, iMiddle, iEnd, A, operations);
}


/* Copy array A to array B, from indices iBetin to iEnd */
int CopyArray(int A[], int iBegin, int iEnd, int B[])
{
  int operations = 0;
  for(int k = iBegin; k < iEnd; k++) {
    B[k] = A[k];
    operations++;
  }
  return operations;
}

/* Array A[] has the items to sort; array B[] is a work array. */
int TopDownMergeSort(int A[], int B[], int n)
{
  int operations = CopyArray(A, 0, n, B);           // duplicate array A[] into B[]
  TopDownSplitMerge(B, 0, n, A, &operations);   // sort data from B[] into A[]
  return operations;
}

/**********************************************/
int main(){
  struct timespec ts;

  /* Using time in nanosseconds as random seed: */    
  timespec_get(&ts, TIME_UTC);
  srand(ts.tv_nsec);
  
  int i, N;
  long int operations;
  scanf("%d", &N);
  /* N = 17; */
  int vector1[N], vector2[N], vector3[N], vector4[N], vector5[N], vector6[N];

  /* Initialise randomly */ 
  for (i = 0; i < N; i++){
    /* scanf("%d", &vector1[i]); */
    vector1[i] = rand()%N; /* N-i-1; */ 
    vector2[i] = vector1[i];
    vector3[i] = vector1[i];
    vector4[i] = vector1[i];
    vector5[i] = vector1[i];
    vector6[i] = vector1[i];
  }
  /* print_array(vector1, N); */
  printf("Sorted by Bubble sort in %d operations.\n", bubble_sort(vector2, N));
  printf("Sorted by SelectSort in %d operations.\n", select_sort(vector6, N));
  printf("Sorted by Students   in %d operations.\n", ordene(vector1, N));
  printf("Sorted by Insertion  in %d operations.\n", insertion_sort(vector3, N));
  printf("Sorted by MergeSort  in %d operations.\n", TopDownMergeSort(vector4, vector5, N));
  
  if(VERBOSE){
    printf("Bubble:  ");
    print_array(vector2, N);
    printf("Select:");
    print_array(vector6, N);    
    printf("Student:");
    print_array(vector1, N);
    printf("Insert: ");
    print_array(vector3, N);
    printf("MergeS.:");
    print_array(vector4, N);
  }
  return 0;
}