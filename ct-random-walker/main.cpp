#define OLC_PGE_APPLICATION

#include <iostream>
#include <vector>

#include "olcPixelGameEngine.h"
#include "walker.h"

class RandomWalker : public olc::PixelGameEngine {
public:
    int r;
    std::vector<Walker> vecWalker;
    
    RandomWalker()
    {
        sAppName = "RandomWalker";
    }
    
protected:
    
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
        
        r = rand() % 4;
        
        switch (r) {
            case 0:
                walker.SetCoord(walker.GetCoord().x + 1, walker.GetCoord().y);
                break;
            case 1:
                walker.SetCoord(walker.GetCoord().x - 1, walker.GetCoord().y);
                break;
            case 2:
                walker.SetCoord(walker.GetCoord().x, walker.GetCoord().y + 1);
                break;
            case 3:
                walker.SetCoord(walker.GetCoord().x, walker.GetCoord().y - 1);
                break;
            default:
                break;
        }
        return;
    }
    
    bool OnUserCreate() override
    {
        // Called once at the start, so create things here
        Clear(olc::Pixel(74, 72, 69));
        
        vecWalker.push_back(Walker());
        
        return true;
    }
    
    bool OnUserUpdate(float fElapsedTime) override
    {
        for (auto &w : vecWalker)
        {
            FillRect(
                     w.GetCoord().x,
                     w.GetCoord().y,
                     w.GetSize(),
                     w.GetSize(),
                     olc::Pixel(
                                w.GetColor().red,
                                w.GetColor().green,
                                w.GetColor().blue
                                )
                     );
            
            randomizedDirection(w);
            
            correctOutOfBounce(w);
        }
        
        return true;
    }
};


int main(int argc, char const *argv[])
{
    RandomWalker demo;
    if (demo.Construct(400, 400, 1, 1))
        demo.Start();
    
    return 0;
}
