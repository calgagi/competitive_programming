#include<iostream>

using namespace std;

int main(){

  int ROW_SIZE = 4;
  int COL_SIZE = 4;
  int array[ROW_SIZE][COL_SIZE] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {7, 8, 9, 10},
    {11, 12, 13, 14}
  };

  for(int i = 0; i < ROW_SIZE; i++){
    for(int j = 0; j < COL_SIZE; j++){
      int temp = array[ROW_SIZE - i][j];
      array[ROW_SIZE - i][j] = array[i][j];
      array[ROW_SIZE - j][ROW_SIZE - i] =
    }
  }
  return 0;
}
