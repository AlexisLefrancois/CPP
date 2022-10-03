#include "sources.h"

int find_motive(int argc, char* argv[]) {
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " <path to textfile> <motive to find>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cout << "The file " << argv[1] << " could not be opened" << std::endl;
        return 1;
    }

    std::string word;
    int count = 0;
    while (file >> word) {
        if (word.find(argv[2]) != std::string::npos) {
            count++;
        }
    }

    std::cout << "The file " << argv[1] << " contains " << count << " words containing the motive " << argv[2] << std::endl;
    return 0;
}
