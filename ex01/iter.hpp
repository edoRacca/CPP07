
#ifndef ITER_H
# define ITER_H

template <typename A, typename T, typename F> void iter(A *arr, T len, F f)
{
	for (T i = 0; i < len; i++)
		f(arr[i]);
}

#endif