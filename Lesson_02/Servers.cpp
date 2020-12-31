//
// Created by Hernan Teran on 12/31/20.
//

#include "Servers.h"
#include <random> /* used to generate random numbers */
#include <iostream> /* used to overload the insertion/extraction operators */

/* default constructor
 *
 * initialized to 1 but then uses a random number generator
 * to assign a value
 */
Servers::Servers() : world(1), currentMember(false)
{
    world = randWorld();
}

/*
 * user-defined constructor
 *
 * validated by exception class
 */
Servers::Servers(unsigned int worldRequest, bool isMember) : world(worldRequest), currentMember(isMember)
{
    world = validateWorld(worldRequest);
}

/*
 * @getWorld
 *
 * getter for the world variable
 */
unsigned int Servers::getWorld() const
{
    return world;
}

/*
 * @setWorld
 *
 * setter for world variable
 * validated by exception class
 */
void Servers::setWorld(unsigned int w)
{
    Servers::world = validateWorld(w);
}

/*
 * @randWorld
 *
 * sets a random world for the user
 * in the default constructor
 *
 * has its own logic to assign free/member world
 */
unsigned int Servers::randWorld()
{
    /* Generating Random Numbers */
    std::random_device rd;  /* will be used to obtain a seed for the random number engine */
    std::mt19937 gen(rd()); /* standard mersenne_twister_engine seeded with rd() */
    std::uniform_int_distribution<> random_world_non(1, 148); /* range of random numbers (1 - 148) */
    std::uniform_int_distribution<> random_world_mem(149, 300); /* range of random numbers (149 - 300) */

    /* ternary operator */
    world = currentMember ? random_world_mem(gen) : random_world_non(gen);

    return world;
}

/*
 * @validateWorld
 *
 * throws an exception if conditions aren't met
 * returns world if no exception
 */
unsigned int Servers::validateWorld(unsigned int worldRequest)
{
    unsigned int currentWorld = this->world;

    if (!currentMember && worldRequest > 148)
    {
        world = currentWorld;
        throw MembersOnly(worldRequest);
    }
    return worldRequest;
}

/*
 * @ostream
 *
 * instead of writing out std::cout << object.getWorld();
 * now it'll just be std::cout << object;
 */
std::ostream &operator << (std::ostream &strm, const Servers &obj)
{
    strm << "[Currently in World " << obj.getWorld() << "]\n";
    return strm;
}

/*
 * @istream
 *
 * instead od writing std::cin >> variable;
 * now it'll just be std::cin >> object;
 *
 * validated by setter function
 *
 * if successful then the requested world
 * will be assigned to the world variable
 *
 * otherwise the world will remain the same
 * and the extraction operator won't return
 * what was inputted
 */
std::istream &operator >> (std::istream &strm, Servers &obj)
{
    std::cout
    << "[Free worlds 1-148]\t[Member worlds 149-300]\n"
    << "Join World: ";

    strm >> obj.world;

    std::cout << '\n';

    unsigned int worldRequest = obj.world;
    obj.setWorld(worldRequest);

    return strm;
}

/*
 * @MembersOnly
 *
 * exception class that validates a requested world
 * based off of membership
 */
Servers::MembersOnly::MembersOnly(unsigned int world) : world(world) {}

/*
 * @getWorld
 *
 * getter for the MembersOnly class that returns the invalid world
 */
unsigned int Servers::MembersOnly::getWorld() const
{
    return world;
}