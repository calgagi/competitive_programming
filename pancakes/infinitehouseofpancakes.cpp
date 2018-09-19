#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void start(string);

int main(){
  string line;
  ifstream file ("A-small-practice.in");

  if(file.is_open()){
    getline(file,line);
    while(getline(file, line)){
      cout << line << endl;
      start(line);
    }
  }
  file.close();
  return 0;
}

void start(string tc){
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

  //
}
