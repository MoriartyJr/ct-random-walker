//
//  walker.cpp
//  ct-random-walker
//
//  Created by Antonio Lombardi on 29.04.20.
//  Copyright © 2020 Antonio Lombardi. All rights reserved.
//
#include <iostream>
#include <vector>
#include <math.h>

#include "walker.h"

Walker::Walker(int x, int y)
{
    Walker::SetCoord({x, y});
    Walker::SetColor({rand() % 255, rand() % 255, rand() % 255});
    Walker::SetSize(1);
    Walker::SetType(0);
    Walker::vecStepTree.push_back({x, y});
    return;
}

Walker::Walker(int x, int y, int red, int green, int blue, int size, int type)
{
    Walker::SetCoord(x, y);
    Walker::SetColor(red, green, blue);
    Walker::SetSize(size);
    Walker::SetType(type);
    Walker::vecStepTree.push_back({x, y});
    return;
};

Walker::Walker(sCoord coord, sColor color, int size, int type)
{
    Walker::SetCoord(coord);
    Walker::SetColor(color);
    Walker::SetSize(size);
    Walker::SetType(type);
    Walker::vecStepTree.push_back({x, y});
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
        case 2:
            DiffusionStep();
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

bool Walker::IsInCircle(int circleX, int circleY, int rad, int pointX, int pointY)
{
    if ((pointX - circleX) * (pointX - circleX) + (pointY - circleY) * (pointY - circleY) <= rad * rad) {
        return true;
    }
    else
    {
        return false;
    }
};

void Walker::DiffusionStep()
{
    int height = 600;
    int width = 600;
    int upperLimitX = 0;
    int lowerLimitX = width;
    int upperLimitY = 0;
    int lowerLimitY = height;
    int dirStepX = 0;
    int dirStepY = 0;
    
    bool collision = false;
    
    for (auto &tree : vecStepTree) {
        if (tree.x + 10 > upperLimitX) {
            upperLimitX = tree.x + 10;
        }
        if (tree.x - 10 < lowerLimitX) {
            lowerLimitX = tree.x - 10;
        }
        if (tree.y + 10 > upperLimitY) {
            upperLimitY = tree.y + 10;
        }
        if (tree.y - 10 < lowerLimitY) {
            lowerLimitY = tree.y - 10;
        }
    }
    
    dirStepX = (upperLimitX - lowerLimitX) * sin(2*3.14*random()) + width/2;
    dirStepY = (upperLimitY - lowerLimitY) * cos(2*3.14*random()) + height/2;
    
    while (IsInCircle(width/2, height/2, upperLimitX - lowerLimitX -20, dirStepX, dirStepY)) {
        dirStepX = (upperLimitX - lowerLimitX) * sin(2*3.14*random()) + width/2;
        dirStepY = (upperLimitY - lowerLimitY) * cos(2*3.14*random()) + height/2;
    }
    
    stepDir = { dirStepX, dirStepY };
    
    for (auto &tree : vecStepTree)
    {
        if (stepDir.x <= (tree.x + GetSize()*2) && stepDir.x >= (tree.x - GetSize()*2)) {
            if (stepDir.y <= (tree.y + GetSize()*2) && stepDir.y >= (tree.y - GetSize()*2)) {
                collision = true;
            }
        }
    }
    
    if (collision) {
        SetCoord(stepDir);
        vecStepTree.push_back(stepDir);
    }
    
    return;
};
