#pragma once

#include <boost/spirit/home/x3/char/char_class.hpp>
#include <boost/spirit/home/x3/numeric/uint.hpp>
#include <boost/spirit/home/x3/string/literal_string.hpp>


namespace pdl::spirit::grammar::skipped {

constexpr auto whitespace             = x3::space;

constexpr auto singleLineCommentType1 = x3::lit('#') >> *(x3::char_ - x3::eol);
constexpr auto singleLineCommentType2 = x3::lit("//") >> *(x3::char_ - x3::eol);
constexpr auto multiLineComment       = x3::lit("/*") >> *(x3::char_ - x3::lit("*/")) >> x3::lit("*/");
constexpr auto comment                = singleLineCommentType1 | singleLineCommentType2 | multiLineComment;

constexpr auto anything               = *~whitespace;

}  // namespace skipped.
