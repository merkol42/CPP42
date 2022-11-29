#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef	T*	iterator;
		typedef	const T* const_iterator;

		iterator begin()
		{
			std::vector<T>	v;
			T				top;
			iterator		ret;
			int				n = 0;
			while (!this->empty())
			{
				top = this->top();
				v.push_back(top);
				this->pop();
				n++;
				
			}
			this->push(v[n - 1]);
			n--;
			ret = &(this->top());
			while (n--)
				this->push(v[n]);
			return (ret);
		}

		iterator end()
		{
			return (&this->top() + 1);
		}
};

#endif