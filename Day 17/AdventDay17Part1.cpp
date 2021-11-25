#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

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

template <typename T>
void print3d(vector<vector<vector<T>>> vector) {
  for(int i = 0; i < vector.size(); i++) {
    cout << "z=" << i << endl;
    for(int x = 0; x < vector.at(i).size(); x++) {
      printVector(vector.at(i).at(x));
      cout << endl;
    }
    cout << endl;
  }
}

vector<vector<vector<char>>> readInput () {
  string line;
  vector<vector<vector<char>>> inputVector(1);
  vector<char> tempVector;
  ifstream input ("AdventDay17Input.txt");
  if (input.is_open()){
    while(getline(input, line)) {
      for(int i = 0; i < line.size(); i++) {
        tempVector.push_back(line[i]);
      }
      inputVector[0].push_back(tempVector);
      tempVector.clear();
    }
  }
  return inputVector;
}

vector<vector<vector<char>>> resizeZ(vector<vector<vector<char>>> input) {
  vector<vector<char>> insert;
  vector<char> insert1(input.at(0).at(0).size(), '.');
  for(int z = 0; z < input[0].size(); z++) {
    insert.push_back(insert1);
  }
  cout << "kdjfakjlefdh" << endl;
  printWrapper(insert);
  input.insert(0, insert);
  input.push_back(insert);
  return input;
}

vector<vector<vector<char>>> resizeY(vector<vector<vector<char>>> input) {
  vector<char> insert(input.at(0).at(0).size(), '.');
  for(int z = 0; z < input.size(); z++) {
    //input[z].insert(0, insert);
    input[z].push_back(insert);
  }
  return input;
}

vector<vector<vector<char>>> resizeX(vector<vector<vector<char>>> input) {
  char insert = '.';
  for(int z = 0; z < input.size(); z++) {
    for(int y = 0; y < input.at(z).size(); y++) {
      //input[z][y].insert(0, insert);
      input[z][y].push_back(insert);
    }
  }
  return input;
}

int checkNeighbor(vector<vector<vector<char>>> input, int xPos, int yPos, int zPos) {
  for(int z = -1; z < 2; z++) {
    for(int y = -1; y < 2; y++) {
      for(int x = -1; x < 2; x++) {
        if(xPos+x > input.at(z).at(y).size() || xPos+x < 0) {

        }
      }
    }
  }
  return 0;
}

int algorithm(vector<vector<vector<char>>> input) {
  int cycles = 6;

  for(int z = 0; z < input.size(); z++) {
    for(int x = 0; x < input.at(z).size(); x++) {
      for(int y = 0; y < input.at(z).at(x).size(); y++) {

      }
    }
  }

  return 0;
}

int main() {
  vector<vector<vector<char>>> input = readInput();
  print3d(input);
  input = resizeZ(input);
  print3d(input);
  return 0;
}
