#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <map>
#include <ctype.h>
#include <algorithm>

using namespace std;

vector<string> readInput ();
void printVector(vector<string> vector);
void printMap(map<string, string> map);
map <string, string> createMap (string input);

vector<string> readInput() {
  string line;
  string tempString;
  vector<string> inputVector;
  vector<string> tempVector;
  ifstream input ("AdventDay4Input.txt");

  if (input.is_open()){
    while (getline(input, line)){
      if(line != ""){
        tempString.append(" " + line);
      }
      else {
        tempString.erase(0,1);
        inputVector.push_back(tempString);
        cout << tempString << endl;
        tempString = "";
      }
    }
    tempString.erase(0,1);
    inputVector.push_back(tempString);
    cout << tempString << endl;
    tempString = "";
  }
  return inputVector;
}

map <string, string> createMap (string input){
  map <string, string> map;
  string tempKey;
  string tempValue;
  while(input != "") {
    tempKey = input.substr(0, (input.find(":")));
    tempValue = input.substr((input.find(":")+1), ((input.find(' ')-input.find(":")-1)));
    input.erase(0, input.find(" ")+1);
    map.insert({tempKey, tempValue});
    if(input.find(" ") == string::npos){
      tempKey = input.substr(0, (input.find(":")));
      tempValue = input.substr((input.find(":")+1), ((input.find(' ')-input.find(":")-1)));
      input.erase(0, input.find(" ")+1);
      map.insert({tempKey, tempValue});
      break;
    }
  }
  return map;
}

int main() {
  int count = 0;
  string temp;
  vector<string> input = readInput();
  vector<string> eyeColors = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
  map<string, string> map;
  cout << "Size: " << input.size() << endl;
  //printVector(input);


  for(int i = 0; i < input.size(); i++) {
    cout << "i: " << i << endl;
    map = createMap(input.at(i));
    printMap(map);
    cout << endl;
    try {
      map.at("byr");
      map.at("iyr");
      map.at("eyr");
      map.at("hgt");
      map.at("hcl");
      map.at("ecl");
      map.at("pid");

      cout << "valid" << endl;
    }
    catch (const out_of_range& e) {
      cout << "invalid" << endl;
      cout << e.what() << endl;
      ++count;
    }
    cout << endl;
    map.clear();
  }
  cout << (input.size() - count) << endl;
  return 0;
}

void printVector(vector<string> vector) {
  for(int i = 0; i < vector.size(); i++) {
    cout << vector.at(i) << "\n";
  }
}

void printMap(map<string, string> map) {
  for(auto it = map.cbegin(); it != map.cend(); ++it) {
    cout << it->first << ":" << it->second << endl;
  }
}
