CC := clang
CFLAGS := `sdl2-config --libs --cflags` -Wall -lSDL2_image -lSDL2_ttf
SRCS += setup_window.c
SRCS += draw_memory.c
SRCS += font_writing.c
SRCS += write_player_box.c
SRCS += write_info_box.c
SRCS += player_input_writing.c
SRCS += visu_tools.c
OBJS := $(SRCS:.c=.o)
EXEC := corewar_visu 

all: $(EXEC)

$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(EXEC) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
