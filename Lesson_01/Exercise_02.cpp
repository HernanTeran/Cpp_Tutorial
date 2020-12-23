#include <iostream>

void currentEnergy(int); //displays current energy
void running(int&); //makes statement, depletes energy
void walking(int&); //makes statement, increases energy
char getInput(); //gets your input
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
    if (runEnergy > 0)
    {
        runEnergy -= 25;
        std::cout << "Running...\n";
    }
    else
    {
        std::cout << "You have no energy left to run!\n";
    }
    currentEnergy(runEnergy);
}

void walking(int& runEnergy)
{
    runEnergy += 25;
    std::cout
    << "Walking...\n";
    currentEnergy(runEnergy);
}

char getInput()
{
    char tempInput;

    std::cout << "Would you like to drink an energy potion? (Y/N)\n";
    std::cin.get(tempInput);

    return tempInput;
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
    else
    {
        std::cout << "Did not drink energy potion.\n";
    }
    currentEnergy(runEnergy);
}
