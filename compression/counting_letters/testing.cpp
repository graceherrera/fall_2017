#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void heapify(int arr[], int n, int i)
{
  int largest = i; //initialize largest as root
  int l = 2*i + 1;
  int r = 2*i + 2;

//if the left child is larger than root
  if (l < n && arr[r] > arr[largest]) {largest = l;}
//if the right child is larger than the largest so far
  if (r < n && arr[r] > arr[largest]) {largest = r;}
//if largest is not root
  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapsort(int arr[], int n){
  for(int i = n/2-1; i>=0; i--){
    heapify(arr, n, i);
  }

  for(int i=n-1; i>=0; i--){
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }

}

void printArray(int arr[], int n)
{
  for (int i = 0; i<n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

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
  int count = 0;

  input.open("input.txt");

  while(input >> ch){count++;}
  //counts newline character
  input.close();

  input.open("input.txt");
  output.open("output.txt");

  //populate the array
  for(int i = 0; i < count -1; i++){
    input >> num;
    sort[i] = num;
    output << sort[i] << " ";
  }

  int n = sizeof(sort)/sizeof(sort[0]);
  heapsort(sort, n);
  cout << "Sorted Array" << endl;
  printArray(sort, n);
  input.close();
  output.close();

  return 0;
}
