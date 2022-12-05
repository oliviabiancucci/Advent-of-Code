//Advent of Code 2022 Day 1 Part 1 by Olivia Biancucci

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int largestSum = 0;
  int currNum = 0;
  int currSum = 0;
  char buffer[1024];

  FILE * fp = fopen("d1p1.txt", "r");
  if (fp == NULL){
    printf("Error opening file.\n");
    return(-1);
  }

  fgets(buffer, sizeof(buffer), fp);
  while(!feof(fp)){
    if ((strcmp(buffer, "\r\n") == 0) || (strcmp(buffer, "\n") == 0)){
      if (currSum > largestSum){
        largestSum = currSum;
      }
        currSum = 0;
    }
    else{
      currNum = atoi(buffer);
      currSum += currNum;
    }
    fgets(buffer, sizeof(buffer), fp);
  }

  printf("Largest Sum: %d\n", largestSum);

  fclose(fp);
  return 0;
}
