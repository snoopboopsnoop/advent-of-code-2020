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
      getline(input, line);
      while(line.find(',') != string::npos) {
        temp = line.substr(0, line.find(','));
        line.erase(0, line.find(',')+1);
        if(temp == "x") {
          inputVector.push_back(-1);
          continue;
        }
        inputVector.push_back(stoi(temp));
      }
      inputVector.push_back(stoi(line));
  }
  return inputVector;
}

long long fuckYouSunTzu(vector<vector<long long>> input) {
  vector<long long> currentMod;
  long long n = 1;
  long long Ni = 0;
  long long xi = 0;
  long long biNixi = 1;
  long long temp = 1;
  long long count = 0;

  for(int i = 0; i < input.size(); i++) {
    n *= input[i][1];
  }

  for(int i = 0; i < input.size(); i++) {
    currentMod = input.at(i);
    Ni = n/currentMod.at(1);
    currentMod.push_back(Ni);
    xi = Ni%currentMod.at(1);
    while (true) {
      if((xi*temp)%currentMod.at(1) == 1) {
        break;
      }
      temp++;
    }
    xi = temp;
    currentMod.push_back(xi);
    currentMod.erase(currentMod.begin()+1);
    for(int x = 0; x < currentMod.size(); x++) {
      biNixi *= currentMod.at(x);
    }
    currentMod.push_back(biNixi);
    input.at(i) = currentMod;
    temp = 1;
    biNixi = 1;
  }
  for(int i = 0; i < input.size(); i++) {
    count += input[i][input.at(i).size()-1];
  }
  count = count%n;
  return count;
}

vector<vector<long long>> parseInput(vector<int> input) {
  vector<vector<long long>> newInput;
  vector<long long> tempVector;
  for(int i = 0; i < input.size(); i++) {
    if(input.at(i) == -1) {
      continue;
    }
    tempVector.push_back((long long)(input.size()-i-1)%input.at(i));
    tempVector.push_back((long long) input.at(i));
    newInput.push_back(tempVector);
    tempVector.clear();
  }
  sort(newInput.begin(), newInput.end(), [](const vector<long long> &a, const vector<long long> &b){return a[1] < b[1];});
  return newInput;
}

int main() {
  vector<int> input = readInput();
  cout << fuckYouSunTzu(parseInput(input))-input.size()+1;
  return 0;
}
