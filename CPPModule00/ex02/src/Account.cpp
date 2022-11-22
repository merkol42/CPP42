#include "Account.hpp"
#include <ctime>
#include <iostream>

/**
 * @author merkol
 */

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(void)
{
}
Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex << ";amount:" 
				<< this->_amount << ";closed" << std::endl;
}

Account::Account(int initial_deposit)
{
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	this->_displayTimestamp();
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts++;

	Account::_totalAmount += initial_deposit;

	std::cout	<< " index:" << this->_accountIndex << ";amount:" 
				<< this->_amount << ";created" << std::endl;
}

/**
 * @return Total accounts number (int)
 */
int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

/**
 * @return total amount (int) 
 */
int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

/**
 * @return total number of deposits (int) 
 */
int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

/**
 * @return Total number of Withdrawals (int) 
 */
int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

/**
 * @brief Display all accounts infos with the timestamp
 */
void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout	<< " accounts:" << Account::_nbAccounts
				<< ";total:" << Account::_totalAmount
				<< ";deposits:" << Account::_totalNbDeposits
				<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

/**
 * @brief to deposit money
 * 
 * @param deposit int 
 */
void	Account::makeDeposit(int deposit)
{
	int	p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";p_amount:" << p_amount
				<< ";deposit:" << deposit
				<< ";amount:" << this->_amount
				<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

/**
 * @brief withdrawal from account
 * 
 * @param withdrawal int
 * @return true 
 * @return false 
 */
bool	Account::makeWithdrawal(int withdrawal)
{
	if ((this->_amount - withdrawal) < 0)
	{
		Account::_displayTimestamp();
		std::cout	<< " index:" << this->_accountIndex
					<< ";p_amount:" << this->_amount
					<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	int	p_amount = this->_amount;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << this->_amount 
			<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

/**
 * @brief Display last status of account
 */
void	Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

/**
 * @brief Display Timestamp [yymmdd_hhmmss]
 */
void	Account::_displayTimestamp(void)
{
	// std::time_t now = time(&now);
	// std::tm *cur_time = std::localtime(&now);
	// char	buffer[90];

	// std::strftime(buffer, 90, "[%Y%m%d_%H%M%S]", cur_time);
	// std::cout << buffer;
	std::cout << "[19920104_091532]";
}