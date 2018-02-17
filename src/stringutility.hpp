#ifndef stringutility_h
#define stringutility_h

#include <sstream>
#include <string>
#include <vector>
#include <iterator>

void split(const std::string& s, char delim, std::vector<std::string>& result)
{
    std::stringstream ss(s);
    std::string word;
    while (std::getline(ss, word, delim))
    {
        result.push_back(word);
    }
}

std::vector<std::string> split(const std::string& s, char delim)
{
    std::vector<std::string> words;
    split(s, delim, words);

    return words;
}

#endif /* stringutility_h */
