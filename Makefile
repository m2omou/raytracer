##
## Makefile for fdf in /home/wilgen_t//afs/projets/BSQ
## 
## Made by thomas wilgenbus
## Login   <wilgen_t@epitech.net>
## 
## Started on  Wed Oct 27 08:11:45 2010 thomas wilgenbus
## Last update Sun Jun  5 18:23:53 2011 thomas wilgenbus
##

NAME=		rt

LIB=            -L/usr/local/lib/ -lmlx		\
		-Lmy_printf/ -lmy_printf_`uname -m`-`uname -s`	\
                -L/usr/lib/ -lX11 -lXext	\
		-lm				\
		-pthread

INC=            -I/usr/local/include		\
		-Imy_printf			\
		-Iinclude

SRC=		parser/get_nbr.c		\
		parser/get_next_line.c		\
		parser/parser_loop.c		\
		parser/parser.c			\
		parser/parser_utils.c		\
		parser/properties_utils.c	\
		parser/complex.c		\
		parser/get_properties.c		\
		parser/obj_utils.c		\
		parser/variable.c		\
		parser/list_utils.c		\
		parser/propertie.c		\
		parser/str_utils.c		\
		source/main.c			\
		source/create_win.c		\
		source/throw_vect.c		\
		source/rotation.c		\
		source/translation.c		\
		source/link_fct_to_obj.c	\
		source/hooked_fct.c		\
		source/cellshading.c		\
		source/fill_img.c		\
		source/get_vect_color.c		\
		source/get_light_color.c	\
		source/get_reflex_color.c	\
		source/get_transp_color.c	\
		source/multi_thread.c		\
		source/op_on_color.c		\
		source/op_on_vect.c		\
		source/load_texture.c		\
		source/get_direct_color.c	\
		source/get_tex_color.c		\
		source/mouvement.c		\
		source/neg_object.c		\
		source/get_shadow.c		\
		source/calc_line.c		\
		source/get_focus_color.c	\
		source/calc_focus_distance.c	\
		source/copy_img.c		\
		source/parse_arg.c		\
		source/cell_overlay.c		\
		source/get_perlin_color.c	\
		source/calc_noise_perlin.c	\
		source/get_bump_mapping_normal.c\
		source/kind_texture_perlin.c	\
		utils/check_sys.c		\
		utils/display_error.c		\
		object/sphere.c			\
		object/plane.c			\
		object/cylinder.c		\
		object/cone.c			\
		object/mobus.c			\
		object/mobus_utils.c		\
		object/object_utils.c		\
		anti_alias/anti_alias.c		\
		anti_alias/test_aliasing.c	\
		anti_alias/random.c		\
		bmp/header_bmp.c		\
		bmp/signature.c			\
		bmp/loading_bitmap.c		\
		bmp/convert_scene_to_bmp.c	\
		bmp/name_of_bitmap.c		\
		bmp/write_the_bmp.c		\
		bmp/xwrite.c			\
		slide_show/header_show.c	\
                slide_show/signature_show.c	\
                slide_show/slide_show.c		\
                slide_show/aff_the_bmp.c	\
                slide_show/load_bmp_img.c	\
                slide_show/xclosedir.c

NETWORK_SRC=	network/init.c			\
		network/loop.c			\
		network/net_close.c		\
		network/xnetwork2.c		\
		network/xnetwork3.c		\
		network/xnetwork.c		\
		network/scene_transfer.c	\
		network/event.c			\
		network/server_response.c	\
		network/client_order.c		\
		network/client_response.c	\
		network/st_waiting.c		\
		network/get_missing_data.c	\
		network/send_scene.c		\
		network/cell_transfer.c

OBJ=		$(SRC:.c=.o)

NETWORK_OBJ=	$(NETWORK_SRC:.c=.o)

CFLAGS=		-Wextra -Wall -Werror -ansi -pedantic $(INC) -O2 -D_BSD_SOURCE

ifeq ($(NETWORK), true)
CFLAGS +=	 -D_CC_NETWORK_
OBJ += $(NETWORK_OBJ)
endif

ifeq ($(DEBUG), true)
CFLAGS +=	-g3 -D_CC_DEBUG_
endif

$(NAME):	$(OBJ)
	cc $(OBJ) -o $(NAME) $(LIB)

all:		$(NAME)

network:	clean $(OBJ) $(NETWORK_OBJ)
	cc $(OBJ) $(NETWORK_OBJ) -o $(NAME) $(LIB)

re:		fclean $(NAME)

clean:
	rm -rf $(OBJ) $(NETWORK_OBJ)

fclean:		clean
	rm -rf $(NAME)
