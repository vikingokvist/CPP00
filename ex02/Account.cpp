#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int 	Account::_nbAccounts = 0;
int 	Account::_totalAmount = 0;
int 	Account::_totalNbDeposits = 0;
int 	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;
	
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";created" 
	<< std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout 
	<< "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";closed" 
	<< std::endl;
}

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
	<< "accounts:" << getNbAccounts()
	<< ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits()
	<< ";withdrawals:" << getNbWithdrawals()
	<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout 
	<< "index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount
	<< ";deposit:" << deposit
	<< ";amount:" << this->_amount + deposit
	<< ";nb_deposits:" << this->_nbDeposits + 1
	<< std::endl;

	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;

	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout 
	<< ";withdrawal:" << withdrawal
	<< ";amount:" << this->_amount
	<< ";nb_withdrawals:" << this->_nbWithdrawals
	<< std::endl;

	return (true);
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout 
	<< "index:" 
	<< this->_accountIndex 
	<< ";amount:" 
	<< this->_amount 
	<< ";deposits:"
	<< this->_nbDeposits
	<< ";withdrawals:"
	<< this->_nbWithdrawals
	<< std::endl;
}

void	Account::_displayTimestamp(void)
{
   	std::time_t currentTime = std::time(0);
	std::tm		*now = std::localtime(&currentTime);


	std::cout << "[" << (now->tm_year + 1900);
	(now->tm_mon + 1 < 10) ? (std::cout << "0" << now->tm_mon + 1) : (std::cout << now->tm_mon + 1);
	(now->tm_mday < 10) ? (std::cout << "0" << now->tm_mday) : (std::cout << now->tm_mday);
	std::cout << "_";
	(now->tm_hour < 10) ? (std::cout << "0" << now->tm_hour) : (std::cout << now->tm_hour);
	(now->tm_min < 10) ? (std::cout << "0" << now->tm_min) : (std::cout << now->tm_min);
	(now->tm_sec < 10) ? (std::cout << "0" << now->tm_sec) : (std::cout << now->tm_sec);
	std::cout << "] ";
}
