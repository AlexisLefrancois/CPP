// Do not change
#include <iostream>
#include <fstream>

#include <list>
#include <vector>
#include <deque>
#include <tuple>

#include "my_sort.hpp"

template<class T, class CONTAINER>
void read_file_to_cont(std::ifstream& f, CONTAINER& c)
{
    if constexpr (std::is_same<T, char>::value)
    {
        char tmp = '\n';
        while (f.get(tmp))
        {
            if (tmp != '\n')
            {
                c.push_back(tmp);
            }
        }

    } else {
        T elm;
        while (f >> elm)
        {
            c.push_back(elm);
        }
    }

}



template<class T, class CONTAINER>
void read_and_sort(std::ifstream& fi, std::ofstream& fo)
{
    CONTAINER c;
    read_file_to_cont<T, CONTAINER>(fi, c);
    auto begin = c.begin();
    auto end = c.end();

    if constexpr (std::is_same_v<T, char> || std::is_same_v<T, int>
                  || std::is_same_v<T, unsigned int> )
    {
        my_sort(begin, end,[](T l, T r)->bool{return std::make_tuple(l%2, l) < std::make_tuple(r%2, r);} );
    } else {
        my_sort(begin, end,[](T l, T r)->bool{return l > r; } );
    }

    for (T& elm : c) {
        fo << elm << "\n";
    }
}


template<class T>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo)
{
    char container;
    fi >> container;
    fo << container << "\n";

    switch (container)
    {
        case 'l':
            read_and_sort<T, std::list<T>>(fi, fo);
            break;
        case 'v':
            read_and_sort<T, std::vector<T>>(fi, fo);
            break;
        case 'd':
            read_and_sort<T, std::deque<T>>(fi, fo);
            break;
        default:
            break;
    }
}


void read_and_sort_decide_valuetype(std::ifstream& fi, std::ofstream& fo)
{
    char type;
    fi >> type;
    fo << type << "\n";

    switch (type)
    {
        case 'i':
            read_and_sort_decide_container<int>(fi, fo);
            break;
        case 'u':
            read_and_sort_decide_container<unsigned int>(fi, fo);
            break;
        case 'c':
            read_and_sort_decide_container<char>(fi, fo);
            break;
        case 'f':
            read_and_sort_decide_container<float>(fi, fo);
            break;
        case 's':
            read_and_sort_decide_container<std::string>(fi, fo);
            break;
        default:
            break;
    }
}
