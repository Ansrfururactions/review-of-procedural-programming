

#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

const int namesAmt = 6;
const int gradesAmt = 6;

const string Filename = "StudentGrades.txt";

ifstream inputFile; 
int getdata(istream &inputFile, string names[], int grades[][gradesAmt]);



int main()
{
    string names[namesAmt];
    int grades[namesAmt][gradesAmt];
    int namecounter;
    ifstream inputFile;

    inputFile.open(Filename);
    if (!inputFile.fail())
    {
        cout << "could not open file, rerun the program and try again.";
        return 0;
    }
    
    namecounter = getdata(inputFile, names, grades);

    for (int r=0; r < namecounter; r++)
    {
        cout << names[r] << " ";
        for (int c = 0; c < gradesAmt; c++)
        {
            cout << grades[r][c] << " ";
        }
        cout << endl;
    }
}
int getdata(istream& inputFile, string names[], int grades[][gradesAmt])
{
    int record = 0;
    while (inputFile >> names[record] && record <= namesAmt)
    {
        for (int c = 0; c < gradesAmt; c++)
        {
            inputFile >> grades[record][c];
        }
        record++;
    }
    return record;
}

