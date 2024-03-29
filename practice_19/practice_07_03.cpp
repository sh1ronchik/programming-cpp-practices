#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

void appendToFile(const std::string& path, const std::string& strToAppend)
{
    std::filesystem::path fsPath(path);
    if (!fsPath.is_absolute()) {
        throw std::runtime_error("The specified string is not a valid file path.");
    }

    if (!std::filesystem::exists(fsPath)) { 
        throw std::runtime_error("The specified file path does not exist."); 
    }

    auto perms = std::filesystem::status(fsPath).permissions();
    if ((perms & std::filesystem::perms::owner_write) == std::filesystem::perms()) {
        throw std::runtime_error("No write access to the file.");
    }

    std::ofstream file(fsPath, std::ios::app);

    file << strToAppend;

    if (!file.good()) {
        throw std::runtime_error("Not enough disk space to append the string to the file.");
    }

    file.close();
}

int main() {
    std::string filePath;
    std::cout << "Enter the file path: ";
    std::cin >> filePath;

    std::string strToAppend;
    std::cout << "Enter the line to add: ";
    std::cin >> strToAppend;

    try {
        appendToFile(filePath, strToAppend);
        std::cout << "String successfully appended to " << filePath << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl; 
    }

    return 0;
}
