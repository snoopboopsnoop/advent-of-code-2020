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

vector<vector<string>> readInput() {
  string line;
  string tempString;
  vector<vector<string>> inputVector;
  vector<string> tempVector;
  ifstream input ("AdventDay6Input.txt");

  if (input.is_open()){
    while (getline(input, line)){
      if(line != ""){
        tempVector.push_back(line);
      }
      else {
        inputVector.push_back(tempVector);
        tempVector.clear();
      }
    }
    inputVector.push_back(tempVector);
  }
  return inputVector;
}

void algorithm(vector<vector<string>> input) {
  vector<string> group;
  string answer;
  vector<char> answers;
  int count = 0;
  int size = 0;
  for(int i = 0; i < input.size(); i++) {
    group = input.at(i);
    for(int x = 0; x < group.size(); x++) {
      answer = group.at(x);
      if(x == 0) {
        for(int y = 0; y < answer.size(); y++) {
          answers.push_back(answer.at(y));
        }
      }
      size = answers.size();
      for(int y = 0; y < size; y++) {
        if(find(answer.begin(), answer.end(), answers.at(y)) == answer.end()) {
          replace(answers.begin(), answers.end(), answers.at(y), '0');
        }
      }
    }
    answers.erase(remove(answers.begin(), answers.end(), '0'), answers.end());
    count += answers.size();
    answers.clear();
  }
  cout << count;
}

int main() {
  vector<vector<string>> input = readInput();
  algorithm(input);
  return 0;
}
