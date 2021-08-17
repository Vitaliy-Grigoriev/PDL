// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of ProtocolDeclarationLanguage open source project under MIT License.
// ============================================================================

#include "Parser.hpp"
#include "AstTrace.hpp"
#include "spirit/Grammar.hpp"

#include <fstream>
#include <iostream>


namespace x3 = boost::spirit::x3;
namespace syntax = pdl::spirit::syntax;
namespace grammar = pdl::spirit::grammar;


namespace pdl::parser {
namespace {

std::size_t getOffsetToEnd(std::ifstream& _file)
{
    const auto position = _file.tellg();
    const auto size = _file.seekg(position, std::ios_base::end).tellg();

    _file.seekg(position);

    return static_cast<std::size_t>(size);
}

bool readFileToEnd(const std::filesystem::path& _path, std::string& _data) noexcept
{
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        file.open(_path, std::ios_base::in);
        const std::size_t size = getOffsetToEnd(file);
        if (size == 0) {
            return false;
        }

        _data.reserve(size);
        _data.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
    }
    catch (const std::ifstream::failure& /*err*/) {
        return false;
    }

    return true;
}

}


bool Parser::parse(const std::string& _script)
{
    auto first = spirit::PositionIterator{ _script.cbegin() };
    auto last = spirit::PositionIterator{ _script.cend() };

    spirit::ErrorHandler error{ first, last, std::cerr };
    spirit::PositionCache position{ first, last };
    AstTrace trace;

    const auto parser = x3::with<spirit::PositionTag>(std::ref(position))[
                            x3::with<spirit::ErrorTag>(std::ref(error))[
                                x3::with<spirit::SuccessCallbackTag>(std::ref(trace))[
                                    grammar::script
                                ]
                            ]
                        ];

    if (!x3::phrase_parse(first, last, parser, grammar::skipper, script)) {
        std::cerr << "[error] Mistake in Spirit grammar." << std::endl;
        return false;
    }

    if (first != last) {
        const std::size_t line = boost::spirit::get_line(first);
        const std::size_t column = boost::spirit::get_column(position.first().base(), first.base());

        std::cerr << "[error] Parsing stopped at line '" << line << "', column '" << column << "'." << std::endl;
        std::cerr << "[error] Trace: " << std::endl;
        trace.print(std::cerr);
    }
    trace.print(std::cerr);
    return first == last;
}

bool Parser::parse(const std::filesystem::path& _path)
{
    std::string scr;
    return readFileToEnd(_path, scr) && parse(scr);
}

syntax::Script::CRef Parser::getScript() const noexcept
{
    return script;
}

}  // namespace parser.
