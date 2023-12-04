#include <fstream>
#include <iostream>
#include <map>
#include <vector>

int main(void)
{
    std::ifstream fp;

    fp.open("./input");

    if (!fp.is_open())
    {
        std::cout << "Failed to open file" << std::endl;
        return 1;
    }

    int         sum      = 0;
    int         num      = -1;
    int         last_num = -1;
    std::string line;

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
