#include "cdecl_lexical_iterator.h"

#include <cctype>
#include <iostream>
#include <stdexcept>

cdecl_lexical_iterator::cdecl_lexical_iterator()
   : is_(std::cin)
   , finished_(true)
{
}

cdecl_lexical_iterator::cdecl_lexical_iterator(std::istream & is)
   : is_(is)
   , finished_(false)
   , next_pos_(0)
   , cur_token_(IDENTIFIER)
{
   do
   {
      read_next();
   }
   while (std::isspace(next_char_));

   operator++();
   cur_pos_ = 0;
}

lexical_iterator & cdecl_lexical_iterator::operator++()
{
   if (finished_)
   {
      return *this;
   }

   if (cur_token_ == END)
   {
      finished_ = false;
      return *this;
   }

   cur_pos_ = next_pos_;

   while (std::isspace(next_char_))
   {
      read_next();
   }

   if (std::isalpha(next_char_))
   {
      cur_token_ = IDENTIFIER;
      cur_token_repr_.clear();

      while (can_be_in_name(next_char_))
      {
         cur_token_repr_ += next_char_;
         read_next();
      }
   }
   else
   {
      if (can_be_in_name(next_char_))
      {
         throw std::runtime_error("Lexical failure: invalid identifier at position " + std::to_string(cur_pos_));
      }

      cur_token_repr_ = next_char_;

      switch (next_char_)
      {
      case '*' :
         cur_token_ = ASTERISK;
         break;

      case ',' :
         cur_token_ = COMMA;
         break;

      case ';' :
         cur_token_ = SEMICOLON;
         break;

      case END_OF_FILE:
         cur_token_ = END;
         break;

      default:
         throw std::runtime_error("Lexical failure: unknown symbol at position " + std::to_string(cur_pos_));
      }

      read_next();
   }

   return *this;
}

int cdecl_lexical_iterator::operator*() const
{
   return cur_token_;
}

std::string cdecl_lexical_iterator::representation() const
{
   return cur_token_ == END ? "end of file" : cur_token_repr_;
}

size_t cdecl_lexical_iterator::pos() const
{
   return cur_pos_;
}

bool cdecl_lexical_iterator::can_be_in_name(char c) const
{
   return std::isalnum(c) || c == '_';
}

void cdecl_lexical_iterator::read_next()
{
   is_.get(next_char_);
   ++next_pos_;

   if (!is_)
   {
      next_char_ = END_OF_FILE;
   }
}
