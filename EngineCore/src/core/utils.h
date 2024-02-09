#pragma once
#include <fstream>
#include <sstream>

namespace utils
{
    inline std::string stringify_file(const std::string& filepath)
    {
        std::ifstream file(filepath);

        if (!file)
        {
            return "";
        }

        std::stringstream ss;
        ss << file.rdbuf();
        return ss.str();
    }
}