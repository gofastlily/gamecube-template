#include "utils.hpp"


namespace utils {


char* Utils::CppStandard() {
	switch (__cplusplus) {
		case 202101L: return (char*)"C++23";
		case 202002L: return (char*)"C++20";
		case 201703L: return (char*)"C++17";
		case 201402L: return (char*)"C++14";
		case 201103L: return (char*)"C++11";
		case 199711L: return (char*)"C++98";
		default: return (char*)"pre-standard C++";
	}
}


}	// namespace utils
