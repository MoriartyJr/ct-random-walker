//
//  walker.cpp
//  ct-random-walker
//
//  Created by Antonio Lombardi on 29.04.20.
//  Copyright © 2020 Antonio Lombardi. All rights reserved.
//
#include <iostream>
#include <vector>

#include "walker.h"

Walker::Walker(int x, int y)
{
    Walker::SetCoord({x, y});
    Walker::SetColor({rand() % 255, rand() % 255, rand() % 255});
    Walker::SetSize(1);
    Walker::SetType(0);
    return;
}

Walker::Walker(int x, int y, int red, int green, int blue, int size, int type)
{
    Walker::SetCoord(x, y);
    Walker::SetColor(red, green, blue);
    Walker::SetSize(size);
    Walker::SetType(type);
    return;
};

Walker::Walker(sCoord coord, sColor color, int size, int type)
{
    Walker::SetCoord(coord);
    Walker::SetColor(color);
    Walker::SetSize(size);
    Walker::SetType(type);
    return;
};

void Walker::TakeRandomStep()
{
    switch (type) {
        case 0:
            DefaultStep();
            break;
        case 1:
            LevyStep();
            break;
        default:
            break;
    }
    return;
};

void Walker::DefaultStep()
{
    stepDir = { (rand() % 3) - 1, (rand() % 3) - 1 };
    SetCoord(GetCoord().x + stepDir.x, GetCoord().y + stepDir.y);
    return;
};

void Walker::LevyStep()
{
    stepDir = { (rand() % 3) - 1, (rand() % 3) - 1 };
    
    int levyRand = rand() % 100;
    int stepSizeX = (rand() % 25) + 5;
    int stepSizeY = (rand() % 25) + 5;
    
    if (levyRand < 1) {
        stepDir.x *= stepSizeX;
        stepDir.y *= stepSizeY;
    }
    
    SetCoord(GetCoord().x + stepDir.x, GetCoord().y + stepDir.y);
    return;
};
