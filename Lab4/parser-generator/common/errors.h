#pragma once

#include <exception>

#include <boost/exception/exception.hpp>
#include <boost/exception/info.hpp>

struct base_error : virtual std::exception, virtual boost::exception
{
   ~base_error() noexcept {}
};

struct grammar_read_error : base_error
{
   ~grammar_read_error() noexcept {}
};

struct grammar_file_open_error : grammar_read_error
{
   ~grammar_file_open_error() noexcept {}
};

struct grammar_unexpected_character : grammar_read_error
{
   ~grammar_unexpected_character() noexcept {}
};

typedef boost::error_info<struct tag_terminal_name, std::string> errinfo_terminal_name;

struct unknown_terminal : base_error
{
   ~unknown_terminal() noexcept {}
};

typedef boost::error_info<struct tag_message, std::string> errinfo_message;

struct invalid_grammar : base_error
{
   ~invalid_grammar() noexcept {}
};
