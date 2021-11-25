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

void printSet(set<string> set) {
  for(string const& bag : set) {
    cout << bag << ", ";
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

vector<int> findBag(vector<string> input, string bagType){
  string rule;
  string tempBag;
  int iteratorFirst = 0;
  int iteratorLast = 0;
  vector<int> answers;
  for(int i = 0; i < input.size(); i++) {
    rule = input.at(i);
    iteratorFirst = rule.find(" ", rule.find("contain") + 8)+1;
    iteratorLast = rule.find(" ", rule.find(" ", iteratorFirst)+1);
    while(true) {
      if(rule.find("contain no other bags") != string::npos) {
        break;
      }
      tempBag = rule.substr(iteratorFirst, iteratorLast-iteratorFirst);
      if(tempBag == bagType) {
        answers.push_back(i);
        break;
      }
      if(rule.find(",", iteratorLast) == string::npos) {
        break;
      }
      iteratorFirst = rule.find(" ", rule.find(",", iteratorLast)+2)+1;
      iteratorLast = rule.find(" ", rule.find(" ", iteratorFirst)+1);
    }
  }
  return answers;
}

string findBagName(vector<string> input, int pos) {
  string rule;
  rule = input.at(pos);
  int iteratorLast = rule.find(" ", rule.find(" ")+1);
  return rule.substr(0, iteratorLast);
}

int algorithm(vector<string> input) {
  set<string> bagSet;
  vector<int> returnVector = findBag(input, "shiny gold");
  for(int i = 0; i < returnVector.size(); i++) {
    bagSet.insert(findBagName(input, returnVector.at(i)));
  }
  int lastSize = 0;
  while(true) {
    lastSize = bagSet.size();
    for(string bag : bagSet) {
      returnVector = findBag(input, bag);
      for(int i = 0; i < returnVector.size(); i++) {
        bagSet.insert(findBagName(input, returnVector.at(i)));
      }
    }
    if(lastSize == bagSet.size()) {
      return bagSet.size();
    }
  }
  return 0;
}

int main() {
  vector<string> input = readInput();
  cout << algorithm(input);
  return 0;
}
