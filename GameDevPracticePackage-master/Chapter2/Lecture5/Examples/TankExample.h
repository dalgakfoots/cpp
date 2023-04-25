#pragma once

#include "Game2D.h"
#include <map>
//#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace jm
{
	class Actor
	{
	public:
		virtual void moveUp(float dt) = 0;
		virtual void moveDown(float dt) = 0;
		virtual void moveLeft(float dt) = 0;
		virtual void moveRight(float dt) = 0;
		virtual void space(float dt) = 0;
	};

	class Command
	{
	public:
		virtual ~Command() {}
		virtual void execute(Actor& actor, float dt) = 0;
	};

	// Commands

	class UpCommand : public Command 
	{
	public:
		virtual void execute(Actor& actor, float dt) override
		{
			actor.moveUp(dt);
		}
	};

	class DownCommand : public Command
	{
	public:
		virtual void execute(Actor& actor, float dt) override
		{
			actor.moveDown(dt);
		}
	};

	class LeftCommand : public Command
	{
	public:
		virtual void execute(Actor& actor, float dt) override
		{
			actor.moveLeft(dt);
		}
	};

	class RightCommand : public Command
	{
	public:
		virtual void execute(Actor& actor, float dt) override
		{
			actor.moveRight(dt);
		}
	};

	class SpaceCommand : public Command
	{
	public:
		virtual void execute(Actor& actor, float dt) override
		{
			actor.space(dt);
		}
	};

	class MyBullet
	{
	public:

		vec2 center = { 0.0f , 0.0f };
		vec2 velocity = { 0.0f , 0.0f };

		void draw()
		{
			beginTransformation();
			translate(center);
			drawFilledRegularConvexPolygon(Colors::yellow, 0.02f, 8);
			drawWiredRegularConvexPolygon(Colors::gray, 0.02f, 8);
			endTransformation();

		}


		void update(float dt)
		{
			center += velocity * dt;
		}
	};

	class MyTank : public Actor
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		//vec2 direction = vec2(1.0f, 0.0f, 0.0f);
		MyBullet* bullet = nullptr;

		~MyTank()
		{
			if (bullet != nullptr) delete bullet;
		}

		void moveUp(float dt) override
		{
			center.y += 0.025f * dt;
		}

		void moveDown(float dt) override
		{
			center.y -= 0.025f * dt;
		}

		void moveLeft(float dt) override
		{
			center.x -= 0.025f * dt;
		}

		void moveRight(float dt) override
		{
			center.x += 0.025f * dt;
		}

		void space(float dt) override
		{
			if (bullet == nullptr)
			{
				bullet = new MyBullet;
				bullet->center = this->center + vec2(0.2f, 0.1f);
				bullet->velocity = { 0.5f, 0.0f };
			}
		}

		void draw()
		{
			beginTransformation();
			{
				translate(center);
				drawFilledBox(Colors::green, 0.25f, 0.1f); // body
				translate(-0.02f, 0.1f);
				drawFilledBox(Colors::blue, 0.15f, 0.09f); // turret
				translate(0.15f, 0.0f);
				drawFilledBox(Colors::red, 0.15f, 0.03f);  // barrel
			}
			endTransformation();
		}
	};

	class InputHandler
	{
	public:
		Command * button_up = nullptr;

		std::map<int, Command *> key_command_map;

		InputHandler()
		{
			button_up = new UpCommand;
		}

		void handleInput(Game2D & game, Actor & actor, float dt)
		{
			//if (game.isKeyPressed(GLFW_KEY_UP))  button_up->execute(actor, dt);

			for (auto & m : key_command_map)
			{
				if (game.isKeyPressed(m.first)) m.second->execute(actor, dt);
			}
		}
	};

	class TankExample : public Game2D
	{
	public:
		MyTank tank;
		InputHandler input_handler;

	public:
		TankExample()
			: Game2D("This is my digital canvas!", 1024, 768, false, 2)
		{

			// load key-setting file
			std::ifstream ifs("key_binding.txt");

			if (!ifs)
			{
				//key mapping
				input_handler.key_command_map[GLFW_KEY_UP] = new UpCommand;
				input_handler.key_command_map[GLFW_KEY_DOWN] = new DownCommand;
				input_handler.key_command_map[GLFW_KEY_LEFT] = new LeftCommand;
				input_handler.key_command_map[GLFW_KEY_RIGHT] = new RightCommand;
			}
			else
			{
				
				while (ifs)
				{
					std::string str;
					getline(ifs, str);
					if (str.empty()) continue;
					std::stringstream ss(str);


					std::string temp;
					std::vector<std::string> v;
					while (getline(ss, temp, ' ')) {
						if (temp == "SPACE") temp = " ";
						v.push_back(temp);
					}

					//std::cout << (int)(v[0].c_str()[0]) << std::endl;
					input_handler.key_command_map[(int)(v[0].c_str()[0])] = getCommand(v[1]);
				}
			}
			
		}

		~TankExample()
		{
		}

		void update() override
		{
			// move tank
			/*if (isKeyPressed(GLFW_KEY_LEFT))	tank.center.x -= 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_RIGHT))	tank.center.x += 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_UP))		tank.center.y += 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_DOWN))	tank.center.y -= 0.5f * getTimeStep();*/

			input_handler.handleInput(*this, tank, getTimeStep());

			// update
			if (tank.bullet != nullptr) tank.bullet->update(getTimeStep());

			// rendering
			tank.draw();
			if (tank.bullet != nullptr)
			{
				if (tank.bullet->center.x >= 1.5f)
				{
					delete tank.bullet;
					tank.bullet = nullptr;
				}
				else
				{
					tank.bullet->draw();
				}
				
			}
				
		}
	private:
		Command* getCommand(const std::string& input)
		{
			if (input == "move_up") return new UpCommand;
			else if (input == "move_down") return new DownCommand;
			else if (input == "move_left") return new LeftCommand;
			else if (input == "move_right") return new RightCommand;
			else if (input == "shoot") return new SpaceCommand;
			else return nullptr;
		}
	};

	

}