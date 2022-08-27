

#include <iostream>
#include <string>
#include <sstream>

#include <array>
#include <unordered_map>

#include "CoordinateGrid.h"


namespace utility
{

    std::vector<std::vector<bool>> rotateMatrix(std::vector<std::vector<bool>> mat)
    {

        int N = (int)mat.size();
        // Consider all squares one by one
        for (int x = 0; x < N / 2; x++)
        {
            // Consider elements in group
            // of 4 in current square
            for (int y = x; y < N - x - 1; y++)
            {
                // Store current cell in
                // temp variable
                bool temp = mat[x][y];

                // Move values from right to top
                mat[x][y] = mat[y][N - 1 - x];

                // Move values from bottom to right
                mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];

                // Move values from left to bottom
                mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];

                // Assign temp to left
                mat[N - 1 - y][x] = temp;
            }
        }
        return mat;
    }
 

    std::string parseArrayToString(std::array<int, 2> myArray) {
        std::string myString;
        myString = std::to_string(myArray[0]) + "," + std::to_string(myArray[1]);
        return myString;
    }

    std::array<int, 2> parseStringToArray(std::string myString) {
        std::array<int, 2> myArray;
        std::stringstream ss(myString);
        for (int i = 0; i < 2; i++ ) {
            std::string subMyString;
            getline(ss, subMyString, ',');
            myArray[i] = std::stoi(subMyString);
        }
        return myArray;
    
    }


    std::unordered_map<std::string, bool> shiftHashValuesDown(std::unordered_map<std::string, bool> hash)
    {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 20; j++) {
                std::array<int, 2> myArray = { i, j };
                
                std::string myCoordsKey = parseArrayToString(myArray);
                if (hash[myCoordsKey]) {
                    std::cout << "coord before: " << myCoordsKey << std::endl;
                    hash.erase(myCoordsKey);
                    myArray[1] ++;
                    myCoordsKey = parseArrayToString(myArray);
                    hash[myCoordsKey] = true;
                    std::cout << "coord after: " << myCoordsKey << std::endl;
                    std::cout << "hash value at : " <<  myCoordsKey<<" : " <<  hash[myCoordsKey] << std::endl;
                }
            }
        }

       
                    std::cout << "--------------------------------------------" << std::endl;

            return hash;

    }




}