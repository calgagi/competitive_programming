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
      cout << array[i][j] << " ";
    }
    cout << endl;
  }

  for(int i = 0; i < ROW_SIZE - 1; i++){
    for(int j = 0; j < COL_SIZE - 1; j++){
      int temp0 = array[i][j];
      int temp1 = array[ROW_SIZE - 1 - i][j];
      int temp2 = array[ROW_SIZE - 1 - i][COL_SIZE - 1 - j];
      int temp3 = array[i][COL_SIZE - 1 - j];
      array[ROW_SIZE - 1 - i][j] = temp0;
      array[ROW_SIZE - 1 - j][COL_SIZE - 1 - i] = temp1;
      array[i][COL_SIZE - 1 - j] = temp2;
      array[i][j] = temp3;
    }
  }

  for(int i = 0; i < ROW_SIZE; i++){
    for(int j = 0; j < COL_SIZE; j++){
      cout << array[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
