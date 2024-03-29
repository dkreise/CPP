#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
    std::time_t t;
    std::tm *lt;

    t = std::time(NULL);
    lt = std::localtime(&t);
    std::cout << "[" << lt->tm_year + 1900;
    if (lt->tm_mon < 10)
        std::cout << "0";
    std::cout << lt->tm_mon + 1;
    if (lt->tm_mday < 10)
        std::cout << "0";
    std::cout << lt->tm_mday <<  "_";
    if (lt->tm_hour < 10)
        std::cout << "0";
    std::cout << lt->tm_hour;
    if (lt->tm_min < 10)
        std::cout << "0";
    std::cout << lt->tm_min;
    if (lt->tm_sec < 10)
        std::cout << "0";
    std::cout << lt->tm_sec << "] ";
}

Account::Account(void)
{
    std::cout << "constructor emptyyyy" << std::endl;
}

Account::Account(int initial_deposit)
{
    this->_amount = initial_deposit;
    this->_accountIndex = _nbAccounts;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";created" << std::endl;
    _nbAccounts ++;
    _totalAmount += this->_amount;
}

Account::~Account(void) 
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int p_amount;

    p_amount = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits ++;
    _totalNbDeposits ++;
    _totalAmount += deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << p_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
        int p_amount;

    p_amount = this->_amount;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << p_amount << ";";
    if (p_amount < withdrawal)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    else
    {
        this->_amount -= withdrawal;
        this->_nbWithdrawals ++;
        _totalNbWithdrawals ++;
        _totalAmount -= withdrawal;
        std::cout << "withdrawal:" << withdrawal << ";";
        std::cout << "amount:" << this->_amount << ";";
        std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return (true);
    }     
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

int Account::checkAmount(void) const
{
    return (this->_amount);
}