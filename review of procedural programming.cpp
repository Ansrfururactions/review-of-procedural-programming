

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std; 

const int COLS = 5;
const int ROWS = 6;




const string Filename = "StudentGrades.txt";
 
int getdata(istream &inFile, string names[], int grades[][COLS]);
void getAverages(int grades[][COLS], double averageArray[],int namecounter);
void getLettergrade(double average, char letterArray[ROWS]);



int main()
{
    string names[ROWS];
    int grades[ROWS][COLS];
    double averageArray[ROWS];
    char letterArray[ROWS];
    int namecounter;
    double average = 0;
    ifstream inFile;

    inFile.open(Filename);
    if (!inFile.is_open())
    {
        cout << "could not open file, rerun the program and try again.";
        return (1);
    }

    namecounter = getdata(inFile, names, grades);

    for (int r = 0; r < namecounter; r++)
    {
        cout << names[r] << " ";

        for (int c = 0; c < COLS; c++)
        {
            cout << grades[r][c] << " ";
        }
        cout << endl;
    }

    getAverages(grades, averageArray, namecounter);
    void getLettergrade(double average, char letterArray[ROWS]);

    for (int N = 0; N < namecounter; N++)
    {
        cout << names[N] << " ";
        cout << letterArray[N] << " ";
   
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


void getAverages(int grades[][COLS], double averageArray[], int namecounter)
{

    for (int R=0; R < ROWS; ++R)
    {
        double sum = 0.0;
        for (int C = 1; C < COLS; C++)
        {
            sum += grades[R][C];
        }
        double average = sum / COLS;
        averageArray[R]= average;
    } 
}

void getLettergrade(double average, char letterArray[ROWS])
{
    int R = 0;
    
    for (R; R <= ROWS; ++R)
    {
        if (average >= 90)
            letterArray[R] = 'A';
        else if (average >= 80)
            letterArray[R] = 'B';
        else if (average >= 70)
            letterArray[R] = 'C';
        else if (average >= 60)
            letterArray[R] = 'D';
        else
            letterArray[R] = 'F';
    }
}
