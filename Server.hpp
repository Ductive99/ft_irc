/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:17:48 by marwan            #+#    #+#             */
/*   Updated: 2026/02/22 23:47:47 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>
#include <vector>
#include <unistd.h>
#include <cstdlib>

#ifndef SERVER_HPP
#define SERVER_HPP

class Server
{
    private:
        int _port;
        std::string _password;
        int _server_fd;
        std::vector<pollfd>_fds;
    public:
        Server(char *port, char* password);
        void start();
        void acceptClient();
        void receiveMessage(int i);
};

#endif