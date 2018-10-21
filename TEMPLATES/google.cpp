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

}
