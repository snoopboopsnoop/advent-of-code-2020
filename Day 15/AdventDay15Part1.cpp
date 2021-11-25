#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <iterator>

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
  ifstream input ("AdventDay15Input.txt");
  if (input.is_open()){
    getline(input, line);
    while(line.find(",") != string::npos) {
      inputVector.push_back(stoi(line.substr(0, line.find(","))));
      line.erase(0, line.find(",")+1);
    }
    inputVector.push_back(stoi(line));
  }
  return inputVector;
}

int algorithm(vector<int> input) {
  unordered_map<int, int> numbers;
  int currentNum = 0;
  int nextNum = 0;
  int count = 0;
  int temp = 0;

  for(int i : input) {
    count++;
    numbers[i] = count;
  }

  currentNum = input.back();

  while (true) {
    if(numbers.find(currentNum) != numbers.end() && numbers.find(currentNum)->second != count) {
      nextNum = count-numbers[currentNum];
    }
    else nextNum = 0;
    numbers[currentNum] = count;
    count++;

    if(count == 2020) {
      cout << "the " << count << "th number is " << nextNum;
      return nextNum;
    }
    currentNum = nextNum;
  }
  return 0;
}

int main() {
  vector<int> input = readInput();
  algorithm(input);
  return 0;
}
