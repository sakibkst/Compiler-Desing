#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <regex>

using namespace std;

int main() {

    ifstream file("program.cpp");


    regex op_regex("[+\\-*/%&|^~=<>!:]+");
    regex pp_regex("#\\s*\\w+");


    map<string, int> op_counts;
    map<string, int> pp_counts;


    string line;
    while (getline(file, line)) {

        for (sregex_iterator it(line.begin(), line.end(), op_regex), end_it; it != end_it; ++it) {
            string op = it->str();
            op_counts[op]++;
        }


        smatch match;
        if (regex_search(line, match, pp_regex)) {
            string pp = match.str();
            pp_counts[pp]++;
        }
    }


    cout << "Operators:\n";
    for (auto& entry : op_counts) {
        cout << entry.first << ": " << entry.second << endl;
    }
    cout << endl;

    cout << "Preprocessor:\n";
    for (auto& entry : pp_counts) {
        cout << entry.first << ": " << entry.second << endl;
    }


    file.close();




    return 0;
}
