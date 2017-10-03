#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <fstream>

using namespace std;

int main()
{
  //setup your files
  ifstream in;
  ofstream out;
  string iname, oname;
  cout << "Input name of file to compress: " << endl;
  cin >> iname;
  oname = iname + ".mcp";
  in.open(iname.c_str());
  out.open(oname.c_str());

  //setup your map
  char ch;
  map<char, int> charCount;


  while(in >> ch)
  {
    ++charCount[ch];
  }

  for(map<char, int>::iterator it = charCount.begin(); it != charCount.end(); ++it)
  {

    out << it->second << " " << it->first << endl;
  }


  return 0;
}
