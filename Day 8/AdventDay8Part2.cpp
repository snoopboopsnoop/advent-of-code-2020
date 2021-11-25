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

int algorithm(vector<string> input) {
  int acc = 0;
  int pos = 0;
  vector<int> instructions;
  string current;
  while(true){
    if(pos > input.size()-1){
      return acc;
    }
    current = input.at(pos);
    for(int i = 0; i < instructions.size(); i++){
      if(instructions.at(i) == pos) {
        return -1;
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
  return -1;
}

int main() {
  string current;
  int result = 0;
  vector<string> input = readInput();
  for(int i = 0; i < input.size(); i++) {
    current = input.at(i);
    if(current.substr(0, 3) == "jmp"){
      input.at(i).replace(0, 3, "nop");
      result = algorithm(input);
      if(result == -1) {
        input.at(i).replace(0, 3, "jmp");
      }
      else{
        cout << result;
        return 0;
      }
    }
    else if(current.substr(0, 3) == "nop"){
      input.at(i).replace(0, 3, "jmp");
      result = algorithm(input);
      if(result == -1) {
        input.at(i).replace(0, 3, "nop");
      }
      else{
        cout << result;
        return 0;
      }
    }
  }
  return 0;
}
