

#include <iostream>
#include <string>
#include <array>
#include <unordered_map>

namespace utility
{

    std::vector<std::vector<bool>> rotateMatrix(std::vector<std::vector<bool>> mat);


    std::string parseArrayToString(std::array<int, 2> myArray);
    std::array<int, 2> parseStringToArray(std::string myString);


    std::unordered_map<std::string, bool> shiftHashValuesDown(std::unordered_map<std::string, bool> hash);

}