#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

int main()
{   
    vector<string> stack_tag;
    map<string, string> dict;
    int line_number, number_request;
    cin >> line_number >> number_request;
    cin.ignore();
    for (int i = 0; i < line_number; i++)
    {
        string line, tag, props, prev, value;
        size_t index;
        getline(cin, line);
        stringstream ss(line);
        ss >> tag;
        if (tag.find("/") != string::npos)
        {
            tag = tag.substr(0, tag.length() - 1);
            stack_tag.push_back(tag);
        }
        while (ss >> props)
        {
            
            if (props == "=")
            {
                ss >> value;
                value.substr(1, value.length() - 2);
                dict[prev] = value;
            }
            prev = props;
        }
        
    }
}