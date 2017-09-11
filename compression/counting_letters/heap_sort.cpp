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

void heapsort(int arr[], int n)
{
  for(int i = n/2-1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }

  for(int i=n-1; i>=0; i--)
  {
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
  ifstream input;
  ofstream output;
  input.open("input.txt");
  output.open("output.txt");
  char ch;
  int num;
  int count = 0;
  while(input >> ch){count++;}
  cout << "count is " << count << endl;
  int arr[count-1] = {};
  for(int i = 0; i < count-1; i++){
    input >> ch;
    num = static_cast<int>(ch);
    arr[i] = num;
  }

  int n = sizeof(arr)/sizeof(arr[0]);
  heapsort(arr, n);
  cout << "Sorted array is \n";
  printArray(arr, n);
}
