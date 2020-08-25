#pragma once

#include <boost/spirit/home/x3/char/char_class.hpp>
#include <boost/spirit/home/x3/numeric/uint.hpp>
#include <boost/spirit/home/x3/string/literal_string.hpp>


namespace pdl::spirit::grammar::types {

constexpr auto bin = x3::lit("0b") > x3::bin;
constexpr auto hex = x3::lit("0x") > x3::hex;
constexpr auto byte = x3::xdigit >> x3::xdigit;
constexpr auto word = byte >> byte;
constexpr auto octet = x3::uint_parser<uint8_t, 10, 1, 3> { };

}  // namespace types.
