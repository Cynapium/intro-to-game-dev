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

TEST_F( JsonParserTest, OperatorPtrAccess )
{
    std::string str(" [ 'one', 2, false, 4.6 ]" );

    entity = StevensDev::sgdd::JsonParser::fromString( str );

    ASSERT_TRUE( entity->isArray() );

    ASSERT_TRUE( entity->asArray()[0]->isString() );
    ASSERT_FALSE( entity->asArray()[0]->isInt() );
    ASSERT_FALSE( entity->asArray()[0]->isBool() );
    ASSERT_FALSE( entity->asArray()[0]->isDouble() );

    ASSERT_FALSE( entity->asArray()[1]->isString() );
    ASSERT_TRUE( entity->asArray()[1]->isInt() );
    ASSERT_FALSE( entity->asArray()[1]->isBool() );
    ASSERT_FALSE( entity->asArray()[1]->isDouble() );

    ASSERT_FALSE( entity->asArray()[2]->isString() );
    ASSERT_FALSE( entity->asArray()[2]->isInt() );
    ASSERT_TRUE( entity->asArray()[2]->isBool() );
    ASSERT_FALSE( entity->asArray()[2]->isDouble() );

    ASSERT_FALSE( entity->asArray()[3]->isString() );
    ASSERT_FALSE( entity->asArray()[3]->isInt() );
    ASSERT_FALSE( entity->asArray()[3]->isBool() );
    ASSERT_TRUE( entity->asArray()[3]->isDouble() );
}

#endif // INCLUDED_JSON_PARSER_TEST
