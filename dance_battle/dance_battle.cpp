#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void start(ifstream&, ofstream&);

int main(){
  string line;
  ifstream inFile ("A-large.in");
  ofstream outFile ("output.txt");
  int num_testcases;
  // PLAN
  string trash;

  int b = 1;
  if(inFile.is_open()){
    // Get rid of # of test cases
    inFile >> num_testcases;
    for(int i = 0; i < num_testcases; i++){
      outFile << "Case #" << b << ": ";
      start(inFile, outFile);
      // get endline
      getline(inFile, trash);
      outFile << endl;
      b++;
    }
  }
  inFile.close();
  outFile.close();
  return 0;
}

void start(ifstream& inFile, ofstream& outFile){
  // Get number of gbusses
  int num_gbusses, num_cities;
  inFile >> num_gbusses;
  int* a = new int[num_gbusses];
  int* b = new int[num_gbusses];
  // Get range of cities each bus serves
  for(int i = 0; i < num_gbusses; i++){
    inFile >> a[i];
    inFile >> b[i];
  }
  // Get number of cities we are interested in
  inFile >> num_cities;
  // Get each city number
  int *c = new int[num_cities];
  for(int i = 0; i < num_cities; i++){
    inFile >> c[i];
  }
  // Find number of buses that serve each city
  cout << "Number of cities " << num_cities << endl;
  cout << "Number of buses " << num_gbusses << endl;
  for(int i = 0; i < num_cities; i++){
    int sum = 0;
    for(int j = 0; j < num_gbusses; j++){
      if(a[j] <= c[i] && b[j] >= c[i]){
        sum = sum + 1;
      }
    }
    outFile << sum << " ";
  }
  delete [] a;
  delete [] b;
  delete [] c;
}
