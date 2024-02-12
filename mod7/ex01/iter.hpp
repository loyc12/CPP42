#ifndef ITER_HPP
# define ITER_HPP

template < typename T > void print( T const &i ) { std::cout << "  value = " << i << std::endl; }
template < typename T > void iter( T *ptr, size_t len, void ( *f )( T const & ) )
{
	T *arr = reinterpret_cast< T * >( ptr );
	for ( size_t i = 0; i < len; i++ )
		f( arr[ i ]);
}

#endif // ITER_HPP