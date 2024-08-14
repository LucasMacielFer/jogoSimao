#pragma once

namespace Auxiliares
{
    template<typename T>
    class Coordenada
    {
        public:
            T x;
            T y;

            Coordenada(T X = 0.0, T Y = 0.0);
            ~Coordenada();

            Coordenada<T> operator+(Coordenada<T> v);
            Coordenada<T> operator-(Coordenada<T> v);
            Coordenada<T> operator*(int i);
            Coordenada<T> operator*(float f);
            Coordenada<T> operator*(double d);
            void operator++();
            void operator+=(Coordenada<T> v);
            T operator*(Coordenada<T> v);
    };

    typedef Coordenada<int> CoordI;
    typedef Coordenada<unsigned int> CoordU;
    typedef Coordenada<float> CoordF;
    typedef Coordenada<double> CoordD;


    template <typename T>
    Coordenada<T>::Coordenada(T X, T Y): x(X), y(Y)
    {}

    template <typename T>
    Coordenada<T>::~Coordenada()
    {
        x = 0.0;
        y = 0.0;
    }

    template <typename T>
    Coordenada<T> Coordenada<T>::operator+(Coordenada v)
    {
        return Coordenada<T>(x + v.x, y + v.y);
    }

    template <typename T>
    Coordenada<T> Coordenada<T>::operator-(Coordenada v)
    {
        return Coordenada<T>(x - v.x, y - v.y);
    }

    template <typename T>
    Coordenada<T> Coordenada<T>::operator*(int i)
    {
        return Coordenada<T>(x * i, y * i);
    }

    template <typename T>
    Coordenada<T> Coordenada<T>:: operator*(float f)
    {
        return Coordenada<T>(x * f, y * f);
    }

    template <typename T>
    Coordenada<T> Coordenada<T>:: operator*(double d)
    {
        return Coordenada<T>(x * d, y * d);
    }

    template <typename T>
    void Coordenada<T>:: operator++()
    {
        x++;
        y++;
    }

    template <typename T>
    void Coordenada<T>:: operator+=(Coordenada<T> v)
    {
        x += v.x;
        y += v.y;
    }

    template <typename T>
    T Coordenada<T>::operator*(Coordenada<T> v)
    {
        return x*(v.x) + y*(v.y);
    }

}