// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of ProtocolAnalyzer open source project under MIT License.
// ============================================================================

#pragma once

#include "Error.hpp"  // error::panic.

#include <algorithm>
#include <cstring>
#include <memory>


namespace pdl::common::memory {

/**
  * @brief Function that allocates and constructs object.
  *
  * @tparam [in] Type - Type of object.
  * @tparam [in] args - Arguments for construct the object.
  *
  * @return Smart pointer to allocated object.
  */
template <typename Type, typename... Args>
std::unique_ptr<Type> allocObject (const Args&... _args)
{
    return std::make_unique<Type>(_args...);
}

/**
  * @brief Function that allocates array of selected type.
  *
  * @tparam [in] Type  - Type of data.
  * @param  [in] count - Number of elements in array.
  *
  * @return Smart pointer to allocated array.
  */
template <typename Type>
std::unique_ptr<Type[]> allocArray (const std::size_t _count)
{
    if (!_count) {
        panic(Module::Memory, Code::ZeroMemoryAllocation, "Specified 0 bytes for allocation");
    }
    return std::make_unique<Type[]>(_count);
}

/**
  * @brief Function that allocates array of selected type and if needed fills it.
  *
  * @tparam [in] Type  - Type of data.
  * @param  [in] count - Number of elements in array.
  * @param  [in] data  - Pointer to any copied data.
  * @param  [in] size  - Size of copied data in bytes.
  *
  * @return Smart pointer to allocated array.
  *
  * @note If size of copied data more than allocated bytes then only part of the data will be copied.
  */
template <typename Type>
std::unique_ptr<Type[]> allocArray (const std::size_t _count, const void * const _data, const std::size_t _size)
{
    if (!_count) {
        panic(Module::Memory, Code::ZeroMemoryAllocation, "Specified 0 bytes for allocation");
    }

    auto memory = std::make_unique<Type[]>(_count);

    if (_data && _size) {
        const std::size_t bytes = _count * sizeof(Type);
        if (bytes <= _size) {
            memcpy(memory.get(), _data, bytes);
        }
        else {  // If copied data size less then allocated data size.
            memcpy(memory.get(), _data, _size);
            memset(memory.get() + _size, 0, bytes - _size);
        }
    }
    return memory;
}

/**
  * @brief Function that allocates and constructs array of object.
  *
  * @tparam [in] Type  - Type of object.
  * @param  [in] count - Number of elements in array.
  * @tparam [in] args  - Arguments for construct each object in array.
  *
  * @return Smart pointer to allocated array.
  */
template <typename Type, typename... Args>
std::unique_ptr<std::unique_ptr<Type>[]> allocArrayOfObjects (const std::size_t _count, const Args&... _args)
{
    auto array = allocArray<std::unique_ptr<Type>[]>(_count);
    std::generate(array.get(), array.get() + _count, allocObject<Type>(_args...));
    return array;
}

}  // namespace memory.
