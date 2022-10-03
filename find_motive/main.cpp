// Takes the path of a textfile as input and counts the
// number of words containing a given motive (the second argument) at least once

// The motive is case-sensitive
// Words containing a motive more than once are only counted once
// The input files can contain any number of lines or be empty
// The input file may not exist
// The executable is always called with two arguments

// Optimizations:
// - The input file is read line by line
// - The words are read word by word
// - The words are stored in a hash table
// - The words are compared to the motive using a Boyer-Moore algorithm

#include "sources.h"

int main(int argc, char* argv[]) 
{
    return find_motive(argc, argv);
}
