//
// FILE:        Vector.h
// LICENSE:     The MIT license
// PURPOUSE:    2D vectors.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

#include <stdexcept>
#include "Util.h"

namespace Engine
{
    template<class T>
    class vec2
    {
    private:
        T v[2];

    public:
        vec2 ()
        {
        }

        vec2 ( const T& x, const T& y )
        {
            v[0] = x;
            v[1] = y;
        }

        vec2 ( const vec2& other )
        {
            for ( int i = 0; i < NUMELEMS(v); ++i )
                v[i] = other.v[i];
        }

        vec2& operator= ( const vec2& other )
        {
            for ( int i = 0; i < NUMELEMS(v); ++i )
                v[i] = other.v[i];
            return *this;
        }

        T& operator[] ( int idx )
        {
            if ( idx < 0 || idx > NUMELEMS(v) )
                throw std::out_of_range("vector index");
            return v[idx];
        }

        const T& operator[] ( int idx ) const
        {
            if ( idx < 0 || idx > NUMELEMS(v) )
                throw std::out_of_range("vector index");
            return v[idx];
        }
    };


    //---------------------------------------------
    // Define the vectors for the different types
    typedef vec2<int>    vec2i;
    typedef vec2<float>  vec2f;
    typedef vec2<double> vec2d;
}
