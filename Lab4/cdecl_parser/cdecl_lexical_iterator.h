#pragma once

#include "lexical_iterator.h"

#include <istream>
#include <string>

enum token_t
{
   END, IDENTIFIER, SEMICOLON, ASTERISK, COMMA
};

struct cdecl_lexical_iterator : lexical_iterator
{
   cdecl_lexical_iterator();
   cdecl_lexical_iterator(std::istream & is);

   int operator*()               const;
   std::string representation()  const;
   size_t pos()                  const;

   lexical_iterator & operator++();

private:
   bool can_be_in_name(char c)   const;
   void read_next();

private:
   static const char END_OF_FILE = '$';

   std::istream & is_;
   bool finished_;

   char next_char_;
   size_t cur_pos_, next_pos_;
   token_t cur_token_;
   std::string cur_token_repr_;

};
