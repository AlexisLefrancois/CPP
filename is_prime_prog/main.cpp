#include <iostream>
#include "sources.h"

int main()
{
    long long i;
    while (std::cin >> i)
    {
        if (is_prime(i))
        {
            std::cout << i << " is a prime: True" << std::endl;
            return 1;
        }
        else
        {
            std::cout << i << " is a prime: False" << std::endl;
            return 1;
        }
    }
    return 0;
}
