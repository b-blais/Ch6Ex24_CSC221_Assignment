/*
Title: Chapter 6 Exercise 24 - Rock. Paper , Scissors
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
 */

#include <iostream>
#include <random>
using namespace std;

int randomNumber();
string computerChoiceFunc();
string userChoiceFunc();
string theGameEngine(string, string);

int main()
{
    
    string computerChoice = computerChoiceFunc();
    string userChoice = userChoiceFunc();
    string winner = theGameEngine(computerChoice, userChoice);
    cout << "Game Over\n";
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
        cout << "Choose your weapon!\n";
        cout << "-------------------\n";
        cout << "1\tRock\n";
        cout << "2\tPaper\n";
        cout << "3\tScissors\n";
        cin >> userSelection;
        cout << "\n";
    } 
    while (userSelection < 1 || userSelection > 3);
    switch (userSelection) {
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

int randomNumber() {
    random_device myengine;
    uniform_int_distribution<int> randomInt(1, 3);
    return randomInt(myengine);
}

string theGameEngine(string computerChoice, string userChoice) {
    string result;
    
    cout << "The battle starts ... the computer has throws ** " << computerChoice << " **\n";
    cout << "and you have thrown ** " << userChoice << " **\n";
    
    if (computerChoice == "Rock" && userChoice == "Rock") {
        cout << "You both threw ** Rock **!! No winner, it's a tie.\t";
        string result = "Tie";
    }
    else if (computerChoice == "Rock" && userChoice == "Paper") {
        cout << "Paper wraps rock ... You win!!\t";
        string result = "User Win";
    }
    else if (computerChoice == "Rock" && userChoice == "Scissors") {
        cout << "Rock smashes the scissors ... the computer wins!\t";
        string result = "Computer Win";
    }
    else if (computerChoice == "Paper" && userChoice == "Rock") {
        cout << "Paper wraps rock ... the computer wins!\t";
        string result = "Computer Win";
    }
    else if (computerChoice == "Paper" && userChoice == "Paper") {
        cout << "You both threw ** Paper **!! No winner, it's a tie.\t";
        string result = "Tie";
    }
    else if (computerChoice == "Paper" && userChoice == "Scissors") {
        cout << "Scissors cuts paper ... You win!!\t";
        string result = "User Win";
    }
    else if (computerChoice == "Scissors" && userChoice == "Rock") {
        cout << "Rock smashes the scissors ... You win!!\t";
        string result = "User Win";
    }
    else if (computerChoice == "Scissors" && userChoice == "Paper") {
        cout << "Scissors cuts paper ... the computer wins!\t";
        string result = "Computer Win";
    }
    else if (computerChoice == "Scissors" && userChoice == "Scissors") {
        cout << "You both threw ** Scissors **!! No winner, it's a tie.\t";
        string result = "Tie";
    }
    else {
        cout << "Program Error";
    }
    return result;
}