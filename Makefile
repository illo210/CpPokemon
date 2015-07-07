##
## Makefile for CpPokemon in /home/rousse_3/Perso/CpPokemon
## 
## Made by rousse_3
## Login   <rousse_3@epitech.net>
## 
## Started on  Thu Jun 11 20:46:47 2015 rousse_3
## Last update Thu Jun 11 21:10:53 2015 rousse_3
##

CXX		=	g++

RM		=	rm -f

CXXFLAGS	=	-Wall -Wextra
CXXFLAGS	+=	-I includes

DEBUG		=	no

ifeq ($(DEBUG), yes)
CXXFLAGS	+=	-g
endif

LDFLAGS		=

NAME		=	Pokemon

include			source.mk

OBJS		=	$(SRCS:.cpp=.o)

DEPS		=	$(SRCS:.cpp=.dep)

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)

clean		:
			$(RM) $(OBJS) $(DEPS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

%.o		:	%.cpp
			$(CXX) -c -o $@ $< $(CXXFLAGS)
			$(CXX) -MM -o $*.dep $< $(CXXFLAGS)
			@sed -e 's|.*:|$@:|g' -i $*.dep

.PHONY		:	all clean fclean re

-include		$(DEPS)
