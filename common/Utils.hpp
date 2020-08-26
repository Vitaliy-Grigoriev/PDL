#pragma once

#include "Endian.hpp"
#include "Error.hpp"


namespace pdl::common::utils {

std::string toString (Module _module);
std::string toString (Code _code);
std::string toString (data::endian::Endian _endian);

}  // namespace utils.
