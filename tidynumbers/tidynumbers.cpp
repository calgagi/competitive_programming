#include<iostream>
#include<string>
#include<fstream>
#include<math.h>

using namespace std;

void start(ofstream&, string);

int main(){
  string line;
  ifstream file ("B-large-practice.in");
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

void start(ofstream& file, string line){
  // Plan:
  // For the length of the string
  // Start at back, if number at spot i is less
  // than the next number, set number to next number

  string answer = line;
  cout << answer << endl;
  for(int i = answer.length() - 2; i >= 1; i--){
    int current = answer[i] - '0';
    int next = answer[i+1] - '0';
    if(next > current){
      answer[i] = answer[i+1];
    }
  }
  file << answer << endl;
}
