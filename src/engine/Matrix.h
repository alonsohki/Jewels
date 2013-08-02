//
// FILE:        Matrix.h
// LICENSE:     The MIT license
// PURPOUSE:    Transform matrices.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

namespace Engine
{
    template<typename T>
    class Matrix
    {
    private:
        T v[3][3];

    public:
        Matrix ()
        {
        }

        Matrix ( const T v0[3], const T v1[3], const T v2[3] )
        {
            memcpy ( &v[0][0], &v0[0], sizeof(T)*3 );
            memcpy ( &v[1][0], &v1[0], sizeof(T)*3 );
            memcpy ( &v[2][0], &v2[0], sizeof(T)*3 );
        }

        Matrix ( const Matrix& other )
        {
            for ( int i = 0; i < 3; ++i )
                for ( int j = 0; j < 3; ++j )
                    v[i][j] = other.v[i][j];
        }

        Matrix& operator= ( const Matrix& other )
        {
            for ( int i = 0; i < 3; ++i )
                for ( int j = 0; j < 3; ++j )
                    v[i][j] = other.v[i][j];
            return *this;
        }
    };



    //--------------------------------------------------
    // Special matrix constructions
    template<typename T>
    class IdentityMatrix : public Matrix<T>
    {
    public:
        IdentityMatrix ()
        : Matrix({1.0f, 0.0f, 0.0f},
                 {0.0f, 1.0f, 0.0f},
                 {0.0f, 0.0f, 1.0f})
        {
        }
    };



    //--------------------------------------------------
    // Define the different matrix types for float and double.
    typedef Matrix<float>  Matrixf;
    typedef Matrix<double> Matrixd;
}
