/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:42:25 by pabalvar          #+#    #+#             */
/*   Updated: 2026/06/08 18:59:21 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed( void ) : _raw(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ) : _raw( src._raw ) 
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed & Fixed::operator=( Fixed const & rhs ) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if ( this != &rhs ) {
        _raw = rhs._raw;
    }
    return *this;
}

Fixed::~Fixed( void ) 
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return _raw;
}

void Fixed::setRawBits( int const raw ) 
{
    _raw = raw;
}
