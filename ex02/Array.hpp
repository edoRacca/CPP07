
#ifndef ARRAY_H
# define ARRAY_H


template <typename T>
class Array
{

private:
	T				*_arr;
	unsigned int	_size;

public:
	Array()
	{
		this->_arr = NULL;
	};
	Array(unsigned int n)
	{
		this->_size = n;
		this->_arr = new T[n]();
	}
	~Array()
	{
		delete this->_arr;
	};

	T& operator=(const T& a)
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
		try
		{
			return (this->_arr[idx]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	};

};

#endif