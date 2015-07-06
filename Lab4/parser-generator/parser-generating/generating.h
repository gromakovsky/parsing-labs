#pragma once

#include "grammar.h"

#include <string>

std::string generate_function(const grammar_ptr & grammar, const nonterm_t & non_term);
