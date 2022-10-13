#include <algorithm>
#include <cstddef>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
map<string, string> buildMap(ifstream& map_file)
{
    map<string, string> trans_map;
    string key;
    string value;

    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1) {
            trans_map[key] = value.substr(1);  // delete pre_board
        }else {
            throw runtime_error("no rule for " + key);
        }
    }
    return trans_map;
}
const string& transform(const string& s, const map<string, string>& m)
{
    auto map_it = m.find(s);
    if (map_it != m.end())
        return map_it->second;
    else
        return s;
}

void word_tranform(ifstream& map_file, ifstream& input)
{
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text)) {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}
int main()
{
    // word conversion
    ifstream map_file("a.txt"), input("b.txt");
    word_tranform(map_file, input);

    map_file.close();
    input.close();
    return 0;
}
