#ifndef FOO_HPP
# define FOO_HPP

# include "DefLibs.hpp"

# define C_STR const std::string

// CLASS FOO ( implemented in .cpp file )
class Foo
{
	private:
		// Attributes
		bool	_debug;
		STR		_name;
		int		*_ptrVal;

	protected:
		// Nested Classes
		class BadName : XCPT( "Foo error : invalid name, idiot!" );

	public:
		// Debuggers
		void	debug( bool _debug );
		bool	debug( void ) const;

		// Destructor
		~Foo();

		// Constructors
		Foo();
		Foo( C_STR _name );

		// Reconstructors
		Foo( const Foo &other );
		Foo &operator= ( const Foo &other );

		// Clearers
		void	clearName( void );
		void	clearPtrVal( void );
		void	clearPtr( void );

		// Setters
		void	setName( C_STR _name );
		void	setPtrVal( int _val );

		// Getters
		C_STR	getName( void ) const;
		int		getPtrVal( void ) const;

		// Fetchers
		C_STR	&fetchName( void );
		int		&fetchPtrVal( void );
		int*	&fetchPtr( void );

		// Checkers
		bool	checkName() const;
		bool	checkPtrVal() const;

		// Writers
		void	writeName( std::ostream &out ) const;
		void	printName( void ) const;

		friend	std::ostream &operator<< ( std::ostream &out, const Foo &rhs );
};

// TEMPLATE CLASS FOO_T ( implemented in .tpp file )
TTT class Foo_T
{
	private:
		// Attributes
		bool	_debug;
		T		_bar;
		T		*_ptrVal;

	protected:
		// Nested Classes
		class BadBar : XCPT( "Foo error : invalid bar, idiot!" );

	public:
		// Debuggers
		void	debug( bool _debug );
		bool	debug( void ) const;

		// Destructor
		~Foo_T();

		// Constructors
		Foo_T();
		Foo_T( T bar );

		// Reconstructors
		Foo_T( const Foo_T< T > &other );
		Foo_T &operator= ( const Foo_T< T > &other );

		// Clearers
		void	clearBar( void );
		void	clearPtrVal( void );
		void	clearPtr( void );

		// Setters
		void	setBar( T _bar );
		void	setPtrVal( T _val );

		// Getters
		T		getBar( void ) const;
		T		getPtrVal( void ) const;

		// Fetchers
		T		&fetchBar( void );
		T		&fetchPtrVal( void );
		T*		&fetchPtr( void );

		// Checkers
		bool	checkBar() const;
		bool	checkPtrVal() const;

		// Writers
		void	writeBar( std::ostream &out ) const;
		void	printBar( void ) const;

		friend	std::ostream &operator<<( std::ostream &out, const Foo_T< T > &rhs );
};

# include "Foo.tpp"

#endif // FOO_HPP