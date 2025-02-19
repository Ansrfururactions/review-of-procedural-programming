#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

const int COLS = 5;
const int ROWS = 6;




const string Filename = "StudentGrades.txt";
 
int getdata(istream &inFile, string names[], int grades[][COLS]);
void getAverages(int grades[][COLS], double averageArray[],int namecounter);
char getLettergrade(double average, double averageArray[], char letter, int RN);
int printreport (string names[], char letterArray[], double averageArray[], int namecounter);



int main()
{
    string names[ROWS];
    int grades[ROWS][COLS], namecounter;
    double averageArray[ROWS], average = 0;
    char letter = 'a', letterArray[ROWS];
    ifstream inFile;

    inFile.open(Filename);
    if (!inFile.is_open())
    {
        cout << "could not open file, rerun the program and try again.";
        return 0;
    }

    namecounter = getdata(inFile, names, grades);


    getAverages(grades, averageArray, namecounter);
    
    int RN = 0;
    while (RN < ROWS)
    {
        letterArray[RN] = getLettergrade(average, averageArray, letter, RN);
        RN++;
    }
   
    printreport(names, letterArray, averageArray, namecounter);
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

char getLettergrade(double average, double averageArray[], char letter, int RN)
{
    average = averageArray[RN];
    for (RN; RN <= ROWS;++RN)
    {
        if (average >= 90)
            letter = 'A';
        else if (average >= 80)
            letter = 'B';
        else if (average >= 70)
            letter = 'C';
        else if (average >= 60)
            letter = 'D';
        else
            letter= 'F';
    }
    return letter;
}

int printreport(string names[], char letterArray[], double averageArray[], int namecounter)
{
    int egg = 0;
    for (int egg = 0; egg < namecounter; egg++)
    {
        cout << "report for " << names[egg] << " " << endl;
        cout << "overall average grade for " << names[egg] << ": " << averageArray[egg] << " ";
         cout<< letterArray[egg] << " ";
             
        cout << endl;
    }
    return 0;
}