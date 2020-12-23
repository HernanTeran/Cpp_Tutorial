#include <iostream>

void currentEnergy(int); //displays current energy
void running(int&); //makes statement, depletes energy
void walking(int&); //makes statement, increases energy
char getInput(); //gets your input
char validateInput(char&); //validates input
void drinkPotion(int&); //to drink or not to drink

int main()
{
    int runEnergy = 100;

    running(runEnergy);
    running(runEnergy);
    running(runEnergy);
    running(runEnergy);
    running(runEnergy);

    walking(runEnergy);
    walking(runEnergy);

    drinkPotion(runEnergy);

    running(runEnergy);

    return 0;
}

void currentEnergy(const int runEnergy)
{
    std::cout << "Current run energy: " << runEnergy << "\n\n";
}

void running(int& runEnergy)
{
    const int run = 25;

    if (runEnergy - run > 0)
    {
        runEnergy -= 25;
        std::cout << "Running...\n";
    }
    else
    {
        runEnergy = 0;
        std::cout << "You have no energy left to run!\n";
    }
    currentEnergy(runEnergy);
}

void walking(int& runEnergy)
{
    const int run = 25;
    if (runEnergy + run < 100)
    {
        runEnergy += run;
        std::cout
        << "Walking...\n";
    }
    else
    {
        runEnergy = 100;
        std::cout << "Your run energy is full.\n";
    }
    currentEnergy(runEnergy);
}

char validateInput(char& input)
{
    if (input == 'Y' || input == 'N')
    {
        return input;
    }
    else
    {
        std::cerr
        << "Error, input must be either Y or N!" << '\n'
        << "Your input: " << input << '\n'
        << "Try again.\n";

        std::cin.ignore();
        std::cin.get(input);

        return input;
    }
}

char getInput()
{
    char tempInput;

    std::cout << "Would you like to drink an energy potion? (Y/N)\n";
    std::cin.get(tempInput);

    return validateInput(tempInput);
}

void drinkPotion(int& runEnergy)
{
    char input = getInput();
    const int maxRun = 100;
    int currentRun = runEnergy,
                     restoredEnergy;

    if (input == 'Y')
    {
        restoredEnergy = maxRun - currentRun;
        runEnergy += restoredEnergy;
        std::cout
                << "Drinking potion...it restored " << restoredEnergy << " run energy!\n";
    }
    else if (input == 'N')
    {
        std::cout << "Did not drink energy potion.\n";
    }
    else
    {
        std::cerr
        << "Error, input still invalid.\n";
    }
    currentEnergy(runEnergy);
}
