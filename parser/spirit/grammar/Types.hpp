#pragma once

#include <boost/spirit/home/x3.hpp>


namespace pdl::spirit::grammar::types
{
    namespace x3 = boost::spirit::x3;

    const auto bin = x3::lit("0b") > x3::bin;
    const auto hex = x3::lit("0x") > x3::hex;
    const auto byte = x3::xdigit >> x3::xdigit;
    const auto word = byte >> byte;
    const auto octet = x3::uint_parser<uint8_t, 10, 1, 3>{};

}  // namespace types.
