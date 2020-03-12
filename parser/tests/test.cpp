// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

// ============================================================================
// Copyright (c) 2017-2019, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of ProtocolAnalyzer open source project under MIT License.
// ============================================================================

#include <iostream>
#include <Parser.hpp>

int32_t main (int32_t size, char** data)
{
    std::filesystem::path path{"../tests/simple.pdl"};

    pdl::Parser parser;
    std::cout << "[*] Result: " << parser.parse(path) << std::endl;

    const auto& script = parser.getScript();


    std::cout << "[+] Exit." << std::endl;
    return EXIT_SUCCESS;
}
