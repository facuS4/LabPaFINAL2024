executable = Main
compiler = g++
compiler-options = -g -Wall -Wextra -Werror

ifdef OS
	executable := $(executable).exe
endif

build:
	$(compiler) $(compiler-options) -o $(executable) ICollection/*.cpp ICollection/collections/*.cpp ICollection/interfaces/*.cpp clases/datatypes/cpp/*.cpp clases/cpp/*.cpp ISistema.cpp SistemaFactory.cpp Sistema.cpp main.cpp