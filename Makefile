################################################################################
# DIRECTORIES ##################################################################
################################################################################

# Includes
INC_DIR = inc/ libft/inc/

# Objects and dependencies
OBJ_DIR = obj/

# Source directories
SRC_DIR = $(sort $(dir $(wildcard src/*/))) src/

# Target directory
TARGET_DIR = ./

# Library directories
LIB_DIR = libft/
LDIR = $(LIB_DIR:%=-L%)

################################################################################
# BASIC ########################################################################
################################################################################

# Target name
NAME = fdf

# Sources
ifdef B
SRCS =\
main_bonus.c						vec4d_bonus.c	\
vec4d_ops_bonus.c					vec4d_ops_assign_bonus.c \
bounds4d_bonus.c					matrix4d_ortho_bonus.c	\
matrix4d_rotate_bonus.c				matrix4d_translate_bonus.c \
matrix4d_scale_bonus.c				matrix4d_bonus.c \
plane4d_bonus.c						util_bonus.c \
status_bonus.c						image_bonus.c \
modifiers_bonus.c					window_bonus.c \
hooks_bonus.c						state_bonus.c \
keymap_bonus.c						mesh_bonus.c \
clip_bonus.c						view_bonus.c \
color_bonus.c						color4d_ops_bonus.c \
color4d_bonus.c						projection_bonus.c \
projection_position_bonus.c			projection_rotation_bonus.c \
projection_select_bonus.c			draw_bonus.c \
zbuffer_bonus.c						view_draw_bonus.c \
keymap_handlers_bonus.c				map_bonus.c \
map_vertex_bonus.c					map_row_bonus.c \
map_rows_bonus.c
else
SRCS =\
main.c								vec4d.c	\
vec4d_ops.c							vec4d_ops_assign.c \
bounds4d.c							matrix4d_ortho.c	\
matrix4d_rotate.c					matrix4d_translate.c \
matrix4d_scale.c					matrix4d.c \
plane4d.c							util.c \
status.c							image.c \
modifiers.c							window.c \
hooks.c								state.c \
keymap.c							mesh.c \
clip.c								view.c \
color.c								color4d_ops.c \
color4d.c							projection.c \
projection_select.c					draw.c \
zbuffer.c							view_draw.c \
keymap_handlers.c					map.c \
map_vertex.c						map_row.c \
map_rows.c
endif

# Compiler
CC = cc

# Optimization flags
OPT = -O3 -ffast-math

# Extra flags
EXTRA =-Wall -Werror -Wextra

# Depflags
DEP = -MP -MMD

# Libraries
LIBS = ft mlx
LIB = $(LIBS:%=-l%)

FRAMEWORKS = OpenGL AppKit
FWK = $(FRAMEWORKS:%=-framework %)

################################################################################
# CONFIG #######################################################################
################################################################################

vpath %.c $(SRC_DIR)
.PHONY: all clean fclean re debug d libft
override FLAGS +=\
$(EXTRA) $(OPT) $(DEP) \
$(INC_DIR:%=-I%) $(SRC_DIR:%=-I%)

OBJS := $(SRCS:%.c=$(OBJ_DIR)%.o)
DEPS = $(SRCS:%.c=$(OBJ_DIR)%.d)

################################################################################
# RULES ########################################################################
################################################################################

# Default rule
all: mandatory

# Objects
$(OBJS): $(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c -o $@ $<

# Target
$(NAME): $(OBJS) | $(TARGET_DIR) libft
	$(CC) $(FLAGS) $(FWK) $(LDIR) $(LIB) -o $@ $^

libft:
	make -C libft

bonus:
#	Run a full clean if the project was previously compiled without bonuses
	-test -f $(OBJ_DIR)main.o && make fclean
	make $(NAME) B="1"

mandatory:
#	Run a full clean if the project was previously compiled with bonuses
	-test -f $(OBJ_DIR)main_bonus.o && make fclean
	make $(NAME)

# Cleanup
clean_local:
	rm -rf $(OBJS) $(DEPS)

clean:
	rm -rf $(OBJ_DIR)

fclean_local: clean
	rm -rf $(NAME)

fclean: fclean_local
	make fclean -C libft

# Debug
debug:
	make fclean
	make all FLAGS="-g -fsanitize=address"

# Aliases
re: fclean all
d: debug

# Dir creation
$(OBJ_DIR) $(TARGET_DIR):
	@mkdir -p $@

-include $(DEPS)