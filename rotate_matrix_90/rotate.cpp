#include<iostream>
#include<iomanip>

using namespace std;

int main(){

  int ROW = 5;
  int COL = 5;
  int array[COL][ROW] = {
    {0, 1, 2, 3, 4},
    {5, 6, 7, 8, 9},
    {10, 11, 12, 13, 14},
    {15, 16, 17, 18, 19},
    {20, 21, 22, 23, 24}
  };

  for(int i = 0; i < ROW; i++){
    for(int j = 0; j < COL; j++){
      cout << setw(3) << array[i][j] << " ";
    }
    cout << endl;
  }
  for(int y = 0; y < ROW / 2; y++){
    for(int x = y; x < COL - 1 - y; x++){
      int *Top = &array[x][y];
      int *Right = &array[y][ROW - x - 1];
      int *Bottom = &array[ROW - x - 1][COL - y - 1];
      int *Left = &array[COL - y - 1][x];

      int temp_T = *Top;
      int temp_R = *Right;
      int temp_B = *Bottom;
      int temp_L = *Left;

      *Right = temp_T;
      *Bottom = temp_R;
      *Left = temp_B;
      *Top = temp_L;
    }
  }
  cout << "=============================" << endl;
  for(int i = 0; i < ROW; i++){
    for(int j = 0; j < COL; j++){
      cout << setw(3) << array[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
