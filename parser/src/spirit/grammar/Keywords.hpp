#pragma once

#include "../syntax/Types.hpp"
#include <boost/spirit/home/x3.hpp>


namespace pdl::spirit::grammar::keywords
{
    namespace x3 = boost::spirit::x3;

    static struct Keywords : x3::symbols<x3::unused_type>
    {
        auto make (std::string word)
        {
            add(word);
            return x3::lit(word);
        }
    } keywords;

    static struct ReservedTypes : x3::symbols<syntax::types::InternalVariableType>
    {
        ReservedTypes()
        {
            add("bit",    syntax::types::InternalVariableType::BIT)
               ("bool",   syntax::types::InternalVariableType::BOOLEAN)
               ("byte",   syntax::types::InternalVariableType::BYTE)
               ("i8",     syntax::types::InternalVariableType::INT8)
               ("i16",    syntax::types::InternalVariableType::INT16)
               ("i32",    syntax::types::InternalVariableType::INT32)
               ("i64",    syntax::types::InternalVariableType::INT64)
               ("u8",     syntax::types::InternalVariableType::UINT8)
               ("u16",    syntax::types::InternalVariableType::UINT16)
               ("u32",    syntax::types::InternalVariableType::UINT32)
               ("u64",    syntax::types::InternalVariableType::UINT64)
               ("float",  syntax::types::InternalVariableType::FLOAT)
               ("mac",    syntax::types::InternalVariableType::MAC)
               ("ipv4",   syntax::types::InternalVariableType::IPv4)
               ("ipv6",   syntax::types::InternalVariableType::IPv6);
        }
    } reservedTypes;

    static struct ReservedDefines : x3::symbols<syntax::types::InternalDefines>
    {
        ReservedDefines()
        {
            add("LOCAL_MAC_ADDRESS",  syntax::types::InternalDefines::LOCAL_MAC_ADDRESS)
               ("TARGET_MAC_ADDRESS", syntax::types::InternalDefines::TARGET_MAC_ADDRESS)
               ("LOCAL_IP_ADDRESS",   syntax::types::InternalDefines::LOCAL_IP_ADDRESS)
               ("TARGET_IP_ADDRESS",  syntax::types::InternalDefines::TARGET_IP_ADDRESS);
        }
    } reservedDefines;

    static struct OptionalGroupType : x3::symbols<syntax::types::OptionalGroupType>
    {
        OptionalGroupType()
        {
            add("single",  syntax::types::OptionalGroupType::SINGLE)
               ("multi",   syntax::types::OptionalGroupType::MULTI);
        }
    } optionalGroupType;

    static struct Endian : x3::symbols<syntax::types::EndianType>
    {
        Endian()
        {
            add("big_endian",    syntax::types::EndianType::BIG)
               ("little_endian", syntax::types::EndianType::LITTLE);
        }
    } _endian;

    static struct VariableScope : x3::symbols<syntax::types::VariableScope>
    {
        VariableScope()
        {
            add("local",  syntax::types::VariableScope::LOCAL)
               ("global", syntax::types::VariableScope::GLOBAL);
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
