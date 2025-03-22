#include "Calculator_Processor.h"
Calculator_Processor* Calculator_Processor::_calculation= nullptr;

Calculator_Processor::Calculator_Processor() {};

Calculator_Processor* Calculator_Processor::GetCalculation() {
	if (!_calculation) {
		_calculation = new Calculator_Processor();
	}
	return _calculation;
}

double Calculator_Processor::Calculate(const std::string& expression) {

	//Tokenization and yard here.
	return 0.0;
}