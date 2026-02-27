/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:15:29 by marwan            #+#    #+#             */
/*   Updated: 2026/02/27 21:32:11 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client():_fd(-1), _registered(false), _pass_ok(false), _nick_ok(false),_user_ok(false){}

Client::Client(int fd):_fd(fd),_registered(false), _pass_ok(false), _nick_ok(false),_user_ok(false){}

Client::~Client(){}

int Client::get_fd()const{return this->_fd;}

std::string Client::get_nickname()const{return this->_nickname;}

void Client::set_user(const std::string &user){this->_username = user;}

void Client::set_nickname(const std::string &nickname){this->_nickname = nickname;}

void Client::set_pass(bool b){this->_pass_ok = b;}

void Client::set_nickOK(bool b){this->_nick_ok = b;}

void Client::set_userOK(bool b){this->_user_ok = b;}

void Client::Register(){_registered = true;}

bool Client::get_registered()const{return this->_registered;}

bool Client::is_registerable()const{return (_pass_ok && _nick_ok && _user_ok);}

void Client::set_registered(bool b)
{
   _registered = b;
}



