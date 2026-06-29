#include "../includes/Fixed.hpp"
#include <cmath>

const int Fixed::_fractionnalBits = 8;

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default contructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = value << _fractionnalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = static_cast<int>(roundf(value * (1 << _fractionnalBits)));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

float	Fixed::tofloat( void ) const {
	return static_cast<float>(this->_rawBits) / (1 << _fractionnalBits);
}

int	Fixed::toInt( void ) const {
	return this->_rawBits >> _fractionnalBits;
}

// comparisons
bool Fixed::operator>(const Fixed &other) const { return this->_rawBits > other._rawBits; }
bool Fixed::operator<(const Fixed &other) const { return this->_rawBits < other._rawBits; }
bool Fixed::operator>=(const Fixed &other) const { return this->_rawBits >= other._rawBits; }
bool Fixed::operator<=(const Fixed &other) const { return this->_rawBits <= other._rawBits; }
bool Fixed::operator==(const Fixed &other) const { return this->_rawBits == other._rawBits; }
bool Fixed::operator!=(const Fixed &other) const { return this->_rawBits != other._rawBits; }

// arithmetic
Fixed Fixed::operator+(const Fixed &other) const {
	Fixed res;
	res._rawBits = this->_rawBits + other._rawBits;
	return res;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed res;
	res._rawBits = this->_rawBits - other._rawBits;
	return res;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed res;
	long tmp = static_cast<long>(this->_rawBits) * static_cast<long>(other._rawBits);
	res._rawBits = static_cast<int>((tmp >> _fractionnalBits));
	return res;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed res;
	long tmp = (static_cast<long>(this->_rawBits) << _fractionnalBits) / other._rawBits;
	res._rawBits = static_cast<int>(tmp);
	return res;
}

// increment / decrement
Fixed &Fixed::operator++() { // pre
	this->_rawBits += 1;
	return *this;
}

Fixed Fixed::operator++(int) { // post
	Fixed tmp = *this;
	this->_rawBits += 1;
	return tmp;
}

Fixed &Fixed::operator--() { this->_rawBits -= 1; return *this; }
Fixed Fixed::operator--(int) { Fixed tmp = *this; this->_rawBits -= 1; return tmp; }

// min / max
Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return (a < b) ? a : b; }
Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return (a > b) ? a : b; }

std::ostream &operator<<(std::ostream &os, const Fixed &other) {
	os << other.tofloat();
	return os;
}
