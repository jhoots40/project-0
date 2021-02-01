#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project-0.h"

//FUNCTION DEFINITION AND WORLD_SIZE IN FILE project-0.h

int main(int argc, char* argv[]){
  int world[WORLD_SIZE][WORLD_SIZE];
  int fps = 60;
  bool customFps = false;
  //Checks if more than one argument, then looks for --fps flag
  if(argc > 1){
    if(!strcmp("--fps",argv[1])){
      //Parses custom fps number and makes sure remaining args are multiple of 3
      if(argc > 2){
	fps = atoi(argv[2]);
	customFps = true;
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
  //Fills world array with 0
  blank_world(world);
  //Breaks down tuple args into sand piles in world array
  parse_args();
  //Prints world arrat to console
  print_world(world);
}



void blank_world(int world[WORLD_SIZE][WORLD_SIZE]){
  int i, j;
  for(i = 0; i < WORLD_SIZE; i++){
    for(j = 0; j < WORLD_SIZE; j++){
      world[i][j] = 0;
    }
  }
}

void parse_args(){
  //still working on how to parse tuples into points
}

void print_world(int world[WORLD_SIZE][WORLD_SIZE]){
  int i, j;
  for(i = 0; i < WORLD_SIZE; i++){
    for(j = 0; j < WORLD_SIZE; j++){
      printf("%d", world[i][j]);
    }
    printf("\n");
  }
}

