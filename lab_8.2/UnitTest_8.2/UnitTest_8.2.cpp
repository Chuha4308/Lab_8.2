#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_8.2/lab8.2.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest82
{
    TEST_CLASS(UnitTest82)
    {
    public:

        TEST_METHOD(TestFindMinConsecutiveDigits_SimpleCase)
        {
            std::string input = "a123b456c";
            int expectedOutput = 3;
            int actualOutput = findMin(input);

            Assert::AreEqual(expectedOutput, actualOutput);
        }

        TEST_METHOD(TestFindMinConsecutiveDigits_SingleDigit)
        {
            std::string input = "a1b2c3";
            int expectedOutput = 1;
            int actualOutput = findMin(input);

            Assert::AreEqual(expectedOutput, actualOutput);
        }

        TEST_METHOD(TestFindMinConsecutiveDigits_NoDigits)
        {
            std::string input = "abcdef";
            int expectedOutput = 0;
            int actualOutput = findMin(input);

            Assert::AreEqual(expectedOutput, actualOutput);
        }

        TEST_METHOD(TestFindMinConsecutiveDigits_MixedCase)
        {
            std::string input = "abc12def345gh";
            int expectedOutput = 2;
            int actualOutput = findMin(input);

            Assert::AreEqual(expectedOutput, actualOutput);
        }

       
    };
}
