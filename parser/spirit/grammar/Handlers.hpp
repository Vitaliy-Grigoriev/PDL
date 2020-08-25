#include <iostream>
#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/utility/error_reporting.hpp>
#include <boost/spirit/home/support/iterators/line_pos_iterator.hpp>


namespace pdl::spirit::grammar {

using ErrorTag = x3::error_handler_tag;
struct PositionTag {
};

using PositionIterator = boost::spirit::line_pos_iterator<std::string::const_iterator>;
using PositionCache = x3::position_cache<std::vector<PositionIterator>>;
using ErrorHandler = x3::error_handler<PositionIterator>;


struct RuleId
{
    template <typename Iterator, typename Expectation, typename Context>
    x3::error_handler_result on_error (Iterator first, Iterator last, const Expectation& x, const Context& context) const
    {
        auto& error = x3::get<ErrorTag>(context).get();
        const std::string message = "Error! Expecting: " + x.which();
        error(first, x.where(), message);
        return x3::error_handler_result::fail;
    }

    template <typename Ast, typename Iterator, typename Context>
    void on_success (Iterator first, Iterator last, Ast& ast, const Context& context)
    {
        auto& position = x3::get<PositionTag>(context).get();
        position.annotate(ast, first, last);
        ast.input = std::string {first.base(), last.base()};
        ast.lineBegin = boost::spirit::get_line(first);
        ast.columnBegin = boost::spirit::get_column(position.first().base(), first.base());
        ast.lineEnd = boost::spirit::get_line(last);
        ast.columnEnd = boost::spirit::get_column(position.first().base(), last.base());

        std::cout << ast.position() + " [info] Parsing '" << ast.tag << "' finish successfully." << std::endl;
    }

    virtual ~RuleId() = default;
};

}  // namespace grammar.
