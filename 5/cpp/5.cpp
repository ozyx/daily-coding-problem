/*
	Author - Omkar Kadam
*/

#include<iostream>
using namespace std;

// template is used to make the cons(), car(), and cdr() functions generic i.e to work on any datatype

template <class T1, class T2> 
pair<T1,T2> cons(T1 a, T2 b)			// Function to construct a pair
{
	pair<T1,T2> p;
	p.first = a;
	p.second = b;
	return p;
}

template <class T1, class T2> 
T1 car(pair<T1,T2> p)					// Function which returns first element of the pair
{
	return p.first;
}

template <class T1, class T2> 
T2 cdr(pair<T1,T2> p)					// Function which returns second element of the pair
{
	return p.second;
}

int main()
{
	cout<<"Constructing pair of two integers:\n";
	// cons() function constructs and returns a pair
	cout<<car(cons(3,4))<<endl;			// car() function returns first element of pair
	cout<<cdr(cons(3,4))<<endl;			// cdr() function returns second element of pair
	

	cout<<"\nConstructing pair of a double and a character:\n";
	cout<<car(cons(4.2, 'd'))<<endl;
	cout<<cdr(cons(4.2, 'd'))<<endl;
	
	return 0;
}
