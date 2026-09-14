#include <expected>
#include <string>
#include <iostream>

//get_number function
std::expected<double, std::string> get_number(std::istream & input){
	double number{};
	input >> number;
	if(input){
		return number;
	}
	//Should return if not a number
	return std::unexpected{"That's not a number!\n"};
}
int main(){
	std::cout << "Please enter a number: \n";
	auto number = get_number(std::cin);
        if (number){
		std::cout << "Thank you, your number was " << number.value();
	}
	else {
		std::cout << number.error() << "\n";
	}
	
}
