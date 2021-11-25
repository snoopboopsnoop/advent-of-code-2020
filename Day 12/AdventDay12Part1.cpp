#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

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

string rotate(string facing, char direction, int degrees) {
  int turns = degrees/90;
  if(direction == 'R') {
    for(int i = 0; i < turns; i++) {
      switch (facing.at(0)) {
        case 'n':
          facing = "east";
          break;
        case 's':
          facing = "west";
          break;
        case 'e':
          facing = "south";
          break;
        case 'w':
          facing = "north";
          break;
      }
    }
  }
  else if(direction == 'L') {
    for(int i = 0; i < turns; i++) {
      switch (facing.at(0)) {
        case 'n':
          facing = "west";
          break;
        case 's':
          facing = "east";
          break;
        case 'e':
          facing = "north";
          break;
        case 'w':
          facing = "south";
          break;
      }
    }
  }
  return facing;
}

int algorithm(vector<string> input) {
  string currentInstruction;
  string facing = "east";
  char currentAction;
  int currentValue;
  int xPos = 0;
  int yPos = 0;
  for(int i = 0; i < input.size(); i++) {
    currentInstruction = input.at(i);
    currentAction = currentInstruction.at(0);
    currentValue = stoi(currentInstruction.substr(1, currentInstruction.size()-1));
    switch (currentAction) {
      case 'F':
        switch (facing.at(0)) {
          case 'n':
            yPos += currentValue;
            break;
          case 's':
            yPos -= currentValue;
            break;
          case 'e':
            xPos += currentValue;
            break;
          case 'w':
            xPos -= currentValue;
            break;
        }
        break;
      case 'L':
      case 'R':
        facing = rotate(facing, currentAction, currentValue);
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
  return abs(xPos) + abs(yPos);
}

int main() {
  vector<string> input = readInput();
  cout << algorithm(input);
  return 0;
}
