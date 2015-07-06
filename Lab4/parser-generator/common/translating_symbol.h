#pragma once

#include <string>

struct translating_symbol_t
{
   std::string code;

   explicit translating_symbol_t(const std::string & code)
      : code(code)
   {
   }
};
