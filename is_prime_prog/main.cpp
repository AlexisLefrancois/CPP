#include <iostream>
#include "sources.h"

int main()
{
    long long int i;
    while (std::cin >> i)
    {
        std::cout << i << " is a prime: " << (is_prime(i) ? "True" : "False") << std::endl;
    }
    return 0;
}
