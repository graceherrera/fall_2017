#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;


int main()
{
  string text, pattern;

  cout << "Enter the string" << endl;
  getline(cin, text);
  int text_len = text.length();

  cout << "Enter the substring you wish to search for" << endl;
  cin >> pattern;
  int pattern_len = pattern.length();

  cout<< text << " " << text_len << " " <<  pattern << " " << pattern_len << endl;

  int i, j;
  for (i = 0, j = 0; j < pattern_len && i < text_len; i++, j++){
    while (text[i] != pattern[j] && text[i] != '?') {i -= j - 1; j = 0;}
  if (j == pattern_len) cout << i - pattern_len << endl;
  else cout << i << endl;;
  }

  return 0;
}
