#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include <vector>
#include <memory>

//#include "Triangle.h"
//#include "Circle.h"
//#include "Box.h"
#include "GeometricObject.h"

namespace jm
{


	class Example : public Game2D
	{
	public:


		std::vector<GeometricObject *> my_objs;
		Example()
			: Game2D()
		{
			/*auto my_triangle = new Triangle(Colors::gold, vec2{ -0.5f , 0.2f }, 0.25f);
			auto my_circle = new Circle(Colors::skyblue, vec2{ 0.2f , 0.2f }, 0.25f);
			auto my_box = new Box(Colors::black, vec2{ 0.5f , 0.5f }, 0.25f, 0.25f);

			my_objs.push_back(my_triangle);
			my_objs.push_back(my_circle);
			my_objs.push_back(my_box);*/

			my_objs.push_back(GeometricObject::makeTriangle(Colors::gold, vec2{ -0.5f , 0.2f }, 0.25f));
			my_objs.push_back(GeometricObject::makeCircle(Colors::red, vec2{ 0.2f , 0.2f }, 0.25f));
			my_objs.push_back(GeometricObject::makeBox(Colors::black, vec2{ 0.5f , 0.5f }, 0.25f, 0.25f));
			my_objs.push_back(GeometricObject::makeStar(Colors::silver, vec2{ -0.5f , -0.5f }, 0.5f, 0.25f));
		}

		~Example()
		{
			for (const auto & obj : my_objs)
			{
				delete obj;
			}
		}

		void update() override
		{
			for (const auto obj : my_objs)
			{
				obj->draw();
			}
		}
	};
}

int main(void)
{
	jm::Example().run();
	//jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	//jm::PrimitivesGallery().run();

	return 0;
}
