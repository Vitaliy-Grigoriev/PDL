// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "Header.hpp"


namespace pdl::core::data {

Header::Header() noexcept :
    Declaration{ this }
{ }

Constructor::Constructor (Header& _header) noexcept :
    Declaration{ this },
    header{ _header }
{ }

}  // namespace data.
