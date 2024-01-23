#include "Array.hpp"


// Constructors - Destructor

Array::Array()
{
	std::cout << "[ Called def. constr. for an ARRAY instance ]\n";

	this->size = 0;
	this->arr = new int[ this->size ];

}
Array::Array( int s )
{
	std::cout << "[ Called param. cons. for an ARRAY instance ]\n";

	this->size = s;
	this->arr = new int[ this->size ];

	for ( int i = 0; i < this->size; i++ )
		this->arr[ i ] = 0;
}
Array::Array( const Array &other )
{
	std::cout << "[ Called copy constr. for an ARRAY instance ]\n";

	this->size = other.getSize();
	this->arr = new int[ this->size ];

	for ( int i = 0; i < this->size; i++ )
		this->arr[ i ] = other.getValue( i );
}
Array::~Array()
{
	std::cout << "[ Destroying an ARRAY instance ]\n";

	delete [] this->arr;
}


// Operator Overloads

Array &Array::operator= ( const Array &other )
{
	std::cout << "[ Called assign. op. for an ARRAY instance ]\n";

	delete [] this->arr;

	this->size = other.getSize();
	this->arr = new int[ this->size ];

	for ( int i = 0; i < this->size; i++ )
		this->arr[ i ] = other.getValue( i );

	return *this;
}
int &Array::operator[] ( int i )
{
	//std::cout << "[ Called subscript. op for an ARRAY instance ]\n";

	return this->arr[ this->getIndex( i )];
}


// Setters - Getters

int	Array::getIndex( int i ) const
{
	if ( i < -this->size || i >= this->size )
		throw InvalidIndex();

	else if ( i < 0 ) // allows reading the array backwards via negative indexes
		return this->size + i;

	else
		return i;
}

void Array::setSize( int s )
{
	if ( s < 0 )
		throw InvalidSize();

	int *tmp = new int[ s ];

	for ( int i = 0; i < this->size; i++ )
		tmp[ this->getIndex( i ) ] = this->arr[ this->getIndex( i )];

	delete [] this->arr;

	this->size = s;
	this->arr = tmp;
}
void Array::setValue( int i, int v ) { this->arr[ this->getIndex( i )] = v; }

int Array::getSize( void ) const { return this->size; }
int Array::getValue( int i ) const { return this->arr[ this->getIndex( i )]; }



std::ostream &operator<< (std::ostream &out, const Array &rhs)
{
	out << "[ ";
	for ( int i = 0; i < rhs.getSize(); i++ )
		out << rhs.getValue( i ) << " ";
	out << "]";
	return (out);
}