################################################################################
# DIRECTORIES ##################################################################
################################################################################

# Includes
INC_DIR = inc/ libft/inc/

# Objects and dependencies
OBJ_DIR = obj/

# Sources
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
SRCS =\
main.c \
vec2i.c	\
vec4d.c	\
vec4d_ops.c	\
vec4d_ops_assign.c \
bounds4d.c \
ortho.c	\
rotate.c \
translate.c \
scale.c \
plane4d.c \
util.c \
matrix4d.c \
status.c \
image.c \
vec3i.c \
modifiers.c \
window.c \
color.c \
hooks.c \
state.c \
keymap.c \
mesh.c \
clip.c \
view.c \
projection.c \
color4d_ops.c \
color4d.c \
projection_position.c \
projection_rotation.c \
draw.c \
zbuffer.c \
map.c \
view_draw.c \
keymap_handlers.c \
map_vertex.c \
map_row.c \
projection_select.c
# render.c
#map.c
#buffer.c
#keymap.c
#world.c
#world_rotation.c
#world_position.c
#world_scale.c
#keymap.c

# Compiler
CC = cc

# Optimization flags
OPT =

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

OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)
DEPS = $(SRCS:%.c=$(OBJ_DIR)%.d)

################################################################################
# RULES ########################################################################
################################################################################

# Default rule
all: $(NAME)

# Objects
$(OBJS): $(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c -o $@ $<

# Target
$(NAME): $(OBJS) | $(TARGET_DIR) libft
	$(CC) $(FLAGS) $(FWK) $(LDIR) $(LIB) -o $@ $^

libft:
	make -C libft

# Cleanup
clean_local:
	rm -rf $(OBJS) $(DEPS)

clean: clean_local
	make fclean -C libft

fclean_local: clean_local
	rm -rf $(NAME)

fclean: clean_local
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