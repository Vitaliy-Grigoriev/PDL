// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of ProtocolAnalyzer open source project under MIT License.
// ============================================================================

#pragma once

#include <cassert>    // assert.
#include <memory>     // std::unique_ptr, std::make_unique.
#include <cstring>    // memcpy, memset.
#include <algorithm>  // std::generate.


namespace pdl::common::memory
{
    /**
      * @brief Function that allocates and constructs object.
      *
      * @tparam [in] Type - Type of allocated the object.
      * @tparam [in] args - Arguments for construct the object.
      * @return Smart pointer to allocated object.
      */
    template <typename Type, typename... Args>
    std::unique_ptr<Type> allocObject (const Args&... args)
    {
        return std::make_unique<Type>(args...);
    }

    /**
      * @brief Function that allocates array of selected type and if needed fills it.
      *
      * @tparam [in] Type   - Type of allocated data.
      * @param  [in] count  - Number of elements in array.
      * @param  [in] data   - Pointer to any copied data.   Default: nullptr.
      * @param  [in] length - Size of copied data in bytes. Default: 0.
      * @return Smart pointer to allocated array.
      */
    template <typename Type>
    std::unique_ptr<Type[]> allocArray (const std::size_t count,
                                        const void* const data = nullptr,
                                        const std::size_t length = 0)
    {
        assert(count > 0);

        auto memory = std::make_unique<Type[]>(count);
        if (data == nullptr || length == 0) { return memory; }

        const std::size_t allocatedBytes = count * sizeof(Type);
        if (allocatedBytes <= length) {
            memcpy(memory.get(), data, allocatedBytes);
        }
        else {  // If copied data length less then allocated data size.
            memcpy(memory.get(), data, length);
            memset(memory.get() + length, 0, allocatedBytes - length);
        }
        return memory;
    }

    /**
      * @brief Function that allocates and constructs array of object.
      *
      * @tparam [in] Type  - Type of allocated data.
      * @param  [in] count - Number of elements in array.
      * @tparam [in] args  - Arguments for construct object in array.
      * @return Smart pointer to allocated array of objects.
      */
    template <typename Type, typename... Args>
    std::unique_ptr<std::unique_ptr<Type>[]> allocArrayOfObjects (const std::size_t count, const Args&... args)
    {
        auto array = allocArray<std::unique_ptr<Type>[]>(count);
        std::generate(array.get(), array.get() + count, allocObject<Type>(args...));
        return array;
    }

}  // namespace memory.
