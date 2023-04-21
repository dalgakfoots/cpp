#pragma once

#include "Game2D.h"
#include <vector>
#include <iostream>
namespace jm
{

	class Person
	{
		float time = 0.0f;
		vec2 init_vec;
		bool action = false;

	public :
		Person(vec2 in_vec) : init_vec(in_vec)
		{
		}

	public :
		void draw()
		{
			beginTransformation();
			translate(init_vec);

			// gold face
			beginTransformation();
			translate(0.0f, 0.12f);
			drawFilledCircle(Colors::gold, 0.08f);
			translate(0.05f, 0.03f);
			drawFilledCircle(Colors::white, 0.01f); // while eye

			endTransformation();

			// yellow arm
			beginTransformation();
			rotate(sin(time * 0.25f) * -30.0f);					// animation!
			scale(1.0f, 2.0f);
			translate(0.0f, -0.1f);
			drawFilledBox(Colors::yellow, 0.05f, 0.18f);
			endTransformation();

			// red body
			beginTransformation();
			scale(1.0f, 2.0f);
			translate(0.0f, -0.1f);
			drawFilledBox(Colors::red, 0.13f, 0.2f);
			endTransformation();

			// yellow arm
			beginTransformation();
			if (action)
			{
				rotate(90.0f);					// animation!
			} 
			else
			{
				rotate(sin(time * 0.25f) * 30.0f);					// animation!
			}
			scale(1.0f, 2.0f);
			translate(0.0f, -0.1f);
			drawFilledBox(Colors::yellow, 0.05f, 0.18f);
			endTransformation();

			// green leg
			beginTransformation();
			translate(0.0f, -0.6f);
			translate(0.0f, 0.2f);
			rotate(sinf(time * 0.25f + 3.141592f) * 30.0f);	// animation!
			translate(0.0f, -0.2f);
			drawFilledBox(Colors::green, 0.1f, 0.4f);
			endTransformation();

			// green leg
			beginTransformation();
			translate(0.0f, -0.6f);
			translate(0.0f, 0.2f);
			rotate(sinf(time * 0.25f + 3.141592f) * -30.0f);	// animation!
			translate(0.0f, -0.2f);
			drawFilledBox(Colors::green, 0.1f, 0.4f);
			endTransformation();
			endTransformation();
		}

		void update(const float& dt)
		{
			time += dt;
		}

		void toggleAction(const bool in_action)
		{
			action = in_action;
		}
	};


	class RepulsorBeam
	{
		bool action = false;

	public :

		void draw()
		{
			if (action)
			{
				beginTransformation();
				translate(vec2(0.8f, 0.0f));
				drawFilledBox(Colors::skyblue, 1.0f, 1.0f);
				endTransformation();
				
			}
		}

		void toggleAction(const bool in_action)
		{
			action = in_action;
		}
	};

	/*
	TODO:
	- add left arm and left leg
	- make a Person class and use it to draw many people.
	- make an Ironman and allow for him to shoot repulsor beam with his right hand
	*/

	class WalkingPerson : public Game2D
	{
		//Person p{ vec2(0.5f , 0.5f) };
		std::vector<Person> v_people;
		RepulsorBeam b;
	public :
		WalkingPerson()
		{
			makePeople(3);
		}
	public:
		void update() override
		{
			if (isKeyPressed(GLFW_KEY_SPACE))
			{
				v_people[0].toggleAction(true);
				b.toggleAction(true);
			}
			else {
				v_people[0].toggleAction(false);
				b.toggleAction(false);
			}


			v_people[0].update(getTimeStep());
			v_people[0].draw();
			b.draw();
		}

		void makePeople(const unsigned in_u)
		{
			/*for (unsigned i = 0; i < in_u; i++)
			{
				Person p = Person{ vec2(in_u / 10 , in_u / 10) };
				v_people.push_back(p);
			}*/
			Person p = Person{ vec2(0.0f , 0.0f) };
			Person p1 = Person{ vec2(0.4f , 0.4f) };
			Person p2 = Person{ vec2(-0.2f , -0.2f) };
			v_people.push_back(p);
			v_people.push_back(p1);
			v_people.push_back(p2);

		}
	};
}