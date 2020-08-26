// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of ProtocolDeclarationLanguage open source project under MIT License.
// ============================================================================

#include "Parser.hpp"
#include "spirit/Grammar.hpp"

#include <fstream>
#include <iostream>


namespace x3 = boost::spirit::x3;
namespace syntax = pdl::spirit::syntax;
namespace grammar = pdl::spirit::grammar;


namespace pdl::parser {
namespace {

std::size_t getOffsetToEnd (std::ifstream& _file)
{
    const auto position = _file.tellg();
    const auto size = _file.seekg(position, std::ios_base::end).tellg();
    _file.seekg(position);
    return size;
}

bool readFileToEnd (const std::filesystem::path& _path, std::string& _data) noexcept
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


bool Parser::parse (const std::string& _script)
{
    auto first = grammar::PositionIterator{ _script.cbegin() };
    auto last = grammar::PositionIterator{ _script.cend() };

    grammar::ErrorHandler error{ first, last, std::cerr };
    grammar::PositionCache position{ first, last };
    const auto parser = x3::with<grammar::PositionTag>(std::ref(position))[
                            x3::with<grammar::ErrorTag>(std::ref(error))[
                                grammar::script
                            ]
                        ];

    if (!x3::phrase_parse(first, last, parser, grammar::skipper, script)) {
        std::cerr << "[-] Mistake in Spirit grammar." << std::endl;
        return false;
    }

    if (first != last) {
        auto f = grammar::PositionIterator{ _script.cbegin() };
        std::cerr << "[-] Parsing stopped at '" << std::distance(f, first) << "' position." << std::endl;
        std::cerr << "[-] Tail: " << std::endl << std::string{ first.base(), last.base() } << std::endl;
    }
    return first == last;
}

bool Parser::parse (const std::filesystem::path& _file)
{
    currentPath = _file.string();
    std::string scr;
    return readFileToEnd(_file, scr) ? parse(scr) : false;
}

syntax::Script::CRef Parser::getScript() const noexcept
{
    return script;
}

}  // namespace parser.
