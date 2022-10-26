#include "vector.hh"

#include <string>
#include <iostream>
#include <sstream>


// Operations (+/-/*) between Vectors of different 
// throw a std::runtime_error with the message "Incompatible size".

// Usage of suitable smart_pointer in order to internally manage the resource

// Definition of the constructors

Vector::Vector(const Vector& v) : v_size(v.v_size), data(new value[v_size])
{
    for (size_t i = 0; i < v_size; ++i)
    {
        data[i] = v.data[i];
    }
}

Vector& Vector::operator=(const Vector& v)
{
    if (this != &v)
    {
        v_size = v.v_size;
        data.reset(new value[v_size]);
        for (size_t i = 0; i < v_size; ++i)
        {
            data[i] = v.data[i];
        }
    }
    return *this;
}

Vector::Vector(size_t v_size) : v_size(v_size), data(new value[v_size])
{
    for (size_t i = 0; i < v_size; ++i)
    {
        data[i] = 0;
    }
}

Vector::Vector(std::initializer_list<value> l) : v_size(l.size()), data(new value[v_size])
{
    size_t i = 0;
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        data[i] = *it;
        ++i;
    }
}

size_t Vector::size() const
{
    return v_size;
}

// Definition of the operators

Vector& Vector::operator+=(const Vector& rhs)
{
    if (v_size != rhs.v_size)
    {
        throw std::runtime_error("Incompatible size");
    }
    for (size_t i = 0; i < v_size; ++i)
    {
        data[i] += rhs.data[i];
    }
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    if (v_size != rhs.v_size)
    {
        throw std::runtime_error("Incompatible size");
    }
    for (size_t i = 0; i < v_size; ++i)
    {
        data[i] -= rhs.data[i];
    }
    return *this;
}

Vector& Vector::operator+=(value v)
{
    for (size_t i = 0; i < v_size; ++i)
    {
        data[i] += v;
    }
    return *this;
}

Vector& Vector::operator*=(value v)
{
    for (size_t i = 0; i < v_size; ++i)
    {
        data[i] *= v;
    }
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const
{
    if (v_size != rhs.v_size)
    {
        throw std::runtime_error("Incompatible size");
    }
    Vector result(v_size);
    for (size_t i = 0; i < v_size; ++i)
    {
        result.data[i] = data[i] + rhs.data[i];
    }
    return result;
}

Vector Vector::operator+(value v) const
{
    Vector result(v_size);
    for (size_t i = 0; i < v_size; ++i)
    {
        result.data[i] = data[i] + v;
    }
    return result;
}

value Vector::operator*(const Vector& rhs) const
{
    if (v_size != rhs.v_size)
    {
        throw std::runtime_error("Incompatible size");
    }
    value result = 0;
    for (size_t i = 0; i < v_size; ++i)
    {
        result += data[i] * rhs.data[i];
    }
    return result;
}

Vector Vector::operator*(value v) const
{
    Vector result(v_size);
    for (size_t i = 0; i < v_size; ++i)
    {
        result.data[i] = data[i] * v;
    }
    return result;
}

value& Vector::operator[](size_t idx)
{
    return data[idx];
}

value Vector::operator[](size_t idx) const
{
    return data[idx];
}

Vector operator*(value v, const Vector& rhs)
{
    return rhs * v;
}

Vector operator+(value v, const Vector& rhs)
{
    return rhs + v;
}

std::ostream& operator<<(std::ostream& o, const Vector& v)
{
    o << "{";
    for (size_t i = 0; i < v.size(); ++i)
    {
        o << v[i];
        if (i != v.size() - 1)
        {
            o << ",";
        }
    }
    o << "}";
    return o;
}
