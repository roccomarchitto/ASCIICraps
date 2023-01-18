#ifndef DICE
#define DICE

using namespace std;

class Dice
{
public:
    int RollDice();

private:
    string DiceFrame(int);
    string AppendDots(int, int, string, int[]);
};

#endif