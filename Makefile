all:total

total:main.o selectMap.o PlayAndLevel.o 
	g++ -W -Wall -o game main.o selectMap.o PlayAndLevel.o -lncurses 

selectMap.o:selectMap.cpp
	g++ -W -Wall -c -o selectMap.o selectMap.cpp -lncurses
PlayAndLevel.o:PlayAndLevel.cpp
	g++ -W -Wall -c -o PlayAndLevel.o PlayAndLevel.cpp -lncurses
main.o:main.cpp
	g++ -W -Wall -c -o main.o main.cpp -lncurses
