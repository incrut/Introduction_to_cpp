#include <iostream>
#include <string>

#define PRINT_VALUE(value) std::cout << value << std::endl
#define PRINT_ERROR() std::cerr << "Invalid command. Please use either \"min\" or \"max\"." << std::endl

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        PRINT_ERROR();
        return 1;
    }

    std::string command = argv[3];
    float num1 = std::stof(argv[1]);
    float num2 = std::stof(argv[2]);
    float result;

    if (command == "min")
    {
        result = (num1 < num2) ? num1 : num2;
        PRINT_VALUE(result);
    }
    else if (command == "max")
    {
        result = (num1 > num2) ? num1 : num2;
        PRINT_VALUE(result);
    }
    else
    {
        PRINT_ERROR();
        return 1;
    }

    return 0;
}