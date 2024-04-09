#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template < typename T > void print( T const &i ) { std::cout << "  value = " << i << std::endl; }
template < typename T > void iter( T *ptr, size_t len, void ( *f )( T const & ) )
{
	for ( size_t i = 0; i < len; i++ )
		f( ptr[ i ]);
}

#endif // ITER_HPP