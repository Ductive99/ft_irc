# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/22 23:44:43 by marwan            #+#    #+#              #
#    Updated: 2026/03/13 23:11:47 by esouhail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv

SRCDIR = src
SERVERDIR = $(SRCDIR)/server
CLIENTDIR = $(SRCDIR)/client
CHANNELDIR = $(SRCDIR)/channel
OBJDIR = build
INCDIR = include

SRCS = $(SRCDIR)/main.cpp \
	   $(SERVERDIR)/Server.cpp \
	   $(CLIENTDIR)/Client.cpp \
	   $(CHANNELDIR)/Channel.cpp

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I $(INCDIR) -c $< -o $@

clean : 
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY : re clean all fclean
