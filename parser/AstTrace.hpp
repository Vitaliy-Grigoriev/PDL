// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include "spirit/Annotation.hpp"
#include "spirit/Syntax.hpp"
#include "spirit/TypeRegistry.hpp"

#include <map>


namespace pdl::parser {

class AstTrace
{
public:
    AstTrace() = default;

    void print(std::ostream & _out) const;

    void operator()(spirit::syntax::Script _statement) { };
    void operator()(spirit::syntax::ScriptEntry _statement) { };

    void operator()(spirit::syntax::statements::ImportStatement _statement) { };
    void operator()(spirit::syntax::statements::ProtocolStatement _statement) { };

    template <typename Statement>
    void operator()(Statement _statement) { };

private:
    std::multimap<spirit::TypeRegistry, std::unique_ptr<spirit::BaseStatement>> index;
};

}  // namespace parser.
