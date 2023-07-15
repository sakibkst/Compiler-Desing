#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    ifstream file("program.cpp");
    string line, word;
    vector<std::string> variables, preprocessors;

    while (getline(file, line)) {
        istringstream iss(line);
        if (line[0] == '#') {
            iss >> word; //
            preprocessors.push_back(word);
        } else if (line.find("int") != string::npos) {
            while (iss >> word) {
                if (word.back() == ';' || word.back() == ',') {
                    word.pop_back();
                }
                if (word != "int" && isalpha(word[0])) {
                    variables.push_back(word);
                }
            }
        }
    }

    sort(variables.begin(), variables.end());
    variables.erase(unique(variables.begin(), variables.end()), variables.end());
    unordered_set<string> preprocessor_set(preprocessors.begin(), preprocessors.end());
    preprocessors.assign(preprocessor_set.begin(), preprocessor_set.end());

    cout << "Variables: " << endl;
    for (int i = 0; i < variables.size(); i++) {
        cout << "Variable-" << i+1 << ": " << variables[i] << endl;
    }
    cout << "Total number of variables: " << variables.size() << endl;
    cout << "Preprocessors: " << endl;
    for (int i = 0; i < preprocessors.size(); i++) {
        cout << "Preprocessor-" << i+1 << ": " << preprocessors[i] << endl;
    }
    cout << "Total number of preprocessors: " << preprocessors.size() << endl;

    return 0;
}
