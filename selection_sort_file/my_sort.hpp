// Selection sort implementation :

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

template <typename T>
void my_selection_sort(T begin, T end)
{
    for (T i = begin; i != end; ++i)
    {
        T min = i;
        for (T j = i; j != end; ++j)
        {
            if (*j < *min)
            {
                min = j;
            }
        }
        swap(*i, *min);
    }
}
