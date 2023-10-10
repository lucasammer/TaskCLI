#include <iostream>
#include <filesystem>
#include <fstream>
#include <json.hpp>

using json = nlohmann::json;

struct config
{
    std::string listFile;
};

int main(int argc, char *argv[])
{
    bool verbose = false;
    for (int i = 0; i < argc; i++)
    {
        if (argv[i] == "-v" || argv[i] == "--verbose")
        {
            verbose = true;
        }
    }

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

    json configuration;

    if (!std::filesystem::exists("./.config"))
    {
        std::ofstream configFile("./.config");
        json defaultConfig;
        defaultConfig["listFile"] = "./.list";
        configFile << defaultConfig;
        configuration = defaultConfig;
        configFile.close();
        std::ofstream listFile("./.list");
        listFile << "";
        listFile.close();
        std::cout << "created .config and .list file" << std::endl;
    }
    else
    {
        if (verbose)
            std::cout << "found .config file" << std::endl;
        std::string configContent;
        std::ifstream configFile("./.config");

        while (std::getline(configFile, configContent))
        {
            std::cout << configContent << std::endl;
            configuration = json::parse(configContent);
        }

        configFile.close();
    }

    if (verbose)
        std::cout << "list file name: " << configuration["listFile"] << std::endl;

    return 0;
}