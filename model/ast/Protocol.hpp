// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of ProtocolDeclarationLanguageFramework open source project under MIT License.
// ============================================================================

#pragma once


namespace pdl::model::ast
{

/**
 * @class Protocol   Protocol.hpp   "model/ast/Protocol.hpp"
 * @brief This class implements .
 */
class Protocol
{
private:


public:
    Protocol (Protocol &&) = delete;
    Protocol (const Protocol &) = delete;
    Protocol & operator= (Protocol &&) = delete;
    Protocol & operator= (const Protocol &) = delete;

    Protocol() = default;

    ~Protocol() = default;
};

}  // namespace ast.
