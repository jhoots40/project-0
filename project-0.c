#include <stdio.h>

void update_rec(int x, int y, int table[23][23]) {
   if (table[y][x] <= 8) {
      return;
   }
   table[y][x] = table[y][x] - 8;
   
   int i, j;
   
   for (j = y - 1; j < y + 2; j++) {
      for (i = x - 1; i < x + 2; i++) {
         table[j][i] = table[j][i] + 1;
         update_rec(i, j, table);
      }
   }
}

int main(int argc, char *argv[]) 
{
   int table[23][23] = {0};
	
   int i, j;
   
   for (j = 0; j < 23; j++) {
      for (i = 0; i < 23; i++) {
         printf("%d ", table[j][i]);
      }
      printf("\n");
   }
   return 0;
}
