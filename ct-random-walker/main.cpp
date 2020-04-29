#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class RandomWalker : public olc::PixelGameEngine {
public:
    int x;
    int y;
    int r;
    
    RandomWalker()
    {
        sAppName = "RandomWalker";
    }

protected:
    
    void correctOutOfBounce()
    {
        if (x < 0)
            x = 0;
        if (x > ScreenWidth())
            x = ScreenWidth();
        if (y < 0)
            y = 0;
        if (y > ScreenHeight())
            y = ScreenHeight();
        
        return;
    }
    
    void randomizedDirection() {
        
        r = rand() % 4;
        
        switch (r) {
            case 0:
                x++;
                break;
            case 1:
                x--;
                break;
            case 2:
                y++;
                break;
            case 3:
                y--;
                break;
            default:
                break;
        }
        return;
    }
    
    bool OnUserCreate() override
    {
        // Called once at the start, so create things here
        x = 200;
        y = 200;
        
        Clear(olc::Pixel(74, 72, 69));
        
        return true;
    }
    
    bool OnUserUpdate(float fElapsedTime) override
    {
        FillRect(x, y, 4, 4);
        
        randomizedDirection();
        
        correctOutOfBounce();
        
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
