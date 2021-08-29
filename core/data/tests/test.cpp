// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include <core/data/Memory.hpp>
#include <core/data/RawData.hpp>

#include <iostream>


namespace data = pdl::core::data;

int32_t main (int32_t _size, char** _data)
{
    std::unique_ptr<std::byte[]> memory = data::memory::allocArray<std::byte>(10);
    data::RawData d{ memory.get(), 10 };

    std::cout << "[+] Exit." << std::endl;
    return EXIT_SUCCESS;
}
