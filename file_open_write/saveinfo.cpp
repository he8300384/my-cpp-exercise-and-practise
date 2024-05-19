#include <iostream>
#include <fstream>
#include <sstream>

void saveInfoAtLine(const std::string& filename, int lineNum, const std::string& info) {
    std::ifstream fileIn(filename);
    std::ofstream fileOut("temp.txt");
    std::string line;
    int currentLine = 1;

    while (std::getline(fileIn, line)) {
        if (currentLine == lineNum) {
            fileOut << info << "\n";
        } else {
            fileOut << line << "\n";
        }
        currentLine++;
    }

    fileIn.close();
    fileOut.close();

    // Rename temp file to original file
    std::remove(filename.c_str());
    std::rename("temp.txt", filename.c_str());
}

int main() {
    saveInfoAtLine("data.txt", 3, "New information to save");

    return 0;
}