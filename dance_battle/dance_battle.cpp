#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void start(ifstream&, ofstream&);

int main(){
  string line;
  ifstream inFile ("B-large.in");
  ofstream outFile ("output.txt");
  int num_testcases;
  // PLAN
  // Sort teams by energy level
  // Fight smaller energy level teams until out of energy
  // Recruit highest energy level team
  // Repeat

  int b = 1;
  if(inFile.is_open()){
    // Get rid of # of test cases
    inFile >> num_testcases;
    for(int i = 0; i < num_testcases; i++){
      outFile << "Case #" << b << ": ";
      start(inFile, outFile);
      b++;
    }
  }
  inFile.close();
  outFile.close();
  return 0;
}

void start(ifstream& inFile, ofstream& outFile){
  int energy, num_teams, honor = 0;
  // Get energy + num_teams
  inFile >> energy;
  cout << "Energy: " << energy << endl;
  inFile >> num_teams;
  // Store teams in order
  int *rivals = new int[num_teams];
  for(int i = 0; i < num_teams; i++){
    inFile >> rivals[i];
  }
  // Sort rivals (can be done via delay)
  for(int i = 0; i < num_teams-1; i++){
    for(int j = 0; j < num_teams-i-1; j++){
      if(rivals[j] > rivals[j+1]){
        int temp = rivals[j];
        rivals[j] = rivals[j+1];
        rivals[j+1] = temp;
      }
    }
  }
  // check
  cout << "Rival energy levels: ";
  for(int i = 0; i < num_teams; i++){
    cout << rivals[i] << " ";
  }
  cout << endl;
  // Fight!
  for(int i = 0; i < num_teams; i++){
    // If the rival team has more energy than you
    // don't battle. Instead, recruit last team
    // If rival team has less energy, battle!
    if(rivals[i] < energy){
      energy -= rivals[i];
      honor += 1;
    }else if(honor > 0 && i != num_teams-1){
      energy += rivals[num_teams-1];
      honor -= 1;
      num_teams -= 1;
      i -= 1;
    }else{
      break;
    }
    // if honor is zero, truce and don't do anything
  }
  outFile << honor << endl;
  delete [] rivals;
}
