#pragma once


namespace pdl::common
{

template <typename Type>
class ClassDeclaration
{
public:
    using Ref = Type &;
    using CRef = const Type &;
    using Ptr = Type *;
    using CPtr = const Type *;

    ClassDeclaration() = default;
    virtual ~ClassDeclaration() = default;
};

}  // namespace common.
