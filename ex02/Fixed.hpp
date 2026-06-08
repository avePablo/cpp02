/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:43:06 by pabalvar          #+#    #+#             */
/*   Updated: 2026/06/08 19:01:12 by pabalvar         ###   ########.fr       */
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

    bool operator>( Fixed const & rhs ) const;
    bool operator<( Fixed const & rhs ) const;
    bool operator>=( Fixed const & rhs ) const;
    bool operator<=( Fixed const & rhs ) const;
    bool operator==( Fixed const & rhs ) const;
    bool operator!=( Fixed const & rhs ) const;

    Fixed operator+( Fixed const & rhs ) const;
    Fixed operator-( Fixed const & rhs ) const;
    Fixed operator*( Fixed const & rhs ) const;
    Fixed operator/( Fixed const & rhs ) const;

    Fixed & operator++( void );
    Fixed operator++( int );
    Fixed & operator--( void );
    Fixed operator--( int );

    static Fixed & min( Fixed & lhs, Fixed & rhs );
    static Fixed const & min( Fixed const & lhs, Fixed const & rhs );
    static Fixed & max( Fixed & lhs, Fixed & rhs );
    static Fixed const & max( Fixed const & lhs, Fixed const & rhs );

private:
    int _raw;
    static const int _fractionalBits = 8;
};

std::ostream & operator<<( std::ostream & os, Fixed const & value );

#endif
