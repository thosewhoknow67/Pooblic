#include <iostream>
#include <limits>
int main(){
       	std::cout << "What is your age?\n";
       	double  age{}, number{};
	std::cin >> age; 
        std::cout << "What is your favourite number?\n";
	std::cin >> number;
	int max_int = std::numeric_limits<int>::max();
	std::cout << "Your age is " << age << " and your favourite number is " << number << " and did you know that the highest number for an integer in C++ is " << max_int << "?\n";
}

