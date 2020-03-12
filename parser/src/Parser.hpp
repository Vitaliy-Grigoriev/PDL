#pragma once

#include "detail/Syntax.hpp"

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

        detail::syntax::Script::CRef getScript() const noexcept;

    private:
        detail::syntax::Script script;
        std::string currentPath;
    };

}  // namespace pdl.
