#include<iostream>
#include<string>
#include<fstream>
#include<math.h>

using namespace std;

void start(ofstream&, string);

int main(){
  string line;
  ifstream file ("C-small-practice-1.in");
  ofstream outFile ("output.txt");

  int b = 1;
  if(file.is_open()){
    // filler
    getline(file,line);
    while(getline(file, line)){
      outFile << "Case #" << b << ": ";
      start(outFile, line);
      b++;
    }
  }
  file.close();
  outFile.close();
  return 0;
}
