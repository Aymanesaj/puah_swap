CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BNS = checker
SRC = push_swap.c Src/ft_aatoi.c  ft_printf/ft_bonus_flags.c     ft_printf/ft_len.c       ft_printf/ft_putstr.c    ft_printf/ft_address.c \
      ft_printf/ft_check_argprint.c  ft_printf/ft_numsizet.c  ft_printf/ft_putchar.c   ft_printf/ft_spaces.c \
      ft_printf/ft_addnum.c   ft_printf/ft_givesign.c ft_printf/ft_padding.c   ft_printf/ft_putnbr_base.c \
      ft_printf/ft_isdigit.c   ft_printf/ft_printf.c    ft_printf/ft_putnbr.c    ft_printf/ft_atoi.c   ft_printf/ft_handlestr.c \
      ft_printf/ft_strlen.c   ft_printf/ft_lenu.c      ft_printf/ft_strx.c      ft_printf/ft_specifier.c  ft_printf/ft_strchr.c \
      ft_printf/ft_positive.c ft_printf/ft_checkdot.c  ft_printf/ft_gothrough.c Src/swap.c Src/push.c \
      Src/rotate.c Src/reverse_rotate.c Src/find.c Src/handle_err.c    Src/ft_split.c  Src/ft_substr.c   Src/sortthestack.c Src/calculator.c \
      Src/positioning.c Src/sort_low.c
SRC_BNS = checker_file/get_next_line/get_next_line.c checker_file/get_next_line/get_next_line_utils.c \
      checker_file/checker.c Src/ft_aatoi.c  ft_printf/ft_bonus_flags.c     ft_printf/ft_len.c       ft_printf/ft_putstr.c    ft_printf/ft_address.c \
      ft_printf/ft_check_argprint.c  ft_printf/ft_numsizet.c  ft_printf/ft_putchar.c   ft_printf/ft_spaces.c \
      ft_printf/ft_addnum.c   ft_printf/ft_givesign.c ft_printf/ft_padding.c   ft_printf/ft_putnbr_base.c \
      ft_printf/ft_isdigit.c   ft_printf/ft_printf.c    ft_printf/ft_putnbr.c    ft_printf/ft_atoi.c   ft_printf/ft_handlestr.c \
      ft_printf/ft_strlen.c   ft_printf/ft_lenu.c      ft_printf/ft_strx.c      ft_printf/ft_specifier.c  ft_printf/ft_strchr.c \
      ft_printf/ft_positive.c ft_printf/ft_checkdot.c  ft_printf/ft_gothrough.c Src/swap.c Src/push.c \
      Src/rotate.c Src/reverse_rotate.c Src/find.c Src/handle_err.c    Src/ft_split.c  Src/ft_substr.c   Src/sortthestack.c Src/calculator.c \
      Src/positioning.c  Src/sort_low.c
OBJ = $(SRC:.c=.o)
OBJ_BNS = $(SRC_BNS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(BNS)

# $(NAME_BNS) : $(OBJ_BNS) $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) $(OBJ_BNS) -o $(NAME_BNS)

$(BNS) : $(OBJ_BNS)
	$(CC)  $(CFLAGS) $(OBJ_BNS) -o $(BNS)

clean :
	rm -rf $(OBJ) $(OBJ_BNS)

fclean : clean
	rm -rf $(NAME) $(BNS)

re : fclean all
