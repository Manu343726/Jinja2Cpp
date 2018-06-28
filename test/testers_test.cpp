#include <iostream>
#include <string>

#include "test_tools.h"
#include "jinja2cpp/template.h"

using namespace jinja2;

struct TestersGenericTestTag;
using TestersGenericTest = InputOutputPairTest<TestersGenericTestTag>;


TEST_P(TestersGenericTest, Test)
{
    auto& testParam = GetParam();
    std::string source = "{{ 'true' if " + testParam.tpl + " else 'false'}}";

    Template tpl;
    ASSERT_TRUE(tpl.Load(source));

    std::string result = tpl.RenderAsString(PrepareTestData());
    std::cout << result << std::endl;
    std::string expectedResult = testParam.result;
    EXPECT_EQ(expectedResult, result);
}

INSTANTIATE_TEST_CASE_P(EqTest, TestersGenericTest, ::testing::Values(
                            InputOutputPair{"0 is eq(0)",                         "true"},
                            InputOutputPair{"0 is eq(1)",                         "false"},
                            InputOutputPair{"0.5 is eq(0.5)",                     "true"},
                            InputOutputPair{"0.5 is eq(1.5)",                     "false"},
                            InputOutputPair{"'0.5' is eq('0.5')",                 "true"},
                            InputOutputPair{"'0.5' is eq('1.5')",                 "false"},
                            InputOutputPair{"'Hello World' is eq('hello world')", "false"},
                            InputOutputPair{"0 is equalto(1)",                    "false"},
                            InputOutputPair{"intList[0] is eq(intAsDoubleList[0])", "true"},
                            InputOutputPair{"intAsDoubleList[0] is eq(intList[0])", "true"}
                            ));


INSTANTIATE_TEST_CASE_P(NeTest, TestersGenericTest, ::testing::Values(
                            InputOutputPair{"0 is ne(0)",                         "false"},
                            InputOutputPair{"0 is ne(1)",                         "true"},
                            InputOutputPair{"0.5 is ne(0.5)",                     "false"},
                            InputOutputPair{"0.5 is ne(1.5)",                     "true"},
                            InputOutputPair{"'0.5' is ne('0.5')",                 "false"},
                            InputOutputPair{"'0.5' is ne('1.5')",                 "true"},
                            InputOutputPair{"'Hello World' is ne('hello world')", "true"},
                            InputOutputPair{"intList[0] is ne(intAsDoubleList[0])", "false"},
                            InputOutputPair{"intAsDoubleList[0] is ne(intList[0])", "false"}
                            ));


INSTANTIATE_TEST_CASE_P(GeTest, TestersGenericTest, ::testing::Values(
                            InputOutputPair{"0 is ge(0)",                         "true"},
                            InputOutputPair{"0 is ge(1)",                         "false"},
                            InputOutputPair{"1 is ge(0)",                         "true"},
                            InputOutputPair{"0.5 is ge(0.5)",                     "true"},
                            InputOutputPair{"0.5 is ge(1.5)",                     "false"},
                            InputOutputPair{"1.5 is ge(0.5)",                     "true"},
                            InputOutputPair{"'0.5' is ge('0.5')",                 "true"},
                            InputOutputPair{"'0.5' is ge('1.5')",                 "false"},
                            InputOutputPair{"'1.5' is ge('0.5')",                 "true"},
                            InputOutputPair{"'Hello World' is ge('hello world')", "false"},
                            InputOutputPair{"'hello world' is ge('Hello World')", "true"},
                            InputOutputPair{"intList[0] is ge(intAsDoubleList[0])", "true"},
                            InputOutputPair{"intList[0] is ge(intAsDoubleList[1])", "true"},
                            InputOutputPair{"intList[1] is ge(intAsDoubleList[0])", "false"},
                            InputOutputPair{"intAsDoubleList[0] is ge(intList[0])", "true"},
                            InputOutputPair{"intAsDoubleList[0] is ge(intList[1])", "true"},
                            InputOutputPair{"intAsDoubleList[1] is ge(intList[0])", "false"}
                            ));


INSTANTIATE_TEST_CASE_P(GtTest, TestersGenericTest, ::testing::Values(
                            InputOutputPair{"0 is gt(0)",                         "false"},
                            InputOutputPair{"0 is greaterthan(0)",                "false"},
                            InputOutputPair{"0 is gt(1)",                         "false"},
                            InputOutputPair{"1 is greaterthan(0)",                "true"},
                            InputOutputPair{"0.5 is gt(0.5)",                     "false"},
                            InputOutputPair{"0.5 is gt(1.5)",                     "false"},
                            InputOutputPair{"1.5 is gt(0.5)",                     "true"},
                            InputOutputPair{"'0.5' is gt('0.5')",                 "false"},
                            InputOutputPair{"'0.5' is gt('1.5')",                 "false"},
                            InputOutputPair{"'1.5' is gt('0.5')",                 "true"},
                            InputOutputPair{"'Hello World' is gt('hello world')", "false"},
                            InputOutputPair{"'hello world' is gt('Hello World')", "true"},
                            InputOutputPair{"intList[0] is gt(intAsDoubleList[0])", "false"},
                            InputOutputPair{"intList[0] is gt(intAsDoubleList[1])", "true"},
                            InputOutputPair{"intList[1] is gt(intAsDoubleList[0])", "false"},
                            InputOutputPair{"intAsDoubleList[0] is gt(intList[0])", "false"},
                            InputOutputPair{"intAsDoubleList[0] is gt(intList[1])", "true"},
                            InputOutputPair{"intAsDoubleList[1] is gt(intList[0])", "false"}
                            ));

INSTANTIATE_TEST_CASE_P(LeTest, TestersGenericTest, ::testing::Values(
                            InputOutputPair{"0 is le(0)",                         "true"},
                            InputOutputPair{"0 is le(1)",                         "true"},
                            InputOutputPair{"1 is le(0)",                         "false"},
                            InputOutputPair{"0.5 is le(0.5)",                     "true"},
                            InputOutputPair{"0.5 is le(1.5)",                     "true"},
                            InputOutputPair{"1.5 is le(0.5)",                     "false"},
                            InputOutputPair{"'0.5' is le('0.5')",                 "true"},
                            InputOutputPair{"'0.5' is le('1.5')",                 "true"},
                            InputOutputPair{"'1.5' is le('0.5')",                 "false"},
                            InputOutputPair{"'Hello World' is le('hello world')", "true"},
                            InputOutputPair{"'hello world' is le('Hello World')", "false"},
                            InputOutputPair{"intList[0] is le(intAsDoubleList[0])", "true"},
                            InputOutputPair{"intList[0] is le(intAsDoubleList[1])", "false"},
                            InputOutputPair{"intList[1] is le(intAsDoubleList[0])", "true"},
                            InputOutputPair{"intAsDoubleList[0] is le(intList[0])", "true"},
                            InputOutputPair{"intAsDoubleList[0] is le(intList[1])", "false"},
                            InputOutputPair{"intAsDoubleList[1] is le(intList[0])", "true"}
                            ));


INSTANTIATE_TEST_CASE_P(LtTest, TestersGenericTest, ::testing::Values(
                            InputOutputPair{"0 is lt(0)",                         "false"},
                            InputOutputPair{"0 is lessthan(0)",                   "false"},
                            InputOutputPair{"0 is lessthan(1)",                   "true"},
                            InputOutputPair{"1 is lt(0)",                         "false"},
                            InputOutputPair{"0.5 is lt(0.5)",                     "false"},
                            InputOutputPair{"0.5 is lt(1.5)",                     "true"},
                            InputOutputPair{"1.5 is lt(0.5)",                     "false"},
                            InputOutputPair{"'0.5' is lt('0.5')",                 "false"},
                            InputOutputPair{"'0.5' is lt('1.5')",                 "true"},
                            InputOutputPair{"'1.5' is lt('0.5')",                 "false"},
                            InputOutputPair{"'Hello World' is lt('hello world')", "true"},
                            InputOutputPair{"'hello world' is lt('Hello World')", "false"},
                            InputOutputPair{"intList[0] is lt(intAsDoubleList[0])", "false"},
                            InputOutputPair{"intList[0] is lt(intAsDoubleList[1])", "false"},
                            InputOutputPair{"intList[1] is lt(intAsDoubleList[0])", "true"},
                            InputOutputPair{"intAsDoubleList[0] is lt(intList[0])", "false"},
                            InputOutputPair{"intAsDoubleList[0] is lt(intList[1])", "false"},
                            InputOutputPair{"intAsDoubleList[1] is lt(intList[0])", "true"}
                            ));

INSTANTIATE_TEST_CASE_P(DefinedTest, TestersGenericTest, ::testing::Values(
                            InputOutputPair{"antList is defined",              "false"},
                            InputOutputPair{"intList is defined",              "true"}
                            ));

INSTANTIATE_TEST_CASE_P(UndefinedTest, TestersGenericTest, ::testing::Values(
                            InputOutputPair{"antList is undefined",              "true"},
                            InputOutputPair{"intList is undefined",              "false"}
                            ));

INSTANTIATE_TEST_CASE_P(IterableTest, TestersGenericTest, ::testing::Values(
                            InputOutputPair{"0 is iterable",              "false"},
                            InputOutputPair{"'intList' is iterable",      "false"},
                            InputOutputPair{"false is iterable",          "false"},
                            InputOutputPair{"0.2 is iterable",            "false"},
                            InputOutputPair{"intValue is iterable",       "false"},
                            InputOutputPair{"stringValue is iterable",    "false"},
                            InputOutputPair{"doubleValue is iterable",    "false"},
                            InputOutputPair{"boolFalseValue is iterable", "false"},
                            InputOutputPair{"boolTrueValue is iterable",  "false"},
                            InputOutputPair{"[0, 1, 2] is iterable",      "true"},
                            InputOutputPair{"(0, 1, 2) is iterable",      "true"},
                            InputOutputPair{"{'name'='itemName', 'val'='itemValue'} is iterable",        "true"},
                            InputOutputPair{"mapValue is iterable",       "true"},
                            // InputOutputPair{"mapValue | first is iterable", "false"},
                            InputOutputPair{"intList is iterable",        "true"},
                            InputOutputPair{"reflectedVal is iterable",   "true"},
                            InputOutputPair{"reflectedList is iterable",  "true"}
                            ));

INSTANTIATE_TEST_CASE_P(MappingTest, TestersGenericTest, ::testing::Values(
                            InputOutputPair{"0 is mapping",              "false"},
                            InputOutputPair{"'intList' is mapping",      "false"},
                            InputOutputPair{"false is mapping",          "false"},
                            InputOutputPair{"0.2 is mapping",            "false"},
                            InputOutputPair{"intValue is mapping",       "false"},
                            InputOutputPair{"stringValue is mapping",    "false"},
                            InputOutputPair{"doubleValue is mapping",    "false"},
                            InputOutputPair{"boolFalseValue is mapping", "false"},
                            InputOutputPair{"boolTrueValue is mapping",  "false"},
                            InputOutputPair{"[0, 1, 2] is mapping",      "false"},
                            InputOutputPair{"(0, 1, 2) is mapping",      "false"},
                            InputOutputPair{"{'name'='itemName', 'val'='itemValue'} is mapping",        "true"},
                            InputOutputPair{"mapValue is mapping",       "true"},
                            // InputOutputPair{"mapValue | first is mapping", "true"}, ???
                            InputOutputPair{"intList is mapping",        "false"},
                            InputOutputPair{"reflectedVal is mapping",   "true"},
                            InputOutputPair{"reflectedList is mapping",  "false"}
                            ));

INSTANTIATE_TEST_CASE_P(NumberTest, TestersGenericTest, ::testing::Values(
                            InputOutputPair{"0 is number",              "true"},
                            InputOutputPair{"'intList' is number",      "false"},
                            InputOutputPair{"false is number",          "false"},
                            InputOutputPair{"0.2 is number",            "true"},
                            InputOutputPair{"intValue is number",       "true"},
                            InputOutputPair{"stringValue is number",    "false"},
                            InputOutputPair{"doubleValue is number",    "true"},
                            InputOutputPair{"boolFalseValue is number", "false"},
                            InputOutputPair{"boolTrueValue is number",  "false"},
                            InputOutputPair{"[0, 1, 2] is number",      "false"},
                            InputOutputPair{"(0, 1, 2) is number",      "false"},
                            InputOutputPair{"{'name'='itemName', 'val'='itemValue'} is number",        "false"},
                            InputOutputPair{"mapValue is number",       "false"},
                            // InputOutputPair{"mapValue | first is number", "true"}, ???
                            InputOutputPair{"intList is number",        "false"},
                            InputOutputPair{"reflectedVal is number",   "false"},
                            InputOutputPair{"reflectedList is number",  "false"}
                            ));
                            
INSTANTIATE_TEST_CASE_P(SequenceTest, TestersGenericTest, ::testing::Values(
                            InputOutputPair{"0 is sequence",              "false"},
                            InputOutputPair{"'intList' is sequence",      "false"},
                            InputOutputPair{"false is sequence",          "false"},
                            InputOutputPair{"0.2 is sequence",            "false"},
                            InputOutputPair{"intValue is sequence",       "false"},
                            InputOutputPair{"stringValue is sequence",    "false"},
                            InputOutputPair{"doubleValue is sequence",    "false"},
                            InputOutputPair{"boolFalseValue is sequence", "false"},
                            InputOutputPair{"boolTrueValue is sequence",  "false"},
                            InputOutputPair{"[0, 1, 2] is sequence",      "true"},
                            InputOutputPair{"(0, 1, 2) is sequence",      "true"},
                            InputOutputPair{"{'name'='itemName', 'val'='itemValue'} is sequence",        "false"},
                            InputOutputPair{"mapValue is sequence",       "false"},
                            // InputOutputPair{"mapValue | first is sequence", "true"}, ???
                            InputOutputPair{"intList is sequence",        "true"},
                            InputOutputPair{"reflectedVal is sequence",   "false"},
                            InputOutputPair{"reflectedList is sequence",  "true"}
                            ));

                            
INSTANTIATE_TEST_CASE_P(StringTest, TestersGenericTest, ::testing::Values(
                            InputOutputPair{"0 is string",              "false"},
                            InputOutputPair{"'intList' is string",      "true"},
                            InputOutputPair{"false is string",          "false"},
                            InputOutputPair{"0.2 is string",            "false"},
                            InputOutputPair{"intValue is string",       "false"},
                            InputOutputPair{"stringValue is string",    "true"},
                            InputOutputPair{"doubleValue is string",    "false"},
                            InputOutputPair{"boolFalseValue is string", "false"},
                            InputOutputPair{"boolTrueValue is string",  "false"},
                            InputOutputPair{"[0, 1, 2] is string",      "false"},
                            InputOutputPair{"(0, 1, 2) is string",      "false"},
                            InputOutputPair{"{'name'='itemName', 'val'='itemValue'} is string",        "false"},
                            InputOutputPair{"mapValue is string",       "false"},
                            // InputOutputPair{"mapValue | first is string", "true"}, ???
                            InputOutputPair{"intList is string",        "false"},
                            InputOutputPair{"reflectedVal is string",   "false"},
                            InputOutputPair{"reflectedList is string",  "false"}
                            ));
