#pragma once

#include "TypeRegistry.hpp"

#include <cstddef>
#include <string>
#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>
#include <boost/type_index.hpp>


namespace pdl::spirit {

// Global using.
namespace x3 = boost::spirit::x3;

struct BaseStatement
{
    virtual std::string position() const = 0;
    virtual std::string info() const = 0;

    virtual ~BaseStatement() = default;
};


template <typename Statement>
struct Annotation : BaseStatement, x3::position_tagged
{
    Annotation();

    std::string position() const final;
    std::string info() const override;

    std::string tag;
    std::string input;
    std::size_t lineBegin = 0;
    std::size_t columnBegin = 0;
    std::size_t lineEnd = 0;
    std::size_t columnEnd = 0;
};

template <typename Statement>
Annotation<Statement>::Annotation()
{
    tag = boost::typeindex::type_id<Statement>().pretty_name();
}

template <typename Statement>
std::string Annotation<Statement>::position() const
{
    return std::to_string(lineBegin) + '.' +
           std::to_string(columnBegin) + '-' +
           std::to_string(lineEnd) + '.' +
           std::to_string(columnEnd);
}

template <typename Statement>
std::string Annotation<Statement>::info() const
{
    return input;
}

}  // namespace spirit.
