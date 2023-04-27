NAME = cub3d

CC = cc

CFLAG = -Wall -Wextra -Werror

INC = -I./includes/

LIB_FLAG = -Llib -lft

SRC =	main.c \

SRC_DIR = ./srcs/

OBJS = $(SRCS:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC))

all : $(NAME)

.c.o:
	@$(CC) $(CFLAG) $(INC) $(R_INC) -c $< -o $@

$(NAME): $(OBJS)
	@make -C lib
	@$(CC) $(CFLAG) $^ $(LIB_FLAG) $(R_FLAG) -o $@
	@printf	"Ready for Cub3d\n"

clean :
	@make clean -C lib
	@$(RM) $(OBJS)
	@printf	"Run to Clean\n"

fclean :
	@make fclean -C lib
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@printf	"Run to fClean\n"

re :
	@make fclean
	@make all

.PHONY : all clean fclean re
