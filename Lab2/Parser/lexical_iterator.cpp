#include "lexical_iterator.h"

#include <cctype>
#include <stdexcept>
#include <iostream>


namespace parsing
{
   lexical_iterator::lexical_iterator() : is(std::cin), valid(false)
   {
   }

   lexical_iterator::lexical_iterator(std::istream & is) : is(is), valid(true), next_pos(0), cur_token(NAME)
   {
      do
      {
         read_next();
      }
      while (isspace(next_char));

      operator++();
      cur_pos = 0;
   }

   bool lexical_iterator::operator==(const lexical_iterator & rhs)
   {
      if (valid != rhs.valid)
      {
         return false;
      }

      if (!valid && !rhs.valid)
      {
         return true;
      }

      return cur_pos == rhs.cur_pos;
   }

   bool lexical_iterator::operator!=(const lexical_iterator & rhs)
   {
      return !(*this == rhs);
   }

   lexical_iterator & lexical_iterator::operator++()
   {
      if (!valid)
      {
         return *this;
      }

      if (cur_token == END)
      {
         valid = false;
         return *this;
      }

      cur_pos = next_pos;

      while (isspace(next_char))
      {
         read_next();
      }

      if (isalpha(next_char))
      {
         cur_token = NAME;
         cur_token_string.clear();

         while (can_be_in_name(next_char))
         {
            cur_token_string += next_char;
            read_next();
         }
         
         if (is_qualifier(cur_token_string))
         {
            cur_token = QUALIFIER;
         }

         /*while (isspace(next_char))
         {
            read_next();
         }*/
      }
      else
      {
         cur_token_string = next_char;

         switch (next_char)
         {
         case '*' :
            cur_token = ASTERISK;
            break;

         case ',' :
            cur_token = COMMA;
            break;

         case ';' :
            cur_token = SEMICOLON;
            break;

         case END_OF_FILE:
            cur_token = END;
            break;

         default:
            throw std::runtime_error(std::string("Parsing error. Bad symbol at position ") + std::to_string(cur_pos));
         }

         read_next();
      }

      return *this;
   }

   lexical_iterator lexical_iterator::operator++(int)
   {
      auto tmp = *this;
      ++*this;
      return tmp;
   }

   token_t lexical_iterator::operator*() const
   {
      return cur_token;
   }

   std::string lexical_iterator::token_as_string() const
   {
      return cur_token == END ? "end of file" : cur_token_string;
   }

   int lexical_iterator::pos() const
   {
      return cur_pos;
   }

   bool lexical_iterator::can_be_in_name(char c) const
   {
      return isalnum(c) || c == '_';
   }
   
   bool lexical_iterator::is_qualifier(const std::string & s)
   {
      return s == "volatile" || s == "const";
   }

   void lexical_iterator::read_next()
   {
      is.get(next_char);
      ++next_pos;

      if (!is)
      {
         next_char = END_OF_FILE;
      }
   }

   std::string to_string(token_t token)
   {
      switch (token)
      {
      case NAME:
         return "name";

      case ASTERISK:
         return "asterisk";

      case COMMA:
         return "comma";

      case SEMICOLON:
         return "semicolon";

      case END:
         return "end of input";

      default:
         throw std::logic_error("Unknown token. Unreachable place.");
      }
   }

}