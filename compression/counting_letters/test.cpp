#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//create an array of all ascii characters and get their count
string display(string);

int main(){
  string word;
  ifstream infile;
  infile.open("intest.txt");

  while(!infile.eof())
  {
    getline(infile, word);
    cout << word << endl;
  }

  display(word);
  infile.close();
}

string display(string word){
  int x = 0, len = 0;

  len=word.length()
  int a[2][2];
  int b[2][2]={}{1, 2}, {0, 1}};
  int c[2][2];
  int count=0;
}
