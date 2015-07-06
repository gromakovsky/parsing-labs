#include "parser.h"

#include <stdexcept>

namespace parsing
{
   void parser::ensure(const std::set<token_t> & tokens) const
   {
      if (!tokens.count(*it))
      {
         std::string expected;

         for (auto token : tokens)
         {
            expected += to_string(token);
            expected += " or ";
         }

         expected.erase(expected.length() - 4);

         throw std::runtime_error(std::string("Wrong input format at position ") + std::to_string(it.pos()) + ", " + expected + " was expected, but " + it.token_as_string() + " was found");
      }
   }

   parser::parser(std::istream & is) : it(is)
   {
   }

   node * parser::S()
   // S -> QnVN;S'
   {
      node * tree = new node("S");

      ensure({NAME, QUALIFIER});

      switch (*it)
      {
      // S -> nVN;
      case NAME:
      case QUALIFIER:
         // Q
         tree->add_child(Q());
         
         // n
         ensure({NAME});
         tree->add_child(it.token_as_string());
         ++it;

         // V
         tree->add_child(V());

         // N
         tree->add_child(N());

         // ;
         ensure({SEMICOLON});
         tree->add_child(";");
         ++it;

         // S'
         tree->add_child(SPrime());

         break;

      default:
         throw std::logic_error("Unreachable place");
      }

      return tree;
   }

   node * parser::SPrime()
   // S' -> S
   // S' -> ε
   {
      node * tree = new node("S'");

      ensure({NAME, QUALIFIER, END});

      switch (*it)
      {
      case NAME:
      case QUALIFIER:
         // S
         tree->add_child(S());

         break;

      case END:
         // ε

         break;

      default:
         throw std::logic_error("Unreachable place");
      }
      
      return tree;
   }

   node * parser::V()
   // V -> *V
   // V-> n
   {
      node * tree = new node("V");

      ensure({NAME, ASTERISK});

      switch (*it)
      {
      case NAME:
         // n
         tree->add_child(it.token_as_string());
         ++it;

         break;

      case ASTERISK:
         // *
         tree->add_child("*");
         ++it;

         // V
         tree->add_child(V());

         break;

      default:
         throw std::logic_error("Unreachable place");
      }

      return tree;
   }

   node * parser::N()
   // N -> ,VN
   // N -> ε
   {
      node * tree = new node("N");

      ensure({COMMA, SEMICOLON});

      switch (*it)
      {
      case COMMA:
         // ,
         tree->add_child(",");
         ++it;

         // V
         tree->add_child(V());

         // N
         tree->add_child(N());

         break;

      case SEMICOLON:
         // ε

         break;

      default:
         throw std::logic_error("Unreachable place");
      }

      return tree;
   }
   
   node *parser::Q()
   // Q -> qualifier
   // Q -> eps
   {
      node * tree = new node("Q");

      ensure({QUALIFIER, NAME});

      switch (*it)
      {
      case QUALIFIER:
         // qualifier
         ensure({QUALIFIER});
         tree->add_child(it.token_as_string());
         ++it;

         break;

      case NAME:
         // ε

         break;

      default:
         throw std::logic_error("Unreachable place");
      }

      return tree;
   }
      
   node * parser::parse()
   {
      auto res = S();
      ensure({END});
      return res;
   }
}
