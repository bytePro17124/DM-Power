/**
____________________________________________________________________________
>
>  https://github.com/bytePro17124/DM-Power-Core-Version
>
>  Program Created by Matthew Jay Early | @matthewjearly | matthewjearly@gmail.com
>  
>  Copyright (c) 2015-2017 Early Athens Tech Giants LLC. All rights reserved.
>
____________________________________________________________________________
**/

#include "gen_encounter.h"
#include "globalfuncts.h"
#include <iostream>
#include <cmath>

using namespace std;

Encounter::Encounter()
{
    ave_lvl = partysize = 0;
}

std::string Encounter::Gen_Encounter()
{
    set_party_level();

    int seed = (randomNumber(1, 5) - 3);

    //very easy, easy, average, hard, very hard
    if (testing)
        cout << "Seed (random difficulty changes CR anywhere from -2 to +2) is: " << seed << " (" << getDifficulty(seed) << ")\n";
    if (testing)
        cout << "Party size Difficulty Multiplier is set to: " << floor((partysize - 2) / 2) << "\n";
    if (testing)
        cout << "Average Party Level: " + toString(ave_lvl) << "\n\n";

    return ("Give Encounter of difficulty: " + getDifficulty(seed) + "\n" +
            " CR: " + toString(ave_lvl + seed + floor((partysize - 2) / 2)) + "\n");
    find_terrain();
}

void Encounter::set_party_level()
{

    ave_lvl = 0;
    int tmp(0);
    cout << "Enter the Total Number of party members (max=10): ";
    partysize = getNumber(1, 10);
    for (int i = 0; i < partysize; i++)
    {
        cout << "Enter level of party member #" << i + 1 << "(max=20):";
        tmp += getNumber(1, 20);
    }
    ave_lvl = floor(tmp / partysize);
}

void Encounter::find_terrain()
{
}

std::string Encounter::getDifficulty(const int &val)
{
    switch (val)
    {
    case -2:
        return "Very Easy";
    case -1:
        return "Easy";
    case 0:
        return "Average";
    case 1:
        return "Hard";
    case 2:
        return "Very Hard";
    default:
        return "Error in Difficulty Switch";
    }
}
