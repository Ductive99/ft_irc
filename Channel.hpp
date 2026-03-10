/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 20:17:58 by marwan            #+#    #+#             */
/*   Updated: 2026/03/10 12:53:19 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>
#include <map>
#include <vector>
#include "Client.hpp"
#include <sys/socket.h>

class Channel
{
    private:
        std::string _name;
        std::string _topic;
        std::map<int , Client*> _channelClients;
        std::vector<int> _operators;
        std::vector<int> _invited;
        
    public:
        Channel();
        Channel(std::string name);
        void addClient(Client *client);
        void removeClient(int fd);
        std::string get_name()const;
        void broadcast(int sender_fd, const std::string &msg);
        std::string getTopic() const;//b
        void        setTopic(const std::string &topic);//b
        std::string getClientList() const;//b
        void addOperator(int fd);//b
        void removeOperator(int fd);//b
        bool isOperator(int fd) const;//b
        bool hasClient(int fd) const; //b
        void addInvited(int fd);
        bool isInvited(int fd) const;
        void removeInvited(int fd);  
};


#endif