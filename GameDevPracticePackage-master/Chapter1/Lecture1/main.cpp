#include "Game2D.h"
#include "PrimitivesGallery.h"
#include "TankExample.h"
#include "FaceExample.h"
#include "WalkingPerson.h"
#include "SolarSystem.h"

// my example
#include "SolarExample.h"
#include "MyTankExample.h"

namespace jm
{
	class RotatingStarExample : public Game2D
	{
		float time = 0.0f;

	public:
		void update() override
		{
			rotate(time * 10.0f);
			drawFilledStar(Colors::gold, 0.4f, 0.25f);

			time += this->getTimeStep();
		}
	};

	class TransformationsExample : public Game2D
	{
	public :
		float time = 0;
		void update() override
		{
			// 1.
			////translation
			//const float dx = 0.1f;
			//const float dy = 0.2f;
			/*const vec2 p0(0.0f + dx, 0.0f + dy);
			const vec2 p1(0.5f + dx, 0.5f + dy);
			const vec2 p2(0.5f + dx, 0.0f + dy);*/


			// 2.
			/*beginTransformation();

			translate(0.1f, 0.0f); // 점의 좌표가 아닌 공간 (좌표계) 자체가 translate 된다.

			const vec2 p0(0.0f, 0.0f );
			const vec2 p1(0.5f, 0.5f );
			const vec2 p2(0.5f, 0.0f );

			drawLine(Colors::red, p0, Colors::blue , p1);
			drawLine(Colors::red, p1, Colors::blue, p2);
			drawLine(Colors::red, p2, Colors::blue, p0);

			endTransformation();

			translate(-0.1f, 0.0f);

			drawLine(Colors::red, p0, Colors::blue, p1);
			drawLine(Colors::red, p1, Colors::blue, p2);
			drawLine(Colors::red, p2, Colors::blue, p0);*/

			// 3.
			/*setLineWidth(3.0f);
			drawWiredBox(Colors::gold, 0.5f, 0.25f);

			beginTransformation();
			rotate(30.0f);
			drawWiredBox(Colors::skyblue, 0.5f, 0.25f);
			endTransformation();

			beginTransformation();
			translate(0.25f, 0.0f);
			rotate(30.0f);
			drawWiredBox(Colors::red, 0.5f, 0.25f);
			endTransformation();

			beginTransformation();
			rotate(30.0f);
			translate(0.25f, 0.0f);
			drawWiredBox(Colors::blue, 0.5f, 0.25f);
			endTransformation();*/

			// 4.
			/*setLineWidth(3.0f);

			const vec2 center_of_rotation(-0.4f, 0.0f);

			drawWiredBox(Colors::skyblue, 0.5f, 0.25f);

			translate(center_of_rotation);
			rotate(45.0f);
			translate(-center_of_rotation);
			

			drawWiredBox(Colors::gold, 0.5f, 0.25f);
			drawPoint(Colors::black, center_of_rotation, 3.0f);*/

			// 5.
			/*setLineWidth(3.0f);

			
			rotate(time * 10.0f);
			translate(0.5f, 0.0f);
			rotate(time * 10.0f);
			scale(2.0f, 0.25f);
			drawWiredBox(Colors::gold, 0.5f, 0.5f);

			time += this->getTimeStep();*/
		}
	};

	class MouseExample : public Game2D
	{
	public :
		void update() override
		{

			const vec2 mouse_pos = getCursorPos();

			if (isMouseButtonPressed(GLFW_MOUSE_BUTTON_1 == true))
			{
				beginTransformation();
				translate(mouse_pos);
				drawFilledCircle(Colors::gold, 0.1f);
				endTransformation();
			}

			if (isMouseButtonPressed(GLFW_MOUSE_BUTTON_2 == true))
			{
				beginTransformation();
				translate(mouse_pos);
				drawFilledCircle(Colors::red, 0.1f);
				endTransformation();
			}
		}
	};

}

int main(void)
{
	// 1-2
	//jm::TransformationsExample().run();
	//jm::SolarExample().run();

	// 1-3
	//jm::TankExample().run();
	//jm::MyTankExample().run();
	//jm::WalkingPerson().run();

	// 1-4
	jm::MouseExample().init("Mouse Example", 1000, 1000, false).run();


	//jm::MouseExample().init("This is my digital canvas!", 1000, 1000, false).run();
	//jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	
	//jm::PrimitivesGallery().init("Primitive Gallery", 1280, 960, false).run();
	//jm::SolarSystem().run();
	


	return 0;
}
