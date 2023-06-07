#include <iostream>
#include <variant>

int main()
{
    try
    {
        std::variant<int, std::string> data;
        data = 10; // we are using the integer memory location for storing 10

        std::cout << std::get<0>(data) << "\n";

        data = "s";

        std::cout << std::get<1>(data) << "\n"; // for string which is at 1st index

        data = "s";

        std::cout << std::get<0>(data) << "\n"; // error!!!!!!!
    }
    catch (const std::bad_variant_access &e)
    {
        std::cerr << "Bad access" << '\n';
    }
}