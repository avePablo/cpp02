/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:43:01 by pabalvar          #+#    #+#             */
/*   Updated: 2026/06/08 19:25:50 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed( void ) : _raw(0) 
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ) : _raw( src._raw ) 
{
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed( int const intValue ) 
{
    // std::cout << "Int constructor called" << std::endl;
    _raw = intValue << _fractionalBits;
}

Fixed::Fixed( float const floatValue ) 
{
    // std::cout << "Float constructor called" << std::endl;
    _raw = static_cast<int>( roundf( floatValue * (1 << _fractionalBits) ) );
}

Fixed & Fixed::operator=( Fixed const & rhs ) 
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if ( this != &rhs ) {
        _raw = rhs._raw;
    }
    return *this;
}

Fixed::~Fixed( void ) 
{
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const 
{
    // std::cout << "getRawBits member function called" << std::endl;
    return _raw;
}

void Fixed::setRawBits( int const raw ) 
{
    _raw = raw;
}

float Fixed::toFloat( void ) const 
{
    return static_cast<float>( _raw ) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const 
{
    return _raw >> _fractionalBits;
}

bool Fixed::operator>( Fixed const & rhs ) const 
{
    return _raw > rhs._raw;
}

bool Fixed::operator<( Fixed const & rhs ) const 
{
    return _raw < rhs._raw;
}

bool Fixed::operator>=( Fixed const & rhs ) const 
{
    return _raw >= rhs._raw;
}

bool Fixed::operator<=( Fixed const & rhs ) const 
{
    return _raw <= rhs._raw;
}

bool Fixed::operator==( Fixed const & rhs ) const 
{
    return _raw == rhs._raw;
}

bool Fixed::operator!=( Fixed const & rhs ) const 
{
    return _raw != rhs._raw;
}

Fixed Fixed::operator+( Fixed const & rhs ) const 
{
    Fixed result;
    result._raw = _raw + rhs._raw;
    return result;
}

Fixed Fixed::operator-( Fixed const & rhs ) const 
{
    Fixed result;
    result._raw = _raw - rhs._raw;
    return result;
}

Fixed Fixed::operator*( Fixed const & rhs ) const 
{
    Fixed result;
    long long temp = static_cast<long long>( _raw ) * rhs._raw;
    result._raw = static_cast<int>( temp >> _fractionalBits );
    return result;
}

Fixed Fixed::operator/( Fixed const & rhs ) const 
{
    Fixed result;
    long long temp = ( static_cast<long long>( _raw ) << _fractionalBits ) / rhs._raw;
    result._raw = static_cast<int>( temp );
    return result;
}

Fixed & Fixed::operator++( void ) 
{
    ++_raw;
    return *this;
}

Fixed Fixed::operator++( int ) 
{
    Fixed temp( *this );
    ++_raw;
    return temp;
}

Fixed & Fixed::operator--( void ) 
{
    --_raw;
    return *this;
}

Fixed Fixed::operator--( int ) 
{
    Fixed temp( *this );
    --_raw;
    return temp;
}

Fixed & Fixed::min( Fixed & lhs, Fixed & rhs ) 
{
    return lhs < rhs ? lhs : rhs;
}

Fixed const & Fixed::min( Fixed const & lhs, Fixed const & rhs ) 
{
    return lhs < rhs ? lhs : rhs;
}

Fixed & Fixed::max( Fixed & lhs, Fixed & rhs ) 
{
    return lhs > rhs ? lhs : rhs;
}

Fixed const & Fixed::max( Fixed const & lhs, Fixed const & rhs ) 
{
    return lhs > rhs ? lhs : rhs;
}

std::ostream & operator<<( std::ostream & os, Fixed const & value ) 
{
    os << value.toFloat();
    return os;
}
