// review of procedural programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std; 

int calculateaverage(int, int, int);

int main()
{
 
    ifstream inputFile;
    inputFile.open("StudentGrades.txt");
    if (inputFile.fail())
    {
        cout << "could not open file, rerun the program and try again.";
        return 0;
    }


    const int GradeAmt = 5;
    int grade= 0;
    int arr[GradeAmt];
    int currentgrades = 0;
    
    void addElement(int arr[], int& currentgrades, int element, int GradeAmt);
    {
        while (currentgrades < GradeAmt)
        {
            arr[currentgrades++] = grade;
        }

    }
}

int calculateaverage(int scores, int combined, int average)
{

    return average;
}
