#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct letterType
{
  char letter;
  int letterCount;
};
void openFile(ifstream& inFile, ofstream& outFile);
//just counting big and small letters
void count(ifstream& inFile, letterType letterList[], int& totalBig, int& totalSmall);
void printResult(ofstream& outFile, letterType letterList[], int totalBig, int totalSmall);

int main()
{
  ifstream input;
  ofstream output;
  int totalCapital = 0;
  int totalLower = 0;
  letterType letterObj[52]; //just capitals and lowers each it's own thing

  openFile(input, output);
  count(input, letterObj, totalCapital, totalLower);
  printResult(output, letterObj, totalCapital, totalLower);

  input.close();
  output.close();

  return 0;
}

void openFile(ifstream& inFile, ofstream& outFile)
{
  string inFileName;
  string outFileName;

  cout << "Enter the name of the input file: ";
  cin >> inFileName;
  inFile.open(inFileName.c_str());
  cout << endl;

  cout << "Enter the name of the output file: ";
  cin >>outFileName;
  outFile.open(outFileName.c_str());
  cout << endl;

}

void count(ifstream& inFile, letterType letterList[], int& totalBig, int& totalSmall)
{
  char ch;
  for(int index = 0; index < 26; index++)
  {
    letterList[index + 26].letter = static_cast<char>(65 + index); //changing char to its ascii index
    letterList[index + 26].letterCount = 0;
  }

  inFile >> ch;
  while(!inFile.eof())
  {
    if('A' <= ch && ch <= 'Z')
    {
      letterList[static_cast<int>(ch) - 65].letterCount++;
      totalBig++;
    }
    else if('a' <= ch <= 'z')
    {
      letterList[static_cast<int>(ch) - 71].letterCount++;
      totalSmall++;
    }

    inFile >> ch;
  }
}

void printResult(ofstream& outFile, letterType letterList[], int totalBig, int totalSmall)
{
  outFile << fixed << showpoint << setprecision(2);
  outFile << "Letter Occurrences Percentage " << endl;

  for(int index = 0; index < 52; index++)
  {
    if(0 <= index && index <= 25)
		{
			outFile << setw(4) << letterList[index].letter << setw(12) << letterList[index].letterCount << " ";
			outFile << setw(15) << 100 * (letterList[index].letterCount / static_cast<double>(totalBig)) << "%" << endl;
		}
		else
		{
			outFile << setw(4) << letterList[index].letter << setw(12) << letterList[index].letterCount << " ";
			outFile << setw(15) << 100 * (letterList[index].letterCount / static_cast<double>(totalSmall)) << "%" << endl;
		}
  }
}
