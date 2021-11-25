#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
  auto start = high_resolution_clock::now();
  vector<int> input = readInput();
  int temp1;
  int temp2;
  for (int i = 0; i < input.size(); i++) {
    temp1 = input.at(i);
    for (int x = 0; x < input.size(); x++) {
      temp2 = input.at(x);
      if(temp1 + temp2 == 2020){
        cout << temp1 * temp2 << endl;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop-start);
        cout << duration.count();
        return 0;
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
