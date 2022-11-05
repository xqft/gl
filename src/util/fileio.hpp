#pragma once

#include <string>
#include <fstream>
#include <sstream>

namespace util
{
    std::string read_file(const char* path)
    {
        std::string content;
        std::ifstream file;

        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            file.open(path);
            std::stringstream filestream;
            filestream << file.rdbuf();
            file.close();
            content = filestream.str();
        }
        catch(std::fstream::failure e)
        {
            //TODO: Handle err
        }
        return content;
    }
}