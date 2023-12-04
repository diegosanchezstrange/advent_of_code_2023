#include <fstream>
#include <iostream>
#include <map>
#include <vector>

std::map<char, std::vector<std::string>> create_map()
{
    std::map<char, std::vector<std::string>> map;

    map['o'] = {"one"};
    map['t'] = {"two", "three"};
    map['f'] = {"four", "five"};
    map['s'] = {"six", "seven"};
    map['e'] = {"eight"};
    map['n'] = {"nine"};
    map['O'] = {"One"};
    map['T'] = {"Two", "Three"};
    map['F'] = {"Four", "Five"};
    map['S'] = {"Six", "Seven"};
    map['E'] = {"Eight"};
    map['N'] = {"Nine"};

    return map;
}

std::map<std::string, int> create_map2()
{
    std::map<std::string, int> map;

    map["zero"]  = 0;
    map["one"]   = 1;
    map["two"]   = 2;
    map["three"] = 3;
    map["four"]  = 4;
    map["five"]  = 5;
    map["six"]   = 6;
    map["seven"] = 7;
    map["eight"] = 8;
    map["nine"]  = 9;

    return map;
}

int main(void)
{
    std::ifstream fp;

    fp.open("./input");

    if (!fp.is_open())
    {
        std::cout << "Failed to open file" << std::endl;
        return 1;
    }

    int                                      sum      = 0;
    int                                      num      = -1;
    int                                      last_num = -1;
    std::string                              line;
    std::map<char, std::vector<std::string>> map  = create_map();
    std::map<std::string, int>               map2 = create_map2();

    while (std::getline(fp, line).good())
    {
        num      = -1;
        last_num = -1;
        for (int i = 0; i < line.length(); i++)
        {
            // Check if the character is a digit and is the first digit
            if (std::isdigit(line[i]) && num == -1)
                num = (line[i] - '0') * 10;
            // Check if the character is a digit and is possibly the last digit
            else if (std::isdigit(line[i]) && num != -1)
                last_num = (line[i] - '0');
            // Check if the character is a letter and is the first letter of a
            // number And the first digit
            else if (map.find(line[i]) != map.end() && num == -1)
            {
                for (std::string str : map[line[i]])
                    line.substr(i, str.length()) == str ? num = map2[str] * 10
                                                        : 0;
            }
            // Check if the character is a letter and is the first letter of a
            // number And possibly the last digit
            else if (map.find(line[i]) != map.end() && num != -1)
            {
                for (std::string str : map[line[i]])
                    line.substr(i, str.length()) == str ? last_num = map2[str]
                                                        : 0;
            }
        }
        if (last_num == -1)
            num += num / 10;
        else
            num += last_num;
        std::cout << num << std::endl;
        sum += num;
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
