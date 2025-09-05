
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
		this->_arr = new T[0]();
		this->_size = 0;
	};

	Array(unsigned int n)
	{
		this->_size = n;
		this->_arr = new T[n]();
	};

	Array(const Array& a)
	{
		this->_size = a._size;
		this->_arr = new T[this->_size]();
		for (unsigned int i = 0; i < a._size; i++)
			this->_arr[i] = a._arr[i];
	};

	~Array()
	{
		delete this->_arr;
	};

	unsigned int size() const
	{
		return (this->_size);
	};

	Array& operator=(const Array& a)
	{
		if (this != &a)
		{
			delete this->_arr;
			this->_size = a._size;
			this->_arr = new T[this->_size]();
			for (unsigned int i = 0; i < a._size; i++)
				this->_arr[i] = a._arr[i];
		}
		return (*this);
	};

	T& operator[](unsigned int idx) const
	{
		if (idx >= this->_size)
			throw (std::out_of_range("Index out of bound"));	
		return (this->_arr[idx]);
	};

};

#endif