#include "exception.hpp"

using namespace engn;

const char * DoubleInitException::what(void) const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
    return "Several objects of the class GameHandler have been initialized";
}