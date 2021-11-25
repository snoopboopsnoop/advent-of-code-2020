#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>

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
  ifstream input ("AdventDay5Input.txt");

  if (input.is_open()){
    while (getline(input, line)){
      inputVector.push_back((line));
    }
  }

  return inputVector;
}

void createPlane(vector<vector<int>> &inputVector) {
  int count = 0;
  vector<int> tempVector(9);
  iota(tempVector.begin()+1, tempVector.end(), 0);
  for(int i = 0; i < inputVector.size(); i++) {
    tempVector.at(0) = count;
    inputVector.at(i) = tempVector;
    count++;
  }
}

int findSeatID(string pass) {
  vector<vector<int>> plane(128);
  createPlane(plane);
  char currentCommand;
  int rowNum = 0;
  int seatNum = 0;
  vector<int> planeRow;
  vector<int> passes;
  for(int x = 0; x < 7; x++) { //first seven characters are rows
    currentCommand = pass.at(x);
    if(currentCommand == 'F'){
      plane.erase(plane.begin() + plane.size()/2, plane.end());
    }
    if(currentCommand == 'B'){
      plane.erase(plane.begin(), plane.begin() + plane.size()/2);
    }
  }
  planeRow = plane.at(0);
  rowNum = planeRow.at(0);
  planeRow.erase(planeRow.begin());
  for(int x = 7; x < 10; x++) {
    currentCommand = pass.at(x);
    if(currentCommand == 'L'){
      planeRow.erase(planeRow.begin() + planeRow.size()/2, planeRow.end());
    }
    if(currentCommand == 'R'){
      planeRow.erase(planeRow.begin(), planeRow.begin() + planeRow.size()/2);
    }
  }
  seatNum = planeRow.at(0);
  return (rowNum*8 + seatNum);
}

void algorithm(vector<string> input) {
  vector<int> passes;
  int lastPass = 0;
  for(int i = 0; i < input.size(); i++) {
    passes.push_back(findSeatID(input.at(i)));
  }
  sort(passes.begin(), passes.end());
  lastPass = passes.at(0);
  for(int i = 1; i < passes.size()-1; i++) {
    if(passes.at(i) != lastPass+1){
      cout << lastPass+1;
      break;
    }
    ++lastPass;
  }
}

int main() {
  vector<string> input = readInput();
  algorithm(input);
  return 0;
}
