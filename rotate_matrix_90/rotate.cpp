#include<iostream>
#include<iomanip>

using namespace std;

int main(){

  int ROW_SIZE = 4;
  int COL_SIZE = 4;
  int array[ROW_SIZE][COL_SIZE] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11},
    {12, 13, 14, 15}
  };

  for(int i = 0; i < ROW_SIZE; i++){
    for(int j = 0; j < COL_SIZE; j++){
      cout << setw(3) << array[i][j] << " ";
    }
    cout << endl;
  }

  int r = ROW_SIZE - 1;
  int c = COL_SIZE - 1;
  for(int i = 0; i < ROW_SIZE / 2; i++){
    for(int j = (2*i); j < c - (2*i); j++){
      int temp_TL = array[i][j];
      int temp_TR = array[i+j][c];
      int temp_BR = array[r][c-j];
      int temp_BL = array[r-j][j];

      array[i+j][c] = temp_TL;
      array[r][c-j] = temp_TR;
      array[r-j][j] = temp_BR;
      array[i][j] = temp_BL;
    }
  }
  cout << "=============================" << endl;
  for(int i = 0; i < ROW_SIZE; i++){
    for(int j = 0; j < COL_SIZE; j++){
      cout << setw(3) << array[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
