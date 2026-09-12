#include <expected>
#include <array>
#include <iostream>
#include <limits>

void array_experiment(){
}
std::expected<double, std::string> get_number(std::istream & input){
	double number {};
	input >> number; 
	if (input){
		return number;
	}
        input.clear();
        input.ignore(std::numeric_limits<std:streamsize>::max(),'\n');
        return std::unexpected{"That's not a number"};	
}


int main(){
	array_experiment();
}
