#pragma once
#include "Game2D.h"

namespace jm
{
    class GeometricObject
    {
    public :
        vec2 pos;
        RGB color;

    public :

        virtual ~GeometricObject()
        {

        }

        void init(const RGB & _color , const vec2 & _pos)
        {
            color = _color;
            pos = _pos;
        }

        virtual void drawGeometry() = 0;

        void draw()
        {
            beginTransformation();
            {
                translate(pos);
                drawGeometry();
            }
            endTransformation();
        }

        static GeometricObject* makeTriangle(const RGB& _color, const vec2 _pos, const float _size);
        static GeometricObject* makeCircle(const RGB& _color, const vec2 _pos, const float _size);
        static GeometricObject* makeBox(const RGB& _color, const vec2 _pos, const float _width, const float _height);
        static GeometricObject* makeStar(const RGB& _color, const vec2 _pos, const float _or, const float _ir);
    };
}
