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
  ifstream input ("AdventDay7Input.txt");

  if (input.is_open()){
    while (getline(input, line)){
      inputVector.push_back((line));
    }
  }
  return inputVector;
}

vector<string> findBag(vector<string> input, string bagType){
  string rule;
  string tempBag;
  int iteratorFirst = 0;
  int iteratorLast = 0;
  vector<string> answers;

  for(int i = 0; i < input.size(); i++) {
    rule = input.at(i);
    if(rule.substr(0, rule.find(" ", rule.find(" ")+1)) == bagType) {
      iteratorFirst = rule.find(" ", rule.find("contain"))+1;
      iteratorLast = rule.find(" ", rule.find(" ", rule.find(" ", iteratorFirst)+1)+1);
      while(true) {
        if(rule.find("contain no other bags") != string::npos) {
          break;
        }
        tempBag = rule.substr(iteratorFirst, iteratorLast-iteratorFirst);
        answers.push_back(tempBag);
        if(rule.find(",", iteratorLast) == string::npos) {
          break;
        }
        iteratorFirst = rule.find(",", iteratorLast)+2;
        iteratorLast = rule.find(" ", rule.find(" ", rule.find(" ", iteratorFirst)+1)+1);
      }
    }
  }
  return answers;
}

int algorithm(vector<string> input, string bagType) {
  string temp;
  int count = 0;
  int repeats = 0;
  vector<string> returnVector = findBag(input, bagType);
  if(returnVector.size() == 0) {
    return count;
  }
  for(int i = 0; i < returnVector.size(); i++) {
    temp = returnVector.at(i);
    repeats = stoi(temp.substr(0, temp.find(" ")));
    temp.erase(0, temp.find(" ")+1);
    count += repeats;
    for(int x = 0; x < repeats; x++) {
      count += algorithm(input, temp);
    }
  }
  return count;
}

int main() {
  vector<string> input = readInput();
  cout << algorithm(input, "shiny gold");
  return 0;
}
