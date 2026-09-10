#include <cassert>
#include <sstream>
#include <istream>

bool get_number(std::istream & input, double & number){
	input >> number;
	if (input){
		return true;
	}
	else{
		return false;
	}
}

void test_code(){
	double value{};
	std::stringstream forced_input{"1"};
	const bool ok = get_number(forced_input, value);
	assert(ok);
	assert(value == 1);

	double value2{};
	std::stringstream failing_input{"q"};
	const bool not_ok = get_number(failing_input, value2);
	assert(!not_ok);
	assert(value2 == 0);
}

int main(){
	test_code();
}
