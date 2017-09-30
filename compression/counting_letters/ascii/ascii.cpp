#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  int ascii[96];
  ifstream input;
  ofstream output;

  input.open("input.txt");
  output.open("output.txt");
  char ch;

  for(int i=0; i< 96; i++){
    while(input >> ch){
      ascii[i] = int(ch);
    }
    output << ascii[i] << endl;
  }

}
