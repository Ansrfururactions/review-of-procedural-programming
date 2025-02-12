

#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

const int COLS = 5;
const int ROWS = 15;

const string Filename = "StudentGrades.txt";
 
int getdata(istream &inFile, string names[], int grades[][COLS]);



int main()
{
    string names[ROWS];
    int grades[ROWS][COLS];
    int namecounter;
    ifstream inFile;

    inFile.open(Filename);
    if (inFile.is_open())
    {
        cout << "could not open file, rerun the program and try again.";
        return (1);
    }
    
    namecounter = getdata(inFile, names, grades);

    for (int r=0; r < namecounter; r++)
    {
        cout << names[r] << " ";
        for (int c = 0; c < COLS; c++)
        {
            cout << grades[r][c] << " ";
        }
        cout << endl;
    }
}
int getdata(istream& inFile, string names[], int grades[][COLS])
{
    int records = 0;
    while (inFile >> names[records] && records <= ROWS)
    {
        for (int c = 0; c < COLS; c++)
        {
            inFile >> grades[records][c];
        }
        records++;
    }
    return records;
}

