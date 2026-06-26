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
        if (tag.find("/") == string::npos)
        {
           
            if (tag.back() == '>')
            {
                tag = tag.substr(1, tag.length() - 2);
            }
            else
                tag = tag.substr(1, tag.length() - 1);
            stack_tag.push_back(tag);
        }
        else 
            stack_tag.pop_back();
        while (ss >> props)
        {
            string path;
            if (props == "=")
            {
                ss >> value;
                if (value.back() == '>')
                {
                    value.pop_back();
                    value = value.substr(1, value.length() - 2);
                }
                else
                    value = value.substr(1, value.length() - 2);
                for (size_t k = 0; k < stack_tag.size(); k++)
                {
                    if (k > 0)
                        path += '.';
                    path += stack_tag[k];
                }
                path += "~" + prev;
                dict[path] = value;
            }
            prev = props;
        }
        
    }
}