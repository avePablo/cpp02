/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:42:33 by pabalvar          #+#    #+#             */
/*   Updated: 2026/06/08 18:59:27 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed 
{
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

#endif
