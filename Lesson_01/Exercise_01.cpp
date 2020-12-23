#include <iostream>
#include <string>

void examine(const std::string&);

int main()
{
    std::string goblin = "Goblin";
    examine(goblin);

    std::string hillGiant = "Hill Giant";
    examine(hillGiant);

    std::string lesserDemon = "Lesser Demon";
    examine(lesserDemon);

    std::string greaterDemon = "Greater Demon";
    examine(greaterDemon);
    
    return 0;
}

void examine(const std::string& npc)
{
    if (npc == "Goblin")
    {
        std::cout << "An ugly green creature.\n";
    }
    else if (npc == "Hill Giant")
    {
        std::cout << "A very large foe.\n";
    }
    else if (npc == "Lesser Demon")
    {
        std::cout << "Lesser, but still pretty big.\n";
    }
    else
    {
        std::cout << "Only 3 NPCs exist at the moment.\n";
    }
}
