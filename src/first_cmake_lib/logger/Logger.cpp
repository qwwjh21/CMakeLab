#include "Logger.h"
#include <iostream>

Logger::Logger()
{
    std::cout << "Create Logger()" << std::endl;
}

Logger::~Logger()
{
    std::cout << "~Logger()" << std::endl;
}