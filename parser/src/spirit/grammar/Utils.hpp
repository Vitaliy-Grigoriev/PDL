#pragma once

#include "Symbols.hpp"
#include "Keywords.hpp"


namespace pdl::spirit::grammar::utils
{
    template <typename Property>
    auto makeProperty (const Property& pr) noexcept
    {
        return symbols::property > pr;
    }

    template <typename Cast>
    auto makeCast (const Cast& to) noexcept
    {
        return keywords::asKeyword > to;
    }

    namespace detail
    {
        template <typename Statement>
        auto makeSequence (const Statement& st) noexcept
        {
            return st;
        }

        template <typename Statement, typename... Args>
        auto makeSequence (const Statement& st, const Args&... args) noexcept
        {
            return st > detail::makeSequence(args...);
        }
    }

    template <typename... Args>
    auto makeSquareBrace (const Args&... args) noexcept
    {
        return symbols::openSquareBrace >> detail::makeSequence(args...) > symbols::closeSquareBrace;
    }

    template <typename... Args>
    auto makeParamBrace (const Args&... args) noexcept
    {
        return symbols::openParamBrace >> detail::makeSequence(args...) > symbols::closeParamBrace;
    }

    template <typename... Args>
    auto makeBlockBrace (const Args&... args) noexcept
    {
        return symbols::openBlockBrace > detail::makeSequence(args...) > symbols::closeBlockBrace;
    }

}  // namespace utils.


