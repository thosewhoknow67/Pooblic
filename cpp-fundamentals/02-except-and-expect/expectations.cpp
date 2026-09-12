#include <expected>
#include <string>
#include <iostream>

std::expected<double, std::string> get_number(std::istring & input){
	double number{};
	input >> number;
	if(input){
		return number;
	}
	return std::unexpected{"That's not a number!\n"};

int main(){
	std::cout << "Please enter a number: \n";
	auto number = get_number(std::cin);
        if (number.has_value()){
		std::cout << "Thank you, your number was " << number;
	}
	else {
		std::cout << number.error() << "\n";
	}
	
}
