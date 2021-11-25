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
  cout << endl;
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

vector<string> floating(string input) {
  vector<string> finalVector;
  vector<string> tempVector;
  int temp = 0;
  if(input.find('X') != string::npos) {
    temp = input.find('X');
    input.at(temp) = '1';
    tempVector = floating(input);
    for(int x = 0; x < tempVector.size(); x++) {
      finalVector.push_back(tempVector.at(x));
    }
    input.at(temp) = '0';
    tempVector = floating(input);
    for(int x = 0; x < tempVector.size(); x++) {
      finalVector.push_back(tempVector.at(x));
    }
  }
  else finalVector.push_back(input);
  return finalVector;
}

long long algorithm(vector<vector<string>> input) {
  vector<long long> memory;
  vector<vector<long long>> memoryList;
  string mask;
  long long count = 0;
  string value;
  bool tempBool = false;

  for(int i = 0; i< input.size(); i++) {
    if(input.at(i).size() == 1) {
      mask = input.at(i).at(0);
    }
    else if(input.at(i).size() == 2) {
      bitset<36> bitsetValue = stoi(input.at(i).at(0));
      value = bitsetValue.to_string();
      for(int x = 0; x < mask.size(); x++) {
        switch (mask.at(x)) {
          case 'X':
            value.at(x) = ('X');
            break;
          case '1':
            value.at(x) = '1';
        }
      }
      vector<string> addresses = floating(value);
      for(int x = 0; x < addresses.size(); x++) {
        for(int y = 0; y < memoryList.size(); y++) {
          if(memoryList[y][0] == stoll(addresses.at(x), nullptr, 2)) {
            memoryList[y][1] = stoll(input.at(i).at(1));
            tempBool = true;
            break;
          }
        }
        if(tempBool == true) {
          tempBool = false;
          continue;
        }
        memory.push_back(stoll(addresses.at(x), nullptr, 2));
        memory.push_back(stoll(input.at(i).at(1)));
        memoryList.push_back(memory);
        memory.clear();
      }
    }
  }
  printWrapper(memoryList);
  for(int i = 0; i < memoryList.size(); i++) {
    count += memoryList[i][1];
  }
  return count;
}

int main() {
  vector<string> input = readInput();
  vector<vector<string>> parsedInput = parseInput(input);
  cout << algorithm(parsedInput);
}
