#include<iostream>

using namespace std;
/*
   1                                               1
   2        ->    2     1  ->       2  1  ->       2
   .  .  .        .  .  .        .  .  .        .  .  .

/*
   1                                                                                         1
   2        ->    2        ->             ->          1  ->              ->      2     ->    2
   3              3  1           3  1  2        3     2        1  3  2        1  3           3
   .  .  .        .  .  .        .  .  .        .  .  .        .  .  .        .  .  .     .  .  .
*/

void move_disk(int** pegs, int from_col, int to_col){
   int i = 0, f = 0, t = 0;
   while(pegs[from_col][i] != -1 && pegs[from_col][i] != 0){
      i += 1;
   }
   f = i-1;
   i = 0;
   while(pegs[to_col][i] != -1 && pegs[to_col][i] != 0){
      i += 1;
   }
   t = i;
   pegs[to_col][t] = pegs[from_col][f];
   pegs[from_col][f] = 0;
}

void print_game(int **pegs){
   cout << endl;
   int i = 0;
   while(pegs[0][i] != -1){
      i += 1;
   }
   for(int j = i-1; j >= 0; j--){
      for(int p = 0; p < 3; p++){ 
         cout << pegs[p][j] << " ";
      }
      cout << endl;
   }
}



void towers(int num_disks, int** pegs, int from_col, int to_col, int spare){
   if(num_disks > 0){
      towers(num_disks-1, pegs, from_col, spare, to_col);
      move_disk(pegs, from_col, to_col);
      print_game(pegs);
      towers(num_disks-1, pegs, spare, to_col, from_col);
   }
}

int main(){
   // Setup num_disks
   int num_disks;
   cout << "Please enter the number of disks you want: ";
   cin >> num_disks;

   // Initialize pegs
   int** pegs = new int*[3];
   for(int i = 0; i < 3; i++){
      pegs[i] = new int[num_disks+1];
      for(int j = 0; j < num_disks+1; j++){
         pegs[i][j] = 0;
         if(j == num_disks){
            pegs[i][j] = -1;
         }
      }
   }
   for(int i = 0; i < num_disks; i++){
      pegs[0][i] = num_disks-i;
   }

   // Call tower of hanoi solver function
   towers(num_disks, pegs, 0, 1, 2); 

   // Delete memory
   for(int i = 0; i < 3; i++){
      delete [] pegs[i];
   }
   delete [] pegs;
   pegs = NULL;

   // Return 0
   return 0;
}
