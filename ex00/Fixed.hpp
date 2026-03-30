#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
    Fixed( void );
    Fixed( Fixed const & src );
    Fixed & operator=( Fixed const & rhs );
    ~Fixed( void );

    int getRawBits( void ) const;
    void setRawBits( int const raw );

private:
    int _raw;
    static const int _fractionalBits = 8;
};

#endif // FIXED_HPP
