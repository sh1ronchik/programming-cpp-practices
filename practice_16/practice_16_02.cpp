#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc <  2) {
        std::cerr << "Usage: " << argv[0] << " [FILE]...\n";
        return  1;
    }

    for (int i =  1; i < argc; ++i) {
        std::ifstream file(argv[i]);
        if (!file) {
            std::cerr << "Error: Cannot open file " << argv[i] << '\n';
            return  1;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::cout << line;
            if (!file.eof()) {
                std::cout << '\n';
            }
        }

        file.close();
    }

    return  0;
}