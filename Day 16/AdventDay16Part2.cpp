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
      else {
        inputVector.push_back(intVector);
        intVector.clear();
        break;
      }
    }
  }
  inputVector.push_back(intVector);

  temp = input.at(1).at(1);
  stringstream stream(temp);
  while(getline(stream, substr, ',')) {
    intVector.push_back(stoi(substr));
  }
  inputVector.push_back(intVector);
  intVector.clear();

  input.at(2).erase(input.at(2).begin());
  for(string line : input.at(2)) {
    stringstream stream(line);
    while(getline(stream, substr, ',')) {
      intVector.push_back(stoi(substr));
    }
    inputVector.push_back(intVector);
    intVector.clear();
  }

  return inputVector;
}

long long algorithm(vector<vector<int>> input) {
  vector<int> key;
  vector<vector<int>> possibilities;
  vector<vector<int>> rules;
  vector<int> checkSum;
  vector<int> numbers;
  vector<vector<int>> validTickets;
  vector<vector<int>> columns;
  vector<int> tempVector;
  long long count = 1;
  bool foundInvalid = false;

  for(int i = 0; i < input.size(); i++) {
    vector<int> rule = input.at(i);
    for(int x : rule) {
      if(find(checkSum.begin(), checkSum.end(), x) == checkSum.end()) {
        checkSum.push_back(x);
      }
    }
    if(rule.size() == 0) {
      input.erase(input.begin(), input.begin()+i);
      break;
    }
    rules.push_back(rule);
  }
  input.erase(input.begin());

  for(vector<int> ticket : input) {
    for(int num : ticket) {
      if(find(checkSum.begin(), checkSum.end(), num) == checkSum.end()) {
        foundInvalid = true;
        break;
      }
    }
    if(foundInvalid == true) {
      foundInvalid = false;
      continue;
    }
    validTickets.push_back(ticket);
  }

  for(int i = 0; i < validTickets.at(0).size(); i++) {
    for(vector<int> ticket : validTickets) {
      tempVector.push_back(ticket.at(i));
    }
    columns.push_back(tempVector);
    tempVector.clear();
  }

  vector<vector<int>> check = rules;

  for(vector<int> column : columns) {
    tempVector.push_back(column.at(0));
    for(vector<int> rule : rules) {
      for(int i = 0; i < column.size(); i++) {
        if(find(rule.begin(), rule.end(), column.at(i)) == rule.end()) {
          foundInvalid = true;
          continue;
        }
      }
      if(foundInvalid == true) {
        foundInvalid = false;
      }
      else {
        tempVector.push_back(find(rules.begin(), rules.end(), rule)-rules.begin());
      }
    }
    possibilities.push_back(tempVector);
    tempVector.clear();
  }

  key.resize(possibilities.size());

  sort(possibilities.begin(), possibilities.end(), [](vector<int> a, vector<int> b) {return a.size() < b.size();});
  for(int i = 0; i < possibilities.size(); i++) {
    for(int x = 1; x < possibilities.at(i).size(); x++) {
      if(key[possibilities.at(i).at(x)] == 0) {
        key[possibilities.at(i).at(x)] = possibilities.at(i).at(0);
      }
    }
  }

  for(int i = 0; i < 6; i++) {
    count *= key[i];
  }
  return count;
}

int main() {
  vector<vector<string>> input = readInput();
  cout << algorithm(parseInput(input));
  return 0;
}
