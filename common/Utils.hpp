#pragma once

#include "Endian.hpp"
#include "Error.hpp"


namespace pdl::common::utils {

std::string toString (Module module);
std::string toString (Code code);
std::string toString (data::endian::Endian endian);

}  // namespace utils.
