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
        if (argv[i] == (std::string) "-v" || argv[i] == (std::string) "--verbose")
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
            if (verbose)
                std::cout << configContent << std::endl;
            configuration = json::parse(configContent);
        }

        configFile.close();
    }

    if (verbose)
        std::cout << "list file name: " << configuration["listFile"] << std::endl;

    if (argv[1] == (std::string) "list")
    {
        if (verbose)
        {
            std::cout << "Listing items..." << std::endl;
        }
        std::ifstream listStream(configuration["listFile"]);
        std::string listString;
        std::vector<std::string> items;
        while (std::getline(listStream, listString))
        {
            items.push_back(listString);
        }

        listStream.close();

        for (std::string &currItem : items)
        {
            std::cout << &currItem - &items[0] + 1 << ". " << currItem << std::endl;
        }
    }
    else
    {
        std::cout << argv[1] << " is not a valid instruction!" << std::endl;
    }

    return 0;
}