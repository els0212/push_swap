SWAPNAME = push_swap
CHKNAME = checker
LIBNAME = libft.a
LIBSRCS = $(addprefix libft/, ft_memset.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcpy.c ft_strlcat.c ft_strlen.c ft_strnstr.c ft_bzero.c ft_memccpy.c ft_memcmp.c ft_memmove.c ft_strchr.c ft_strrchr.c ft_strlcpy.c ft_strncmp.c ft_toupper.c ft_tolower.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c)
LIBOBJS = ${LIBSRCS:.c=.o}
CHKSRC = checker.c
CHKOBJ = checker.o
SWAPSRC = push_swap.c
SWAPOBJ = push_swap.o
AR = ar
ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror 
LIBFLAGS = -L. -lft
all : $(LIBNAME) $(CHKNAME) $(SWAPNAME)

${LIBOBJS} : $(LIBSRCS)
	${CC} ${CFLAGS} -c $< -o $@

$(LIBNAME) : ${LIBOBJS}
	${AR} ${ARFLAGS} $(LIBNAME) ${LIBOBJS}

$(CHKNAME) : $(CHKSRC)
	${CC} ${CFLAGS} $< -o $@ ${LIBFLAGS}

$(SWAPNAME) : $(SWAPSRC)
	${CC} ${CFLAGS} $< -o $@ ${LIBFLAGS}

clean :
	rm -rf ${LIBOBJS}

fclean : clean
	rm -rf $(LIBNAME) $(CHKNAME) $(SWAPNAME)

re : fclean all

.PHONY: all clean fclean re