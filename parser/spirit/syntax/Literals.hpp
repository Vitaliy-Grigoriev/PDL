#pragma once

#include "Identifier.hpp"

#include <cstdint>
#include <boost/spirit/home/x3/support/ast/variant.hpp>


namespace pdl::spirit::syntax::literal {

struct Auto : Annotation<Auto>
{
    [[maybe_unused]]
    bool discovered = false;
};

struct Default : Annotation<Default>
{
    [[maybe_unused]]
    bool discovered = false;
};

struct Placeholder : Annotation<Placeholder>
{
    uint16_t value = 0;
};

struct Designator : Annotation<Designator>
{
    Identifier member;
};

struct Numeric : Annotation<Numeric>
{
    std::int64_t value = 0;
};

struct Float : Annotation<Float>
{
    float value = 0.0;
};

struct Boolean : Annotation<Boolean>
{
    bool value = false;
};

struct String : Annotation<String>
{
    std::string value;
};

struct MacAddress : Annotation<MacAddress>
{
    std::string value;
};

struct IPv4Address : Annotation<IPv4Address>
{
    std::string value;
};

struct Definition : Annotation<Definition>
{
    std::string value;
};

struct Prefix : Annotation<Prefix>
{
    std::string value;
};


struct MappingMemberAccess : x3::variant<Placeholder,
                                         Numeric,
                                         Definition>,
                             Annotation<MappingMemberAccess>
{ };

struct MappingMember : Annotation<MappingMember>
{
    std::string statement;
    std::string member;
    MappingMemberAccess value;
};

struct DefaultValue : x3::variant<Placeholder,
                                  Numeric,
                                  Definition>,
                      Annotation<DefaultValue>
{
    using base_type::base_type;
    using base_type::operator=;
};

struct Literal : x3::variant<Default,
                             Numeric,
                             Float,
                             Boolean,
                             String,
                             MacAddress,
                             IPv4Address>,
                 Annotation<Literal>
{
    using base_type::base_type;
    using base_type::operator=;
};

struct Id : x3::variant<Auto,
                        Numeric,
                        Definition>,
            Annotation<Id>
{
    using base_type::base_type;
    using base_type::operator=;
};

struct Variable : x3::variant<Literal,
                              types::InternalDefines,
                              Definition>,
                  Annotation<Variable>
{
    using base_type::base_type;
    using base_type::operator=;
};

}  // namespace literal.

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::literal::Auto,          discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::literal::Default,       discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::literal::Placeholder,   value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::literal::Designator,    member)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::literal::Numeric,       value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::literal::Float,         value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::literal::Boolean,       value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::literal::String,        value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::literal::MacAddress,    value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::literal::IPv4Address,   value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::literal::Definition,    value)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::literal::Prefix,        value)
