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
  string temp;
  string line;
  vector<int> inputVector;
  ifstream input ("AdventDay13Input.txt");

  if (input.is_open()){
      getline(input, line);
      inputVector.push_back(stoi(line));
      getline(input, line);
      while(line.find(',') != string::npos) {
        temp = line.substr(0, line.find(','));
        line.erase(0, line.find(',')+1);
        if(temp == "x") {
          continue;
        }
        inputVector.push_back(stoi(temp));
      }
      inputVector.push_back(stoi(line));
  }
  return inputVector;
}

int main() {
  vector<int> input = readInput();
  vector<int> times;
  int time;
  int timestamp = input.at(0);
  input.erase(input.begin());
  for(int i = 0; i < input.size(); i++) {
    time = (input.at(i) - (timestamp%input.at(i)));
    if(times.size() == 0) {
      times.push_back(input.at(i));
      times.push_back(time);
      continue;
    }
    if(times.at(1) > time) {
      times.at(0) = (input.at(i));
      times.at(1) = (time);
    }
  }
  cout << times.at(0) * times.at(1);
  return 0;
}
