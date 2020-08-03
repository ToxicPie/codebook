.PRECIOUS: ./p%

%: p%
	ulimit -s unlimited && ./$<

p%: p%.cpp
	g++ -std=gnu++17 -Wall -Wextra -Wshadow \
	-fsanitize=address -fsanitize=undefined \
	-o $@ $<

init:
	for i in a b c d e f g h; do \
		cp default.cpp "p$$i.cpp"; \
	done
