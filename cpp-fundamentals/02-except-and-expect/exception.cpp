#include <istream>
#include <iostream>
#include <exception>

double get_number(std::istream & input){
	double number{};
	input >> number;

	if(input){
		return number;
	}
	throw std::exception{};
}

int main(){
	std::cout << "Please enter a number: ";
	double number = get_number(std::cin);
	std::cout << "Got it, " << number << ", thanks :)\n";

}
