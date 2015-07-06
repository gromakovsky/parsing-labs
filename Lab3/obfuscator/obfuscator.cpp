#include "obfuscator.h"

#include <random>
#include <iostream>
#include <stdexcept>

obfuscation::obfuscator::obfuscator(std::ostream & output, size_t min_len, size_t max_len, bool trace_parsing/* = false*/, bool trace_scanning/* = false*/) : MIN_LEN(min_len ? min_len : 1)
   , MAX_LEN(max_len)
   , length_distribution(MIN_LEN, MAX_LEN)
   , symbol_distribution(0, symbols_in_names.size() - 1)
   , output(output)
   , trace_parsing(trace_parsing)
   , trace_scanning(trace_scanning)
{
   if (MAX_LEN < MIN_LEN)
   {
      throw std::runtime_error("Max length can't be less than min length");
   }
}

std::string obfuscation::obfuscator::generate_name()
{
   std::string name;

   do
   {
      do
      {
         name = symbols_in_names[symbol_distribution(generator)];
      }
      while (!std::isalpha(name[0]));

      size_t len = length_distribution(generator);

      for (size_t i = 1; i != len; ++i)
      {
         name += symbols_in_names[symbol_distribution(generator)];
      }
   }
   while (generated_names.count(name));

   generated_names.insert(name);

   return name;
}

std::string obfuscation::obfuscator::process_name(const std::string & name)
{
   if (!names_map.count(name))
   {
      names_map[name] = generate_name();
   }

   return names_map[name];
}

std::string obfuscation::obfuscator::split_string(const std::string & str) const
{
   std::string res;

   for (size_t i = 1; i < str.length() - 1; ++i)
   {
      res += " \""; 
      res += str[i];
      res += "\"\n";
   }
   return res;
}

std::string obfuscation::obfuscator::convert_number(int num) const
{
   return std::string("(") + std::to_string(num / 2) + " + " + std::to_string(num - num / 2) + ")";
}

int obfuscation::obfuscator::obfuscate(const std::string & filename)
{
   if (!start_scan(filename))
   {
      return EXIT_FAILURE;
   }

   current_input = filename;

   output << "/*" << std::endl;
   output << "\tIt is an obfuscated version of " << filename << std::endl;
   output << "*/" << std::endl;
   output << std::endl;

   yy::obfuscation_parser parser(*this);
   parser.set_debug_level(trace_parsing);
   int res = parser.parse();

   finish_scan();

   output << std::endl;
   return res;
}

void obfuscation::obfuscator::error(const yy::location & l, const std::string & m) const
{
   std::cerr << l << ": " << m << std::endl;
}

void obfuscation::obfuscator::error(const std::string & m) const
{
   std::cerr << m << std::endl;
}
