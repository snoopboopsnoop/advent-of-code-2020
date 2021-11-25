#include <iostream>
#include <vector>
#include <fstream>

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

int main() {
  vector<int> input = readInput();
  int preamble = 25;
  vector<int> preambleInts;
  int currentNum = 0;

  for(int i = 0; i < preamble; i++) {
    preambleInts.push_back(input.at(i));
  }

  for(int i = preamble; i < input.size(); i++) {
    currentNum = input.at(i);
    if(checkNum(input, preambleInts, currentNum) != 1){
      cout << currentNum;
      return 0;
    }
    preambleInts.push_back(input.at(i));
    preambleInts.erase(preambleInts.begin());
  }
  return 0;
}
