STD = -std=c99
# -std=c99: padrao C99 da linguagem C
# -ansi:    padrao C90 da linguagem C

OPTIONS = -Wall -Wpedantic -Wno-unused-result -O0 -g
# -O0: nao otimiza o codigo ao compilar
# -g:  prepara o terreno para que o gdb possa verificar bugs
lp1 : main.cpp funcionario.h funcionario.cpp empresa.h empresa.cpp sebrae.h sebrae.cpp
	g++  $(OPTIONS) main.cpp empresa.cpp funcionario.cpp sebrae.cpp -o lp1

