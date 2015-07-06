#pragma once

#include <istream>
#include <string>

namespace parsing
{
   enum token_t
   {
      NAME, ASTERISK, COMMA, SEMICOLON, END, QUALIFIER
   };
   
   std::string to_string(token_t token);

   class lexical_iterator : public std::iterator<std::input_iterator_tag, token_t>
   {
      const static char END_OF_FILE = '%';
      
      std::istream & is;
      bool valid;
      
      char next_char;
      int cur_pos, next_pos;
      token_t cur_token;
      std::string cur_token_string;

      bool can_be_in_name(char c) const;
      bool is_qualifier(std::string const & s);
      void read_next();

   public:

      lexical_iterator();
      lexical_iterator(std::istream & is);

      bool operator==(const lexical_iterator & rhs);
      bool operator!=(const lexical_iterator & rhs);

      lexical_iterator & operator++();
      lexical_iterator operator++(int);

      token_t operator*() const;
      std::string token_as_string() const;

      int pos() const;

   };
}