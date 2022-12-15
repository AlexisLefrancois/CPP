#include <set>
#include <type_traits>
#include <concepts>

// Theme : operator overloading and generic programming

/*
   Given the sets s1 and s2 (over any [admissible]) type we want and an (positive) integral n:
   • s1 + s2 to return a new set containing the union of s1 and s2
   • s1 - s2 to return a new set containing the difference of s1 and s2, that is all values of s1 not in s2
   • s1 ^ s2 to return a new set containing the symmetric difference of s1 and s2 (xor of s1 and s2)
   • s1 * s2 to return a new set {x1+x2 | forall x1 in s1 and x2 in s2}
   • s1 ^ n to return a new set containing the original set multiplied with itself n times
*/

std::set<int> operator+(const std::set<int>& s1,const std::set<int>& s2)
{
    std::set<int> result;
    for (auto& x : s1)
        result.insert(x);
    for (auto& x : s2)
        result.insert(x);
    return result;
}

std::set<int> operator-(const std::set<int>& s1,const std::set<int>& s2)
{
    std::set<int> result;
    for (auto& x : s1)
        result.insert(x);
    for (auto& x : s2)
        result.erase(x);
    return result;
}

std::set<int> operator^(const std::set<int>& s1,const std::set<int>& s2)
{
    std::set<int> result;
    for (auto& x : s1)
        result.insert(x);
    for (auto& x : s2) {
        if (result.find(x) != result.end())
            result.erase(x);
        else
            result.insert(x);
    }
    return result;
}

std::set<int> operator*(const std::set<int>& s1,const std::set<int>& s2)
{
    std::set<int> result;
    for (auto& x : s1)
    {
        for (auto& y : s2)
            result.insert(x+y);
    }
    return result;
}

std::set<int> operator^(const std::set<int>& s1,const int n)
{
    std::set<int> result = s1;

    for (int i = 0; i < n; ++i)
        result = result * s1;

    return result;
}

std::set<std::string> operator*(const std::set<std::string>& s1,const std::set<std::string>& s2)
{
    std::set<std::string> result;
    for (auto& x : s1)
    {
        for (auto& y : s2)
            result.insert(x+y);
    }
    return result;
}

std::set<std::string> operator^(const std::set<std::string>& s1,const int n)
{
    if (n < 0)
        throw std::invalid_argument("n must be positive");
    if (n == 0)
        return std::set<std::string>();
    std::set<std::string> result = s1;
    for (int i = 0; i < n; ++i)
        result = result * s1;
    return result;
}
