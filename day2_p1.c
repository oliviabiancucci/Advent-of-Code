//Advent of Code 2022 Day 2 Part 1 by Olivia Biancucci
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A,X rock = 1, B,Y paper = 2, C,Z scissors = 3
//win = 6, tie = 3, loss = 0

int movePlayed (char myMove){
  if(myMove == 'X'){
    return 1;
  }
  if(myMove == 'Y'){
    return 2;
  }
  if(myMove == 'Z'){
    return 3;
  }
  return 0;
}

int main(){
  int myScore = 0;
  int mpResult = 0;
  char oppMove, myMove;

  FILE * fp = fopen("day2.txt", "r");
  if (fp == NULL){
    printf("Error opening file.\n");
    return(-1);
  }

  fscanf(fp, " %c %c", &oppMove, &myMove);
  while(!feof(fp)){
    if((mpResult = (movePlayed(myMove))) == 0){
      printf("Error detecting move played.\n");
      return -1;
    }
    myScore += mpResult;

    if(((oppMove == 'A') && (myMove == 'X')) || ((oppMove == 'B') && (myMove == 'Y')) || ((oppMove == 'C') && (myMove == 'Z'))){ //draw
      myScore += 3;
    }
    else if(((oppMove == 'A') && (myMove == 'Y')) || ((oppMove == 'B') && (myMove == 'Z')) || ((oppMove == 'C') && (myMove == 'X'))){ //I win
      myScore += 6;
    }
  fscanf(fp, " %c %c", &oppMove, &myMove);
  }

  printf("Total Score: %d\n", myScore);
  fclose(fp);
  return 0;
}
