#pragma once

#include <boost/spirit/home/x3.hpp>


namespace pdl::spirit::grammar::skipped
{
    const auto whitespace             = x3::space;

    const auto singleLineCommentType1 = x3::lit('#') >> *(x3::char_ - x3::eol);
    const auto singleLineCommentType2 = x3::lit("//") >> *(x3::char_ - x3::eol);
    const auto multiLineComment       = x3::lit("/*") >> *(x3::char_ - x3::lit("*/")) >> x3::lit("*/");
    const auto comment                = singleLineCommentType1 | singleLineCommentType2 | multiLineComment;

    const auto anything               = *~whitespace;

}  // namespace skipped.
