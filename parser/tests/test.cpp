// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

// ============================================================================
// Copyright (c) 2017-2019, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of ProtocolAnalyzer open source project under MIT License.
// ============================================================================

#include <iostream>
#include <Parser.hpp>
#include <boost/hana.hpp>

namespace syntax = pdl::detail::syntax;

int32_t main (int32_t size, char** data)
{
    std::filesystem::path path{"../tests/simple.pdl"};

    pdl::Parser parser;
    bool res = parser.parse(path);
    std::cout << "[*] Result: " << res << std::endl;
    if (!res) {
        return EXIT_FAILURE;
    }

    const auto& script = parser.getScript();

    const auto& protocol = boost::get<syntax::ProtocolStatement>(script.statements[1]);
    const auto& defines = boost::get<syntax::DefinesStatement>(protocol.statements[0]);
    const auto& mapping = boost::get<syntax::MappingStatement>(defines.statements[4]);
    for (auto&& value : mapping.values) {
        const auto& mac = boost::get<syntax::MacAddressLiteral>(value.value);
        const auto& def = boost::get<syntax::DefinitionProperty>(value.properties[1]);
        std::cout << mac.value << " - " << def.value.value << std::endl;
    }

    const auto& usingSt1 = boost::get<syntax::UsingStatement>(defines.statements[1]);
    const auto& value1 = boost::get<syntax::Identifier>(usingSt1.value);
    std::cout << "Using 1 " << value1.value << std::endl;

    const auto& usingSt2 = boost::get<syntax::UsingStatement>(defines.statements[2]);
    const auto& value2 = boost::get<syntax::MemberExpr>(usingSt2.value);
    std::cout << "Using 2 " << value2[0].value << std::endl;

    std::cout << "[+] Exit." << std::endl;
    return EXIT_SUCCESS;
}
