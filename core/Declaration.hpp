// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include <memory>


namespace pdl::core {

template <typename Type>
class Declaration
{
public:
    using Ref  = Type &;
    using CRef = const Type &;
    using Ptr  = Type *;
    using CPtr = const Type *;

    using UniquePtr = std::unique_ptr<Type>;

    explicit Declaration(Ptr _pointer) noexcept :
        pointer{ _pointer }
    { }

    inline Ref ref() noexcept
    {
        return *pointer;
    }

    inline CRef ref() const noexcept
    {
        return *pointer;
    }

    inline Ptr ptr() noexcept
    {
        return pointer;
    }

    inline CPtr ptr() const noexcept
    {
        return pointer;
    }

private:
    Ptr pointer = nullptr;
};

}  // namespace core.
