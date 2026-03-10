/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 20:22:30 by marwan            #+#    #+#             */
/*   Updated: 2026/03/10 12:57:37 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

Channel::Channel():_name("Default channel"){};

Channel::Channel(std::string name):_name(name){}

void Channel::addClient(Client *client)
{
    _channelClients[client->get_fd()] = client;
}

void Channel::removeClient(int fd)
{
    _channelClients.erase(fd);
}

std::string Channel::get_name()const{return this->_name;}

void Channel::broadcast(int sender_fd, const std::string &msg)
{
    for(std::map<int, Client*>::iterator it = _channelClients.begin(); it != _channelClients.end();it++)
    {
        if (it->first != sender_fd)
            send(it->first, msg.c_str(), msg.size(),0);
    }
}

std::string Channel::getTopic() const { return this->_topic; }

void Channel::setTopic(const std::string &topic)
{
    this->_topic = topic;
}

std::string Channel::getClientList() const
{
    std::string list;
    for (std::map<int, Client*>::const_iterator it = _channelClients.begin();
         it != _channelClients.end(); it++)
    {
        if (!list.empty())
            list += " ";
        if (isOperator(it->first))
            list += "@";
        list += it->second->get_nickname();
    }
    return list;
}

void Channel::addOperator(int fd)
{
    for (std::vector<int>::iterator it = _operators.begin();
         it != _operators.end(); it++)
    {
        if (*it == fd) return;
    }
    _operators.push_back(fd);
}

void Channel::removeOperator(int fd)
{
    for (std::vector<int>::iterator it = _operators.begin();
         it != _operators.end(); it++)
    {
        if (*it == fd)
        {
            _operators.erase(it);
            return;
        }
    }
}

bool Channel::isOperator(int fd) const
{
    for (std::vector<int>::const_iterator it = _operators.begin();
         it != _operators.end(); it++)
    {
        if (*it == fd) return true;
    }
    return false;
}

bool Channel::hasClient(int fd) const
{
    return (_channelClients.find(fd) != _channelClients.end());
}

void Channel::addInvited(int fd)
{
    for (std::vector<int>::iterator it = _invited.begin();
         it != _invited.end(); it++)
    {
        if (*it == fd) return;
    }
    _invited.push_back(fd);
}

bool Channel::isInvited(int fd) const
{
    for (std::vector<int>::const_iterator it = _invited.begin();
         it != _invited.end(); it++)
    {
        if (*it == fd) return true;
    }
    return false;
}

void Channel::removeInvited(int fd)
{
    for (std::vector<int>::iterator it = _invited.begin();
         it != _invited.end(); it++)
    {
        if (*it == fd)
        {
            _invited.erase(it);
            return;
        }
    }
}