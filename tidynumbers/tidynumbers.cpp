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
  for(int i = 1; i < answer.length() - 1; i++){
    if(answer[i-1] > answer[i]){
      answer[i-1]--;
      for(int j = i; j < answer.length() - 1; j++){
        answer[j] = '9';
      }
      for(int j = i - 1; j >= 1; j--){
        if(answer[j] < answer[j-1]){
          answer[j] = '9';
          answer[j-1]--;
        }
      }
      break;
    }
  }

  for(int i = 0; i < answer.length() - 1; i++){
    if(answer[i] != '0'){
      answer = answer.substr(i,answer.length()-1);
      break;
    }
  }
  file << answer << endl;
}
