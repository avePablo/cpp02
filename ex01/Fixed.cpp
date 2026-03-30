#include <cmath>
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed( void ) : _raw(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ) : _raw( src._raw ) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed( int const intValue ) {
    std::cout << "Int constructor called" << std::endl;
    _raw = intValue << _fractionalBits;
}

Fixed::Fixed( float const floatValue ) {
    std::cout << "Float constructor called" << std::endl;
    _raw = static_cast<int>( roundf( floatValue * (1 << _fractionalBits) ) );
}

Fixed & Fixed::operator=( Fixed const & rhs ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if ( this != &rhs ) {
        _raw = rhs._raw;
    }
    return *this;
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _raw;
}

void Fixed::setRawBits( int const raw ) {
    _raw = raw;
}

float Fixed::toFloat( void ) const {
    return static_cast<float>( _raw ) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const {
    return _raw >> _fractionalBits;
}

std::ostream & operator<<( std::ostream & os, Fixed const & value ) {
    os << value.toFloat();
    return os;
}
