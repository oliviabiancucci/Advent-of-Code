//Advent of Code 2022 Day 1 Part 2 by Olivia Biancucci
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findLowest(int ls1, int ls2, int ls3){
  if (ls1 < ls2 && ls1 < ls3){
    return 1;
  }
  else if (ls2 < ls3){
    return 2;
  }
  else {
    return 3;
  }
  return 0;
}

int main(){
  int largestSum1 = 0;
  int largestSum2 = 0;
  int largestSum3 = 0;
  int currNum = 0;
  int currSum = 0;
  int lowestFound = 0;
  char buffer[1024];

  FILE * fp = fopen("day1.txt", "r");
  if (fp == NULL){
    printf("Error opening file.\n");
    return(-1);
  }

  fgets(buffer, sizeof(buffer), fp);
  while(!feof(fp)){
    if ((strcmp(buffer, "\r\n") == 0) || (strcmp(buffer, "\n") == 0)){
      if (largestSum1 == 0){
        largestSum1 = currSum;
      }
      else if (largestSum2 == 0){
        largestSum2 = currSum;
      }
      else if (largestSum3 == 0){
        largestSum3 = currSum;
      }
      else{
        lowestFound = findLowest(largestSum1, largestSum2, largestSum3);
        if (lowestFound == 0){
          printf("Error finding lowest sum.\n");
          return(-1);
        }
        else if (lowestFound == 1){
          if(largestSum1 < currSum){
            largestSum1 = currSum;
          }
        }
        else if (lowestFound == 2){
          if(largestSum2 < currSum){
            largestSum2 = currSum;
          }
        }
        else if (lowestFound == 3){
          if(largestSum3 < currSum){
            largestSum3 = currSum;
          }
        }
      }
      currSum = 0;
    }
    else{
      currNum = atoi(buffer);
      currSum += currNum;
    }
    fgets(buffer, sizeof(buffer), fp);
  }

  printf("Total: %d\n", largestSum1 + largestSum2 + largestSum3);

  fclose(fp);
  return 0;
}
