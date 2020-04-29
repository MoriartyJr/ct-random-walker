#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Example : public olc::PixelGameEngine {
    public:
        Example() {
            sAppName = "Example";
        }

    public:
        bool OnUserCreate() override {
            // Called once at the start, so create things here
            return true;
        }

        bool OnUserUpdate(float fElapsedTime) override {
            Clear(olc::Pixel(71, 71, 82));
            
            FillRect(GetMouseX(), GetMouseY(), 1, 1);
            return true;
        }
};


int main(int argc, char const *argv[]) {
	Example demo;
	if (demo.Construct(100, 100, 4, 4))
		demo.Start();

	return 0;
}
