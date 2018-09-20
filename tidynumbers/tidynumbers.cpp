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
  int b = 0;
  for(int j = line.length()-1; j >= 0; j--){
    int x = line[j] - '0';
    num += x*pow(10, b);
    b++;
  }

  cout << num << endl;

  int answer = -1;
  for(int i = num; i > 0; i--){
    int remember = 9;
    int m = 10;
    while(true){
      if(m - i > 0){
        answer = i;
        break;
      }
      if(i % m >= remember){
        remember = i % m;
      }else{
        break;
      }
      m = m * 10;
    }
    if(answer != -1){
      file << answer << endl;
      break;
    }
  }
}
