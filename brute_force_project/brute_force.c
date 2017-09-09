#include <iostream>
#include <string>

using namespace std;

int brute_search(char *p, char *a){
  int i, j, M = strlen(p), N = strlen(a);
  for(i = 0, j = 0; j < M && i < N; i++, j++){
    while(a[i] != p[j]){i -= j - 1; j = 0;}
  if (j == M) return i - M;
  else return i;
  }
}

int main()
{
  string text = "REALLY LONG LIST OF STRINGS WITH CONFUSING STR?NG ?????G";
  string pattern = "STRING";
  brute_search(pattern, text);
}
