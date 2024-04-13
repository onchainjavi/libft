
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarinel <jmarinel@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 19:03:39 by jmarinel          #+#    #+#              #
#    Updated: 2023/05/03 17:18:45 by jmarinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------------------------->COLORS<-----------------------------------#
DEF_COLOR = \033[1;39m
WHITE = \033[1m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PINK = \033[1;35m
CIAN = \033[1;36m

#------------------------------------>NAME<------------------------------------#
NAME = libft.a
PRINTF_DIR = ./ft_printf/srcs/
GNL_DIR = ./get_next_line/

#----------------------------------->HEADER<-----------------------------------#
HEADER = libft.h

#------------------------------------->SRC<----–-------------------------------#
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	   ft_memchr.c	ft_memcmp.c	ft_strlen.c ft_isalpha.c \
	   ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	   ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
	   ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	   ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	   ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	   ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c \
	   ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

FILESPRINTF = ft_printf.c ft_parse.c ft_hexnum.c ft_digit.c ft_ptr.c ft_ui.c utils.c
FILESGNL 	= get_next_line_bonus.c get_next_line_utils_bonus.c

SRCSPRINTF = $(addprefix ${PRINTF_DIR}, ${FILESPRINTF})
SRCSGNL = $(addprefix ${GNL_DIR}, ${FILESGNL})

#------------------------------------>OBJ<-------------------------------------#
OBJS_DIR = $(shell pwd)/objs/

OBJS = $(addprefix ${OBJS_DIR}, ${SRCS:.c=.o})
OBJSPRINTF = $(addprefix ${OBJS_DIR}, ${SRCSPRINTF:.c=.o})
OBJSGNL = $(addprefix ${OBJS_DIR}, ${SRCSGNL:.c=.o})

#----------------------------------->COMANDS<----------------------------------#
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MDP = mkdir -p
AR = ar crs
INCLUDE = -I ./

#------------------------------------>RULES<-----------------------------------#
${OBJS_DIR}%.o: %.c Makefile
	@${MDP} $(dir $@)
	@${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@

all			: ${NAME}

${NAME}		:	${OBJS} ${OBJSPRINTF} ${OBJSGNL}
	@${AR} ${NAME} ${OBJS} ${OBJSPRINTF} ${OBJSGNL}
	@echo "\n${GREEN}LIBRARY: libft has been created.${DEF_COLOR}\n"

clean:
	@${RM} -r ${OBJS_DIR}
	@echo "${RED}OBJ && DEPS of 'libft' has been removed.${DEF_COLOR}"

fclean		: clean
	@${RM} ${NAME}
	@echo "${RED}LIBRARY: 'libft' has been removed.${DEF_COLOR}"

re			: fclean all
	@echo "${CIAN}LIBRARY: 'libft' has been remake${DEF_COLOR}"

.PHONY: all bonus clean fclean re bonus

#target: prerequisites \
	$@: target \
	$< first prerequisites \
	$^ all prerequisites

