#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "RigidCircle.h"
#include <vector>
#include <memory>

namespace jm
{
	using namespace std;

	static const auto gravity = vec2(0.0f, -9.8f);

	class Particle
	{
	public:
		vec2 pos;
		vec2 vel;
		RGB  color;

		float age;
		float life;

		float rot;
		float angular_velocity;

		void update(const float & dt)
		{
			const auto acc = gravity; //assumes GA only.

			vel += acc * dt;
			pos += vel * dt;
			
			rot += angular_velocity * dt;

			// update age.
			age += dt;
			// update color (blend with background color)
		}
	};

	class ParticleSystem
	{
	public:
		vector<Particle> particles;

		RandomNumberGenerator rn;

		ParticleSystem()
		{
			reset();
		}

		auto getRandomUnitVector()
		{
			const float theta = rn.getFloat(0.0f, 3.141592f * 2.0f); // 0.0 ~ 2pi

			return vec2{cos(theta), -sin(theta)};
		}

		auto getRandomColor()
		{
			return RGB{ rn.getFloat(0.0f, 1.0f), rn.getFloat(0.0f, 1.0f), rn.getFloat(0.0f, 1.0f) };
		}

		void reset()
		{
			particles.clear();

			// initialize particles
			for (int i = 0; i < 1000; ++i)
			{
				Particle new_particle;
				new_particle.pos = vec2(0.0f, 0.5f) + getRandomUnitVector() * rn.getFloat(0.001f, 0.03f);
				new_particle.vel = getRandomUnitVector() * rn.getFloat(0.01f, 2.0f);
				new_particle.color = getRandomColor();
				new_particle.age = 0.0f;
				new_particle.life = rn.getFloat(0.1f, 1.0f);
				new_particle.rot = rn.getFloat(0.0f, 360.0f);
				new_particle.angular_velocity = rn.getFloat(-1.0f , 1.0f) * 360.0f * 4.0f;
				particles.push_back(new_particle);
			}
		}

		void update(const float & dt)
		{
			for (auto & pt : particles)
			{
				pt.update(dt);

				// remove particles when they are 1. too old, 2. out of screen.
			}
		}

		void draw()
		{
			beginTransformation();

			for (const auto & pt : particles)
			{
				if (pt.age > pt.life) continue;

				const float alpha = 1.0f - pt.age / pt.life;
				const RGB blended_color = { (pt.color.r * alpha + 1.0f * (1.0f - alpha)) , (pt.color.g * alpha + 1.0f * (1.0f - alpha)) , (pt.color.b * alpha + 1.0f * (1.0f - alpha)) };
					
				//drawPoint(blended_color, pt.pos, 3.0f);
				beginTransformation();
				translate(pt.pos);
				rotate(pt.rot);
				drawFilledStar(blended_color, 0.03f, 0.01f);
				endTransformation();
			}

			endTransformation();
		}
	};

	class Example : public Game2D
	{
	public:
		ParticleSystem ps;

		Example()
			: Game2D()
		{
			reset();
		}

		void reset()
		{
			ps.reset();
		}

		void update() override
		{
			const float dt = getTimeStep() * 0.05f;

			ps.update(dt);

			ps.draw();

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
