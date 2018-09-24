#include<iostream>
#include<iomanip>

using namespace std;

int main(){

  int ROW = 3;
  int COL = 3;
  int array[COL][ROW] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8}
  };

  for(int i = 0; i < ROW; i++){
    for(int j = 0; j < COL; j++){
      cout << setw(3) << array[i][j] << " ";
    }
    cout << endl;
  }
  cout << "Val " << array[0][1] << endl;
  for(int y = 0; y < COL / 2; y++){
    cout << endl;
    for(int x = y; x < ROW - 1 - y; y++){
      cout << array[x][y] << " " << array[][COL/2-x] << endl;
      int *Top = &array[x][y];
      /*int *Right = &array[(COL/2)-y][x];
      int *Bottom = &array[(COL/2)-y][ROW-1-y];
      int *Left = &array[x][ROW-1-y];

      int temp_T = *Top;
      int temp_R = *Right;
      int temp_B = *Bottom;
      int temp_L = *Left;

      *Right = temp_T;
      *Bottom = temp_R;
      *Left = temp_B;
      *Top = temp_L;*/
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
