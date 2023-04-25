#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _size(0), _sorted(false) {}

PmergeMe::PmergeMe(int argc, char **argv) : _size(argc - 1), _sorted(false)
{
	this->_assignArgs(argc, argv, this->_vector);
	this->_assignArgs(argc, argv, this->_deque);
}

template <typename T>
struct is_vector {
	static const bool value = false;
};

template <typename T, typename A>
struct is_vector<std::vector<T, A> >{
	static const bool value = true;
};

template<typename T>
void	PmergeMe::_assignArgs(int argc, char **argv, T& vectorDeque)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		int value = atoi(arg.c_str());
		if (value < 0)
			throw invalidArgumentError();
		vectorDeque.push_back(value);
	}
	if (is_vector<T>::value)
		this->_checkDuplicates();
}

void	PmergeMe::sort()
{
	this->_printContainers();
	double tBegin = this->_getTime();
	this->_mergeInsertSort(_vector);
	this->_elapsedTimeVector = this->_elapsedTime(tBegin);

	tBegin = this->_getTime();
	this->_mergeInsertSort(_deque);
	this->_elapsedTimeDeque = this->_elapsedTime(tBegin);

	this->_sorted = true;
	this->_printContainers();

	this->_printTime("vector");
	this->_printTime("deque");
}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
	*this = obj;
	return ;
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	if (this != &obj)
	{
		this->_size = obj._size;
		this->_sorted = obj._sorted;
		this->_vector = obj._vector;
		this->_deque = obj._deque;
		this->_elapsedTimeVector = obj._elapsedTimeVector;
		this->_elapsedTimeDeque = obj._elapsedTimeDeque;
	}
	return (*this);
}

void PmergeMe::_checkDuplicates(void)
{
	std::set<int> nums;

	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
	{
		int num = *it;
		if (nums.find(num) != nums.end())
			throw duplicatesError();
		nums.insert(num);
	}
}

template <typename T>
void	PmergeMe::_mergeInsertSort(T& container)
{
	const int threshold = 10;
	const int size = container.size();

	if (size < 2)
		return ;
	if (size < threshold)
	{
		for (typename T::iterator i = container.begin(); i != container.end(); ++i)
		{
			typename T::iterator j = i;
			while (j != container.begin() && *(j - 1) > *j)
			{
				std::swap(*j, *(j - 1));
				--j;
			}
		}
		return ;
	}
	typename T::iterator middle = container.begin() + size / 2;
	T left(container.begin(), middle);
	T right(middle, container.end());
	_mergeInsertSort(left);
	_mergeInsertSort(right);
	typename T::iterator i = left.begin();
	typename T::iterator j = right.begin();
	typename T::iterator k = container.begin();
	while (i != left.end() && j != right.end())
	{
		if (*i < *j)
		{
			*k = *i;
			++i;
		}
		else
		{
			*k = *j;
			++j;
		}
		++k;
	}
	while (i != left.end())
	{
		*k = *i;
		++i;
		++k;
	}
	while (j != right.end())
	{
		*k = *j;
		++j;
		++k;
	}
}

double	PmergeMe::_getTime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.0001));
}

double	PmergeMe::_elapsedTime(long long time)
{
	if (time > 0)
		return (_getTime() - time);
	return (0);
}

void	PmergeMe::_printContainers(void)
{
	if (this->_sorted == false)
		std::cout << "Before: \n";
	else
		std::cout << "After:  \n";
	std::cout << "-------------VECTOR-------------" << std::endl;
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << "\n-------------DEQUE-------------" << std::endl;
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void	PmergeMe::_printTime(std::string vectorDeque) const
{
	double delta;
	if (vectorDeque == "vector")
		delta = this->_elapsedTimeVector;
	else if (vectorDeque == "deque")
		delta = this->_elapsedTimeDeque;
	std::cout 
		<< "Time to process a range of " << this->_size 
		<< " elements with std::" << vectorDeque << ": "
		<< std::fixed << std::setprecision(5) << delta  << " ms" << std::endl;
}
