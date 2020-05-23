// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of ProtocolDeclarationLanguage open source project under MIT License.
// ============================================================================

#include "Parser.hpp"
#include "spirit/grammar/Grammar.hpp"

#include <fstream>
#include <iostream>

namespace x3 = boost::spirit::x3;
namespace syntax = pdl::spirit::syntax;
namespace grammar = pdl::spirit::grammar;


namespace pdl::parser {

bool Parser::parse (const std::string& scr)
{
    auto first = grammar::PositionIterator{scr.cbegin()};
    auto last = grammar::PositionIterator{scr.cend()};

    grammar::ErrorHandler error{first, last, std::cerr};
    grammar::PositionCache position{first, last};
    const auto parser = x3::with<grammar::PositionTag>(std::ref(position))[
                            x3::with<grammar::ErrorTag>(std::ref(error))[
                                grammar::script
                            ]
                        ];

    bool r = x3::phrase_parse(first, last, parser, grammar::skipper, script);
    if (!r) {
        std::cerr << "Fail." << std::endl;
        return false;
    }

    if (first != last) {
        auto distance = std::distance(first, last);
        std::cerr << "Parsing stopped at " << std::to_string(distance) << " characters from the end, after the symbol: " << *first << *(++first) << std::endl;
    }
    return first == last;
}

std::size_t getFileSize (const std::filesystem::path& path) noexcept
{
    std::ifstream file(path, std::ios_base::binary);
    if (file.is_open() && file.good()) {
        const auto size = file.seekg(0, std::ios_base::end).tellg();
        file.close();
        return static_cast<std::size_t>(size);
    }
    return 0;
}

bool readFileToEnd (const std::filesystem::path& path, std::string& data) noexcept
{
    try {
        const std::size_t size = getFileSize(path);
        if (size == 0) {
            return false;
        }
        data.reserve(size);

        std::ifstream file(path, std::ios_base::in);
        if (file.is_open() && file.good()) {
            data.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
            return true;
        }
    }
    catch (const std::exception& /*err*/) { }
    return false;
}

bool Parser::parse (const std::filesystem::path& file)
{
    currentPath = file.string();
    std::string scr;
    if (readFileToEnd(file, scr)) {
        return parse(scr);
    }
    else {
        return false;
    }

}

syntax::Script::CRef Parser::getScript() const noexcept
{
    return script;
}

}