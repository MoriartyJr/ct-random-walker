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

Walker::Walker()
{
    Walker::SetCoord({200, 200});
    Walker::SetColor({255, 255, 255});
    Walker::SetSize(4);
    Walker::SetType("default");
    return;
}

Walker::Walker(int x, int y, int red, int green, int blue, int size, std::string type)
{
    Walker::SetCoord(x, y);
    Walker::SetColor(red, green, blue);
    Walker::SetSize(size);
    Walker::SetType(type);
    return;
};

Walker::Walker(sCoord coord, sColor color, int size, std::string type)
{
    Walker::SetCoord(coord);
    Walker::SetColor(color);
    Walker::SetSize(size);
    Walker::SetType(type);
    return;
};
