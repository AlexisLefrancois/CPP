// Do not change
#include <iostream>
#include <fstream>

#include <list>
#include <vector>
#include <deque>

#include "my_sort.hpp"

/* 
   First line of the file is the container type :
   i => integer
   u => unsigned integer
   f => float
   d => double
   c => char
   s => std::string

   The second line corresponds to the type of container used for sorting :
   l => std::list
   v => std::vector
   d => std::deque

   All other lines correspond to values (one value per line).
   You program must then create a new file with the name "sorted_values.txt"
   containing the value type, the container type and the sorted values
*/


template <typename T>
void read_file_to_cont(std::ifstream& f, T& c) 
{
    T val;
    while (f >> val) 
    {
        c.push_back(val);
    }
}

template <typename T>
void read_and_sort(std::ifstream& fi, std::ofstream& fo) 
{
    T c;
    read_file_to_cont(fi, c);
    my_selection_sort(c.begin(), c.end());
    fo << c;
}

template <typename T>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo) 
{
    char container_type;
    fi >> container_type;
    switch (container_type) 
    {
        case 'l':
            read_and_sort<std::list<T>>(fi, fo);
            break;
        case 'v':
            read_and_sort<std::vector<T>>(fi, fo);
            break;
        case 'd':
            read_and_sort<std::deque<T>>(fi, fo);
            break;
    }
}

void read_and_sort_decide_valuetype(std::ifstream& fi, std::ofstream& fo) 
{
    char value_type;
    fi >> value_type;
    switch (value_type) 
    {
        case 'i':
            read_and_sort_decide_container<int>(fi, fo);
            break;
        case 'u':
            read_and_sort_decide_container<unsigned int>(fi, fo);
            break;
        case 'f':
            read_and_sort_decide_container<float>(fi, fo);
            break;
        case 'd':
            read_and_sort_decide_container<double>(fi, fo);
            break;
        case 'c':
            read_and_sort_decide_container<char>(fi, fo);
            break;
        case 's':
            read_and_sort_decide_container<std::string>(fi, fo);
            break;
    }
}
