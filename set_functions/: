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

template <class T>
concept Admissible = std::is_integral_v<T> || std::is_floating_point_v<T> || std::is_same_v<T, std::string>;

template <Admissible T>
std::set<T> operator+(const std::set<T>& s1, const std::set<T>& s2)
{
    std::set<T> result;
    for (const auto& e : s1)
        result.insert(e);
    for (const auto& e : s2)
        result.insert(e);
    return result;
}

template <Admissible T>
std::set<T> operator-(const std::set<T>& s1, const std::set<T>& s2)
{
    std::set<T> result;
    for (const auto& e : s1)
        if (s2.find(e) == s2.end())
            result.insert(e);
    return result;
}

template <Admissible T>
std::set<T> operator^(const std::set<T>& s1, const std::set<T>& s2)
{
    std::set<T> result;
    for (const auto& e : s1)
        if (s2.find(e) == s2.end())
            result.insert(e);
    for (const auto& e : s2)
        if (s1.find(e) == s1.end())
            result.insert(e);
    return result;
}

template<Admissible T>
std::set<T> operator*(const std::set<T>& s1, const std::set<T>& s2)
{
    std::set<T> result;
    for (const auto& e1 : s1)
        for (const auto& e2 : s2)
            result.insert(e1 + e2);
    return result;
}

template <Admissible T>
std::set<T> operator^(const std::set<T>& s, const int n)
{
    std::set<T> result;
    if (n == 0)
        result.insert(T{});
    else if (n == 1)
        result = s;
    else
    {
        result = s;
        for (int i = 1; i < n; ++i)
            result = result * s;
    }
    return result;
}

