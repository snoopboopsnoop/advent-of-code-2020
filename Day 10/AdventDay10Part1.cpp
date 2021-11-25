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

vector<int> readInput () {
  string line;
  vector<int> inputVector;
  ifstream input ("AdventDay10Input.txt");

  if (input.is_open()){
    while (getline(input, line)){
      inputVector.push_back(stoi(line));
    }
  }
  return inputVector;
}

int algorithm(vector<int> input) {
  int jolt = 0;
  int difference1 = 0;
  int difference2 = 0;
  int difference3 = 0;

  while(jolt != input.at(input.size()-1)){
    for(int i = 0; i < input.size(); i++) {
      if(input.at(i) == jolt+1) {
        difference1++;
        jolt = input.at(i);
      }
      else if(input.at(i) == jolt+2) {
        difference2++;
        jolt = input.at(i);
      }
      else if(input.at(i) == jolt+3) {
        difference3++;
        jolt = input.at(i);
      }
    }
  }
  return difference1 * difference3;
}

int main() {
  vector<int> input = readInput();
  input.push_back(*max_element(input.begin(), input.end())+3);
  sort(input.begin(), input.end());
  cout << algorithm(input);
}
