//Advent of Code 2022 Day 6 Part 1 by Olivia Biancucci
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkUnique(char a, char b, char c, char d){ //0 is false, 1 is true
  if(a == b || a == c || a == d || b == c || b == d || c == d){
    return 0;
  }
  return 1;
}

int main(){
  char input[5000];
  int i = 0;

  FILE * fp = fopen("day6.txt", "r");
  if (fp == NULL){
    printf("Error opening file.\n");
    return(-1);
  }

  fgets(input, sizeof(input), fp);

  while(input[i] != '\0'){
    int result = checkUnique(input[i], input[i+1], input[i+2], input[i+3]);
    if(result == 1){
      break;
    }
    i++;
  }

  i += 4; //account for the 4 unique characters found

  printf("Number of Characters Processed: %d\n", i);
  fclose(fp);
  return 0;
}
