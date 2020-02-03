//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>

#include <parser/Loader.hpp>
#include <fstream>
#include <iterator>
#include <sstream>


bool Loader::parse_file(const std::string &filename, Game &game) {
    std::ifstream file(filename);
    std::string line;
    game.clear();


    if (file.is_open()) {
        while  (getline(file, line)) {
            std::istringstream iss(line);
            std::vector<std::string> tokens(std::istream_iterator<std::string>{iss},
                                            std::istream_iterator<std::string>());

            if (tokens.size() == 3) {

                file.close();
                return false;
            }

            file.close();
            return false;

        }
    }
    return false;
}
