#pragma once

#include "errors.h"
#include "user_types.h"
#include "lexical_iterator.h"

// Declaration:
template <class Context>
struct cdecl_parser
{
	cdecl_parser(Context & ctx, lexical_iterator & it);

	void start_parsing();

private:
	node_ptr start();
	node_ptr next();
	node_ptr var();

	void ensure(int token);

private:
	Context & ctx;
	lexical_iterator & it_;
};

// Definitions:
template <class Context>
cdecl_parser<Context>::cdecl_parser(Context & ctx, lexical_iterator & it)
	: ctx(ctx)
	, it_(it)
{}

template <class Context>
void cdecl_parser<Context>::start_parsing()
{
	start();
	ensure(0);
}

template <class Context>
node_ptr cdecl_parser<Context>::start()
{
node_ptr result_;
switch (*it_)
{
// start → IDENTIFIER var next SEMICOLON { ctx.construct(result_, "start", {value0_, value1_, value2_, value3_}); ctx.root_ = result_; }
	case 1: //IDENTIFIER
	{
		// IDENTIFIER
		ensure(1);
		std::string value0_ = it_.representation();
		++it_;

		// var
		node_ptr value1_ = var();

		// next
		node_ptr value2_ = next();

		// SEMICOLON
		ensure(2);
		std::string value3_ = it_.representation();
		++it_;

		// { ctx.construct(result_, "start", {value0_, value1_, value2_, value3_}); ctx.root_ = result_; }
 ctx.construct(result_, "start", {value0_, value1_, value2_, value3_}); ctx.root_ = result_; 
		break;
	}
	default:
		throw parsing_error("input doesn't match grammar");
}
return result_;

}

template <class Context>
node_ptr cdecl_parser<Context>::next()
{
node_ptr result_;
switch (*it_)
{
// next → { ctx.construct(result_, "next", {}); }
	case 2: //SEMICOLON
	{
		// { ctx.construct(result_, "next", {}); }
 ctx.construct(result_, "next", {}); 
		break;
	}
// next → COMMA var next { ctx.construct(result_, "next", {value0_, value1_, value2_}); }
	case 4: //COMMA
	{
		// COMMA
		ensure(4);
		std::string value0_ = it_.representation();
		++it_;

		// var
		node_ptr value1_ = var();

		// next
		node_ptr value2_ = next();

		// { ctx.construct(result_, "next", {value0_, value1_, value2_}); }
 ctx.construct(result_, "next", {value0_, value1_, value2_}); 
		break;
	}
	default:
		throw parsing_error("input doesn't match grammar");
}
return result_;

}

template <class Context>
node_ptr cdecl_parser<Context>::var()
{
node_ptr result_;
switch (*it_)
{
// var → IDENTIFIER { ctx.construct(result_, "var", {value0_}); }
	case 1: //IDENTIFIER
	{
		// IDENTIFIER
		ensure(1);
		std::string value0_ = it_.representation();
		++it_;

		// { ctx.construct(result_, "var", {value0_}); }
 ctx.construct(result_, "var", {value0_}); 
		break;
	}
// var → ASTERISK var { ctx.construct(result_, "var", {value0_, value1_}); }
	case 3: //ASTERISK
	{
		// ASTERISK
		ensure(3);
		std::string value0_ = it_.representation();
		++it_;

		// var
		node_ptr value1_ = var();

		// { ctx.construct(result_, "var", {value0_, value1_}); }
 ctx.construct(result_, "var", {value0_, value1_}); 
		break;
	}
	default:
		throw parsing_error("input doesn't match grammar");
}
return result_;

}

template <class Context>
void cdecl_parser<Context>::ensure(int token)
{
	if (*it_ != token)
		throw parsing_error("input doesn't match grammar");
}

