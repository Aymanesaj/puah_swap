CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_bonus_flags.c     ft_len.c       ft_putstr.c    ft_address.c \
      ft_check_argprint.c  ft_numsizet.c  ft_putchar.c   ft_spaces.c \
      ft_addnum.c          ft_givesign.c  ft_padding.c   ft_putnbr_base.c \
      ft_isdigit.c         ft_printf.c    ft_putnbr.c    ft_atoi.c   ft_handlestr.c \
      ft_strlen.c          ft_lenu.c      ft_strx.c      ft_specifier.c  ft_strchr.c \
      ft_positive.c        ft_checkdot.c  ft_gothrough.c
	  
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)
re : fclean all
