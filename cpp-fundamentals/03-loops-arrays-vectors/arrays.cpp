#include <expected>
#include <array>
#include <iostream>
#include <limits>

std::expected<double, std::string> get_number(std::istream & input){
	double number {};
	input >> number; 
	if (input){
		return number;
	}
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        return std::unexpected{"That's not a number"};	
}


int main(){
	std::cout << "Please enter some numbers:\n "; 
	std::array<double, 5u> numbers{};
	size_t count{0u};
	while (count < numbers.size())
	{
		std::cout << '>';
		auto number = get_number(std::cin);
		if (number.has_value()){
			numbers[count] = number.value();
			std::cout << "Your number was " << number.value() << '\n';
		}
		else { 
			std::cout << number.error() << '\n';	
		}
		++count;
	}
}
