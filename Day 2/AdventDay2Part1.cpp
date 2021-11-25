#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<string> readInput ();
void printVector(vector<int> vector);

vector<string> readInput () {
  string line;
  vector<string> inputVector;
  ifstream input ("AdventDay2Input.txt");

  if (input.is_open()){
    while (getline(input, line)){
      inputVector.push_back((line));
    }
  }

  return inputVector;
}

int main () {
  string temp;
  string policy;
  char letter;
  string password;
  int maxLetters;
  int minLetters;
  int pos;
  int count = 0;
  int totalcount = 0;
  vector<string> input = readInput();
  for(int i = 0; i < input.size(); i++) {
    count = 0;
    temp = input.at(i);
    pos = temp.find(" ");
    policy = temp.substr(0, pos);
    letter = temp[pos+1];
    password = temp.substr(pos+4);
    pos = policy.find("-");
    minLetters = stoi(policy.substr(0, pos));
    maxLetters = stoi(policy.substr(pos+1));
    for(int i = 0; i < password.length(); i++) {
      if(password.at(i) == letter){
        count++;
      }
    }
    if(minLetters <= count && count <= maxLetters) ++totalcount;
  }
  cout << totalcount;
  return 0;
}

void printVector(vector<string> vector) {
  for(int i = 0; i < vector.size(); i++) {
    cout << vector.at(i) << "\n";
  }
}
