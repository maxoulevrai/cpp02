#include "includes/Fixed.hpp"
#include <iostream>

int main() {
	Fixed a;
	Fixed b(10);
	Fixed c(42.42f);
	Fixed d(b);

	a = Fixed(5.5f);
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	// comparisons
	std::cout << std::boolalpha;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "b > c: " << (b > c) << std::endl;

	// arithmetic
	std::cout << "b + c = " << (b + c) << std::endl;
	std::cout << "c - b = " << (c - b) << std::endl;
	std::cout << "b * c = " << (b * c) << std::endl;
	std::cout << "c / b = " << (c / b) << std::endl;

	// increment
	Fixed e;
	std::cout << "e = " << e << std::endl;
	std::cout << "++e = " << ++e << std::endl;
	std::cout << "e++ = " << e++ << std::endl;
	std::cout << "e = " << e << std::endl;

	// min / max
	std::cout << "min(b, c) = " << Fixed::min(b, c) << std::endl;
	std::cout << "max(b, c) = " << Fixed::max(b, c) << std::endl;

	return 0;
}
