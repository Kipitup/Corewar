NAME := corewar_visu
HEAD := visu.h 
CC := clang
CFLAGS := `sdl2-config --libs --cflags` -Wall -lSDL2_image -lSDL2_ttf
SRCS += setup_window
SRCS += draw_main_zone
SRCS += font_writing
SRCS += write_arena
SRCS += write_player_box
SRCS += write_info_box
SRCS += player_input_writing
SRCS += visu_tools
BUILD_DIR = objs/
OBJS := $(patsubst %, $(BUILD_DIR)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

$(OBJS): $(BUILD_DIR)%.o: %.c $(HEAD) Makefile
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR)

fclean:
	$(RM) -r $(NAME) $(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re
