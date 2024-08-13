#pragma once
#include <iostream>
using namespace std;

namespace Math {
    template <typename T>
    class Coordinates {
    private:
        T x;
        T y;
    public:
        Coordinates(T x, T y);
        Coordinates();
        ~Coordinates();
        T* getCoordinates() const;
        T getX() const;
        T getY() const;
        void setCoordinates(T x, T y);
        void setX(T x);
        void setY(T y);

        //Operator overloading
        Coordinates<T> operator+(Coordinates<T> &c);
        Coordinates<T> operator-(Coordinates<T> &c);
        Coordinates<T> operator*(Coordinates<T> &c);
        Coordinates<T> operator/(Coordinates<T> &c);
        void operator+=(Coordinates<T> &c);
        void operator-=(Coordinates<T> &c);
        void operator*=(Coordinates<T> &c);
        void operator/=(Coordinates<T> &c);
        void operator+=(T &c);
        void operator-=(T &c);
        void operator*=(T &c);
        void operator/=(T &c);
        bool operator==(Coordinates<T> &c);
        bool operator!=(Coordinates<T> &c);
        bool operator>(Coordinates<T> &c);
        bool operator<(Coordinates<T> &c);
        bool operator>=(Coordinates<T> &c);
        bool operator<=(Coordinates<T> &c);
    };

    typedef Coordinates<int> IntCoords;
    typedef Coordinates<float> FloatCoords;
    typedef Coordinates<double> DoubleCoords;
    typedef Coordinates<unsigned int> UIntCoords;

    template <typename T>
    Coordinates<T>::Coordinates(T xx, T yy):
    x((T)0),
    y((T)0)
    {
        setCoordinates(xx, yy);
    }

    template <typename T>
    Coordinates<T>::Coordinates()
    {
        setCoordinates(0, 0);
    }

    template <typename T>
    Coordinates<T>::~Coordinates()
    {
    }

    template <typename T>
    T* Coordinates<T>::getCoordinates() const
    {
        T coords[2] = {x, y};
        return coords;
    }

    template <typename T>
    T Coordinates<T>::getX() const
    {
        return x;
    }

    template <typename T>
    T Coordinates<T>::getY() const
    {
        return y;
    }

    template <typename T>
    void Coordinates<T>::setCoordinates(T xx, T yy)
    {
        x = xx;
        y = yy;
    }

    template <typename T>
    void Coordinates<T>::setX(T xx)
    {
        x = xx;
    }

    template <typename T>
    void Coordinates<T>::setY(T yy)
    {
        y = yy;
    }

    template <typename T>
    Coordinates<T> Coordinates<T>::operator+(Coordinates<T> &c)
    {
        return Coordinates<T>(x + c.getX(), y + c.getY());
    }

    template <typename T>
    Coordinates<T> Coordinates<T>::operator-(Coordinates<T> &c)
    {
        return Coordinates<T>(x - c.getX(), y - c.getY());
    }

    template <typename T>
    Coordinates<T> Coordinates<T>::operator*(Coordinates<T> &c)
    {
        return Coordinates<T>(x * c.getX(), y * c.getY());
    }

    template <typename T>
    Coordinates<T> Coordinates<T>::operator/(Coordinates<T> &c)
    {
        if(c.getX() == 0 || c.getY() == 0)
        {
            throw "Division by zero";
        }
        else
            return Coordinates<T>(x / c.getX(), y / c.getY());
    }

    template <typename T>
    void Coordinates<T>::operator+=(Coordinates<T> &c)
    {
        x += c.getX();
        y += c.getY();
    }

    template <typename T>
    void Coordinates<T>::operator-=(Coordinates<T> &c)
    {
        x -= c.getX();
        y -= c.getY();
    }

    template <typename T>
    void Coordinates<T>::operator*=(Coordinates<T> &c)
    {
        x *= c.getX();
        y *= c.getY();
    }

    template <typename T>
    void Coordinates<T>::operator/=(Coordinates<T> &c)
    {
        if(c.getX() == 0 || c.getY() == 0)
        {
            throw "Division by zero";
        }
        else
        {
            x /= c.getX();
            y /= c.getY();
        }
    }

    template <typename T>
    void Coordinates<T>::operator+=(T &c)
    {
        x += c;
        y += c;
    }

    template <typename T>
    void Coordinates<T>::operator-=(T &c)
    {
        x -= c;
        y -= c;
    }

    template <typename T>
    void Coordinates<T>::operator*=(T &c)
    {
        x *= c;
        y *= c;
    }

    template <typename T>
    void Coordinates<T>::operator/=(T &c)
    {
        if(c == 0)
        {
            throw "Division by zero";
        }
        else
        {
            x /= c;
            y /= c;
        }
    }

    template <typename T>
    bool Coordinates<T>::operator==(Coordinates<T> &c)
    {
        return (x == c.getX() && y == c.getY());
    }

    template <typename T>
    bool Coordinates<T>::operator!=(Coordinates<T> &c)
    {
        return (x != c.getX() || y != c.getY());
    }

    template <typename T>
    bool Coordinates<T>::operator>(Coordinates<T> &c)
    {
        return (x > c.getX() && y > c.getY());
    }

    template <typename T>
    bool Coordinates<T>::operator<(Coordinates<T> &c)
    {
        return (x < c.getX() && y < c.getY());
    }

    template <typename T>
    bool Coordinates<T>::operator>=(Coordinates<T> &c)
    {
        return (x >= c.getX() && y >= c.getY());
    }
    
    template <typename T>
    bool Coordinates<T>::operator<=(Coordinates<T> &c)
    {
        return (x <= c.getX() && y <= c.getY());
    }
}