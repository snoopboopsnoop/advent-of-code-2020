#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

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

vector<string> readInput() {
  string line;
  string tempString;
  vector<string> inputVector;
  vector<string> tempVector;
  ifstream input ("AdventDay6Input.txt");

  if (input.is_open()){
    while (getline(input, line)){
      if(line != ""){
        tempString.append(line);
      }
      else {
        inputVector.push_back(tempString);
        tempString = "";
      }
    }
    inputVector.push_back(tempString);
    tempString = "";
  }
  return inputVector;
}

void algorithm(vector<string> input) {
  string group;
  vector<char> answers;
  int count = 0;
  for(int i = 0; i < input.size(); i++) {
    group = input.at(i);
    for(int x = 0; x < group.size(); x++) {
      if(find(answers.begin(), answers.end(), group.at(x)) == answers.end()) {
        answers.push_back(group.at(x));
      }
    }
    count += answers.size();
    answers.clear();
  }
  cout << count;
}

int main() {
  vector<string> input = readInput();
  algorithm(input);
  return 0;
}
