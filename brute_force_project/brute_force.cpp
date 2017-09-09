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

  int i, j;

  for (i = 0; i <= text_len - pattern_len; i++){
    for(j = 0; j < pattern_len; j++){
      if(pattern[j] != text[i+j] && text[i] != '?') break;
    }
    if (j == pattern_len) cout << "Pattern found at: " << i << endl;
  }

  return 0;
}
