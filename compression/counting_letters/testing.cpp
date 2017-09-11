#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

  char ch;
  int num;

  // cout << "read in char" << endl;
  // cin >> ch;
  // num = static_cast<int>(ch);
  // cout << "the char is: " << ch << " the num is: " << num << endl;
  // cout << "now the other way " << static_cast<char>(num) << endl;
  int sort[10] = {};
  ifstream input;
  ofstream output;

  input.open("input.txt");
  output.open("output.txt");

  output << "an empty array: " << endl;

  for(int j = 0; j < 10; j++)
  {
    output << sort[j];
  }

  output << endl;

  for(int i = 0; i < 10; i++){
    input >> num;
    sort[i] = num;
    output << sort[i] << " ";
  }

  input.close();
  output.close();

  return 0;
}
