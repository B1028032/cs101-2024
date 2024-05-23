#include <iostream>
#include <fstream>
#include <regex>
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
        regex classRegex("class\\s+(\\w+)\\s*\\{?");

        while (getline(file, line)) {
            smatch match;
            if (regex_search(line, match, classRegex)) {
                cout << "class " << match[1] << endl;
                classCount++;
            }
        }

        cout << classCount << " classes in main.cpp" << endl;
    }
};

int main() {
    ReadClass rfile;
    rfile.showClass();
    return 0;
}
