#pragma once

#include <string>
#include <cstddef>
#include <boost/type_index.hpp>
#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>


namespace pdl::spirit {

// Global using.
namespace x3 = boost::spirit::x3;

template <typename Type>
struct Annotation : x3::position_tagged
{
    Annotation() noexcept;

    std::string position() const noexcept;

    std::string tag;
    std::string input;
    std::size_t lineBegin = 0;
    std::size_t columnBegin = 0;
    std::size_t lineEnd = 0;
    std::size_t columnEnd = 0;
};

template <typename Type>
Annotation<Type>::Annotation() noexcept
{
    tag = boost::typeindex::type_id<Type>().pretty_name();
}

template <typename Type>
std::string Annotation<Type>::position() const noexcept
{
    return std::to_string(lineBegin) + '.' +
           std::to_string(columnBegin) + '-' +
           std::to_string(lineEnd) + '.' +
           std::to_string(columnEnd) + ':';
}

}  // namespace spirit.
