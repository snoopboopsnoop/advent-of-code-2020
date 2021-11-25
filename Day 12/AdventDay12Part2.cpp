#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
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

vector<string> readInput () {
  string line;
  vector<string> inputVector;
  ifstream input ("AdventDay12Input.txt");

  if (input.is_open()){
    while (getline(input, line)){
      inputVector.push_back((line));
    }
  }
  return inputVector;
}

int algorithm(vector<string> input) {
  string currentInstruction;
  char currentAction;
  int currentValue;
  int shipXPos = 0;
  int shipYPos = 0;
  int xPos = 10;
  int yPos = 1;

  for(int i = 0; i < input.size(); i++) {
    currentInstruction = input.at(i);
    currentAction = currentInstruction.at(0);
    currentValue = stoi(currentInstruction.substr(1, currentInstruction.size()-1));
    switch (currentAction) {
      case 'F':
        shipXPos += xPos*currentValue;
        shipYPos += yPos*currentValue;
        break;
      case 'L':
        switch (currentValue) {
          case 90:
            swap(xPos, yPos);
            xPos = -xPos;
            break;
          case 180:
            xPos = -xPos;
            yPos = -yPos;
            break;
          case 270:
            swap(xPos, yPos);
            yPos = -yPos;
            break;
        }
        break;
      case 'R':
        switch (currentValue) {
          case 90:
            swap(xPos, yPos);
            yPos = -yPos;
            break;
          case 180:
            xPos = -xPos;
            yPos = -yPos;
            break;
          case 270:
            swap(xPos, yPos);
            xPos = -xPos;
            break;
        }
        break;
      case 'N':
        yPos += currentValue;
        break;
      case 'S':
        yPos -= currentValue;
        break;
      case 'E':
        xPos += currentValue;
        break;
      case 'W':
        xPos -= currentValue;
        break;
    }
  }
  return abs(shipXPos) + abs(shipYPos);
}

int main() {
  vector<string> input = readInput();
  cout << algorithm(input);
  return 0;
}
