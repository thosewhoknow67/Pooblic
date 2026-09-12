#include <expected>
#include <string>
#include <iostream>

std::expected<double, std::string> get_number(std::istream & input){
	double number{};
	input >> number;
	if(input){
		return number;
	}
	return std::unexpected{"That's not a number!\n"};
}
int main(){
	std::cout << "Please enter a number: \n";
	auto number = get_number(std::cin);
	while (true){
		if (number){
			std::cout << "Thank you, your number was " << number.value();
			break;
		}
		else {
			std::cout << number.error() << "\n";
		}						
	}
}
