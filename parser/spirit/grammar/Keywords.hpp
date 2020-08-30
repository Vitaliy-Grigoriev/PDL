#pragma once

#include <boost/spirit/home/x3.hpp>
#include <parser/spirit/syntax/Types.hpp>


namespace pdl::spirit::grammar::keywords {

static struct Keywords : x3::symbols<x3::unused_type>
{
    Keywords()
    {
        name("Keywords");
    }

    auto make (const std::string& _word)
    {
        add(_word);
        return x3::lit(_word);
    }
} keywords;

static struct ReservedTypes : x3::symbols<syntax::types::InternalVariableType>
{
    ReservedTypes()
    {
        name("ReservedTypes");
        add("bit",     syntax::types::InternalVariableType::Bit)
           ("bool",    syntax::types::InternalVariableType::Boolean)
           ("byte",    syntax::types::InternalVariableType::Byte)
           ("i8",      syntax::types::InternalVariableType::Int8)
           ("i16",     syntax::types::InternalVariableType::Int16)
           ("i32",     syntax::types::InternalVariableType::Int32)
           ("i64",     syntax::types::InternalVariableType::Int64)
           ("u8",      syntax::types::InternalVariableType::UInt8)
           ("u16",     syntax::types::InternalVariableType::UInt16)
           ("u32",     syntax::types::InternalVariableType::UInt32)
           ("u64",     syntax::types::InternalVariableType::UInt64)
           ("float32", syntax::types::InternalVariableType::Float32)
           ("float64", syntax::types::InternalVariableType::Float64)
           ("mac",     syntax::types::InternalVariableType::Mac)
           ("ipv4",    syntax::types::InternalVariableType::IPv4)
           ("ipv6",    syntax::types::InternalVariableType::IPv6);
    }
} reservedTypes;

static struct ReservedDefines : x3::symbols<syntax::types::InternalDefines>
{
    ReservedDefines()
    {
        name("ReservedDefines");
        add("LOCAL_MAC_ADDRESS",  syntax::types::InternalDefines::LocalMacAddress)
           ("TARGET_MAC_ADDRESS", syntax::types::InternalDefines::TargetMacAddress)
           ("LOCAL_IP_ADDRESS",   syntax::types::InternalDefines::LocalIpAddress)
           ("TARGET_IP_ADDRESS",  syntax::types::InternalDefines::TargetIpAddress);
    }
} reservedDefines;

static struct OptionalGroupType : x3::symbols<syntax::types::OptionalGroupType>
{
    OptionalGroupType()
    {
        name("OptionalGroupType");
        add("single",  syntax::types::OptionalGroupType::Single)
           ("multi",   syntax::types::OptionalGroupType::Multi);
    }
} optionalGroupType;

static struct Endian : x3::symbols<syntax::types::EndianType>
{
    Endian()
    {
        add("big_endian",    syntax::types::EndianType::Big)
           ("little_endian", syntax::types::EndianType::Little);
    }
} _endian;

static struct VariableScope : x3::symbols<syntax::types::VariableScope>
{
    VariableScope()
    {
        add("local",  syntax::types::VariableScope::Local)
           ("global", syntax::types::VariableScope::Global);
    }
} variableScope;

static struct Boolean : x3::symbols<bool>
{
    Boolean()
    {
        add("true",  true)
           ("false", false);
    }
} _boolean;

static struct Required : x3::symbols<bool>
{
    Required()
    {
        add("required", true);
    }
} _required;

static struct Variable : x3::symbols<bool>
{
    Variable()
    {
        add("variable", true);
    }
} _variable;

static struct Final : x3::symbols<bool>
{
    Final()
    {
        add("final", true);
    }
} _final;

static struct Const : x3::symbols<bool>
{
    Const()
    {
        add("const", true);
    }
} _const;

static struct Calculated : x3::symbols<bool>
{
    Calculated()
    {
        add("calculated", true);
    }
} _calculated;

static struct Auto : x3::symbols<bool>
{
    Auto()
    {
        add("auto", true);
    }
} _auto;

static struct Default : x3::symbols<bool>
{
    Default()
    {
        add("default", true);
    }
} _default;

static struct Root : x3::symbols<bool>
{
    Root()
    {
        add("root", true);
    }
} _root;


const auto _as           = keywords.make("as");
const auto _id           = keywords.make("id");
const auto _definition   = keywords.make("def");
const auto _ieee         = keywords.make("ieee");
const auto _rfc          = keywords.make("rfc");
const auto _group        = keywords.make("group");
const auto _static       = keywords.make("static");
const auto _conditional  = keywords.make("conditional");
const auto _optional     = keywords.make("optional");
const auto _nextProtocol = keywords.make("next_protocol");
const auto _priority     = keywords.make("priority");
const auto _round        = keywords.make("round");
const auto _request      = keywords.make("request");
const auto _response     = keywords.make("response");
const auto _using        = keywords.make("using");
const auto _struct       = keywords.make("struct");
const auto _header       = keywords.make("header");
const auto _mapping      = keywords.make("mapping");
const auto _structure    = keywords.make("structure");
const auto _declaration  = keywords.make("declaration");
const auto _protocol     = keywords.make("protocol");
const auto _import       = keywords.make("import");
const auto _prefix       = keywords.make("prefix");
const auto _suffix       = keywords.make("suffix");


static struct FutureReservedWords : x3::symbols<x3::unused_type>
{
    FutureReservedWords()
    {
        name("FutureReservedWords");
        add("break")("case")("continue")
           ("do")("enum")("for")("while")("function")
           ("in")("interface")("null")("package")
           ("return")("static")("switch")
           ("union")("until")("with");
    }
} futureReservedWords;

const auto reservedWords = keywords |
                           futureReservedWords |
                           _boolean |
                           _required |
                           _variable |
                           _endian |
                           variableScope |
                           _final |
                           _const |
                           _calculated |
                           _auto |
                           _default | _root |
                           reservedTypes |
                           reservedDefines |
                           optionalGroupType;

}  // namespace keywords.
