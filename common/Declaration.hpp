// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once


namespace pdl::common {

template <typename Type>
class Declaration
{
public:
    using Ref = Type &;
    using CRef = const Type &;
    using Ptr = Type *;
    using CPtr = const Type *;
};

}  // namespace common.
