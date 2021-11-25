#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
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

vector<int> readInput () {
  string line;
  vector<int> inputVector;
  ifstream input ("AdventDay9Input.txt");

  if (input.is_open()){
    while (getline(input, line)){
      inputVector.push_back(stoll(line));
    }
  }
  return inputVector;
}

int checkNum(vector<int> input, vector<int> preambleInts, int num) {
  for(int x = 0; x < preambleInts.size(); x++) {
    for(int y = 0; y < preambleInts.size(); y++) {
      if(x == y) continue;
      if(preambleInts.at(x) + preambleInts.at(y) == num) {
        return 1;
      }
    }
  }
  return 0;
}

int addNum(vector<int> input, int num) {
  int count = 0;
  for(int i = 0; i < input.size(); i++) {
    for(int x = i; x < input.size(); x++) {
      if(count > num) break;
      else if(count == num){
        return *max_element((input.begin()+i), (input.begin()+x)) + *min_element((input.begin()+i), (input.begin()+x));
      }
      count += input.at(x);
    }
    count = 0;
  }
  return 0;
}

int main() {
  vector<int> input = readInput();
  int preamble = 25;
  vector<int> preambleInts;
  int currentNum = 0;
  int rightNum = 0;

  for(int i = 0; i < preamble; i++) {
    preambleInts.push_back(input.at(i));
  }

  for(int i = preamble; i < input.size(); i++) {
    currentNum = input.at(i);
    if(checkNum(input, preambleInts, currentNum) != 1){
      rightNum = currentNum;
      break;
    }
    preambleInts.push_back(input.at(i));
    preambleInts.erase(preambleInts.begin());
  }

  cout << addNum(input, rightNum);

  return 0;
}
