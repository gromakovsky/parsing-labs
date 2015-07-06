#pragma once

#include <stdexcept>

struct parsing_error : std::runtime_error
{
   parsing_error(const char * msg) : std::runtime_error(msg)
   {
   }
};

