//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>

#include <parser/Loader.hpp>
#include <fstream>
#include <cstring>
#include <shape/STriangle.hpp>
#include <shape/MTriangle.hpp>
#include <shape/GTriangle.hpp>
#include <shape/Square.hpp>
#include <shape/Parallelogram.hpp>


std::filesystem::path Loader::refactor_path(const std::filesystem::path &path) {
    std::filesystem::path cwd = std::filesystem::current_path();

    std::size_t pos = cwd.string().find("Tangram");

    std::filesystem::path absolute(
            cwd.string().substr(0, pos + std::string("Tangram").size()) + std::string("/extern/board/") +
            path.string());
    return absolute;
}

bool Loader::parse_file(const std::string &filename, Game &game) {
    //std::filesystem::path path(refactor_path(filename));
    std::filesystem::path path(filename);
    std::ifstream file;
    std::string shape;

    std::vector<std::shared_ptr<Shape>> vec_objective;
    double x = 0.0, y = 0.0, angular = 0.0;

    game.clear();

    file.open(path, std::ifstream::in);

    if (file.is_open()) {
        while (file >> shape >> x >> y >> angular) {
            char *buf = const_cast<char *>(shape.c_str());
            switch (str2int(buf)) {
                case str2int("STriangle") :
                    game.add_shape(std::shared_ptr<Shape>(std::make_shared<STriangle>()));
                    vec_objective.push_back(std::shared_ptr<Shape>(
                            std::make_shared<STriangle>(Point<double>(x, y), angular, game.get_Objective_Color())));
                    break;
                case str2int("MTriangle") :
                    game.add_shape(std::shared_ptr<Shape>(std::make_shared<MTriangle>()));
                    vec_objective.push_back(std::shared_ptr<Shape>(
                            std::make_shared<MTriangle>(Point<double>(x, y), angular, game.get_Objective_Color())));
                    break;
                case str2int("GTriangle") :
                    game.add_shape(std::shared_ptr<Shape>(std::make_shared<GTriangle>()));
                    vec_objective.push_back(std::shared_ptr<Shape>(
                            std::make_shared<GTriangle>(Point<double>(x, y), angular, game.get_Objective_Color())));
                    break;
                case str2int("Square") :
                    game.add_shape(std::shared_ptr<Shape>(std::make_shared<Square>()));
                    vec_objective.push_back(std::shared_ptr<Shape>(
                            std::make_shared<Square>(Point<double>(x, y), angular, game.get_Objective_Color())));
                    break;
                case str2int("Parallelogram") :
                    game.add_shape(std::shared_ptr<Shape>(std::make_shared<Parallelogram>()));
                    vec_objective.push_back(std::shared_ptr<Shape>(
                            std::make_shared<Parallelogram>(Point<double>(x, y), angular, game.get_Objective_Color())));
                    break;
            }
        }
        game.set_Objective(vec_objective);
        file.close();
        return true;
    }
    return false;
}
