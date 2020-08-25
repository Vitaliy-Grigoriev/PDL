#pragma once

#include "Variables.hpp"


namespace pdl::spirit::syntax::groups {

struct GroupEntry : Annotation<GroupEntry>
{
    Identifier name;
    std::vector<variables::Variable> fields;
};

struct StaticGroup : Annotation<StaticGroup>
{
    std::vector<variables::Variable> fields;
};

struct ConditionalGroup : Annotation<ConditionalGroup>
{
    std::vector<variables::Variable> fields;
};

struct OptionalGroupEntry : x3::variant<variables::Variable,
                                        GroupEntry>,
                            Annotation<OptionalGroupEntry>
{
    using base_type::base_type;
    using base_type::operator=;
};

struct OptionalGroup : Annotation<OptionalGroup>
{
    types::OptionalGroupType type = types::OptionalGroupType::SINGLE;
    std::vector<OptionalGroupEntry> fields;
};

}  // namespace groups.

BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::groups::GroupEntry,         name, fields)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::groups::StaticGroup,        fields)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::groups::ConditionalGroup,   fields)
BOOST_FUSION_ADAPT_STRUCT(pdl::spirit::syntax::groups::OptionalGroup,      type, fields)
