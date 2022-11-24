// Selection sort implementation :

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(size_t a, size_t b)
{
    size_t temp = a;
    a = b;
    b = temp;
}

/*
   • Sort in descending order
*/

template <typename T>
void my_selection_sort( T begin, T end)
{
    for (T i = begin; i != end; ++i)
    {
        T max = i;
        for (T j = i; j != end; ++j)
        {
            if (*j > *max)
            {
                max = j;
            }
        }
        swap(*i, *max);
    }
}

// All integral types to be sorted: first all even values, then all odd ones. Within even/odd values in ascending order
// Version for int only :
template <int T>
void my_selection_sort(size_t begin, size_t end)
{
    for (size_t i = begin; i != end; ++i)
    {
        size_t min = i;
        for (size_t j = i; j != end; ++j)
        {
            if (j % 2 == 0 && min % 2 == 0)
            {
                if (j < min)
                {
                    min = j;
                }
            }
            else if (j % 2 == 1 && min % 2 == 1)
            {
                if (j < min)
                {
                    min = j;
                }
            }
            else if (j % 2 == 0 && min % 2 == 1)
            {
                min = j;
            }
        }
        swap(i, min);
    }
}
