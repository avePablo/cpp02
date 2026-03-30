#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
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

#endif // FIXED_HPP
