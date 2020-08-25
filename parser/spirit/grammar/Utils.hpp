#pragma once

#include "Symbols.hpp"
#include "Keywords.hpp"


namespace pdl::spirit::grammar::utils {

template <typename Property>
constexpr auto makeProperty (const Property& _pr)
{
    return symbols::property > _pr;
}

template <typename Cast>
auto makeCast (const Cast& _to)
{
    return keywords::_as > _to;
}

namespace detail
{
    template <typename Statement>
    constexpr auto makeSequence (const Statement& _st) noexcept
    {
        return _st;
    }

    template <typename Statement, typename... Args>
    constexpr auto makeSequence (const Statement& _st, const Args&... _args) noexcept
    {
        return _st > detail::makeSequence(_args...);
    }
}

template <typename... Args>
constexpr auto makeSquareBrace (const Args&... _args) noexcept
{
    return symbols::openSquareBrace >> detail::makeSequence(_args...) > symbols::closeSquareBrace;
}

template <typename... Args>
constexpr auto makeSquareBraceExpect (const Args&... _args) noexcept
{
    return symbols::openSquareBrace > detail::makeSequence(_args...) > symbols::closeSquareBrace;
}

template <typename... Args>
constexpr auto makeParamBrace (const Args&... _args) noexcept
{
    return symbols::openParamBrace >> detail::makeSequence(_args...) > symbols::closeParamBrace;
}

template <typename... Args>
constexpr auto makeParamBraceExpect (const Args&... _args) noexcept
{
    return symbols::openParamBrace > detail::makeSequence(_args...) > symbols::closeParamBrace;
}

template <typename... Args>
constexpr auto makeBlockBrace (const Args&... _args) noexcept
{
    return symbols::openBlockBrace > detail::makeSequence(_args...) > symbols::closeBlockBrace;
}

}  // namespace utils.
