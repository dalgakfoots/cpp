#pragma once

#include "Game2D.h"
#include <iostream>
namespace jm
{
    class SolarExample : public Game2D
    {
        float time = 0.0f;
        public :
            void update() override
            {
                drawSun();
                drawEarth();
            }

            void drawSun()
            {
                beginTransformation();
                rotate(time * 1.0f);
                drawFilledStar(Colors::red, 0.4f, 0.2f);
                endTransformation();
            }

            void drawEarth()
            {
                beginTransformation();
                rotate(time * 2.0f);
                const vec2 earth_point(0.7f, 0.0f);
                translate(earth_point);
                drawFilledCircle(Colors::green, 0.1f);

                drawMoon();

                time += this->getTimeStep();
                endTransformation();
            }

            void drawMoon()
            {
                rotate(time * 3.0f);
                const vec2 moon_point(0.2f , 0.0f);
                translate(moon_point);
                drawFilledCircle(Colors::yellow, 0.05f);

            }
    };
}