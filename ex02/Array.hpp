
#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include <exception>

template <typename T>
class Array
{

private:
	T				*_arr;
	unsigned int	_size;

public:
	Array()
	{
		this->_arr = 0;
		this->_size = 0;
	};

	Array(unsigned int n)
	{
		this->_arr = new T[n]();
		this->_size = n;
	};

	Array(const Array& a)
	{
		this->_arr = new T[a._size]();
		this->_size = a._size;
		for (unsigned int i = 0; i < a._size; i++)
			this->_arr[i] = a._arr[i];
	};
	
	~Array()
	{
		delete[] this->_arr;
	};

	Array& operator=(const Array& a)
	{
		if (this != &a)
		{
			this->_arr = new T[a._size]();
			this->_size = a._size;
			for (unsigned int i = 0; i < a._size; i++)
				this->_arr[i] = a._arr[i];
		}
		return (*this);
	};

	T& operator[](unsigned int idx)
	{
		if (idx >= this->_size || idx < 0)
			throw (std::out_of_range("Index out of bound"));
		else
			return (this->_arr[idx]);
	};

	unsigned int size(void) const
	{
		return (this->_size);
	};
};

#endif