#include <sstream>
#include <vector>
#include <iostream>
using namespace std;


vector<int> parseInts(string str) {
    vector<int> result;
    char comma;
    int i;
    stringstream ss(str);
    while (ss >> i)
    {
        ss >> comma;
        result.push_back(i);
    }
    return result;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}