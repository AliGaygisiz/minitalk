SRC = 		ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c\
			ft_strlen.c \
			ft_bzero.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_calloc.c \
			ft_strmapi.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_itoa.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memmove.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_substr.c \
			ft_strtrim.c \
			ft_split.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_striteri.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

SRCS = ${addprefix ./libft/,${SRC}} \
			ft_printf.c \
			src/ft_core_prints.c \
			src/ft_count_utils.c \
			src/ft_send_args.c \
			src/ft_split_parts.c \

OBJS = ${SRCS:.c=.o}
SRCSB = ${addprefix ./libft/,${SRC}} \
		ft_printf.c \
		src_bonus/ft_chr_utils.c \
		src_bonus/ft_core_prints.c \
		src_bonus/ft_count_utils.c \
		src_bonus/ft_flags.c \
		src_bonus/ft_merge_prints.c \
		src_bonus/ft_modifiers.c \
		src_bonus/ft_nbr_utils.c \
		src_bonus/ft_ptr_utils.c \
		src_bonus/ft_send_args.c \
		src_bonus/ft_size_counters.c \
		src_bonus/ft_split_parts.c \
		src_bonus/ft_str_utils.c \
		src_bonus/ft_utils.c \

OBJS_B = ${SRCSB:.c=.o}
NAME = libftprintf.a
CC = gcc
CFLAGS = -fPIE -g -Wall -Werror -Wextra  
RM = rm -rf
LIBC = ar -rcs

all: ${NAME}

bonus: fclean ${OBJS_B}
	@${LIBC} ${NAME} ${OBJS_B}

${NAME}: ${OBJS}
	@${LIBC} ${NAME} ${OBJS}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@${RM} ${OBJS} ${OBJS_B}

fclean: clean
	@${RM} ${NAME} ${bonus}

re: fclean all

.PHONY: all bonus clean fclean re .c.o
