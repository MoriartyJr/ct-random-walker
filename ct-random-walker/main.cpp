#define OLC_PGE_APPLICATION

#include <iostream>
#include <ios>
#include <vector>

#include "olcPixelGameEngine.h"
#include "walker.h"

class RandomWalker : public olc::PixelGameEngine {
public:
    int levyRand;
    int stepSizeX;
    int stepSizeY;
    float timer;
    
    struct sPos
    {
        int x;
        int y;
    };
    
    struct Color {
        int red;
        int green;
        int blue;
    };
    
    sPos stepTo;
    
    std::vector<Walker> vecWalker;
    std::vector<Walker::sColor> vecPalette;
    
    RandomWalker()
    {
        sAppName = "RandomWalker";
    }
    
protected:
    
    void InitpPalette()
    {
        vecPalette.push_back(Walker::sColor(0xABDEE6));
        vecPalette.push_back(Walker::sColor(0xCBAACB));
        vecPalette.push_back(Walker::sColor(0xFFFFB5));
        vecPalette.push_back(Walker::sColor(0xFFCCB6));
        vecPalette.push_back(Walker::sColor(0xF3B0C3));
        
        vecPalette.push_back(Walker::sColor(0xC6DBDA));
        vecPalette.push_back(Walker::sColor(0xFEE1E8));
        vecPalette.push_back(Walker::sColor(0xFED7C3));
        vecPalette.push_back(Walker::sColor(0xF6EAC2));
        vecPalette.push_back(Walker::sColor(0xECD5E3));
        
        vecPalette.push_back(Walker::sColor(0xFF968A));
        vecPalette.push_back(Walker::sColor(0xFFAEA5));
        vecPalette.push_back(Walker::sColor(0xFFC5BF));
        vecPalette.push_back(Walker::sColor(0xFFD8BE));
        vecPalette.push_back(Walker::sColor(0xFFC8A2));
        
        vecPalette.push_back(Walker::sColor(0xD4F0F0));
        vecPalette.push_back(Walker::sColor(0x8FCACA));
        vecPalette.push_back(Walker::sColor(0xCCE2CB));
        vecPalette.push_back(Walker::sColor(0xB6CFB6));
        vecPalette.push_back(Walker::sColor(0x97C1A9));
        
        vecPalette.push_back(Walker::sColor(0xFCB9AA));
        vecPalette.push_back(Walker::sColor(0xFFCBCC));
        vecPalette.push_back(Walker::sColor(0xECEAE4));
        vecPalette.push_back(Walker::sColor(0xA2E1DB));
        vecPalette.push_back(Walker::sColor(0x55CBCD));
        
        return;
    }
    
    void correctOutOfBounce(Walker &walker)
    {
        int x = walker.GetCoord().x;
        int y = walker.GetCoord().y;
        
        if (x < 0)
            x = 0;
        if (x > ScreenWidth())
            x = ScreenWidth();
        if (y < 0)
            y = 0;
        if (y > ScreenHeight())
            y = ScreenHeight();
        
        walker.SetCoord(x, y);
        
        return;
    }
    
    void randomizedDirection(Walker &walker) {
        
        stepSizeX = 1;
        stepSizeY = 1;
        levyRand = rand() % 100;
        stepTo = {(rand() % 3)-1, (rand() % 3)-1};
        
        if (levyRand < 1) {
            stepSizeX = (rand() % 25) + 5;
            stepSizeY = (rand() % 25) + 5;
        }
        
        walker.SetCoord(walker.GetCoord().x + (stepTo.x * stepSizeX), walker.GetCoord().y + (stepTo.y * stepSizeY));
        
        return;
    }
    
    bool OnUserCreate() override
    {
        // Called once at the start, so create things here
        timer = 0;
        
        InitpPalette();
        
        Clear(olc::Pixel(74, 72, 69));
        
        vecWalker.push_back(Walker({ScreenWidth() / 2, ScreenHeight() / 2}, vecPalette.at(1), 1, "default"));
        
        return true;
    }
    
    bool OnUserUpdate(float fElapsedTime) override
    {
        timer += fElapsedTime;
        
        if (timer >= 10.0F) {
            vecWalker.push_back(Walker({rand() % ScreenWidth(), rand() % ScreenHeight()}, vecPalette.at(rand() % vecPalette.size()), 1, "default"));
            timer = 0;
        }
        
        for (auto &w : vecWalker)
        {
            Walker prevWalker = w;
            
            randomizedDirection(w);
            correctOutOfBounce(w);
            
            FillCircle(w.GetCoord().x, w.GetCoord().y, w.GetSize(),
                       olc::Pixel(
                                  w.GetColor().red,
                                  w.GetColor().green,
                                  w.GetColor().blue
                                  )
                       );
            
            DrawLine(prevWalker.GetCoord().x, prevWalker.GetCoord().y, w.GetCoord().x, w.GetCoord().y,
                     olc::Pixel(
                                w.GetColor().red,
                                w.GetColor().green,
                                w.GetColor().blue
                                ));
        }
        
        return true;
    }
};


int main(int argc, char const *argv[])
{
    RandomWalker demo;
    if (demo.Construct(600, 600, 1, 1))
        demo.Start();
    
    return 0;
}
