########################################
########## VARIABLES

NAME		= push_swap
BONUS_NAME	= checker
CC			= gcc
INCLUDES	= includes
CFLAGS		= -Wall -Werror -Wextra -I
FT_PRINTF	= ft_printf
LIBFT		= libft
RM			= rm -f
SRCS_DIR	= srcs/

########################################
########## SOURCES
SRCS_FILES	=	main_mandatory \
				push_swap ft_error ft_check_arg parsing ft_insert min_max \
				calculated_move \
				display_process ft_utils check_is_sort extract_method \
				algorithms/optimisation \
				algorithms/main_algorithm \
				algorithms/algorithm_up_to_3 \
				algorithms/algorithm_up_to_5 \
				algorithms/algorithm_up_to_n \
				operations/ft_push \
				operations/ft_reverse_rotate \
				operations/ft_rotate \
				operations/ft_swap
SRCS 		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= $(SRCS:.c=.o)

BSRCS_FILES	=	main_bonus handle_bonus \
				push_swap ft_error ft_check_arg parsing ft_insert min_max \
				calculated_move \
				display_process ft_utils check_is_sort extract_method \
				algorithms/optimisation \
				algorithms/main_algorithm \
				algorithms/algorithm_up_to_3 \
				algorithms/algorithm_up_to_5 \
				algorithms/algorithm_up_to_n \
				operations/ft_push \
				operations/ft_reverse_rotate \
				operations/ft_rotate \
				operations/ft_swap \
				get_next_line \
				get_next_line_utils
SRCS_BONUS	= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(BSRCS_FILES)))
BONUS_OBJS	= $(SRCS_BONUS:.c=.o)

.c.o:
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

########################################
########## RULES

all:		$(NAME)

$(NAME):	$(OBJS)
				make -C $(FT_PRINTF)
				make -C $(LIBFT)
				mv ft_printf/libftprintf.a .
				mv libft/libft.a .
				$(CC) $(OBJS) libftprintf.a libft.a -o $(NAME)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)
				make clean -C $(FT_PRINTF)
				make clean -C $(LIBFT)

fclean: 	clean
				@$(RM) $(NAME)
				@$(RM) $(BONUS_NAME)
				@$(RM) libftprintf.a
				@$(RM) libft.a

re:			fclean all

bonus:	$(BONUS_OBJS)
			make -C $(FT_PRINTF)
			make -C $(LIBFT)
			mv ft_printf/libftprintf.a .
			mv libft/libft.a .
			$(CC) $(BONUS_OBJS) libftprintf.a libft.a -o $(BONUS_NAME)

norm:
			norminette $(SRCS) $(INCLUDES) $(FT_PRINTF) $(LIBFT) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm bonus
