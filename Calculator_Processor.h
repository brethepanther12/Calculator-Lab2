#pragma once
#include <string>
#include <cmath>
#include <cctype>
#include <vector>
#include <stack>
#include <stdexcept>
class Calculator_Processor
{
private:
	static Calculator_Processor* _calculation;

	Calculator_Processor();

public:
	static Calculator_Processor* GetCalculation();
	
	double Calculate(const std::string& expression);

	std::vector<std::string> Tokenize(const std::string& expression);
	std::vector<std::string> ShuntingYard(std::vector<std::string>& tokens);
	double Evaluation(const std::vector<std::string>& evaluate);

	int Precedence(const std::string& _operator);
	bool IsOperator(const std::string& token);
	bool IsFunction(const std::string& token);
};

