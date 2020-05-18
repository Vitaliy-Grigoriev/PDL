#pragma once

namespace pdl::common
{

template <typename Type>
class Declaration
{
public:
    using Ref = Type &;
    using CRef = const Type &;
    using Ptr = Type *;
    using CPtr = const Type *;

    Declaration() = default;
};

}  // namespace common.
