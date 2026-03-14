/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 19:00:51 by esouhail          #+#    #+#             */
/*   Updated: 2026/03/14 19:03:12 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

void Server::initCommandHandlers() {
    return ;
}

bool Server::isAllowedBeforeRegistration(const std::string &command) const {
    return false;
}

void Server::handleMessage(int fd, const Message &msg) {
    
}

