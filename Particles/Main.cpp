#include <iostream>
#include <SDL.h>
#include <Math.h>
#include<time.h>
#include "Screen.h"
#include "Swarm.h"
using namespace std;
using namespace vaibhav;

int main(int argc, char* args[])
{
    srand(time(NULL));

    Screen screen;
    if (screen.init() == false) {
        cout << "Error intialsing SDL" << endl;
    }

    Swarm swarm;
    
    
    while (true) {
        int elapsed = SDL_GetTicks();

        swarm.update(elapsed);

        unsigned char green = (unsigned char)((1 + sin(elapsed*0.0001) * 128));
        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002) * 128));
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003) * 128));

    
        const Particles* const pParticles = swarm.getParticles();
        for (int i = 0; i < Swarm::NPARTICLES; i++) {

            Particles particles = pParticles[i];

            int x = (particles.m_x + 1) * Screen::SCREEN_WIDTH / 2;
            int y = particles.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2;

            screen.setPixel(x, y, red, green, blue);
        }

        screen.boxBlur();

        screen.update();

        if (screen.processEvents() == false)
        {
            break;
        }
        }

    screen.close();
    return 0;
}
