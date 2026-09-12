#include <array>
#include <iostream>

void array_experiment(){
	std::array<double, 5> number{};
	std::cout << number[0] << '\n';
	number[0] = 2.5;
	std::cout << number[0];	
}

int main(){
	array_experiment();
}
