#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

template <typename T>
void printVector(vector<T> vector) {
  for(int i = 0; i < vector.size(); i++) {
    cout << vector.at(i) << " ";
  }
}

template <typename T>
void printWrapper(vector<vector<T>> vector) {
  for(int i = 0; i < vector.size(); i++) {
    printVector(vector.at(i));
    cout << endl;
  }
}

vector<string> readInput () {
  string line;
  vector<string> inputVector;
  ifstream input ("AdventDay8Input.txt");

  if (input.is_open()){
    while (getline(input, line)){
      inputVector.push_back((line));
    }
  }
  return inputVector;
}

int main() {
  int acc = 0;
  int pos = 0;
  vector<string> input = readInput();
  vector<int> instructions;
  string current;
  while(true){
    current = input.at(pos);
    for(int i = 0; i < instructions.size(); i++){
      if(instructions.at(i) == pos) {
        cout << acc;
        return 0;
      }
    }
    instructions.push_back(pos);
    if(current.substr(0,3) == "acc"){
      if(current.at(4) == '+') {
        acc += stoi(current.substr(5));
      }
      else acc -= stoi(current.substr(5));
    }
    if(current.substr(0,3) == "jmp") {
      if(current.at(4) == '+') {
        pos += stoi(current.substr(5));
      }
      else pos -= stoi(current.substr(5));
    }
    else pos += 1;
  }
  return 0;
}
