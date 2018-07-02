# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:17:34 by ahryhory          #+#    #+#              #
#    Updated: 2017/12/24 13:57:13 by ahryhory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Werror -Wextra

F = -lmlx -framework OpenGL -framework AppKit

OBJ = $(SRC:.c=.o)

PATHLIBFT = includes/libft

LIB = includes/libft/libft.a

SRC =

SRC += main.c
SRC += ft_draw.c
SRC += ft_get_coordinate.c
SRC += ft_rotate.c
SRC += ft_to_centre.c
SRC += ft_to_locale.c
SRC += ft_get_scale.c
SRC += ft_scale.c
SRC += ft_cordcpy.c
SRC += ft_err.c
SRC += ft_clr.c
SRC += ft_cordclr.c
SRC += ft_parse_z_col.c
SRC += ft_redraw.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(PATHLIBFT)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) $(F)

%.o: %.c
	@gcc $(FLAGS) -c  -I. $<

clean:
	@make clean -C $(PATHLIBFT)
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C $(PATHLIBFT)
	@rm -rf $(NAME)

re: fclean all
