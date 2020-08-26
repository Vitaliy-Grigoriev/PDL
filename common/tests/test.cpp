// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "../Memory.hpp"
#include "../RawData.hpp"

#include <iostream>


namespace common = pdl::common;

int32_t main (int32_t _size, char** _data)
{
    std::unique_ptr<std::byte[]> memory = common::memory::allocArray<std::byte>(10);
    common::data::RawData d{ memory.get(), 10 };

    std::cout << "[+] Exit." << std::endl;
    return EXIT_SUCCESS;
}
