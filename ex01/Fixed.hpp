/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:42:54 by pabalvar          #+#    #+#             */
/*   Updated: 2026/06/08 19:01:37 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
public:
    Fixed( void );
    Fixed( Fixed const & src );
    Fixed( int const intValue );
    Fixed( float const floatValue );
    Fixed & operator=( Fixed const & rhs );
    ~Fixed( void );

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

private:
    int _raw;
    static const int _fractionalBits = 8;
};

std::ostream & operator<<( std::ostream & os, Fixed const & value );

#endif
