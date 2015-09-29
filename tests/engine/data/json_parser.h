// json_parser_tests.h

#ifndef INCLUDED_JSON_PARSER_TEST
# define INCLUDED_JSON_PARSER_TEST

#include <gtest/gtest.h>
#include "data/json_parser.h"

class JsonParserTest : public ::testing::Test
{
  public:
    StevensDev::sgdd::JsonEntity*       entity;
};

TEST_F( JsonParserTest, ArrayOnePrimitive )
{
    std::string str(" [ 'prim' ]" );

    entity = StevensDev::sgdd::JsonParser::fromString( str );

    ASSERT_TRUE( entity->isArray() );
    ASSERT_TRUE( entity->asArray()[0]->isString() );

    ASSERT_EQ( "prim", entity->asArray()[0]->asString() );
}

TEST_F( JsonParserTest, ArrayPrimitives )
{
    std::string str(" [ 'one', 234, false, 4.6 ]" );

    entity = StevensDev::sgdd::JsonParser::fromString( str );

    ASSERT_TRUE( entity->isArray() );

    // Check type of the string
    ASSERT_TRUE( entity->asArray()[0]->isString() );
    ASSERT_FALSE( entity->asArray()[0]->isInt() );
    ASSERT_FALSE( entity->asArray()[0]->isBool() );
    ASSERT_FALSE( entity->asArray()[0]->isDouble() );

    // Check type of the integer
    ASSERT_FALSE( entity->asArray()[1]->isString() );
    ASSERT_TRUE( entity->asArray()[1]->isInt() );
    ASSERT_FALSE( entity->asArray()[1]->isBool() );
    ASSERT_FALSE( entity->asArray()[1]->isDouble() );

    // Check type of the boolean
    ASSERT_FALSE( entity->asArray()[2]->isString() );
    ASSERT_FALSE( entity->asArray()[2]->isInt() );
    ASSERT_TRUE( entity->asArray()[2]->isBool() );
    ASSERT_FALSE( entity->asArray()[2]->isDouble() );

    // Check type of the double
    ASSERT_FALSE( entity->asArray()[3]->isString() );
    ASSERT_FALSE( entity->asArray()[3]->isInt() );
    ASSERT_FALSE( entity->asArray()[3]->isBool() );
    ASSERT_TRUE( entity->asArray()[3]->isDouble() );

    // Check values
    ASSERT_EQ( "one", entity->asArray()[0]->asString() );
    ASSERT_EQ( 234, entity->asArray()[1]->asInt() );
    ASSERT_EQ( false, entity->asArray()[2]->asBool() );
    ASSERT_EQ( 4.6, entity->asArray()[3]->asDouble() );
}

TEST_F( JsonParserTest, ObjectOnePrimitive )
{
    std::string str("{ 'name': 'Test' }" );
    std::string name("name");

    entity = StevensDev::sgdd::JsonParser::fromString( str );

    ASSERT_TRUE( entity->isObject() );
    ASSERT_TRUE( ( *entity )[name].isString() );
    ASSERT_EQ( "Test", ( *entity )[name].asString() );
}

TEST_F( JsonParserTest, ObjectPrimitives )
{
    std::string str("{ 's': 'One', 'i': 42, 'd': 13.37, 'b': true }" );
    std::string s("s");
    std::string i("i");
    std::string d("d");
    std::string b("b");

    entity = StevensDev::sgdd::JsonParser::fromString( str );

    ASSERT_TRUE( entity->isObject() );

    ASSERT_TRUE( ( *entity )[s].isString() );
    ASSERT_TRUE( ( *entity )[i].isInt() );
    ASSERT_TRUE( ( *entity )[d].isDouble() );
    ASSERT_TRUE( ( *entity )[b].isBool() );

    ASSERT_EQ( "One", ( *entity )[s].asString() );
    ASSERT_EQ( 42, ( *entity )[i].asInt() );
    ASSERT_EQ( 13.37, ( *entity )[d].asDouble() );
    ASSERT_EQ( true, ( *entity )[b].asBool() );
}

TEST_F( JsonParserTest, TestSubject )
{
    std::string str("{ 'name' : 'Configuration', 'values' : [ 1, 3, 'penguin' ] }" );
    std::string name("name");
    std::string values("values");

    entity = StevensDev::sgdd::JsonParser::fromString( str );

    ASSERT_TRUE( entity->isObject() );

    ASSERT_TRUE( ( *entity )[name].isString() );
    ASSERT_EQ( "Configuration", ( *entity )[name].asString() );

    // Check types
    ASSERT_TRUE( ( *entity )[values].isArray() );
    ASSERT_TRUE( ( *entity )[values][0].isInt() );
    ASSERT_TRUE( ( *entity )[values][1].isInt() );
    ASSERT_TRUE( ( *entity )[values][2].isString() );

    // Check values
    ASSERT_EQ( 1,         ( *entity )[values][0].asInt() );
    ASSERT_EQ( 3,         ( *entity )[values][1].asInt() );
    ASSERT_EQ( "penguin", ( *entity )[values][2].asString() );
}


#endif // INCLUDED_JSON_PARSER_TEST
