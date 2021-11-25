#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <bitset>
#include <stdexcept>

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
  ifstream input ("AdventDay14Input.txt");

  if (input.is_open()){
    while (getline(input, line)){
      inputVector.push_back((line));
    }
  }
  return inputVector;
}

vector<vector<string>> parseInput (vector<string> input) {
  vector<vector<string>> parsedInputs;
  vector<string> inputVector;
  string currentCommand;
  for(int i = 0; i < input.size(); i++) {
    currentCommand = input.at(i);
    if(currentCommand.substr(0, 4) == "mask") {
      inputVector.push_back(currentCommand.substr(7));
    }
    else if(currentCommand.substr(0, 3) == "mem") {
      inputVector.push_back(currentCommand.substr(4, currentCommand.find(']')-4));
      inputVector.push_back(currentCommand.substr(currentCommand.find('=')+2));
    }
    parsedInputs.push_back(inputVector);
    inputVector.clear();
  }
  return parsedInputs;
}

long long algorithm(vector<vector<string>> input) {
  vector<long long> memory(36, 0);
  string mask;
  long long count = 0;

  for(int i = 0; i< input.size(); i++) {
    if(input.at(i).size() == 1) {
      mask = input.at(i).at(0);
    }
    else if(input.at(i).size() == 2) {
      bitset<36> value = stoi(input.at(i).at(1));
      for(int x = 0; x < mask.size(); x++) {
        if(mask.at(x) != 'X') {
          value.set(mask.size()-x-1, mask.at(x)-'0');
        }
      }
      try {
        memory.at(stoi(input.at(i).at(0))) = value.to_ullong();
      }
      catch (const out_of_range& e) {
        memory.resize(stoi(input.at(i).at(0))+1);
        memory.at(stoi(input.at(i).at(0))) = value.to_ullong();
      }
    }
  }
  for(int i = 0; i < memory.size(); i++) {
    count += memory.at(i);
  }
  return count;
}

int main() {
  vector<string> input = readInput();
  vector<vector<string>> parsedInput = parseInput(input);
  cout << algorithm(parsedInput);
}
