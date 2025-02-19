#include <iostream>
#include <random>
using namespace std;

int PlayerInput(string playerinput, int playerinputstandin);
void match(int playerinputstandin, int robotscore, int playerscore);
void matchwinner(int playerscore, int robotscore);
void tournamentwinner(int playerwins, int robotwins);

int main()
{
    random_device generator;
    uniform_int_distribution<int> robochoice(1, 3);
    string playerinput;
    int playerwins = 0;
    int robotwins= 0;
    int rounds = 0;
    int matches = 0;
    int roundsaskedfor = 0;
    int matchesaskedfor = 0;
   
    cout << "How many rounds would you like to play?" << endl;
    cin >> roundsaskedfor;
    cout << "How many matches would you like to play?" << endl;
    cin >> matchesaskedfor;

    while (matches < matchesaskedfor)
    {
        rounds = 0;
        int playerscore = 0;
        int robotscore = 0;
        while (rounds < roundsaskedfor)
        {
            int playerinputstandin = 0;
            playerinputstandin = PlayerInput(playerinput, playerinputstandin);
            match(playerinputstandin, robotscore, playerscore);
            rounds++;
        }
        matchwinner(playerscore, robotscore);
        matches++;
    }
    tournamentwinner(playerwins, robotwins);

     
}

int PlayerInput(string playerinput, int playerinputstandin)
{
    cout << "rock, paper, or scissors? or quit?" << endl;
    cin >> playerinput;


    if (playerinput == "rock")
    {
        playerinputstandin = playerinputstandin + 1;
    }
    else if (playerinput == "paper")
    {
        playerinputstandin = playerinputstandin + 2;
    }
    else if (playerinput == "scissors")
    {
        playerinputstandin = playerinputstandin + 3;
    }
    else if (playerinput == "quit")
    {
        return 0;
    }
    
    return  playerinputstandin;
}
void match(int playerinputstandin, int robotscore, int playerscore)
{
    random_device generator;
    uniform_int_distribution<int> robochoice(1, 3);
    int robotchoice = robochoice(generator);
    int loopvar = 0;
    while (loopvar == 0)
    {
        if (playerinputstandin == robotchoice)
        {
            cout << "its a draw!" << endl;
            loopvar++;
        }
        else if (playerinputstandin == 1 && robotchoice == 2)
        {
            cout << "you lose! paper wraps rock."<<endl;        
            robotscore + 1;
            loopvar++;
           
        }
        else if (playerinputstandin == 1 && robotchoice == 3)
        {
            cout << "you win! rock smashes scissors." << endl;
            playerscore + 1;
            loopvar++;
        }
        else if (playerinputstandin == 2 && robotchoice == 1)
        {
            cout << "you win! paper wraps rock." << endl;
            playerscore + 1;
            loopvar++;
        }
        else if (playerinputstandin == 2 && robotchoice == 3)
        {
            cout << "you lose! scissors cuts paper." << endl;
            robotscore + 1;
            loopvar++;
        }
        else if (playerinputstandin == 3 && robotchoice == 2)
        {
            cout << "you win! scissors cuts paper." << endl;
            playerscore + 1;
            loopvar++;
        }
        else if (playerinputstandin == 3 && robotchoice == 1)
        {
            cout << "you lose! rock smashes scissors." << endl;
            robotscore + 1;
            loopvar++;

        }
    }
}

void matchwinner(int playerscore, int robotscore)
{
    if (playerscore = robotscore)
    {
        cout << "this match is a draw" << endl;
    }
    else if (playerscore > robotscore)
    {
        cout << "you win this match" << endl;
        playerscore++;
    }
    else
    {
        cout << "you lost this match" << endl;
        robotscore++;
    }
}
void tournamentwinner(int playerwins, int robotwins)
{
    if (playerwins = robotwins)
    {
        cout << "this tournament is a draw" << endl;
    }
    else if (playerwins > robotwins)
    {
        cout << "you won the tournament" << endl;
    }
    else
    {
        cout << "you lost the tournament" << endl;
    }
}
