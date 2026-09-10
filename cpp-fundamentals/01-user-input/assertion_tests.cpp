#include <iostream>
#include <cassert>
#include <sstream>
#include <istream>

[[nodiscard]] bool get_number(std::istream & input, double & number){
	input >> number;
	if (input){
		return true;
	}
	else{
		return false;
	}
}

void test_code(){
	double value{};
	std::stringstream forced_input{"1"};
	const bool ok = get_number(forced_input, value);
	assert(ok);
	assert(value == 1);

	double value2{};
	std::stringstream failing_input{"q"};
	const bool not_ok = get_number(failing_input, value2);
	assert(!not_ok);
}

int main(){
	test_code();

	double number{};
	std::cout << "Input a number please:\n";
	if (get_number(std::cin, number)){
		std::cout << "Thank you, " << number << " was your number!";
	}
	else{
		std::cout << "Something went wrong :(\n";
	}
}
