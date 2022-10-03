#include "sources.h"

bool is_prime(int i)
{
    if (i == 1)
    {
        return false;
    }
    for (int j = 2; j < i; j++)
    {
        if (i % j == 0)
        {
            return false;
        }
    }
    return true;
}
