/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:16:16 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/18 14:28:25 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	return ;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";amount:"<<this->_amount<<";created"<<std::endl;
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";amount:"<<this->_amount<<";closed"<<std::endl;
}

int	Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
}

int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
}

int	Account::getTotalAmount( void )
{
	return(_totalAmount);
}

int	Account::getNbAccounts( void )
{
	return(_nbAccounts);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout<<"accounts:"<<getNbAccounts()<<";total:"<<getTotalAmount()\
	<<";deposits:"<<getNbDeposits()<<";withdrawals:"<<getNbWithdrawals()\
	<<std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";amount:"<<this->_amount<<";deposits:"\
	<<this->_nbDeposits<<";withdrawals:"<<this->_nbWithdrawals<<std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";p_amount:"<<this->_amount<<";deposit:"\
	<<deposit<<";amount:";
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout<<this->_amount<<";nb_deposits:"<<this->_nbDeposits<<std::endl;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";p_amount:"<<this->_amount<<";withdrawal:";
	if (withdrawal >= this->_amount)
		return (std::cout<<"refused"<<std::endl, false);
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	std::cout<<withdrawal<<";amount:"<<this->_amount<<";nb_withdrawals:"<<this->_nbWithdrawals<<std::endl;
	return (true);
}
int		Account::checkAmount( void ) const
{
	return (0);
}

void	Account::_displayTimestamp( void )
{
	time_t		now = time(0);
	struct tm	t;
	char		buffer[20];

	localtime_r(&now, &t);
	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", &t);
	std::cout<<buffer;
}
