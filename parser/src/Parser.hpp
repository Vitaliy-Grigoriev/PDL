#pragma once

#include "spirit/syntax/Syntax.hpp"

#include <filesystem>


namespace pdl
{
    class Parser final
    {
    public:
        Parser() = default;
        ~Parser() = default;

        bool parse (const std::string & script);
        bool parse (const std::filesystem::path & file);

        spirit::syntax::Script::CRef getScript() const noexcept;

    private:
        spirit::syntax::Script script;
        std::string currentPath;
    };

}  // namespace pdl.
