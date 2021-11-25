#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>

using namespace std;

vector<string> readInput();
void printVector(vector<int> vector);
long double algorithm(vector<vector<char>> inputArray, int incrementX, int incrementY, int inputLength, int inputWidth);

vector<string> readInput() {
  string line;
  vector<string> inputVector;
  ifstream input ("AdventDay3Input.txt");

  if (input.is_open()){
    while (getline(input, line)){
      inputVector.push_back((line));
    }
  }

  return inputVector;
}

int main() {
  vector<string> input = readInput();
  int inputWidth = input.at(0).length();
  int inputLength = input.size();
  long double count = 0;
  vector<vector<char>> inputArray;
  inputArray.resize(inputLength);
  for(int i = 0; i < inputLength; i++) {
    inputArray.at(i).resize(inputWidth);
    for(int x = 0; x < inputWidth; x++) {
      inputArray[i][x] = input.at(i).at(x);
    }
  }

  cout << algorithm(inputArray, 3, 1, inputLength, inputWidth);
  return 0;
}

long double algorithm(vector<vector<char>> inputArray, int incrementX, int incrementY, int inputLength, int inputWidth){
  long double count = 0;
  int posX = 0;
  int posY = 0;
  while(true){
    if(inputArray[posY][posX] == '#'){
      ++count;
    }
    posX += incrementX;
    posY += incrementY;

    if(posX >= inputWidth){
      posX -= inputWidth;
    }
    if(posY >= inputLength){
      return count;
    }
  }
}

void printVector(vector<string> vector) {
  for(int i = 0; i < vector.size(); i++) {
    cout << vector.at(i) << "\n";
  }
}
