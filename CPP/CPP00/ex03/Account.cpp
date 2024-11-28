/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:18:11 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/28 15:40:00 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
    t::_totalAmount += initial_deposit;
    this->_accountIndex = t::_nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    t::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" <<std::endl;
}

Account::Account( void )
{
    t::_totalAmount += 0;
    this->_accountIndex = t::_nbAccounts++;
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    t::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" <<std::endl;
}

Account::~Account( void )
{
    t::_nbAccounts--;
    _totalAmount -= _amount;
    t::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" <<std::endl;
}


void Account::displayAccountsInfos( void )
{
    t::_displayTimestamp();
    std::cout << "accounts:" << t::_nbAccounts << ";total:" << t::_totalAmount;
    std::cout << ";deposits:" << t::_totalNbDeposits << ";withdrawals:" << t::_totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    time_t  tmp;
    tm      *timer;

    time(&tmp);
    timer = localtime(&tmp);
    std::cout << "[" << timer->tm_year + 1900;
    std::cout << (timer->tm_mon < 9 ? "0" : "") << timer->tm_mon + 1;
    std::cout << (timer->tm_mday < 9 ? "0" : "") << timer->tm_mday << "_";
    std::cout << (timer->tm_hour < 9 ? "0" : "") << timer->tm_hour;
    std::cout << (timer->tm_min < 9 ? "0" : "") << timer->tm_min;
    std::cout << (timer->tm_sec < 9 ? "0" : "") << timer->tm_sec << "] ";
}


void	Account::makeDeposit( int deposit )
{
    t::_totalNbDeposits++;
    t::_totalAmount += deposit;
    this->_nbDeposits++;
    t::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex <<";p_amount:" << this->_amount; 
    this->_amount += deposit;
    std::cout << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    t::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
    if (this->_amount < withdrawal)
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    this->_amount -= withdrawal;
    t::_totalAmount -= withdrawal;
	t::_totalNbWithdrawals++;
	this->_nbWithdrawals++;
    std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}



int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}