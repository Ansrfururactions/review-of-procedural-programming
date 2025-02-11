// review of procedural programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
using namespace std;


int main()
{
    random_device generator;
    uniform_int_distribution<int> robochoice(1, 3);
    string playerinput;
    int playerinputstandin = 0;

    cout << "rock, paper, or scissors? or quit?" << endl;
        cin >> playerinput;
      

        if (playerinput == "rock")
        {
            playerinputstandin = playerinputstandin+1;
        }
        else if (playerinput == "paper")
        {
            playerinputstandin = playerinputstandin+2;
        }
        else if (playerinput == "scissors")
        {
            playerinputstandin = playerinputstandin+3;
        }
        else if (playerinput == "quit")
        {
            return 0;
        }
        
        if (playerinputstandin == robochoice(generator))
        {
            cout << "its a draw!" << endl;
        }
        else if (playerinputstandin == 1 && robochoice(generator) == 2)
        {
            cout << "you lose! paper wraps rock.";
                return 0;
        }
        else if (playerinputstandin == 1 && robochoice(generator) == 3)
        {
            cout << "you win! rock smashes scissors.";
                return 0;
        }
        else if (playerinputstandin == 2 && robochoice(generator) == 1)
        {
            cout << "you win! paper wraps rock.";
                return 0;
        }
        else if (playerinputstandin == 2 && robochoice(generator) == 3)
        {
            cout << "you lose! scissors cuts paper.";
                return 0;
        }
        else if (playerinputstandin == 3 && robochoice(generator) == 2)
        {
            cout << "you win! scissors cuts paper.";
                return 0;
        }
        else if (playerinputstandin == 3 && robochoice(generator) == 1)
        {
            cout << "you lose! rock smashes scissors.";
                return 0;
        }

     
}

