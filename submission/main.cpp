#include <iostream>
#include "Dice.h"

using namespace std;

int RollTwoDice(Dice &d1, Dice &d2)
{
    // Print the rolls of two dice and return their sum

    cout << "Press Enter to roll both dice..." << endl;
    cin.ignore();

    int roll1 = d1.RollDice();
    cout << "Your roll is... " << roll1 << "\n\n";

    // Second roll
    int roll2 = d2.RollDice();
    cout << "Your roll is... " << roll2 << "\n";

    // Sum
    int rollSum = roll1 + roll2;
    cout << "The sum of your rolls is... " << rollSum << "\n\n";
    return rollSum;
}

void PlayRound()
{
    // Plays one round of craps

    Dice dice1 = Dice();
    Dice dice2 = Dice();

    int rollSum = RollTwoDice(dice1, dice2);

    if (rollSum == 7 || rollSum == 11)
    {
        // If sum is 7 or 11, player wins
        cout << "YOU ROLLED A " << rollSum << " ON THE FIRST ROLL AND WON!\n";
    }
    else if (rollSum == 2 || rollSum == 3 || rollSum == 12)
    {
        // If sum is 2, 3, or 12, player loses
        cout << "YOU ROLLED A " << rollSum << " ON THE FIRST ROLL AND LOST!\n";
    }
    else
    {
        // Otherwise, the sum is the player's point
        int point = rollSum;
        while (true)
        {
            cout << "Your point: " << point << endl;
            // Roll the dice until either 1) sum is the point (win)
            //      or 2) sum is 7 (lose)
            int rollSum = RollTwoDice(dice1, dice2);
            if (rollSum == 7)
            {
                cout << "YOU ROLLED A 7 AND LOST!\n";
                break;
            }
            else if (rollSum == point)
            {
                cout << "YOU ROLLED YOUR POINT AND WON!\n";
                break;
            }
        }
    }
}

int main()
{
    // Seed the random generator
    srand(time(NULL));

    cout << "Welcome to ASCII Craps!\n\n";

    while (true)
    {
        PlayRound();
        // Ask user to play again
        cout << "Do you want to play again? (y/n)\n";
        string playAgain;
        cin >> playAgain;
        cin.ignore();
        if (playAgain != "y")
        {
            break;
        }
        cout << "\n\n\n\n";
    }
}