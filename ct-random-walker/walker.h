//
//  walker.h
//  ct-random-walker
//
//  Created by Antonio Lombardi on 29.04.20.
//  Copyright © 2020 Antonio Lombardi. All rights reserved.
//

#ifndef walker_h
#define walker_h

#include <iostream>
#include <vector>
#include <stdio.h>

class Walker
{
private:
    int x;
    int y;
    int red;
    int green;
    int blue;
    int size;
    std::string type;
    
public:
    struct sCoord {
        int x;
        int y;
    };
    
    struct sColor {
        int red;
        int green;
        int blue;
        
        sColor(int colorCode)
        {
            this->red = colorCode >> 16;
            this->green = (((colorCode >> 8) << 8) - ((colorCode >> 16) << 16)) >> 8;
            this->blue = (colorCode) - ((colorCode >> 8) << 8);
        };
        
        sColor(int red, int green, int blue)
        {
            this->red = red;
            this->green = green;
            this->blue = blue;
        }
    };
    
    Walker(int x, int y);
    Walker(int x, int y, int red, int green, int blue, int size, std::string type);
    Walker(sCoord coord, sColor color, int size, std::string type);
    
    void SetCoord(int x, int y)
    {
        this->x = x;
        this->y = y;
    };
    
    void SetCoord(sCoord coord)
    {
        this->x = coord.x;
        this->y = coord.y;
    }
    
    void SetColor(int red, int green, int blue)
    {
        this->red = red;
        this->green = green;
        this->blue = blue;
    };
    
    void SetColor(sColor color)
    {
        this->red = color.red;
        this->green = color.green;
        this->blue = color.blue;
    };
    
    void SetSize(int size)
    {
        this->size = size;
    }
    
    void SetType(std::string type)
    {
        this->type = type;
    };
    
    sCoord GetCoord()
    {
        return {x, y};
    };
    
    sColor GetColor()
    {
        return sColor(red, green, blue);
    };
    
    int GetSize()
    {
        return size;
    };
    
};

#endif /* walker_h */
