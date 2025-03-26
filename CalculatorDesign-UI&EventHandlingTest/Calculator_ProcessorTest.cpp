#include "pch.h"
#include "../../Calculator-Lab2/Calculator_Processor.h"
#include <CppUnitTest.h>
#include <stdexcept>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
std::wstring StringToWString(const std::string& str) {
	return std::wstring(str.begin(), str.end());
}
namespace CalculatorTests
{
		TEST_CLASS(Calculator_ProcessorTest) {
	public:

		
		TEST_METHOD(TestGetCalculation) {
			Calculator_Processor* calc1 = Calculator_Processor::GetCalculation();
			Calculator_Processor* calc2 = Calculator_Processor::GetCalculation();
			Assert::IsTrue(calc1 == calc2, L"Singleton instance not the same.");
		}

		
		TEST_METHOD(TestCalculate) {
			Calculator_Processor* calc = Calculator_Processor::GetCalculation();
			std::string expression = "3 + 5";
			double result = calc->Calculate(expression);
			Assert::AreEqual(result, 8.0, L"Calculation for simple addition failed.");
		}

		
		TEST_METHOD(TestTokenize) {
			Calculator_Processor* processor = Calculator_Processor::GetCalculation();
			std::string input = "3+5*2";
			std::vector<std::string> expected = { "3", "+", "5", "*", "2" };
			std::vector<std::string> result = processor->Tokenize(input);

			
			for (size_t i = 0; i < expected.size(); ++i) {
				Assert::AreEqual(StringToWString(expected[i]).c_str(),
					StringToWString(result[i]).c_str(),
					L"Tokenization mismatch");
			}
		}

		TEST_METHOD(TestShuntingYard) {
			Calculator_Processor* calc = Calculator_Processor::GetCalculation();
			std::vector<std::string> tokens = { "3", "+", "5" };
			std::vector<std::string> output = calc->ShuntingYard(tokens);
			Assert::AreEqual(output.size(), (size_t)3, L"Shunting Yard output size mismatch.");

		}


		TEST_METHOD(TestEvaluation) {
			Calculator_Processor* calc = Calculator_Processor::GetCalculation();
			std::vector<std::string> tokens = { "3", "5", "+" };
			double result = calc->Evaluation(tokens);
			Assert::AreEqual(result, 8.0, L"Evaluation failed for simple addition.");
		}

	
		TEST_METHOD(TestPrecedence) {
			Calculator_Processor* calc = Calculator_Processor::GetCalculation();
			Assert::AreEqual(calc->Precedence("+"), 1, L"Incorrect precedence for '+' operator.");
			Assert::AreEqual(calc->Precedence("*"), 2, L"Incorrect precedence for '*' operator.");
		}

	
		TEST_METHOD(TestIsOperator) {
			Calculator_Processor* calc = Calculator_Processor::GetCalculation();
			Assert::IsTrue(calc->IsOperator("+"), L"Failed to identify '+' as an operator.");
			Assert::IsFalse(calc->IsOperator("3"), L"Identified a number as an operator.");
		}

		TEST_METHOD(TestIsFunction) {
			Calculator_Processor* calc = Calculator_Processor::GetCalculation();
			Assert::IsTrue(calc->IsFunction("sin"), L"Failed to identify 'sin' as a function.");
			Assert::IsFalse(calc->IsFunction("+"), L"Incorrectly identified '+' as a function.");
		}

	
		TEST_METHOD(TestComplexExpression) {
			Calculator_Processor* calc = Calculator_Processor::GetCalculation();
			std::string expression = "3 + 5 * 2";
			double result = calc->Calculate(expression);
			Assert::AreEqual(result, 13.0, L"Complex expression calculation failed.");
		}
		};
  
}