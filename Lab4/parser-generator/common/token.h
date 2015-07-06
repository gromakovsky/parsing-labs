#pragma once

#include <string>

struct token_t
{
   size_t id;
   std::string representation;
};

struct empty_token_t {};

using token_id_t = size_t;
constexpr token_id_t empty_token_id = static_cast<size_t>(-1);
