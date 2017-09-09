#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int brute_search(char *pattern, char *text){
  int i, j;
  int M = strlen(pattern);
  int N = strlen(text);
  for(i = 0, j = 0; j < M && i < N; i++, j++){
    while(text[i] != pattern[j]){i -= j - 1; j = 0;}
  if (j == M ) return i - M;
  else return i;
  }
}

int main()
{
  char pattern[500], text[500];
  cout << "Enter the string" << endl;
  gets(text);
  cout << "Enter the substring you wish to search for" << endl;
  gets(pattern);
  int x;
  x = brute_search(pattern, text);
  cout << x << endl;
  return 0;
}
