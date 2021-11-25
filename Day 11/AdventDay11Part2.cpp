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

vector<vector<char>> readInput () {
  string line;
  vector<vector<char>> inputVector;
  vector<char> tempVector;
  ifstream input ("AdventDay11Input.txt");

  if (input.is_open()){
    while (getline(input, line)){
      for(int i = 0; i < line.size(); i++) {
        tempVector.push_back(line.at(i));
      }
      inputVector.push_back(tempVector);
      tempVector.clear();
    }
  }
  return inputVector;
}

bool compareSeats(vector<vector<char>> seat1, vector<vector<char>> seat2) {
  if(seat1.size() == 0 || seat2.size() == 0) return false;
  for(int i = 0 ; i < seat1.size(); i++) {
    if(seat1.at(i) != seat2.at(i)) {
      return false;
    }
  }
  return true;
}

int countAdjacent(vector<vector<char>> input, int xPos, int yPos) {
  int adjacentCount = 0;
  char currentSeat;
  int currentX = 0;
  int currentY = 0;
  for(int i = yPos-1; i < yPos+2; i++) {
    for(int x = xPos-1; x < xPos+2; x++) {
      if(i == yPos && x == xPos) {
        continue;
      }
      else if(i < 0 || i >= input.size()) {
        continue;
      }
      else if(x < 0 || x >= input.at(0).size()){
        continue;
      }
      currentSeat = input[i][x];
      if(currentSeat == '#') {
        ++adjacentCount;
      }
      else if(currentSeat == '.') {
        currentX = x;
        currentY = i;

        while(currentX >= 0 && currentX < input.at(0).size() && currentY >= 0 && currentY < input.size()){
          if(input[currentY][currentX] == '#') {
            ++adjacentCount;
            break;
          }
          if(input[currentY][currentX] == 'L') {
            break;
          }
          if(xPos-x == 1 && yPos-i == 1) {
            currentX--;
            currentY--;
          }
          else if(xPos-x == -1 && yPos-i == 1) {
            currentX++;
            currentY--;
          }
          else if(xPos-x == -1 && yPos-i == -1) {
            currentX++;
            currentY++;
          }
          else if(xPos-x == 1 && yPos-i == -1) {
            currentX--;
            currentY++;
          }
          else if(yPos-i == 1) {
            currentY--;
          }
          else if(xPos-x == -1) {
            currentX++;
          }
          else if(yPos-i == -1) {
            currentY++;
          }
          else if(xPos-x == 1) {
            currentX--;
          }
        }
      }
    }
  }
  return adjacentCount;
}

int algorithm(vector<vector<char>> input) {
  vector<vector<char>> seats;
  vector<char> currentLine;
  char currentSeat;
  int count = 0;

  while(!compareSeats(input, seats)) {
    if(seats.size() == 0) {
      seats = input;
    }
    else input = seats;
    seats.clear();
    for(int i = 0; i < input.size(); i++) {
      currentLine = input.at(i);
      for(int x = 0; x < currentLine.size(); x++) {
        currentSeat = currentLine.at(x);
        if(currentSeat == 'L') {
          if(countAdjacent(input, x, i) == 0) {
            currentLine.at(x) = '#';
          }
        }
        else if(currentSeat == '#') {
          if(countAdjacent(input, x, i) >= 5) {
            currentLine.at(x) = 'L';
          }
        }
      }
      seats.push_back(currentLine);
    }
  }

  for(int i = 0; i < seats.size(); i++) {
    for(int x = 0; x < seats.at(0).size(); x++) {
      if(seats[i][x] == '#') {
        ++count;
      }
    }
  }
  return count;
}

int main() {
  vector<vector<char>> input = readInput();
  cout << algorithm(input);
  return 0;
}
