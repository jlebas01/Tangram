//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>
#include <parser/C_Save.hpp>
#include <random>

C_Save::C_Save() {
    mCurrentPages = std::stoi(__ExecCommand(std::string(" ls ../extern/board/ | wc -l").c_str()));
}

std::string C_Save::__ExecCommand(const char *cmd) {
    std::array<char, 128> buffer{};
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}


unsigned int C_Save::__WhereSaveIt() {
    unsigned int nb_file = 0;
    for (unsigned int i = 1; i < mCurrentPages + 1; i++) {
        nb_file = std::stoi(
                __ExecCommand(
                        std::string(" ls ../extern/board/page").append(std::to_string(i)).append("/ | wc -l").c_str()));
        if (nb_file < 12) {
            return i;
        }
    }


    if (0 < __ExecCommand(std::string("mkdir ../extern/board/page").append(std::to_string(mCurrentPages + 1)).c_str()).length()) {
        std::cerr << "error appends" << "file: " << __FILE__ << "/ : " << __func__ << "():" << __LINE__
                  << std::endl;
    }

    return ++mCurrentPages;

}

bool C_Save::__DeleteFile(std::filesystem::path file, unsigned int page) {
    unsigned int nb_file;

    if (0 < __ExecCommand(std::string("rm ../extern/board/page").append(std::to_string(page)).append("/").append(
            file.string()).c_str()).length())
        return false;


    nb_file = stoi(__ExecCommand(
            std::string(" ls ../extern/board/page").append(std::to_string(page)).append("/| wc -l").c_str()));
    if (nb_file == 0 && page != 0) {
        if (0 <
                __ExecCommand(
                        std::string("rm -d ../extern/board/page").append(std::to_string(page)).append("/").c_str()).length()) {
            std::cerr << "error appends" << "file: " << __FILE__ << "/ : " << __func__ << "():" << __LINE__
                      << std::endl;
            std::cerr << std::string("Impossible to delete this directory ../extern/board/page").append(
                    std::to_string(page)) << std::endl;
            return false;
        }
    }
    return true;
}

bool C_Save::Save(const std::vector<std::shared_ptr<A_Shape>> &Game) {
    std::shared_ptr<char[]> rdm(new char[8]);
    __GenRandom(rdm, 8);
    std::string filename = std::move(std::string("save_").append(rdm.get()).append(".txt"));
    std::string path =  std::string("../extern/board/page") + std::to_string(C_Save::__WhereSaveIt()) +
            std::string("/").append(filename);
    std::ofstream file(path);
    if (file.is_open()) {
        for (auto &it : Game) {
            const T_Point<double> p = it->aLeftCorner();
            file << it->aGetShape() << " " << p.x << " " << p.y << " " << it->aCurrentAngular() << " " << it->aGetColor() << std::endl;
        }
        std::cout << path << std::endl;
        file.close();
    } else {
        std::cerr << "File can't be open" << "file: " << __FILE__ << "/ : " << __func__ << "():" << __LINE__
                  << std::endl;
        return false;
    }
    return true;
}

void C_Save::__GenRandom(const std::shared_ptr<char[]>& s, const int len) {
    std::random_device rdm;
    std::uniform_int_distribution<int> dist(0, 2000);
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s.get()[i] = alphanum[dist(rdm) % (sizeof(alphanum) - 1)];
    }

    s.get()[len] = 0;
}

