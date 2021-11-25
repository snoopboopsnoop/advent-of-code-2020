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
      temp = map.at("byr");
      if(stoi(temp) < 1920 || stoi(temp) > 2002){
        throw out_of_range ("byr");
      }

      temp = map.at("iyr");
      if(stoi(temp) < 2010 || stoi(temp) > 2020){
        throw out_of_range ("iyr");
      }

      temp = map.at("eyr");
      if(stoi(temp) < 2020 || stoi(temp) > 2030){
        throw out_of_range ("eyr");
      }

      temp = map.at("hgt");
      cout << (temp.substr((temp.size()-2), (temp.size()))) << endl;
      cout << (temp.substr(0, temp.find("c"))) << endl;
      if(temp.substr((temp.size()-2), temp.size()) == "cm"){
        if(stoi(temp.substr(0, temp.find("c"))) < 150 || stoi(temp.substr(0, temp.find("c"))) > 193){
          throw out_of_range ("hgt");
        }
      }
      else if(temp.substr((temp.size()-2), temp.size()) == "in"){
        if(stoi(temp.substr(0, temp.find("i"))) < 59 || stoi(temp.substr(0, (temp.find("i")))) > 76){
          throw out_of_range ("hgt");
        }
      }
      else throw out_of_range("hgt");

      temp = map.at("hcl");
      if(temp.front() == '#' && temp.size() == 7) {
        for(int i = 1; i < temp.size()-1; i++){
          if((temp.at(i) < 'a' || temp.at(i) > 'f') && !isdigit(temp.at(i))){
            throw out_of_range ("hcl");
          }
        }
      }
      else throw out_of_range ("hcl");

      temp = map.at("ecl");
      if(!(any_of(eyeColors.begin(), eyeColors.end(), [temp](string x){return (x == temp);}))) {
        throw out_of_range ("ecl");
      }

      temp = map.at("pid");
      if(temp.size() != 9){
        throw out_of_range ("pid");
      }

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
