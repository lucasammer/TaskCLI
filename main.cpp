#include <iostream>

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
    }
    return 0;
}