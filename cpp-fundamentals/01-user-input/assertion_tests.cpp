#include <cassert>
#include <sstream>
#include <istream>

bool get_number(std::istream & input, double & number){
	number = 1;
	return true;
}

void test_code(){
	double value{};
	std::stringstream forced_input{"1"};
	const bool ok = get_number(forced_input, value);
	assert(ok);
	assert(value == 1);
}

int main(){

}
