#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <set>
#include <sys/time.h>
#include <stdlib.h>

class PmergeMe
{
private:
	int					_size;
	bool				_sorted;
	std::vector<int>	_vector;
	std::deque<int>		_deque;
	double				_elapsedTimeVector;
	double				_elapsedTimeDeque;
public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe& cpy);
	~PmergeMe();

	PmergeMe&	operator=(const PmergeMe& rhs);
	void	sort();
private:
	template<typename T>
	void	_assignArgs(int	argc, char **argv, T& vectorDeque);

	void	_checkDuplicates(void);
	void	_printContainers(void);
	void	_printTime(std::string vectorDeque) const;

	template <typename T>
	void	_mergeInsertSort(T& container);
	double	_getTime(void);
	double	_elapsedTime(long long time);
public:
	class invalidArgumentError : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("[Error]: invalid argument");
			}
	};

	class duplicatesError : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("[Error]: duplicates are forbidden");
			}
	};
};


#endif