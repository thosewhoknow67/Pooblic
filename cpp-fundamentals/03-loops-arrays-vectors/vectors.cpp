#include <vector>
#include <expected>
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

void vector_insert(){
	std::vector<int> numbers{0,1};
	numbers.insert(numbers.begin(), -123);
	for (const auto number:numbers){
		std::cout << number << '\n';
	}
}

int main(){
	std::cout << "Please enter some numbers:\n ";
	std::vector<double> numbers{};
        auto number = get_number(std::cin);
        while (number.has_value()){
		numbers.push_back(number.value());
		std::cout << number << '\n';
		number = get_number(std::cin);
	}
	std::cout << number.error() << '\n';

	std::cout << "You entered\n";
	for (const auto number: numbers){
		std::cout << number << '\n';
	}
}
