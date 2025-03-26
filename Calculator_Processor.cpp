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
	std::vector<std::string> tokens = Tokenize(expression);
	std::vector<std::string> evaluation = ShuntingYard(tokens);
	return Evaluation(evaluation);
}

std::vector<std::string> Calculator_Processor::Tokenize(const std::string& expression)
{
	std::vector<std::string> tokens;
	std::string number;

	for (size_t i = 0; i < expression.size(); i++) {
		char character = expression[i];

		if (isdigit(character) || character == '.') {number += character;}
		else if (isalpha(character)) {
			std::string function;
			while (i < expression.size() && isalpha(expression[i])) {
				function += expression[i++];
			}
			--i;
			tokens.push_back(function);
		}
		else if (character == '+' || character == '-' || character == '*' || character == '/' || character == '%') {
			if (!number.empty()) {
				tokens.push_back(number);
				number.clear();
			}
			tokens.push_back(std::string(1, character));
		}
		else if (isspace(character)) {
			continue;
		}
	}
	if (!number.empty()) {
		tokens.push_back(number);
	}
 
	return tokens;
}

std::vector<std::string> Calculator_Processor::ShuntingYard(std::vector<std::string>& tokens)
{
	std::vector<std::string> output;
	std::stack<std::string> operatorStack;

	for (const std::string& token : tokens) {
		if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1]))) {
			output.push_back(token); 
		}
		else if (IsFunction(token)) {
			operatorStack.push(token);
		}
		else if (IsOperator(token)) {
			while (!operatorStack.empty() && Precedence(operatorStack.top()) >= Precedence(token)) {
				output.push_back(operatorStack.top());
				operatorStack.pop();
			}
			operatorStack.push(token);
		}
	}

	while (!operatorStack.empty()) {
		output.push_back(operatorStack.top());
		operatorStack.pop();
	}

	return output;
}

double Calculator_Processor::Evaluation(const std::vector<std::string>& evaluate)
{
	std::stack<double> evaluatedStack;

	for (const std::string& token : evaluate) {
		if (IsOperator(token)) {
			if (evaluatedStack.size() < 2) {
				throw std::runtime_error("Insufficient operands for operator " + token);
			}
			double b = evaluatedStack.top(); evaluatedStack.pop();
			double a = evaluatedStack.top(); evaluatedStack.pop();

			if (token == "+") { evaluatedStack.push(a + b); }
			else if (token == "-") { evaluatedStack.push(a - b); }
			else if (token == "*") { evaluatedStack.push(a * b); }
			else if (token == "/") {
				if (b == 0) throw std::runtime_error("Division by zero");
				evaluatedStack.push(a / b);
			}
			else if (token == "%") { evaluatedStack.push(fmod(a, b)); }
		}
		else if (IsFunction(token)) {
			if (evaluatedStack.empty()) {
				throw std::runtime_error("Insufficient operands for function " + token);
			}
			double value = evaluatedStack.top(); evaluatedStack.pop();
			if (token == "sin") { evaluatedStack.push(sin(value)); }
			else if (token == "cos") { evaluatedStack.push(cos(value)); }
			else if (token == "tan") { evaluatedStack.push(tan(value)); }
		}
		else {
			evaluatedStack.push(std::stod(token));
		}
	}

	if (evaluatedStack.empty()) {
		throw std::runtime_error("Evaluation resulted in an empty stack.");
	}
	return evaluatedStack.top();
}

int Calculator_Processor::Precedence(const std::string& _operator)
{
	if (_operator == "sin" || _operator == "cos" || _operator == "tan") { return 3; }
	if (_operator == "*" || _operator == "/" || _operator == "%") { return 2; }
	if (_operator == "+" || _operator == "-") { return 1; }
	return 0;
}

bool Calculator_Processor::IsOperator(const std::string& token)
{
	return token == "+"|| token == "-"||token == "*"|| token == "/"||token == "%";
}

bool Calculator_Processor::IsFunction(const std::string& token)
{
	return token == "sin" || token == "cos" || token == "tan";
}


