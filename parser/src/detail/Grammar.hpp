#pragma once

#include "Syntax.hpp"
#include <iostream>
#include <stdexcept>
#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/support/iterators/line_pos_iterator.hpp>


namespace pdl::detail::grammar
{
    namespace x3 = boost::spirit::x3;

    struct PositionTag {
    };
    using PositionIterator = boost::spirit::line_pos_iterator<std::string::const_iterator>;
    using PositionCache = x3::position_cache<std::vector<PositionIterator>>;

    struct RuleId
    {
        template <typename Iterator, typename Expectation, typename Context>
        x3::error_handler_result on_error (Iterator, Iterator last, const Expectation &x, const Context &context) const
        {
            std::string message = "Error! Expecting: " + x.which() + ", got: " + std::string(x.where(), last);
            std::cerr << message << std::endl;
            return x3::error_handler_result::fail;
        }

        template <typename Ast, typename Iterator, typename Context>
        void on_success (Iterator first, Iterator last, Ast& ast, const Context& context)
        {
            PositionCache& pos = x3::get<PositionTag>(context).get();
            pos.annotate(ast, first, last);
            ast.input = std::string{first.base(), last.base()};
            ast.lineBegin = boost::spirit::get_line(first);
            ast.columnBegin = boost::spirit::get_column(pos.first().base(), first.base());
            ast.lineEnd = boost::spirit::get_line(last);
            ast.columnEnd = boost::spirit::get_column(pos.first().base(), last.base());
        }
    };

    const x3::rule<struct RuleId, syntax::DefinitionProperty> definitionProperty{"definitionProperty"};
    const x3::rule<struct RuleId, syntax::RequiredProperty> requiredProperty{"requiredProperty"};
    const x3::rule<struct RuleId, syntax::VolatileProperty> volatileProperty{"volatileProperty"};
    const x3::rule<struct RuleId, syntax::FinalProperty> finalProperty{"finalProperty"};
    const x3::rule<struct RuleId, syntax::EndianProperty> endianProperty{"endianProperty"};
    const x3::rule<struct RuleId, syntax::DefaultProperty> defaultProperty{"defaultProperty"};
    const x3::rule<struct RuleId, syntax::IdProperty> idProperty{"idProperty"};

    const x3::rule<struct RuleId, syntax::MappingEntryProperties> mappingEntryProperties{"mappingEntryProperties"};
    const x3::rule<struct RuleId, syntax::MappingProperties> mappingProperties{"mappingProperties"};
    const x3::rule<struct RuleId, syntax::VariableProperties> variableProperties{"variableProperties"};

    const x3::rule<struct RuleId, syntax::AutoLiteral> autoLiteral{"autoLiteral"};
    const x3::rule<struct RuleId, syntax::DefaultLiteral> defaultLiteral{"defaultLiteral"};
    const x3::rule<struct RuleId, syntax::PlaceholderLiteral> placeholderLiteral{"placeholderLiteral"};
    const x3::rule<struct RuleId, syntax::NumericLiteral> numericLiteral{"numericLiteral"};
    const x3::rule<struct RuleId, syntax::FloatLiteral> floatLiteral{"floatLiteral"};
    const x3::rule<struct RuleId, syntax::BooleanLiteral> booleanLiteral{"booleanLiteral"};
    const x3::rule<struct RuleId, syntax::StringLiteral> stringLiteral{"stringLiteral"};
    const x3::rule<struct RuleId, syntax::MacAddressLiteral> macAddressLiteral{"macAddressLiteral"};
    const x3::rule<struct RuleId, syntax::IPv4AddressLiteral> ipv4AddressLiteral{"ipv4AddressLiteral"};
    const x3::rule<struct RuleId, syntax::DefinitionLiteral> definitionLiteral{"definitionLiteral"};

    const x3::rule<struct RuleId, syntax::DefaultValueLiteral> defaultValueLiteral{"defaultValueLiteral"};
    const x3::rule<struct RuleId, syntax::IdLiteral> idLiteral{"idLiteral"};
    const x3::rule<struct RuleId, syntax::Literal> literal{"literal"};

    const x3::rule<struct RuleId, syntax::VariableDeclaration> variableDeclaration{"variableDeclaration"};
    const x3::rule<struct RuleId, syntax::MappingEntry> mappingEntry{"mappingEntry"};
    const x3::rule<struct RuleId, syntax::MemberExpr> memberExpr{"memberExpr"};

    const x3::rule<struct RuleId, syntax::RoundStatement> round{"round"};
    const x3::rule<struct RuleId, syntax::RequestStatement> request{"request"};
    const x3::rule<struct RuleId, syntax::ResponseStatement> response{"response"};
    const x3::rule<struct RuleId, syntax::HeaderStatement> header{"header"};
    const x3::rule<struct RuleId, syntax::MappingStatement> mapping{"mapping"};
    const x3::rule<struct RuleId, syntax::DeclarationStatements> declarationStatement{"declarationStatement"};
    const x3::rule<struct RuleId, syntax::DefinesStatements> definesStatement{"definesStatement"};
    const x3::rule<struct RuleId, syntax::DeclarationStatement> declaration{"declaration"};
    const x3::rule<struct RuleId, syntax::DefinesStatement> defines{"defines"};
    const x3::rule<struct RuleId, syntax::ImportStatement> import{"import"};
    const x3::rule<struct RuleId, syntax::ProtocolStatements> protocolStatement{"protocolStatement"};
    const x3::rule<struct RuleId, syntax::ProtocolStatement> protocol{"protocol"};
    const x3::rule<struct RuleId, syntax::ScriptStatements> scriptStatement{"scriptStatement"};
    const x3::rule<struct RuleId, syntax::Script> script{"script"};

    static struct Keywords : x3::symbols<x3::unused_type>
    {
        auto make(std::string word)
        {
            add(word);
            return x3::lit(word);
        }
    } keywords;

    static struct FutureReservedWords : x3::symbols<x3::unused_type>
    {
        FutureReservedWords()
        {
            add("abstract")("break")("case")("catch")("class")("const")("continue")("delete")
               ("do")("enum")("eval")("export")("extern")("for")("function")
               ("implements")("in")("interface")("new")("null")("package")("private")("protected")("public")
               ("return")("static")("struct")("switch")("synchronized")("this")
               ("try")("typeof")("union")("until")("var")("while")("with");
        }
    } futureReservedWords;

    const auto whitespace = x3::space;
    const auto singleLineComment = x3::lit("#") >> *(x3::char_ - x3::eol);
    const auto singleLineCommentCppStyle = x3::lit("//") >> *(x3::char_ - x3::eol);
    const auto multiLineComment = x3::lit("/*") >> *(x3::char_ - "*/") >> x3::lit("*/");
    const auto comment = singleLineComment | singleLineCommentCppStyle | multiLineComment;
    const auto skipper = whitespace | comment;
    const auto anything = *~whitespace;

    static struct Boolean : x3::symbols<bool>
    {
        Boolean() {
            add("true", true)
               ("false", false);
        }
    } boolean;

    static struct VariableType : x3::symbols<syntax::VariableType>
    {
        VariableType() {
            add("bit",   syntax::VariableType::BIT)
               ("bool",  syntax::VariableType::BOOLEAN)
               ("byte",  syntax::VariableType::BYTE)
               ("i8",    syntax::VariableType::INT8)
               ("i16",   syntax::VariableType::INT16)
               ("i32",   syntax::VariableType::INT32)
               ("i64",   syntax::VariableType::INT64)
               ("u8",    syntax::VariableType::UINT8)
               ("u16",   syntax::VariableType::UINT16)
               ("u32",   syntax::VariableType::UINT32)
               ("u64",   syntax::VariableType::UINT64)
               ("float", syntax::VariableType::FLOAT)
               ("mac",   syntax::VariableType::MAC)
               ("ipv4",  syntax::VariableType::IPv4)
               ("ipv6",  syntax::VariableType::IPv6);
        }
    } variableType;

    static struct Endian : x3::symbols<syntax::EndianType>
    {
        Endian() {
            add("big_endian", syntax::EndianType::BIG)
               ("little_endian", syntax::EndianType::LITTLE);
        }
    } endian;

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

    const auto idKeyword = keywords.make("id");
    const auto definitionKeyword = keywords.make("def");
    const auto roundKeyword = keywords.make("round");
    const auto requestKeyword = keywords.make("request");
    const auto responseKeyword = keywords.make("response");
    const auto headerKeyword = keywords.make("header");
    const auto mappingKeyword = keywords.make("mapping");
    const auto definesKeyword = keywords.make("defines");
    const auto declarationKeyword = keywords.make("declaration");
    const auto protocolKeyword = keywords.make("protocol");
    const auto importKeyword = keywords.make("import");

    const auto reservedWords = keywords | futureReservedWords | boolean | requiredKeyword | volatileKeyword;
    const auto identifier = x3::raw[x3::lexeme[(x3::alnum) >> *(x3::alnum | x3::char_('_'))] - reservedWords];

    const auto bin = x3::lit("0b") >> x3::bin;
    const auto hex = x3::lit("0x") >> x3::hex;
    const auto byte = x3::xdigit >> x3::xdigit;
    const auto word = byte >> byte;
    x3::uint_parser<uint8_t, 10, 1, 3> octet;

    const auto autoLiteral_def = autoKeyword;
    const auto defaultLiteral_def = defaultKeyword;
    const auto placeholderLiteral_def = '_' >> x3::uint16;
    const auto numericLiteral_def = bin | hex | x3::int_;
    const auto floatLiteral_def = x3::float_;
    const auto booleanLiteral_def = boolean;
    const auto stringLiteral_def = x3::lexeme['"' >> *(x3::char_ - '"') >> '"'];
    const auto macAddressLiteral_def = x3::raw[x3::repeat(5)[byte >> x3::char_(':')] >> byte];
    const auto ipv4AddressLiteral_def = x3::raw[x3::repeat(3)[octet >> '.'] >> octet];
    const auto definitionLiteral_def = x3::raw[x3::lexeme[x3::alpha >> *(x3::alnum | x3::char_('_') | x3::char_(' '))] - reservedWords];

    const auto defaultValueLiteral_def = placeholderLiteral | numericLiteral | definitionLiteral;
    const auto idLiteral_def = autoLiteral | numericLiteral | definitionLiteral;
    const auto literal_def = defaultLiteral | ipv4AddressLiteral | macAddressLiteral | numericLiteral | floatLiteral | booleanLiteral | stringLiteral;

    const auto definitionProperty_def = definitionKeyword >> '(' >> definitionLiteral >> ')';
    const auto requiredProperty_def = requiredKeyword;
    const auto volatileProperty_def = volatileKeyword;
    const auto finalProperty_def = finalKeyword;
    const auto endianProperty_def = endian;
    const auto defaultProperty_def = x3::lit("default") >> '(' >> defaultValueLiteral >> ')';
    const auto idProperty_def = idKeyword >> '(' >> idLiteral >> ')';

    const auto mappingEntryProperties_def = idProperty | definitionProperty;
    const auto mappingProperties_def = defaultProperty | finalProperty | idProperty | definitionProperty | endianProperty;
    const auto variableProperties_def = definitionProperty | requiredProperty | volatileProperty;

    const auto variableDeclaration_def = variableType >> identifier >> -('=' >> literal) >> -("->" >> +variableProperties);
    const auto memberExpr_def = identifier % '.';

    const auto round_def = roundKeyword >> identifier >> '{' >> identifier >> '}';
    const auto request_def = requestKeyword >> '{' >> +round >> '}';
    const auto response_def = responseKeyword >> '{' >> +round >> '}';
    const auto header_def = headerKeyword >> identifier >> '{' >> +variableDeclaration >> '}';
    const auto mappingEntry_def = literal >> -("->" >> +mappingEntryProperties);
    const auto mapping_def = mappingKeyword >> memberExpr >> -("->" >> +mappingProperties) >> '{' >> +mappingEntry >> '}';
    const auto definesStatement_def = header | mapping;
    const auto declarationStatement_def = request | response;
    const auto defines_def = definesKeyword >> '{' >> +definesStatement >> '}';
    const auto declaration_def = declarationKeyword >> '{' >> +declarationStatement >> '}';
    const auto protocolStatement_def = defines | declaration;
    const auto protocol_def = protocolKeyword >> identifier >> '{' >> +protocolStatement >> '}';
    const auto import_def = importKeyword >> identifier;
    const auto scriptStatement_def = import | protocol;
    const auto script_def = +scriptStatement;

    BOOST_SPIRIT_DEFINE(autoLiteral);
    BOOST_SPIRIT_DEFINE(defaultLiteral);
    BOOST_SPIRIT_DEFINE(placeholderLiteral);
    BOOST_SPIRIT_DEFINE(numericLiteral);
    BOOST_SPIRIT_DEFINE(floatLiteral);
    BOOST_SPIRIT_DEFINE(booleanLiteral);
    BOOST_SPIRIT_DEFINE(stringLiteral);
    BOOST_SPIRIT_DEFINE(macAddressLiteral);
    BOOST_SPIRIT_DEFINE(ipv4AddressLiteral);
    BOOST_SPIRIT_DEFINE(definitionLiteral);
    BOOST_SPIRIT_DEFINE(defaultValueLiteral);
    BOOST_SPIRIT_DEFINE(idLiteral);
    BOOST_SPIRIT_DEFINE(literal);

    BOOST_SPIRIT_DEFINE(definitionProperty);
    BOOST_SPIRIT_DEFINE(requiredProperty);
    BOOST_SPIRIT_DEFINE(volatileProperty);
    BOOST_SPIRIT_DEFINE(finalProperty);
    BOOST_SPIRIT_DEFINE(endianProperty);
    BOOST_SPIRIT_DEFINE(defaultProperty);
    BOOST_SPIRIT_DEFINE(idProperty);

    BOOST_SPIRIT_DEFINE(mappingEntryProperties);
    BOOST_SPIRIT_DEFINE(mappingProperties);
    BOOST_SPIRIT_DEFINE(variableProperties);

    BOOST_SPIRIT_DEFINE(variableDeclaration);
    BOOST_SPIRIT_DEFINE(memberExpr);
    BOOST_SPIRIT_DEFINE(round);
    BOOST_SPIRIT_DEFINE(request);
    BOOST_SPIRIT_DEFINE(response);
    BOOST_SPIRIT_DEFINE(header);
    BOOST_SPIRIT_DEFINE(mappingEntry);
    BOOST_SPIRIT_DEFINE(mapping);
    BOOST_SPIRIT_DEFINE(definesStatement);
    BOOST_SPIRIT_DEFINE(declarationStatement);
    BOOST_SPIRIT_DEFINE(defines);
    BOOST_SPIRIT_DEFINE(declaration);
    BOOST_SPIRIT_DEFINE(protocolStatement);
    BOOST_SPIRIT_DEFINE(protocol);
    BOOST_SPIRIT_DEFINE(import);
    BOOST_SPIRIT_DEFINE(scriptStatement);
    BOOST_SPIRIT_DEFINE(script);

}  // namespace grammar.
