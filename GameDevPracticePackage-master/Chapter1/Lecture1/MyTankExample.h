#pragma once

#include "Game2D.h"
#include <iostream>
#include <queue>
namespace jm {

    class MyCustomTank
    {
    public :
        vec2 center = vec2(0.0f , 0.0f);

    public:
        void draw()
        {
            beginTransformation();
            translate(center);
            drawFilledBox(Colors::red, 0.25f, 0.1f);
            translate(vec2(-0.05f, 0.1f));
            drawFilledBox(Colors::red, 0.15f, 0.1f);
            translate(vec2(0.1f, 0.0f));
            drawFilledBox(Colors::red, 0.3f, 0.025f);
            endTransformation();
        }

    };

    class MyCustomBullet
    {
    public :
        vec2 center = vec2(0.0f, 0.0f);
        vec2 velocity = vec2(0.0f, 0.0f);
    public :
        void draw()
        {
            beginTransformation();
            translate(center);
            drawFilledRegularConvexPolygon(Colors::yellow, 0.02f, 8);
            drawWiredRegularConvexPolygon(Colors::gray, 0.02f, 8);
            endTransformation();
        }

        void update(const float & dt)
        {
            center += velocity * dt;
        }
    };

    class MyTankExample : public Game2D
    {
        MyCustomTank tank;

        MyCustomBullet* bullet = nullptr;

        bool fire = true;

        std::vector<MyCustomBullet*> drum;

    public:
        MyTankExample()
            : Game2D("This is my digital canvas!", 1024, 768, false, 2)
        {}

        ~MyTankExample()
        {
            if (bullet != nullptr) delete bullet;

        }

        void update() override
        {
            // tank position setting
            if (isKeyPressed(GLFW_KEY_LEFT)) { tank.center.x -= 0.03f * getTimeStep();}
            if (isKeyPressed(GLFW_KEY_RIGHT)) { tank.center.x += 0.03f * getTimeStep(); }
            if (isKeyPressed(GLFW_KEY_UP)) { tank.center.y += 0.03f * getTimeStep(); }
            if (isKeyPressed(GLFW_KEY_DOWN)) { tank.center.y -= 0.03f * getTimeStep(); }

            if (isKeyPressed(GLFW_KEY_SPACE))
            {
                if (fire)
                {
                    MyCustomBullet* bullet = new MyCustomBullet;
                    // bullet position setting
                    bullet->center = tank.center;
                    bullet->center.x += 0.3f;
                    bullet->center.y += 0.1f;

                    // bullet velocity setting
                    bullet->velocity = vec2(1.2f, 0.0f);

                    if (drum.size() < 10)
                    {
                        drum.push_back(bullet);
                    }
                }
                fire = !fire;
            }

            //render
            tank.draw();
            
            for (unsigned i = 0; i < drum.size(); i++)
            {
                auto bullet = drum[i];
                if (bullet->center.x <= 1.5f)
                {   
                    bullet->update(getTimeStep());
                    bullet->draw();
                }
                else
                {
                    delete bullet;
                    drum.erase(drum.begin() + i);
                }
            }
        }
    };


}