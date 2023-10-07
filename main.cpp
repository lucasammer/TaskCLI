#include <iostream>
#include <filesystem>
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <instruction>" << std::endl
                  << std::endl
                  << "Available instructions:" << std::endl
                  << "  - list" << std::endl
                  << "  - help" << std::endl
                  << "  - add" << std::endl
                  << "  - remove" << std::endl;
        return 1;
    }

    if (!std::filesystem::exists("./.config"))
    {
        std::ofstream configFile("./.config");
        configFile << "";
        configFile.close();
        std::cout << "created .config file" << std::endl;
    }
    else
    {
        std::cout << "found .config file" << std::endl;
        std::string configContent;
        std::ifstream configFile("./.config");

        while (std::getline(configFile, configContent))
        {
            std::cout << configContent;
        }

        configFile.close();
    }

    return 0;
}