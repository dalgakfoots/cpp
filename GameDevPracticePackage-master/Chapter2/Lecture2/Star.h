#pragma once
#include "GeometricObject.h"

namespace jm
{
    class Star : public GeometricObject
    {
    public:
        float outer_radius, inner_radius;
    public:

        Star(const RGB& _color, const vec2 _pos, const float _outer_radius, const float _inner_radius)
        {
            init(_color, _pos, _outer_radius, _inner_radius);
        }

        void init(const RGB& _color, const vec2 _pos, const float _outer_radius, const float _inner_radius)
        {
            GeometricObject::init(_color, _pos);
            outer_radius = _outer_radius;
            inner_radius = _inner_radius;
        }

        void drawGeometry() override
        {
            drawFilledStar(color, outer_radius , inner_radius);
        }
    };
}