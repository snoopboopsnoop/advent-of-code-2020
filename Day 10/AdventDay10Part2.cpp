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
  cout << endl;
}

template <typename T>
void printWrapper(vector<vector<T>> vector) {
  for(int i = 0; i < vector.size(); i++) {
    printVector(vector.at(i));
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

long long algorithm(vector<int> input) {
  vector<vector<int>> consecutives;
  vector<int> set;
  long long count = 1;
  for(int i = 0; i < input.size()-1; i++) {
    if(input.at(i)+1 == input.at(i+1)) {
      set.push_back(input.at(i));
    }
    else {
      set.push_back(input.at(i));
      if(set.size() != 1) {
        consecutives.push_back(set);
      }
      set.clear();
    }
  }
  for(int i = 0; i < consecutives.size(); i++) {
    if(consecutives.at(i).size() > 3) {
      count = count * (3 * (consecutives.at(i).size() - 3) + 1);
    }
    else if(consecutives.at(i).size() == 3) {
      count = count*2;
    }
  }
  return count;
}

int main() {
  vector<int> input = readInput();
  input.push_back(0);
  input.push_back(*max_element(input.begin(), input.end())+3);
  sort(input.begin(), input.end());
  cout << algorithm(input);
}
