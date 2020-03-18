#pragma once

#include "Annotation.hpp"

#include <cstdint>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>


namespace pdl::detail::syntax
{
    struct AutoLiteral : Annotation<AutoLiteral> {
        bool discovered = false;
    };

    struct DefaultLiteral : Annotation<DefaultLiteral> {
        bool discovered = false;
    };

    struct PlaceholderLiteral : Annotation<PlaceholderLiteral> {
        uint16_t value = 0;
    };

    struct NumericLiteral : Annotation<NumericLiteral> {
        std::int64_t value = 0;
    };

    struct FloatLiteral : Annotation<FloatLiteral> {
        float value = 0.0;
    };

    struct BooleanLiteral : Annotation<BooleanLiteral> {
        bool value = false;
    };

    struct StringLiteral : Annotation<StringLiteral> {
        std::string value;
    };

    struct MacAddressLiteral : Annotation<MacAddressLiteral> {
        std::string value;
    };

    struct IPv4AddressLiteral : Annotation<IPv4AddressLiteral> {
        std::string value;
    };

    struct DefinitionLiteral : Annotation<DefinitionLiteral> {
        std::string value;
    };



    struct DefaultValueLiteral : x3::variant<PlaceholderLiteral, NumericLiteral, DefinitionLiteral>, Annotation<DefaultValueLiteral> {
        using base_type::base_type;
        using base_type::operator=;
    };

    struct Literal : x3::variant<DefaultLiteral, NumericLiteral, FloatLiteral, BooleanLiteral, StringLiteral, MacAddressLiteral, IPv4AddressLiteral>, Annotation<Literal> {
        using base_type::base_type;
        using base_type::operator=;
    };

    struct IdLiteral : x3::variant<AutoLiteral, NumericLiteral, DefinitionLiteral>, Annotation<IdLiteral> {
        using base_type::base_type;
        using base_type::operator=;
    };

}   // namespace syntax.

BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::AutoLiteral, discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::DefaultLiteral, discovered)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::PlaceholderLiteral, value)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::NumericLiteral, value)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::FloatLiteral, value)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::BooleanLiteral, value)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::StringLiteral, value)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::MacAddressLiteral, value)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::IPv4AddressLiteral, value)
BOOST_FUSION_ADAPT_STRUCT(pdl::detail::syntax::DefinitionLiteral, value)
