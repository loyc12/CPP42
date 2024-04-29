#ifndef FOO_TPP
# define FOO_TPP

# include "Foo.hpp" // for template class Foo_T

// Debuggers
TTT void	Foo_T< T >::debug( bool debug ) { this->_debug = debug; }
TTT bool	Foo_T< T >::debug( void ) const { return ( this->_debug ); }

// Destructor
TTT Foo_T< T >::~Foo_T() { DEBUG( std::cout << "[ Destroying a FOO_T instance ]\n" ); }

// Constructors
TTT Foo_T< T >::Foo_T()
{
	DEBUG( std::cout << "[ Called def. constr. for a FOO_T instance ]\n" );
	this->_bar = T();
	this->_ptrVal = NULL;
}
TTT Foo_T< T >::Foo_T( T bar )
{
	DEBUG( std::cout << "[ Called param. constr. for a FOO_T instance ]\n" );
	this->_bar = bar;
	this->_ptrVal = NULL;
}

// Reconstructors
TTT Foo_T< T >::Foo_T( const Foo_T< T > &other )
{
	DEBUG( std::cout << "[ Called copy constr. for a FOO_T instance ]\n" );
	this->_bar = other._bar;
	this->_ptrVal = *other._ptrVal;
}
TTT Foo_T< T > &Foo_T< T >::operator=( const Foo_T< T > &other )
{
	DEBUG( std::cout << "[ Called assign. oper. for a FOO_T instance ]\n" );
	if ( this != &other )
	{
		this->_bar = other._bar;
		this->_ptrVal = new T( *other._ptrVal );
	}
	return ( *this );
}

// Clearers
TTT void	Foo_T< T >::clearBar( void ) { this->_bar = T(); }
TTT void	Foo_T< T >::clearPtrVal( void ) { this->_ptrVal = NULL; }
TTT void	Foo_T< T >::clearPtr( void ) { delete this->_ptrVal; this->_ptrVal = NULL; }

// Setters
TTT void	Foo_T< T >::setBar( T bar ) { this->_bar = bar; }
TTT void	Foo_T< T >::setPtrVal( T val ) { this->_ptrVal = new T( val ); }

// Getters
TTT T	Foo_T< T >::getBar( void ) const { return ( this->_bar ); }
TTT T	Foo_T< T >::getPtrVal( void ) const { return ( *this->_ptrVal ); }

// Fetchers
TTT T	&Foo_T< T >::fetchBar( void ) { return ( this->_bar ); }
TTT T	&Foo_T< T >::fetchPtrVal( void ) { return ( *this->_ptrVal ); }
TTT T*	&Foo_T< T >::fetchPtr( void ) { return ( this->_ptrVal ); }

// Checkers
TTT bool	Foo_T< T >::checkBar() const { return ( this->_bar != T() ); }
TTT bool	Foo_T< T >::checkPtrVal() const { return ( this->_ptrVal != NULL ); }

// Writers
TTT void	Foo_T< T >::writeBar( std::ostream &out ) const { out << this->_bar; }
TTT void	Foo_T< T >::printBar( void ) const { this->writeBar( std::cout );}
TTT std::ostream &operator<<( std::ostream &out, const Foo_T< T > &rhs ) { rhs.writeBar( out ); return ( out ); }

#endif // FOO_TPP