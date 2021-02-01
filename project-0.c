#include <stdio.h>

int main(int argc, char *argv[]) 
{
   int table[23][23];
	
   int i, j;
	
   for (j = 0; j < 23; j++){
      for (i = 0; i < 23; i++) {
         printf("%d ", table[j][i]);
      }
      printf("\n");
   }
	return 0;
}
