# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgasc <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 18:19:19 by lgasc             #+#    #+#              #
#    Updated: 2024/11/19 19:09:15 by lgasc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			Form_up,_maggots!
MAIN =			main.cpp
DEFINITIONS =	#METHOD_INFO=false SPECIAL_INFO=false
CLASSES =		Bureaucrat Form
SOURCES =		$(addsuffix .cpp, $(CLASSES)) #$(MAIN)
HEADERS =		$(addsuffix .hpp, $(CLASSES))
DEPENDENCY =	dependency.d#$(addsuffix .d, $(NAME))
DEP =			$(DEPENDENCY)
#LDLIBS +=		-lreadline
#LIBFT =		libft/libft.a
#LIB_ARCHIVES =	$(LIBFT)
#OBJECTS =		$(SOURCES:.c=.o) $(LIB_ARCHIVES)
OBJECTS =		$(SOURCES:.cpp=.o) $(LIB_ARCHIVES)

CPPFLAGS =	$(addprefix -D, $(DEFINITIONS))

# https://stackoverflow.com/a/56290397/22306298
CCFLAGS +=	-Wall -Wstrict-overflow=5 -Wnarrowing -Wattributes -Wnonnull -g\
			-Wwrite-strings -Wextra -Werror -Wshadow -Wpedantic -Wdeprecated\
			-Wmissing-format-attribute -Wnull-dereference -Wmissing-noreturn\
			-Wunused-macros

GCCFLAGS +=	-Wattribute-alias=2 -Wsuggest-attribute=const -Wstringop-overflow=4\
			-Wsuggest-attribute=pure -Wsuggest-attribute=cold -Wduplicated-cond\
			-Wsuggest-attribute=malloc -Wsuggest-attribute=noreturn\
			-Wduplicated-branches -Wsuggest-attribute=format\
			-Wunused-const-variable=2 -fanalyzer

CLANGFLAGS +=	-Wproperty-attribute-mismatch -Wunused-const-variable#-Xanalyzer

CFLAGS +=	$(CCFLAGS) -Wsuggest-attribute=returns_nonnull -Wenum-conversion
ifeq ($(filter gcc clang, $(CC)),$(if $(filter %.c, $(SOURCES) $(MAIN)),,No .c))
 $(warning ,----------------------------------------------------------------.)
 $(warning | Consider specifying `gcc` or `clang` for more extensive checks |)
 $(warning `----------------------------------------------------------------')
endif
ifeq ($(CC), gcc)
 CFLAGS +=	$(GCCFLAGS)
 ifeq "$(firstword $(shell (gcc -dumpversion;echo 11)|sort -n))" "11"
  CFLAGS +=	-Wmismatched-dealloc -Wmismatched-new-delete -Wfree-nonheap-object\
			-Wsizeof-array-div -Wstringop-overread -Wtsan -Warray-parameter\
			-Wvla-parameter
 endif
else ifeq ($(CC), clang)
 CFLAGS +=	$(CLANGFLAGS) -Wmismatched-dealloc -Wmismatched-new-delete\
			-Wfree-nonheap-object -Wsizeof-array-div -Wstringop-overread -Wtsan\
			-Warray-parameter -Wvla-parameter
endif

CXXSTD =	c++98
CXXFLAGS +=	$(CCFLAGS) -std=$(CXXSTD) -Weffc++ -Wctor-dtor-privacy -Wsign-promo\
			-Wdelete-non-virtual-dtor -Wdeprecated-copy -Wold-style-cast\
			-Wdeprecated-copy-dtor -Wzero-as-null-pointer-constant -Wregister\
			-Wreorder -Wextra-semi -Wnon-virtual-dtor -Wnoexcept-type\
			-Woverloaded-virtual -Wmismatched-tags -Wconversion-null

GXXFLAGS +=	-Wsized-deallocation -Wredundant-tags -Wcatch-value=3\
			-Wcomma-subscript -Wvolatile -Wsuggest-final-methods\
			-Waligned-new=all -Wconditionally-supported -Wnoexcept\
			-Wnamespaces -Wsuggest-final-types -Wplacement-new=2\
			-Wtemplates -Wstrict-null-sentinel -Wclass-memaccess

ifeq "$(filter g++ clang++, $(CXX))" \
	"$(if $(filter %.cpp %.tpp, $(SOURCES) $(MAIN)),,No .cpp nor .tpp)"
 $(warning ,------------------------------------------------------------------.)
 $(warning | Consider specifying `g++` or `clang++` for more extensive checks |)
 $(warning `------------------------------------------------------------------')
endif
ifneq "$(CXXSTD)" "c++98"
 CXXFLAGS +=	-Wsuggest-override
endif
ifeq ($(CXX), g++)
 CXXFLAGS +=	$(GCCFLAGS) $(GXXFLAGS)
 # https://stackoverflow.com/a/60657038/22306298
 ifeq "$(firstword $(shell (g++ -dumpversion;echo 11)|sort -n))" "11"
  CFLAGS +=	-Wmismatched-dealloc -Wmismatched-new-delete -Wfree-nonheap-object\
			-Wsizeof-array-div -Wstringop-overread -Wtsan -Warray-parameter\
			-Wvla-parameter -Wctad-maybe-unsupported -Wrange-loop-construct\
			-Wdeprecated-enum-enum-conversion -Wrange-loop-construct\
			-Wdeprecated-enum-float-conversion -Wvexing-parse\
			-Winvalid-imported-macros -Wdeprecated-literal-operator
 endif
 ifeq "$(firstword $(shell (g++ -dumpversion;echo 13)|sort -n))" "13"
  CXXFLAGS +=	-Wdangling-reference -Wself-move -Winvalid-constexpr
 endif
 ifeq "$(firstword $(shell (g++ -dumpversion;echo 14)|sort -n))" "14"
  CXXFLAGS +=	-Wtemplate-id-cdtor
 endif
else ifeq ($(CXX), clang++)
 CXXFLAGS +=	$(CLANGFLAGS) -Wself-move -Wdeprecated-enum-float-conversion\
				-Wfree-nonheap-object -Wsizeof-array-div -Wrange-loop-construct\
				-Wrange-loop-construct -Wdeprecated-enum-enum-conversion\
				-Wmismatched-new-delete -Wctad-maybe-unsupported -Wvexing-parse\
				-Winvalid-constexpr#-Wcomma-subscript -Wtemplates -Wnoexcept\
				-Wsuggest-final-types -Wconditionally-supported -Wcatch-value=3\
				-Wsuggest-final-methods -Wnamespaces -Wvolatile -Wvla-parameter\
				-Wstringop-overread -Wsized-deallocation -Wstrict-null-sentinel\
				-Wredundant-tags -Wclass-memaccess-Wmultiple-inheritance -Wtsan\
				-Wvirtual-inheritance -Wdangling-reference -Wmismatched-dealloc\
				-Wtemplate-id-cdtor -Warray-parameter -Winvalid-imported-macros\
				-Wdeprecated-literal-operator\
				-Wplacement-new=2 -Waligned-new=all
endif


RESET =			\033[0m
#BOLD =			\033[1m
#FAINT =		\033[2m
#REGULAR =		\033[22m
#ITALIC =		\033[3m
#ROMAN =		\033[23m
#BLACK_FORE =	\033[30m
#OLIVE_FORE =	\033[33m
#DEFAULT_FORE =	\033[39m
#DEFAULT_BOTH =	\033[39;49m
#OLIVE_BACK =	\033[43m
#GREY_FORE =	\033[90m
#WHITE_FORE =	\033[97m
LOW_SCRIPT =	\033[22;23;25;7m
L_C =	$(LOW_SCRIPT)
# Loose inspiration from a gnu head
GNU_SCRIPT =	\033[22;3;27m
G_C =	$(GNU_SCRIPT)
GNU_STYLE =		\033[3;30;43m
G_Y =	$(GNU_STYLE)
# Warning sCript
W_C =			\033[1;6;27m
# Warning stYle, poison colours
W_Y =			\033[1;6;32;45m
BACKQUOTE =	`#`# Vim acts funny when a variable contains one.
REMOVING_START =	'$(G_Y)Removing $(BACKQUOTE)$(L_C)'
RM_S =	$(REMOVING_START)
REMOVING_MORE =		'$(G_C)$(BACKQUOTE), $(BACKQUOTE)$(L_C)'
RM_M =	$(REMOVING_MORE)
REMOVING_END =		'$(G_C)$(BACKQUOTE)...$(RESET)'
RM_E =	$(REMOVING_END)
H_G =				'$(W_Y)Header guard $(BACKQUOTE)$(L_C)'
NF_IN =				'$(W_C)$(BACKQUOTE) not found in $(BACKQUOTE)$(L_C)'
# Warning Bang
W_B =				'$(W_C)$(BACKQUOTE)!$(RESET)'
H_OK =				'$(G_Y)All header guards seems present.$(RESET)'

DIRT =	'TODO|FIXME|XXX|(?<!'\'')\?|\?(?!'\'')|! ?!|DEPREC\w*|[Dd]eprec\w*$\
		|(?:w?c)?log|(?<![/:])/([*/])(?! |!|\1)|(?:[^\t]{0,2}\t|....){20}(?=.)$\
		|\b(?!$(LABEL_ALLOW))[_a-z][A-Z_a-z]*:(?![:])'
LABEL_ALLOW =	By|Created|Updated|https|public$\
				|protected|private|default|c_[a-z]+
CAMEL_TO_SCREAM =	's/[^A-Za-z]/_/g;s/([A-Z])([A-Z][a-z])/\1_\2/g;$\
					s/([a-z])([A-Z])/\1_\2/g;s/.*/\U\0/'



.PHONY:	all re clean fclean

$(NAME):	$(MAIN) $(OBJECTS) #$(DEP) #$(MAIN) $(OBJECTS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(MAIN) $(OBJECTS) $(LDLIBS) --output $(NAME)
	-norminette
	-grep -PRn $(DIRT) --colour=auto --include='*.[cht]pp' --include='*.[ch]'\
	 || echo '$(G_Y)No dirt found.$(RESET)'
	-for h in $$(find * -name \*.h -o -name '*.[ht]pp');\
	 do g=$$(echo $$h|sed -E $(CAMEL_TO_SCREAM)); if ! grep -wq $$g $$h;\
	   then e=+; echo $(H_G)$$g$(NF_IN)$$h$(W_B); fi done;\
	 if [ -z $$e ]; then echo $(H_OK); fi

all:		$(NAME)

clean:		
	#$(MAKE) -C $(dir $(LIBFT)) fclean
	for o in $(OBJECTS); \
	 do if [ -f $$o ]; then if [ -z $$rm ]; then echo -n $(RM_S)$$o;\
	   else echo -n $(RM_M)$$o; fi; rm=+; rm $$o; fi done; if [ -n ''$$rm ];\
	 then echo $(RM_E); else echo '$(G_Y)No object file to remove.$(RESET)'; fi
	if [ -z "$(filter re, $(MAKECMDGOALS))"];\
	 then if [ -f $(DEP) ]; then echo $(RM_S)$(DEP)$(RM_E); rm $(DEP);\
	  else echo '$(G_Y)No dependency file to remove.$(RESET)'; fi fi

fclean:		clean
	if [ -f $(NAME) ]; then echo $(RM_S)$(NAME)$(RM_E); rm $(NAME);\
	 else echo '$(G_Y)No executable to remove.$(RESET)'; fi

re:			fclean all

# Prevent unnecessary inclusion
# 	https://www.gnu.org/software/make/manual/make#index-MAKECMDGOALS
# 	Note how this inclusion remains a requirement of `re`.
ifeq "$(filter clean fclean, $(MAKECMDGOALS))" ""
 include $(DEP)
endif

$(DEP):		$(MAIN) $(SOURCES)
	: > $@
	for s in $^; do $(CC) -MM $$s>>$@; done
	# This is the only place where `-e` is necessary. Why?
	echo -e '$(G_Y)Dependency file `$(L_C)$@$(G_C)` made.$(RESET)'

$(LIBFT):	
	$(MAKE) -C $(dir $@) #bonus


# Use `CC=...` or `CXX=...` instead.
#test:		$(OBJECTS)
#	- clang	$(CFLAGS) $(OBJECTS) $(LDLIBS)
#	- gcc	$(CFLAGS) $(OBJECTS) $(LDLIBS)
#	$(CC)	$(CFLAGS) $(OBJECTS) $(LDLIBS)

#$(SOURCES:.c=.o):	$@
#	echo '@$@ <$< ?$? ^$^'

# https://www.gnu.org/software/make/manual/make.html#Catalogue-of-Rules
# https://www.gnu.org/software/make/manual/make.html#Suffix-Rules
#%.o: %.cpp %.hpp
#	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $<
