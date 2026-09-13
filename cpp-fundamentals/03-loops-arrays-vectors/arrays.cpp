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

void show_numbers(const std::array<double,5u> & array){
	for (const auto number: array){
		std::cout << number << '\n';
	}
}

void max_numbers(const std::array<double,5u> & array){
	double biggest = array[0];
	for (const auto number: array){
		if (number > biggest){
			biggest = number;
		}
	}
	std::cout << "The biggest number was " << biggest << '\n';
}


int main(){
	std::cout << "Please enter some numbers:\n "; 
	std::array<double, 5u> array_numbers{};
	size_t count{0u};
	while (count < array_numbers.size())
	{
		std::cout << '>';
		auto number = get_number(std::cin);
		if (number.has_value()){
			array_numbers[count] = number.value();
			std::cout << "Your number was " << number.value() << '\n';
		}
		else { 
			std::cout << number.error() << '\n';	
		}
		++count;
	}
	show_numbers(array_numbers);
	max_numbers(array_numbers);
}
