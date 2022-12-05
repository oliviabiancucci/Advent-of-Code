//Advent of Code 2022 Day 2 Part 1 by Olivia Biancucci
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A rock = 1, B paper = 2, C scissors = 3
// X needs lose, Y needs draw, Z needs win
//win = 6, tie = 3, loss = 0

int main(){
  int myScore = 0;
  char oppMove, gameResult;

  FILE * fp = fopen("day2.txt", "r");
  if (fp == NULL){
    printf("Error opening file.\n");
    return(-1);
  }

  fscanf(fp, " %c %c", &oppMove, &gameResult);
  while(!feof(fp)){
    if(gameResult == 'Y'){ //draw
      myScore += 3;
      if(oppMove == 'A'){
        myScore += 1;
      }
      else if(oppMove == 'B'){
        myScore += 2;
      }
      else{
        myScore += 3;
      }
    }
    else if(gameResult == 'Z'){ //I win
      myScore += 6;
      if(oppMove == 'A'){
        myScore += 2;
      }
      else if(oppMove == 'B'){
        myScore += 3;
      }
      else{
        myScore += 1;
      }
    }
    else{ //I lose
      if(oppMove == 'A'){
        myScore += 3;
      }
      else if(oppMove == 'B'){
        myScore += 1;
      }
      else{
        myScore += 2;
      }
    }
  fscanf(fp, " %c %c", &oppMove, &gameResult);
  }

  printf("Total Score: %d\n", myScore);
  fclose(fp);
  return 0;
}
