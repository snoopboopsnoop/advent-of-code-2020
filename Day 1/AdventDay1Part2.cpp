#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> readInput ();
void printVector(vector<int> vector);

vector<int> readInput () {
  string line;
  vector<int> inputVector;
  ifstream input ("AdventDay1Input.txt");

  if (input.is_open()){
    while (getline(input, line)){
      inputVector.push_back(stoi(line));
    }
  }

  return inputVector;
}

int main () {
  vector<int> input = readInput();
  int temp1;
  int temp2;
  int temp3;
  for (int i = 0; i < input.size(); i++) {
    temp1 = input.at(i);
    for (int x = 0; x < input.size(); x++) {
      temp2 = input.at(x);
      for(int y = 0; y < input.size(); y++) {
        temp3 = input.at(y);
        if(temp1 + temp2 + temp3 == 2020){
          cout << temp1 * temp2 * temp3;
          return 0;
        }
      }
    }
  }

  return 0;
}

void printVector(vector<int> vector) {
  for(int i = 0; i < vector.size(); i++) {
    cout << vector.at(i) << "\n";
  }
}
