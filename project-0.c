#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "project-0.h"


//FUNCTION DEFINITION AND WORLD_SIZE IN FILE project-0.h

int main(int argc, char* argv[]){
  int world[WORLD_SIZE][WORLD_SIZE] = {0};
  int fps = 60;
  int customFps = 0;
  //Checks if more than one argument, then looks for --fps flag
  if(argc > 1){
    if(!strcmp("--fps",argv[1])){
      //Parses custom fps number and makes sure remaining args are multiple of 3
      if(argc > 2){
	       fps = atoi(argv[2]);
	       customFps = 1;
	       int args_left = argc - 3;
	           if(args_left % 3 != 0){
	              printf("Error: arguments given in tuples for position and sand count\n");
	              return 0;
	           }
      }
    }
  }else{
     printf("Error: no argument given after fps flag\n");
     return 0;
  }
  //Breaks down tuple args into sand piles in world array
  int start;
  if(!customFps){
    start = 1;
  }else{
    start = 3;
  }
  while(start < argc){
    int x = atoi(argv[start]);
    int y = atoi(argv[start+1]);
    int size = atoi(argv[start+2]);
    world[y][x] = size;
    
    //this condition is here to check if the user defines a space in the world greater than 8
    //then runs recursive function on that spot.
    if (size > 8) {
       update_rec(x, y, world);
    }
    start += 3;
  }
  //Prints world array to console
  print_world(world);
  
  while(1){
     ++world[11][11];
     update_rec(11, 11, world);
     print_world(world);
     usleep(1000000 / fps);
  }
}

void update_rec(int x, int y, int table[WORLD_SIZE][WORLD_SIZE]) {
   if (table[y][x] <= 8) {
      return;
   }
   table[y][x] = table[y][x] - 9;
   
   int i, j;
   
   for (j = y - 1; j < y + 2; j++) {
      for (i = x - 1; i < x + 2; i++) {
         if (j < 0 || j >= WORLD_SIZE || i < 0 || i >= WORLD_SIZE || table[j][i] == -1){
            continue;
         }
         table[j][i] = table[j][i] + 1;
         update_rec(i, j, table);
      }
   }
}





void print_world(int world[WORLD_SIZE][WORLD_SIZE]){
  int i, j;
  for(j = 0; j < WORLD_SIZE; j++){
    for(i = 0; i < WORLD_SIZE; i++){
      if(world[j][i] == -1) {
         printf("# ");
         continue;
      }
      printf("%d ", world[j][i]);
    }
    printf("\n");
  }
}

