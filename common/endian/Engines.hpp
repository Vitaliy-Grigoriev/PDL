// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include "engines/BigEndianEngine.hpp"
#include "engines/LittleEndianEngine.hpp"


namespace pdl::common::endian {

/**
 * @brief Function that returns endian EngineInterface for selected type.
 * @param [in] _endian - EngineInterface's endian type.
 * @param [in] _data - Reference to data.
 * @return EngineInterface for selected endian type.
 */
EngineInterface::UniquePtr getEngine(Endian _endian, data::RawData & _data);

}  // namespace endian.
