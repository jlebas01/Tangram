//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>

#include <parser/C_Loader.hpp>
#include <fstream>
#include <cstring>
#include <shape/C_STriangle.hpp>
#include <shape/C_MTriangle.hpp>
#include <shape/C_GTriangle.hpp>
#include <shape/C_Square.hpp>
#include <shape/C_Parallelogram.hpp>


std::filesystem::path C_Loader::__RefactorPath(const std::filesystem::path &path) {
    std::filesystem::path cwd = std::filesystem::current_path();

    std::size_t pos = cwd.string().find("Tangram");

    std::filesystem::path absolute(
            cwd.string().substr(0, pos + std::string("Tangram").size()) + std::string("/extern/board/") +
            path.string());
    return absolute;
}

bool C_Loader::ParseFile(const std::string &filename, C_Game &game) {
    //std::filesystem::path path(__RefactorPath(filename));
    std::filesystem::path path(filename);
    std::ifstream file;
    std::string shape;

    std::vector<std::shared_ptr<A_Shape>> vec_objective;
    MLV_Color color;
    bool reverse;
    double x = 0.0, y = 0.0, angular = 0.0;
    double striangle=0;
    double gtriangle=0;
    game.Clear();

    file.open(path, std::ifstream::in);

    if (file.is_open()) {
        while (file >> shape >> x >> y >> angular >> color >> reverse) {
            char *buf = const_cast<char *>(shape.c_str());
            switch (__StrToInt(buf)) {
                case __StrToInt("C_STriangle") :
                    if (striangle == 0){
                        game.addShape(std::shared_ptr<A_Shape>(std::make_shared<C_STriangle>(T_Point(50.0,50.0), 0.0, color)));
                        striangle++;
                    }
                    else {
                        game.addShape(std::shared_ptr<A_Shape>(std::make_shared<C_STriangle>(T_Point(100.0,100.0), 0.0, color)));
                    }

                    vec_objective.push_back(std::shared_ptr<A_Shape>(
                            std::make_shared<C_STriangle>(T_Point<double>(x, y), angular, game.GetObjectiveColor())));
                    break;
                case __StrToInt("C_MTriangle") :
                    game.addShape(std::shared_ptr<A_Shape>(std::make_shared<C_MTriangle>(T_Point(150.0,50.0), 0.0, color)));
                    vec_objective.push_back(std::shared_ptr<A_Shape>(
                            std::make_shared<C_MTriangle>(T_Point<double>(x, y), angular, game.GetObjectiveColor())));
                    break;
                case __StrToInt("C_GTriangle") :
                    if (gtriangle == 0){
                        game.addShape(std::shared_ptr<A_Shape>(std::make_shared<C_GTriangle>(T_Point(200.0,150.0), 0.0, color)));
                        gtriangle++;
                    }
                    else {
                        game.addShape(std::shared_ptr<A_Shape>(std::make_shared<C_GTriangle>(T_Point(400.0, 150.0), 0.0, color)));
                    }

                    vec_objective.push_back(std::shared_ptr<A_Shape>(
                            std::make_shared<C_GTriangle>(T_Point<double>(x, y), angular, game.GetObjectiveColor())));
                    break;
                case __StrToInt("C_Square") :
                    game.addShape(std::shared_ptr<A_Shape>(std::make_shared<C_Square>(T_Point(350.0,50.0), 0.0, color)));
                    vec_objective.push_back(std::shared_ptr<A_Shape>(
                            std::make_shared<C_Square>(T_Point<double>(x, y), angular, game.GetObjectiveColor())));
                    break;
                case __StrToInt("C_Parallelogram") :
                    game.addShape(std::shared_ptr<A_Shape>(std::make_shared<C_Parallelogram>(T_Point(50.0,150.0), 0.0, color)));
                    vec_objective.push_back(std::shared_ptr<A_Shape>(
                            std::make_shared<C_Parallelogram>(T_Point<double>(x, y), angular, game.GetObjectiveColor(), reverse)));
                    if (reverse){
                        std::cout << "reverse : " << reverse << std::endl;}
                    break;
            }
        }
        game.SetObjective(vec_objective);
        vec_objective.clear();
        std::vector<std::shared_ptr<A_Shape>>().swap(vec_objective);
        file.close();
        return true;
    }
    file.close();
    vec_objective.clear();
    std::vector<std::shared_ptr<A_Shape>>().swap(vec_objective);
    return false;
}
