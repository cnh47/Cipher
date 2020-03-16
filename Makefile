.PHONY: all
all : cipher


cipher : cipher.o
	g++ cipher.o -o cipher

cipher.o : cipher.cpp
	g++ -std=c++17 -c cipher.cpp

.PHONY: clean
clean :
	@rm -f *.o cipher
