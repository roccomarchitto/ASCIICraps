#include <iostream>
#include <string>
#include <ctime>

#include "Dice.h"

using namespace std;

// Dice dot patterns
// Note DotPatterns[0] is a row of zeros
// This lets DotPatterns[n] correspond to dice face n
int DotPatterns[7][9] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1, 0, 1}};

int Dice::RollDice()
{
    // Generate random dice roll, print the roll, and return the value
    int roll = (rand() % 6) + 1;

    cout << "You rolled...\n";

    // Generate the dice frame string
    int DICE_SIZE = 11; // TODO some values give exceptions
    string base_ascii = DiceFrame(DICE_SIZE);

    // Generate and print the dice roll by filling in the frame
    // TODO document
    string roll_ascii = AppendDots(1, DICE_SIZE, base_ascii, DotPatterns[roll]);
    cout << roll_ascii << endl;
    return roll;
}

string Dice::AppendDots(int n, int length, string frame, int dots[9])
{
    // Appends the dot pattern to a dice frame, returns the dice string of the dot pattern
    // Note dot patterns are size 9 arrays that move left to right
    // For example dots = {1,0,1,1,0,1,1,0,1} species a dice roll of 6

    int inner_length = length / 3;               // Spacing between dot positions horizontally
    int line_skip = (length / 2) / 3 + 1;        // Vertical distance (number of lines) to skip for next line of dots
    int start = length + 2 + (inner_length / 2); // The first non-side position

    // Generate an array of size 9 that corresponds to the index of the nth dot
    int dot_idx[9];
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            int idx = start + i * inner_length;
            dot_idx[j * 3 + i] = idx;
        }
        start = start + line_skip * (length + 1);
    }

    // For each 1 entry in the dots array, append a dot in the correct spot
    for (int i = 0; i < 9; i++)
    {
        if (dots[i] == 1)
        {
            frame.replace(dot_idx[i], 1, "o");
        }
    }

    return frame;
}

string Dice::DiceFrame(int length)
{
    // Return a string of the basic frame of a dice

    string diceframe = "";

    // Top
    for (int i = 0; i < length; i++)
    {
        diceframe += "_";
    }
    // Sides
    for (int i = 0; i < length / 2; i++)
    {
        diceframe += "\n";
        diceframe += "|";
        for (int i = 0; i < length - 2; i++)
        {
            diceframe += " ";
        }
        diceframe += "|";
    }
    diceframe += "\n";
    // Top
    for (int i = 0; i < length; i++)
    {
        diceframe += "-";
    }

    return diceframe;
}