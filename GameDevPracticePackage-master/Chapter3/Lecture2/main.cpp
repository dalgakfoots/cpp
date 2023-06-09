#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "RigidCircle.h"
#include <vector>
#include <memory>

namespace jm
{
	class Example : public Game2D
	{
	public:
		RigidCircle rb0, rb1;

		Example()
			: Game2D()
		{
			reset();
		}

		void reset()
		{
			// Initial position and velocity
			rb0.pos = vec2(-0.8f, 0.3f);
			rb0.vel = vec2(5.0f, 0.0f);
			rb0.color = Colors::hotpink;
			rb0.radius = 0.1f;
			rb0.mass = 1.0f;

			rb1.pos = vec2(0.8f, 0.3f);
			rb1.vel = vec2(-5.0f, 0.0f);
			rb1.color = Colors::yellow;
			rb1.radius = 0.15f;
			rb1.mass = rb0.mass * std::pow(rb1.radius / rb0.radius, 2.0f);
		}

		void drawWall()
		{
			setLineWidth(5.0f);
			drawLine(Colors::blue, { -1.0f, -1.0f }, Colors::blue, { 1.0f, -1.0f });
			drawLine(Colors::blue, { 1.0f, -1.0f }, Colors::blue, { 1.0f, 1.0f });
			drawLine(Colors::blue, { -1.0f, -1.0f }, Colors::blue, { -1.0f, 1.0f });
		}

		void update() override
		{
			const float dt = getTimeStep() * 0.4f;
			const float epsilon = 0.5f;

			// physics update
			rb0.update(dt);
			rb1.update(dt);

			// check collision between two rigid bodies
			const float distance = (rb0.pos - rb1.pos).getMagnitude();
			if (distance < rb0.radius + rb1.radius)
			{
				// compute impulse
				
				// 상대속도
				const auto vel_rel = rb0.vel - rb1.vel;
				// 노멀벡터
				const auto normal = -(rb1.pos - rb0.pos) / (rb1.pos - rb0.pos).getMagnitude();
				// 접근하는 경우에만 충돌을 체크
				if (vel_rel.getDotProduct(normal) < 0.0f)
				{
					// 충돌량 계산
					const auto impulse =
						normal * -(1.0f + epsilon) * vel_rel.getDotProduct(normal) /
						((1.0f / rb0.mass) + (1.0f / rb1.mass));

					// update velocities of two bodies
					rb0.vel += impulse / rb0.mass;
					rb1.vel -= impulse / rb1.mass;
				}
			}

			// draw
			drawWall();
			rb0.draw();
			rb1.draw();

			// reset button
			if (isKeyPressedAndReleased(GLFW_KEY_R)) reset();
		}

	};
}

int main(void)
{
	jm::Example().run();

	return 0;
}
