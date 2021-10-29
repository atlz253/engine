#include "exception.hpp"

#include "handler.hpp"

#include <iostream>

using namespace engn;

int main()
{
    try
    {
        Handler handler1, handler2;

        std::cerr << "DoubleInitException not work!" << std::endl;
    }
    catch(const DoubleInitException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}