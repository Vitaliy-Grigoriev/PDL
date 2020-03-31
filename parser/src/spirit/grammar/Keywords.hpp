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
               ("ipv6",   syntax::types::InternalVariableType::IPv6)
               ("string", syntax::types::InternalVariableType::STRING);
        }
    } reservedTypes;

    static struct Endian : x3::symbols<syntax::types::EndianType>
    {
        Endian() {
            add("big_endian",    syntax::types::EndianType::BIG)
               ("little_endian", syntax::types::EndianType::LITTLE);
        }
    } endianKeywords;

    static struct VariableScope : x3::symbols<syntax::types::VariableScope>
    {
        VariableScope() {
            add("local",  syntax::types::VariableScope::LOCAL)
               ("global", syntax::types::VariableScope::GLOBAL);
        }
    } variableScope;

    static struct Boolean : x3::symbols<bool>
    {
        Boolean() {
            add("true",  true)
               ("false", false);
        }
    } booleanKeywords;

    static struct Required : x3::symbols<bool>
    {
        Required() {
            add("required", true);
        }
    } requiredKeyword;

    static struct Volatile : x3::symbols<bool>
    {
        Volatile() {
            add("volatile", true);
        }
    } volatileKeyword;

    static struct Final : x3::symbols<bool>
    {
        Final() {
            add("final", true);
        }
    } finalKeyword;

    static struct Const : x3::symbols<bool>
    {
        Const() {
            add("const", true);
        }
    } constKeyword;

    static struct Auto : x3::symbols<bool>
    {
        Auto() {
            add("auto", true);
        }
    } autoKeyword;

    static struct Default : x3::symbols<bool>
    {
        Default() {
            add("default", true);
        }
    } defaultKeyword;


    const auto idKeyword          = keywords.make("id");
    const auto definitionKeyword  = keywords.make("def");
    const auto roundKeyword       = keywords.make("round");
    const auto requestKeyword     = keywords.make("request");
    const auto responseKeyword    = keywords.make("response");
    const auto usingKeyword       = keywords.make("using");
    const auto headerKeyword      = keywords.make("header");
    const auto mappingKeyword     = keywords.make("mapping");
    const auto definesKeyword     = keywords.make("defines");
    const auto declarationKeyword = keywords.make("declaration");
    const auto protocolKeyword    = keywords.make("protocol");
    const auto importKeyword      = keywords.make("import");
    const auto prefixKeyword      = keywords.make("prefix");
    const auto suffixKeyword      = keywords.make("suffix");


    static struct FutureReservedWords : x3::symbols<x3::unused_type>
    {
        FutureReservedWords()
        {
            add("abstract")("break")("case")("continue")
               ("do")("enum")("for")("while")("function")
               ("implements")("in")("interface")("null")("package")
               ("return")("static")("struct")("switch")
               ("union")("until")("with");
        }
    } futureReservedWords;

    const auto reservedWords = keywords |
                               futureReservedWords |
                               booleanKeywords |
                               requiredKeyword |
                               volatileKeyword |
                               endianKeywords |
                               variableScope |
                               finalKeyword |
                               constKeyword |
                               autoKeyword |
                               defaultKeyword |
                               reservedTypes;

}  // namespace keywords.