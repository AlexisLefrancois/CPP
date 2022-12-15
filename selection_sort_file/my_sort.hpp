// Selection sort implementation :

template <typename T, class Compare>
void my_sort(T begin, T end, Compare c)
{
    for (auto j = begin; j != end; ++j)
    {
        auto min = j;
        for (auto i = j; i != end; ++i)
        {
            if (c(*i, *min))
            {
                min = i;
            }
        }
        auto temp = *j;
        *j = *min;
        *min = temp;
    }
}
