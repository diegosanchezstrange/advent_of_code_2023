#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string str, char delimiter)
{
    std::vector<std::string> internal;
    std::stringstream        ss(str);
    std::string              tok;

    while (getline(ss, tok, delimiter))
    {
        internal.push_back(tok);
    }

    return internal;
}

int getGameNumber(std::string game) { return std::stoi(game.substr(5)); }

int main(void)
{
    std::ifstream input("input");

    int                      sum = 0;
    int                      gameNumber;
    bool                     isGamePossible;
    std::string              line;
    std::vector<std::string> gameInfo;
    std::vector<std::string> tokens;
    std::vector<std::string> balls;

    while (std::getline(input, line))
    {
        isGamePossible = false;
        tokens         = split(line, ':');
        gameNumber     = getGameNumber(tokens[0]);
        gameInfo       = split(tokens[1], ';');

        for (int i = 0; i < gameInfo.size(); i++)
        {
            balls = split(gameInfo[i], ',');
        }
    }

    return 0;
}
