// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of ProtocolDeclarationLanguage open source project under MIT License.
// ============================================================================

#include <iostream>
#include <Parser.hpp>


namespace syntax = pdl::spirit::syntax;

int32_t main (int32_t size, char** data)
{
    std::filesystem::path path{"../tests/ethernet.pdl"};

    pdl::Parser parser;
    bool res = parser.parse(path);
    std::cout << "[*] Result: " << res << std::endl;
    if (!res) {
        return EXIT_FAILURE;
    }

    const auto& script = parser.getScript();

    const auto& protocol = boost::get<syntax::statements::ProtocolStatement>(script.statements[1]);
    const auto& defines = boost::get<syntax::statements::DefineStatement>(protocol.statements[0]);
    const auto& mapping = boost::get<syntax::statements::MappingStatement>(defines.statements[4]);
    for (auto&& value : mapping.values) {
        const auto& mac = boost::get<syntax::literals::MacAddressLiteral>(value.value);
        const auto& def = boost::get<syntax::properties::DefinitionProperty>(value.properties[1]);
        std::cout << mac.value << " - " << def.value.value << std::endl;
    }

    const auto& usingSt1 = boost::get<syntax::statements::UsingStatement>(defines.statements[1]);
    const auto& value1 = boost::get<syntax::Identifier>(usingSt1.value);
    std::cout << "Using 1 " << value1.value << std::endl;

    const auto& usingSt2 = boost::get<syntax::statements::UsingStatement>(defines.statements[2]);
    const auto& value2 = boost::get<syntax::variables::MemberVariable>(usingSt2.value);
    std::cout << "Using 2 " << value2[0].value << std::endl;

    std::cout << "[+] Exit." << std::endl;
    return EXIT_SUCCESS;
}
