#include "Array.hpp"

template class Array<int>;
template class Array<char>;
template class Array<float>;
template class Array<double>;
// template class Array<std::string>;

// default constructor
template<typename T>
Array<T>::Array() : n(0)
{
	std::cout << "Default Constructor" << std::endl;
	t = new T[1];
	t[0] = 0;
}

// unsigned int constructor
template<typename T>
Array<T>::Array(unsigned int _n) : n(_n)
{
	std::cout << "Unsigned int Constructor" << std::endl;
	t = new T[n];
	for (size_t i = 0; i < n; i++) // deneme
	{
		t[i] = 1 + i;
	}
}

// coppy constructor
template<typename T>
Array<T>::Array(const Array& ref) : n(ref.size())
{
	T	*ref_t = ref.getT();
	t = new T[n];
	for (size_t i = 0; i < n; i++)
	{
		t[i] = ref_t[i];
	}
	
}

// destructor
template<typename T>
Array<T>::~Array()
{
	std::cout << "Destructor!!" << std::endl;
	delete[] this->t;
}

// operator=()
template<typename T>
Array<T>&	Array<T>::operator=(const Array& ref)
{
	T	*ref_t = ref.getT();
	this->n = ref.size();

	delete[] this->t;
	this->t = new T[n];
	for (size_t i = 0; i < n; i++)
	{
		this->t[i] = ref_t[i];
	}
	return (*this);
}

// operator[]()
template<typename T>
T&	Array<T>::operator[](int index)
{
	if (index < 0 || index >= static_cast<int>(this->n))
	{
		throw (std::exception());
	}
	else
		return (*(this->t + index));
}

//get
template<typename T>
T	*Array<T>::getT() const
{
	return (t);
}

//getsize
template<typename T>
unsigned int	Array<T>::size() const
{
	return (n);
}