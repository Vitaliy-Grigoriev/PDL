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

    explicit Declaration (Type * _pointer) noexcept :
        pointer{ _pointer }
    { }

    Ref ref() noexcept
    {
        return *pointer;
    }

    CRef ref() const noexcept
    {
        return *pointer;
    }

    Ptr ptr() noexcept
    {
        return pointer;
    }

    CPtr ptr() const noexcept
    {
        return pointer;
    }

private:
    Type * pointer = nullptr;
};

}  // namespace common.
