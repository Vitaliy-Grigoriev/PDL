#pragma once

#include "spirit/Syntax.hpp"

#include <filesystem>


namespace pdl::parser {

class Parser final
{
public:
    bool parse(const std::string & _script);
    bool parse(const std::filesystem::path & _path);

    spirit::syntax::Script::CRef getScript() const noexcept;

private:
    spirit::syntax::Script script;
};

}  // namespace parser.
