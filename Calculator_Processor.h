#pragma once
#include <string>
#include <cmath>
#include <stdexcept>
class Calculator_Processor
{
private:
	static Calculator_Processor* _calculation;

	Calculator_Processor();

public:
	static Calculator_Processor* GetCalculation();
	
	double Calculate(const std::string& expression);
};

