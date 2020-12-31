//
// Created by Hernan Teran on 12/31/20.
//

#ifndef CPP_PRACTICE_SERVERS_H
#define CPP_PRACTICE_SERVERS_H
#include <iostream>

/*
 * The Servers class represents worlds in RuneScape.
 *
 * A world can be chosen at random or the user can
 * choose their own world (1-300).
 *
 * The invariant is that they must be a member to join worlds 149-300.
 *
 * Otherwise they will get an error message and
 * either remain in the same world or remain in the lobby.
 */

class Servers
{
private:
    /* member variables */
    unsigned int world;
    /* invariant */
    bool currentMember;

    /* private member function */
    unsigned int randWorld();
    unsigned int validateWorld(unsigned int);

public:
    /* default constructor */
    Servers();

    /* constructor with 1 parameter */
    explicit Servers(unsigned int, bool);

    /* exception class */
    class MembersOnly
    {
    private:
        unsigned int world;

    public:
        /* explicit prevents implicit conversions between constructors */
        explicit MembersOnly(unsigned int);

        unsigned int getWorld() const;

    };

    /* setter/getter for a world */
    void setWorld(unsigned int);
    unsigned int getWorld() const;

    /* overloading the insertion operator ( << ) */
    friend std::ostream &operator << (std::ostream &strm, const Servers &obj);

    /* overloading the extraction operator ( >> ) */
    friend std::istream &operator >> (std::istream &strm, Servers &obj);

};

#endif //CPP_PRACTICE_SERVERS_H