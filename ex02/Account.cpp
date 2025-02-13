#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;

int	Account::_totalNbWithdrawals = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalAmount = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_totalNbDeposits = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";created"
	<< std::endl;
}

Account::~Account(void) {}

int		Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int		Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout 
	<< "accounts:" << _nbAccounts 
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return (true);
	}
	return (false);
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm 	*localTime = std::localtime(&now);
	char		timeBuffer[20];

	std::cout << std::strftime(timeBuffer, 20, "[%Y%m%d_%H%M%S] ", localTime);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout 
	<< "index:" 
	<< this->_accountIndex 
	<< ";amount:" 
	<< this->_amount 
	<< ";created" 
	<< std::endl;
}

