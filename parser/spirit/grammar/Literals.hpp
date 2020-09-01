#pragma once

#include "Types.hpp"
#include "Identifier.hpp"

#include <parser/spirit/syntax/Literals.hpp>


namespace pdl::spirit::grammar::literals {

struct LiteralRuleId : RuleId {
};

constexpr x3::rule<LiteralRuleId, syntax::literal::Auto>          autoLiteral          { "Auto Literal" };
constexpr x3::rule<LiteralRuleId, syntax::literal::Default>       defaultLiteral       { "Default Literal" };
constexpr x3::rule<LiteralRuleId, syntax::literal::Placeholder>   placeholderLiteral   { "Placeholder Literal" };
constexpr x3::rule<LiteralRuleId, syntax::literal::Designator>    designatorLiteral    { "Designator Literal" };
constexpr x3::rule<LiteralRuleId, syntax::literal::Numeric>       numericLiteral       { "Numeric Literal" };
constexpr x3::rule<LiteralRuleId, syntax::literal::Float32>       float32Literal       { "Float32 Literal" };
constexpr x3::rule<LiteralRuleId, syntax::literal::Float64>       float64Literal       { "Float64 Literal" };
constexpr x3::rule<LiteralRuleId, syntax::literal::Boolean>       booleanLiteral       { "Boolean Literal" };
constexpr x3::rule<LiteralRuleId, syntax::literal::String>        stringLiteral        { "String Literal" };
constexpr x3::rule<LiteralRuleId, syntax::literal::MacAddress>    macAddressLiteral    { "Mac Address Literal" };
constexpr x3::rule<LiteralRuleId, syntax::literal::IPv4Address>   ipv4AddressLiteral   { "IPv4 Address Literal" };
constexpr x3::rule<LiteralRuleId, syntax::literal::Definition>    definitionLiteral    { "Definition Literal" };
constexpr x3::rule<LiteralRuleId, syntax::literal::Prefix>        prefixLiteral        { "Prefix Literal" };

constexpr x3::rule<LiteralRuleId, syntax::literal::DefaultValue>   defaultValueLiteral   { "Default Value Literal" };
constexpr x3::rule<LiteralRuleId, syntax::literal::Id>             idLiteral             { "Id Literal" };
constexpr x3::rule<LiteralRuleId, syntax::literal::Literal>        literal               { "Literal" };


const auto autoLiteral_def        = keywords::_auto;
const auto defaultLiteral_def     = keywords::_default;
const auto placeholderLiteral_def = symbols::underline > x3::uint16;
const auto designatorLiteral_def  = symbols::dot > identifier;
const auto numericLiteral_def     = types::bin | types::hex | x3::int64;
const auto float32Literal_def     = x3::real_parser<float, x3::strict_real_policies<float>> { };
const auto float64Literal_def     = x3::real_parser<double, x3::strict_real_policies<double>> { };
const auto booleanLiteral_def     = keywords::_boolean;
const auto stringLiteral_def      = x3::lexeme[symbols::quote > *(x3::char_ - symbols::quote) > symbols::quote];
const auto macAddressLiteral_def  = x3::raw[x3::repeat(5)[types::byte >> symbols::colon] >> types::byte];
const auto ipv4AddressLiteral_def = x3::raw[x3::repeat(3)[types::octet >> symbols::dot] >> types::octet];
const auto definitionLiteral_def  = x3::raw[x3::lexeme[x3::alnum >> *(x3::alnum | symbols::underline | symbols::space | symbols::dot | symbols::minus)]];
const auto prefixLiteral_def      = x3::raw[x3::lexeme[x3::upper >> *(x3::upper | symbols::underline)] - keywords::reservedWords];

const auto defaultValueLiteral_def = placeholderLiteral | numericLiteral | definitionLiteral;
const auto idLiteral_def           = autoLiteral | numericLiteral | definitionLiteral;
const auto literal_def             = defaultLiteral |
                                     ipv4AddressLiteral |
                                     macAddressLiteral |
                                     float32Literal |
                                     float64Literal |
                                     numericLiteral |
                                     booleanLiteral |
                                     stringLiteral;


BOOST_SPIRIT_DEFINE(autoLiteral);
BOOST_SPIRIT_DEFINE(defaultLiteral);
BOOST_SPIRIT_DEFINE(placeholderLiteral);
BOOST_SPIRIT_DEFINE(designatorLiteral);
BOOST_SPIRIT_DEFINE(numericLiteral);
BOOST_SPIRIT_DEFINE(float32Literal);
BOOST_SPIRIT_DEFINE(float64Literal);
BOOST_SPIRIT_DEFINE(booleanLiteral);
BOOST_SPIRIT_DEFINE(stringLiteral);
BOOST_SPIRIT_DEFINE(macAddressLiteral);
BOOST_SPIRIT_DEFINE(ipv4AddressLiteral);
BOOST_SPIRIT_DEFINE(definitionLiteral);
BOOST_SPIRIT_DEFINE(prefixLiteral);

BOOST_SPIRIT_DEFINE(defaultValueLiteral);
BOOST_SPIRIT_DEFINE(idLiteral);
BOOST_SPIRIT_DEFINE(literal);

}  // namespace literals.
