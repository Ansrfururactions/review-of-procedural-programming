

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
char getLettergrade(double average);



int main()
{
    string names[ROWS];
    int grades[ROWS][COLS];
    double averageArray[ROWS];
    int averagecounter; 
    int namecounter;
    double average=0;
    ifstream inFile;

    inFile.open(Filename);
    if (!inFile.is_open())
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

    average = getAverages(grades);

    

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

char getLettergrade(double average);
