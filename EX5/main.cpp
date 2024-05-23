#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class myString {
private:
    string m_str;
public:
    myString(string s){
        m_str = s;
    }
};

class ReadClass {
public:
    void showClass() {
        ifstream file("main.cpp");
        string line;
        int classCount = 0;

        while (getline(file, line)) {
            if (isClassDeclaration(line)) {
                classCount++;
            }
        }

        // Output the number of classes first
        cout << classCount << " classes in main.cpp" << endl;

        // Reset file pointer to beginning
        file.clear();
        file.seekg(0, ios::beg);

        // Output class declarations
        while (getline(file, line)) {
            if (isClassDeclaration(line)) {
                cout << "class " << extractClassName(line) << endl;
            }
        }
    }

private:
    bool isClassDeclaration(const string& line) {
        return line.find("class ") == 0;
    }

    string extractClassName(const string& line) {
        size_t startPos = line.find("class ") + 6; // Length of "class " is 6
        size_t endPos = line.find_first_of(" {", startPos);
        return line.substr(startPos, endPos - startPos);
    }
};

int main() {
    ReadClass rfile;
    rfile.showClass();
    return 0;
}
