#pragma once

#include <string>

struct lexical_iterator
{
   virtual int operator*()                const = 0;
   virtual std::string representation()   const = 0;
   virtual size_t pos()                   const = 0;

   virtual lexical_iterator & operator++()      = 0;
   virtual lexical_iterator operator++(int)     = 0;
};
