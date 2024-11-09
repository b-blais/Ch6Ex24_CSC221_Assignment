/*
Title: Chapter 7 - Rock. Paper , Scissors Part 3
File Name : Ch6Ex24_CSC221_Assignment
Programmer : Brion Blais
Date : 11 / 2024
Requirements :
Rock, Paper, Scissors Game
Write a program that lets the user play the game of Rock, Paper, Scissors against the computer. The program should work as follows:
1. When the program begins, a random number in the range of 1 through 3 is generated. If the number is 1, then the computer has chosen rock. If the number is 2, then the computer has chosen paper. If the number is 3, then the computer has chosen scissors. (Don’t display the computer’s choice yet.)
2. The user enters his or her choice of “rock”, “paper”, or “scissors” at the keyboard. (You can use a menu if you prefer.)
3. The computer’s choice is displayed.
4. A winner is selected according to the following rules:
  • If one player chooses rock and the other player chooses scissors, then rock wins. (The rock smashes the scissors.)
  • If one player chooses scissors and the other player chooses paper, then scissors wins. (Scissors cuts paper.)
  • If one player chooses paper and the other player chooses rock, then paper wins. (Paper wraps rock.)
  • If both players make the same choice, the game must be played again to determine the winner.
Be sure to divide the program into functions that perform each major task.

Part 2:
Revise your original Rock Paper Scissors Game so that it is repeatable
using  sentinel value to end.. On each iteration of the game you should
accept the name of the player and keep count of how many times they
have won. Modify your program using a new branch of your project so that
you preserve the orginal main branch from Part 1.
Submit the code file as well as a screenshot of your testing

Part 3:
Using your program from the Rock Paper Scissors Part 2 create

a new branch that uses a file to store the results of each new session along
with previous sessions.
When starting you should provide a menu that
that lets the user start a new session, display previous sessions for yourself of any others.
 */

#include <iostream>
#include <random>
#include <fstream>
#include <string>
using namespace std;

int gameMenu();
int randomNumber();
string computerChoiceFunc();
string userChoiceFunc();
string theGameEngine(string, string);
string getPlayerName();
void totalWins(string);
void openRead();
void openWrite();

int gameSummary[] = {0,0,0};
fstream fileStreamObject;


int main()
{
    int menuChoice;
    //openRead();
    do {
        menuChoice = gameMenu();
        if (menuChoice == 1) {
            string playerName = getPlayerName();
            cout << "Starting a new Rock, Paper, Scissors game " << playerName << "!\n\n";
            string userChoice;
            while (userChoice != "Main Menu") {
                string computerChoice = computerChoiceFunc();
                userChoice = userChoiceFunc();
                if (userChoice == "Main Menu") {
                    continue;
                }
                string winner = theGameEngine(computerChoice, userChoice);
                totalWins(winner);
            }
            openWrite();
            fileStreamObject << playerName << "\t   " << gameSummary[0] << "\t    " << gameSummary[1] << "\t     " << gameSummary[2] << "\n";
            fileStreamObject.close();
        }
        else if (menuChoice == 2) {
            string fileContents;
            cout << "********************************\n";
            cout << "         Previous Games\n";
            cout << "********************************\n";
            cout << "Player    Wins    Losses   Ties\n";
            openRead();
            while (getline(fileStreamObject, fileContents)) {
                cout << fileContents << endl;
            }
            cout << "********************************\n\n\n";
            fileStreamObject.close();
        }
        else if (menuChoice == 3) {
            cout << "Exiting ...\n";
            break;
        }
        else cout << "Program error";
        cout << "\n";
        
    
    } while (menuChoice > 0 && menuChoice < 4);
    
    return 0;
}

string computerChoiceFunc() {
    int myRandomNumber = randomNumber();
    switch (myRandomNumber) {
    case 1: 
        return "Rock";
        break; //shouldn't be needed, as return should exit the switch
    case 2:
        return "Paper";
        break; //shouldn't be needed, as return should exit the switch
    case 3:
        return "Scissors";
        break; //shouldn't be needed, as return should exit the switch
    default:
        cout << "Program error.";
        return "Error";
    }        
}

string userChoiceFunc() {
    int userSelection;
    do {
        cout << "  Choose your weapon!\n";
        cout << "-----------------------\n";
        cout << "1\tRock\n";
        cout << "2\tPaper\n";
        cout << "3\tScissors\n";
        cout << "4\tReturn to Main Menu\n";
        cout << "-----------------------\n";
        cin >> userSelection;
        cout << "\n";
    } 
    while (userSelection < 1 || userSelection > 4);
    switch (userSelection) {
    case 1:
        return "Rock";
        break; //shouldn't be needed, as return should exit the switch
    case 2:
        return "Paper";
        break; 
    case 3:
        return "Scissors";
        break;
    case 4:
        return "Main Menu";
        break;
    default:
        cout << "Program error.";
        return "Error";
    }
}

int gameMenu() {
    int userMenuSelection;
    cout << "**********************\n";
    cout << "*        ROCK        *\n";
    cout << "*       PAPER        *\n";
    cout << "*      SCISSORS      *\n";
    cout << "**********************\n";
    cout << "\n";
    do {
        cout << "Press 1 for a new game.\n";
        cout << "Press 2 to view previous game results.\n";
        cout << "Press 3 to exit.\n";
        cin >> userMenuSelection;
        cout << "\n";
    } while (userMenuSelection < 1 || userMenuSelection > 3);
    return userMenuSelection;
}

int randomNumber() {
    random_device myengine;
    uniform_int_distribution<int> randomInt(1, 3);
    return randomInt(myengine);
}

string theGameEngine(string computerChoice, string userChoice) {
    string result;
    
    cout << "The battle starts ... the computer has thrown ** " << computerChoice << " **\n";
    cout << "                      ... and you have thrown ** " << userChoice << " **\n";
    
    if (computerChoice == "Rock" && userChoice == "Rock") {
        cout << "You both threw ** Rock **!! No winner, it's a tie.\t";
        result = "Tie";
    }
    else if (computerChoice == "Rock" && userChoice == "Paper") {
        cout << "Paper wraps rock ... You win!!\t";
        result = "User Win";
    }
    else if (computerChoice == "Rock" && userChoice == "Scissors") {
        cout << "Rock smashes the scissors ... the computer wins!\t";
        result = "Computer Win";
    }
    else if (computerChoice == "Paper" && userChoice == "Rock") {
        cout << "Paper wraps rock ... the computer wins!\t";
        result = "Computer Win";
    }
    else if (computerChoice == "Paper" && userChoice == "Paper") {
        cout << "You both threw ** Paper **!! No winner, it's a tie.\t";
        result = "Tie";
    }
    else if (computerChoice == "Paper" && userChoice == "Scissors") {
        cout << "Scissors cuts paper ... You win!!\t";
        result = "User Win";
    }
    else if (computerChoice == "Scissors" && userChoice == "Rock") {
        cout << "Rock smashes the scissors ... You win!!\t";
        result = "User Win";
    }
    else if (computerChoice == "Scissors" && userChoice == "Paper") {
        cout << "Scissors cuts paper ... the computer wins!\t";
        result = "Computer Win";
    }
    else if (computerChoice == "Scissors" && userChoice == "Scissors") {
        cout << "You both threw ** Scissors **!! No winner, it's a tie.\t";
        result = "Tie";
    }
    else {
        cout << "Program Error";
    }
    return result;
}

string getPlayerName() {
    string playerName;
    cout << "Please enter your name:\t";
    cin >> playerName;
    return playerName;
}

void totalWins(string winner) {
    if (winner == "User Win") {
        gameSummary[0]++; //player wins
    } 
    else if (winner == "Computer Win") {
        gameSummary[1]++;//computerWins;
    }
    else if (winner == "Tie") {
        gameSummary[2]++;//ties;
    }
    cout << "\n\nYou have " << gameSummary[0] << " wins, " << gameSummary[1] << " losses, and " << gameSummary[2] << " ties.\n\n";
}

void openWrite() {
    string fileName = "previousGames.txt";
    fileStreamObject.open(fileName, ios_base::app);
    if (!fileStreamObject) {
        cout << "The previousGames.txt file could not be found.\n";
        cout << "Please check to see if the file is in the correct folder and rerun the program. Exiting ...\n";
        exit(0);
    }
}
void openRead() {
    string fileName = "previousGames.txt";
    fileStreamObject.open(fileName);
    if (!fileStreamObject) {
        cout << "The previousGames.txt file could not be found.\n";
        cout << "Please check to see if the file is in the correct folder and rerun the program. Exiting ...\n";
        exit(0);
    }
}