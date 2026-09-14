#include <iostream>
#include <cassert>
#include <sstream>
#include <istream>
#include <limits>

//get_number function {used no discard to ensure fucntionality}
[[nodiscard]] bool get_number(std::istream & input, double & number){
	input >> number;
	if (input){
		return true;
	}
	else{
		input.clear();
		input.ignore(std::numericlimits<std::streamsize>.max(), '\n');
		return false;
	}
}

void test_code(){
	//Valid code 
	double value{};
	std::stringstream forced_input{"1"};
	const bool ok = get_number(forced_input, value);
	assert(ok);
	assert(value == 1);

	//Testing for valid failure
	double value2{};
	std::stringstream failing_input{"q"};
	const bool not_ok = get_number(failing_input, value2);
	assert(!not_ok);
}

int main(){
	test_code();
	
	//Simple i/o
	double number{};
	std::cout << "Input a number please:\n";
	const bool ok = get_number(std::cin, number);
	if (ok){
		std::cout << "Thank you, " << number << " was your number!";
	}
	else{
		std::cout << "Something went wrong\n Try Again:\n"; 
                const bool ok_now = get_number(std::cin, number);
		if (ok_now){
			std::cout << "Thank you, " << number << " was your number!";
		}
		else{
			std::cout << "Something went wrong again :(";
		}
	}
}
