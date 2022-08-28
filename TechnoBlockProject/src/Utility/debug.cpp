#include "debug.h"

#include <iostream>
#include "CoordinateGrid.h"

#include <unordered_map>

namespace debug {

	void printHashContent(std::unordered_map<std::string, bool> hash) {

		std::cout << "------------" << std::endl;

		std::unordered_map<std::string, bool>::iterator it;

		for (it = hash.begin(); it != hash.end(); it++)
		{
			if (it->second) {
				std::cout << it->second << ':' << it->first << std::endl;

				if ((it->first) == "0,16") {
					std::cout << "THE VALUE IS HERE" << std::endl;
				}


			}
		}
		std::cout << "------------" << std::endl;

	}



}