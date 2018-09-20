#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void start(ofstream&, string);
void flip(string&, int, int);

int main(){
  string line;
  ifstream file ("A-large-practice.in");
  ofstream outFile ("output.txt");

  // PLAN
  // Seperate size of flipper from # of pancakes
  // Parse pancakes into own string
  // Find # of flips

  int b = 1;
  if(file.is_open()){
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

void start(ofstream& file, string tc){
  // PARSE AND SETUP
  string pancakes = "";
  string size = "";
  for(int i = 0; i < tc.length(); i++){
    if(tc[i] == '+' || tc[i] == '-'){
      pancakes += tc[i];
    }else if(isdigit(tc[i])){
      size += tc[i];
    }
  }

  // Algorithm
  int flipper = stoi(size);
  bool impossible = false;
  int numberOfFlips = 0;
  int remember, remember2;
  int flipflop = 0;
  while(true){
    bool skip = false;
    for(int i = 0; i < pancakes.length(); i++){
      if(pancakes[i] == '-'){
        flip(pancakes, i, flipper);
        skip = true;
        if(flipflop == 0){
          if(remember == i){
            impossible = true;
          }else{
            remember = i;
            flipflop = 1;
          }
        }else if(flipflop == 1){
          if(remember2 == i){
            impossible = true;
          }else{
            remember2 = i;
            flipflop = 0;
          }
        }
        numberOfFlips++;
        break;
      }
    }
    // If all pancakes are flipped!
    if(skip == false){
      file << numberOfFlips << endl;
      break;
    }
    // If impossible!
    if(impossible == true){
      file << "IMPOSSIBLE" << endl;
      break;
    }
  }
}

void flip(string& pancakes, int i, int size){
  if((i + size) >= pancakes.length()){
    i += (i + size - pancakes.length());
  }
  for(int j = i; j < i + size; j++){
    if(pancakes[j] == '-'){
      pancakes[j] = '+';
    }else if(pancakes[j] == '+'){
      pancakes[j] = '-';
    }
  }
}
