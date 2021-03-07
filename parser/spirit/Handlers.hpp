// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================


#include <iostream>
#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/utility/error_reporting.hpp>
#include <boost/spirit/home/support/iterators/line_pos_iterator.hpp>


namespace pdl::spirit {

using ErrorTag = x3::error_handler_tag;
struct PositionTag { };
struct SuccessCallbackTag { };

using PositionIterator = boost::spirit::line_pos_iterator<std::string::const_iterator>;
using PositionCache = x3::position_cache<std::vector<PositionIterator>>;
using ErrorHandler = x3::error_handler<PositionIterator>;

struct PositionTrace
{
    void trace (std::string _tag, const BaseStatement &_statement)
    {
        index.emplace(std::move(_tag), &_statement);
    }

    void print (std::ostream& _out) const
    {
        auto it = index.cbegin();
        _out << it->second->position() << ": " << it->first << std::endl;
        for (++it; it != index.cend(); ++it) {
            _out << " -> " << it->second->position() << ": " << it->first << std::endl;
        }
    }

private:
    std::multimap<std::string, const BaseStatement *> index;
};


struct Handler
{
    template <typename Iterator, typename Exception, typename Context>
    x3::error_handler_result on_error(Iterator _first, Iterator, const Exception& _x, const Context& _context) const
    {
        auto& error = x3::get<ErrorTag>(_context).get();
        const std::string message = "[error] Expecting: " + _x.which();
        error(_first, _x.where(), message);
        return x3::error_handler_result::fail;
    }

    template <typename Iterator, typename Ast, typename Context>
    void on_success(Iterator _first, Iterator _last, Ast& _ast, const Context& _context)
    {
        auto& position = x3::get<PositionTag>(_context).get();
        position.annotate(_ast, _first, _last);
        _ast.input = std::string{ _first.base(), _last.base() };
        _ast.lineBegin = boost::spirit::get_line(_first);
        _ast.columnBegin = boost::spirit::get_column(position.first().base(), _first.base());
        _ast.lineEnd = boost::spirit::get_line(_last);
        _ast.columnEnd = boost::spirit::get_column(position.first().base(), _last.base());

        auto& callback = x3::get<SuccessCallbackTag>(_context).get();
        callback(_ast);
    }

    virtual ~Handler() = default;
};

}  // namespace spirit.
