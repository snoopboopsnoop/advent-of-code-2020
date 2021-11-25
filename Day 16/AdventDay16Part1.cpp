#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

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

vector<vector<string>> readInput () {
  string line;
  vector<vector<string>> inputVector;
  vector<string> tempVector;
  ifstream input ("AdventDay16Input.txt");
  if (input.is_open()){
    while(getline(input, line)) {
      if(line == "") {
        inputVector.push_back(tempVector);
        tempVector.clear();
      }
      else tempVector.push_back(line);
    }
    inputVector.push_back(tempVector);
  }
  return inputVector;
}

vector<vector<int>> parseInput(vector<vector<string>> input) {
  vector<string> tempVector;
  vector<vector<int>> inputVector;
  vector<int> intVector;
  string temp;
  string substr;
  int firstNum = 0;
  int lastNum = 0;

  tempVector = input.at(0);
  for(string rule : tempVector) {
    while(true) {
      if(rule.find(':') != string::npos) {
        rule.erase(0, rule.find(':')+1);
      }
      firstNum = stoi(rule.substr(rule.find(' ')+1, rule.find('-')-(rule.find(' ')+1)));
      lastNum = stoi(rule.substr(rule.find('-')+1, rule.find(' ', rule.find('-'))-(rule.find('-')+1)));
      for(int i = firstNum; i <= lastNum; i++) {
        if(find(intVector.begin(), intVector.end(), i) == intVector.end()) {
          intVector.push_back(i);
        }
      }
      if(rule.find("or") != string::npos) {
        rule.erase(0, rule.find("or")+2);
      }
      else break;
    }
  }
  inputVector.push_back(intVector);
  intVector.clear();

  temp = input.at(1).at(1);
  stringstream stream(temp);
  while(getline(stream, substr, ',')) {
    intVector.push_back(stoi(substr));
  }

  input.at(2).erase(input.at(2).begin());
  for(string line : input.at(2)) {
    stringstream stream(line);
    while(getline(stream, substr, ',')) {
      intVector.push_back(stoi(substr));
    }
  }

  inputVector.push_back(intVector);
  return inputVector;
}

int algorithm(vector<vector<int>> input) {
  vector<int> rule;
  vector<int> numbers;
  int count = 0;

  rule = input.at(0);
  numbers = input.at(1);
  for(int i : numbers) {
    if(find(rule.begin(), rule.end(), i) == rule.end()) {
      count += i;
    }
  }
  return count;
}

int main() {
  vector<vector<string>> input = readInput();
  cout << algorithm(parseInput(input));
  return 0;
}
