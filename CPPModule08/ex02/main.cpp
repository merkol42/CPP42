#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "mstack.top() :" << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "after pop() mstack.size() :" << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	mstack.push(0);

	mstack.pop();
	
	std::cout << "mstack.top() :" << mstack.top() << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::list<int> a(it, ite);

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "--list test--" << std::endl;
	std::list<int>::iterator i = a.begin();
	std::list<int>::iterator ie = a.end();

	for (; i != ie; i++)
	{
		std::cout << *i << std::endl;
	}

	std::cout << "--Size--" << std::endl;
	std::stack<int> s(mstack);
	std::cout << s.size() << std::endl;
	std::cout << mstack.size() << std::endl;
	return 0;
}