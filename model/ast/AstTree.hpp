// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include <unordered_map>
#include <variant>
#include <vector>


namespace pdl::model::ast {

enum class NodeType
{
    Undefined = 0U,
    Protocol,
    Header,
    Struct,
    StaticGroup,
    ConditionalGroup,
    OptionalGroup,
    Group,
    Variable
}

struct Node
{
    NodeType type = NodeType::Undefined;
    Node * parent = nullptr;
    std::vector<Node *> children;

    Identifier id = std::string{ "_" };

    std::variant<std::monostate, Enum, Class, Member, Default> data;
};

class Tree
{
public:
    ~Tree();

    Node *find(const core::Reference &) const;
    Node *create(Node *, core::Entity, core::Identifier);

    Node *package(Node *) const;
    core::Reference reference(Node *) const;

    const Node *root() const noexcept;
    Node *root() noexcept;

private:
    Node *create(Node &, core::Entity, core::Identifier);

private:
    Node tree = {};
    std::unordered_map<Reference, Node *> index;
};

}

}  // namespace ast.
