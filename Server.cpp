/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:20:44 by marwan            #+#    #+#             */
/*   Updated: 2026/02/22 23:48:25 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server(char *port, char* password) : _port(atoi(port)),  _password(password)
{}

void Server::acceptClient()
{
    int client_fd = accept(_server_fd, NULL, NULL);
    if (client_fd < 0) return;//ptet ajouter un message derreur
    pollfd newClient;
    newClient.fd = client_fd;
    newClient.events = POLLIN;
    newClient.revents = 0;
    _fds.push_back(newClient);
    std::cout << "New client connected! fd : " << client_fd << std::endl;
}

void Server::receiveMessage(int i)
{
    char buffer[1024];//jimagine qui faut checker si le message est pas trop long! faisable facile avec substr

    int bytes = recv(_fds[i].fd,buffer,sizeof(buffer) -1, 0);
    if (bytes <= 0)//-1 cest erreur nan ? 
    {
        std::cout << "Client disconnected\n";
        close(_fds[i].fd);
        _fds.erase(_fds.begin()+i);
        return;
    }
    buffer[bytes]='\0';
    std::cout << "Message : " << buffer << std::endl;
    
}

void Server::start()
{
    _server_fd = socket(AF_INET, SOCK_STREAM,0);
    if (_server_fd<0)throw std::runtime_error("socket failed\n");
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(_port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(_server_fd,(const sockaddr *)&addr, sizeof(addr)) < 0)
        throw std::runtime_error("Bind error\n");
    if(listen(_server_fd, SOMAXCONN) < 0)
        throw std::runtime_error("Listen error\n");
    pollfd server_poll;
    server_poll.fd = _server_fd;
    server_poll.events = POLLIN;
    server_poll.revents =0;
    _fds.push_back(server_poll);
    std::cout << "Server listening on port " << _port << std::endl;
    while(1)
    {
        if(poll(&_fds[0], _fds.size(), -1) < 0)
            throw std::runtime_error("poll error\n");
        for(size_t i = 0; i< _fds.size();i++)
        {
            if(_fds[i].revents & POLLIN)
            {
                if(_fds[i].fd == _server_fd)
                    acceptClient();
                else receiveMessage(i);
            }
        }
    }
}