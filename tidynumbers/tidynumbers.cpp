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

  // PLAN
  // Parse number
  // Keep going down until find perfect number
  // Use modulus operator

  int b = 1;
  if(file.is_open()){
    // filler
    getline(file,line);
    while(getline(file, line)){
      cout << line << endl;
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
  // PARSE number
  long long num = 0;
  long long b = 1;
  for(int i = 1; i < line.length() - 1; i++){
    b = b * 10;
  }
  for(int j = 0; j < line.length() - 1; j++){
    int x = line[j] - '0';
    num += x * b;
    b = b / 10;
  }

  cout << num << endl;
  // Number successfully parsed!


  long long c = 1;
  for(int i = 1; i < line.length() - 1; i++){
    c = c * 10;
  }
  long long answer = -1;
  for(long long i = num; i > 0; i--){
    string tempi = to_string(i);
    if(tempi.length() == 1){
      file << tempi;
      break;
    }
    for(int j = 1; j < tempi.length() - 1; j++){
      int current = tempi[j] - '0';
      int previous = tempi[j-1] - '0';

    }
  }
}
