#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CARD 52
#define SET 13
#define SEQ_SIZE 7


void init(int *deck,int *op, int len);
void shuffle(int *deck,int *op,int len);
void print_deck(int *deck,int len);
void print_array(int *deck, int len);
void arr_copy(int *deck, int *op, int len);
void sequence_check(int *deck, int *op,int len);
void check(int *deck, int *op, int len);
int compare ( const void *pa, const void *pb );
void create_tmp_array(int deck[], int op[], int mrg[][2]);
void print2d(int a[][2]);


const char suit[4][2]={ "S" , "H" , "D" , "C"};
const char rank[13][6]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
  

void main()
{
int i=0;  
int deck[NUM_CARD];
int op[NUM_CARD];
  srand(time(NULL)); 
  init(deck,op,NUM_CARD );
  print_deck(deck,NUM_CARD);
  //sequence_check(deck,op,NUM_CARD); // Uses brute force
  check(deck,op,NUM_CARD); // creates 2d array and uses qsort + linear scan
  print_deck(op,NUM_CARD);


}

void init(int *deck,int *op, int len) {
  int i=0;
  for(i=0;i<len;i ++) {
  	deck[i] = i ;
  	op[i]=-1;
  }
}

void shuffle(int *deck,int *op, int len) {

  int i=0,j=0,tmp;
  arr_copy(deck,op,len);

  
  // for each element op[i], exchange with random op[j] 
  for(i=0;i<len;i++)
  {
    j = rand() %len;
    tmp = op[i];    
    op[i]=op[j];
    op[j]=tmp;

  }

}

void arr_copy(int *deck, int *op, int len) {
  int i=0;
  for(i=0;i<len;i++) 
  op[i]=deck[i];

}


void print_array(int *deck, int len) {
  int i=0;
  for(i=0;i<len;i++)
	printf("%d ",deck[i]);
  printf("\n");

}

void print_deck(int *deck ,int len){
  int i=0;
  for( i=0; i<len;i++)
  	printf("%s %s,\t",rank[deck[i]%SET],suit[deck[i]/SET]);
  printf("\n");
}



// Does sequence check based on 2d array and qsort
void check(int *deck, int *op, int len)
{
int flag=0,i=0;
int arr[2*NUM_CARD][2];


while(!flag) {
printf("Shuffle\n");
shuffle(deck,op,len);
flag=1; // No need to reshuffle if there is no sequence

create_tmp_array(deck,op,arr);
// sort the 2d array using qsort

qsort(arr, 2*NUM_CARD, sizeof(arr[0]),compare);
for(i=0;i<2*NUM_CARD;i++){
	if(arr[i][0]==arr[i+1][0] && arr[i][1]==arr[i+1][1])
		flag=0; // reshuffle
		break;
      }
}
}


// Brute force method but should takes less memory
void sequence_check(int *deck, int *op, int len) {
  int i=0,j=0,k=0,flag=0;
  int tmp[NUM_CARD];
 
  while(!flag) {
   
   shuffle(deck,op,len);
   flag=0; // Keep shuffling until there is no sequence match
   k=0;
   memset(tmp,-1,sizeof(tmp));
   // Find first element in arr deck[i] which matches with arr op[k] 
   // init k=0. Match only the required sequence length.
   for(i=0;i<len;i++) {
	if(flag==0 && deck[i]==op[k]) {// find
		
		for(j=1;j<(SEQ_SIZE-1);j++) {
	        if(deck[i+j]!=op[k+j]) {
		// even if one comparison fails, no need to shuffle
                flag=1;
		break;
		}
		}
		
	}
	else 
		k++;
		break;
	
}
}
}

int compare ( const void *pa, const void *pb ) {
    const int (*a)[2] = pa;
    const int (*b)[2] = pb;
    if ( (*a)[0] < (*b)[0] ) return -1;
    if ( (*a)[0] > (*b)[0] ) return +1;
    return 0;
}	

void create_tmp_array(int deck[], int op[], int mrg[2*NUM_CARD][2]) {
int i=0,j=0;
for(i=0;i<NUM_CARD;i++) {
mrg[i][0]=deck[i];
mrg[i][1]=deck[i+1];
}
for(j=0;j<NUM_CARD;j++) {
mrg[i+j][0]=op[j];
mrg[i+j][1]=op[j+1];
}
}

void print2d(int a[][2]) {
    int r,c;
    for ( r = 0 ; r < ((2*NUM_CARD)) ; r++ ) {
        for ( c = 0 ; c < 2 ; c++ ) {
            printf( "%d ", a[r][c] );
        }
        printf( "\n" );
    }
}


