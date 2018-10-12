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

  // Print array
  for(int i = 0; i < ROW; i++){
    for(int j = 0; j < COL; j++){
      cout << setw(3) << array[i][j] << " ";
    }
    cout << endl;
  }

  // Rotate
  // Strategy:
  // If you remove 2 columns and 2 rows, you just get a (ROW-2)(COL-2) matrix.
  // Therefore, you just have to sort the outside numbers and then work
  // inwards. Indices are hard to work with.
  // y is the number of matrices you have to rotate. So for a ROW = COL = 5 matrix,
  // you would have to sort 5 / 2 = 2 matrices (integer divide). You don't have to
  // rotate the very middle element.
  // x is the number of elements that row has to be rotated. For a ROW = 5 matrix,
  // you would have 4 elements because the one of the corners don't count.
  // So everytime you hit a new matrix, you need to subtract 1 from each edge.
  for(int y = 0; y < ROW / 2; y++){
    for(int x = y; x < COL - 1 - y; x++){
      // Get top element. Top element starts at
      // [0][0] and goes across to the right
      // (so along ROW).
      int *Top = &array[x][y];
      // Get right element. Right element starts at
      // [0][ROW] and goes down (so along COL).
      int *Right = &array[y][ROW - x - 1];
      // Get bottom element. Bottom element starts
      // at [COL][ROW] and goes across to the left
      // (so along ROW).
      int *Bottom = &array[ROW - x - 1][COL - y - 1];
      // Get left element. Left element starts at
      // [COL][0] and goes up (so along COL).
      int *Left = &array[COL - y - 1][x];

      // Swap elements.
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

  // Print array
  for(int i = 0; i < ROW; i++){
    for(int j = 0; j < COL; j++){
      cout << setw(3) << array[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
