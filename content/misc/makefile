.PRECIOUS: ./p%

%: p%
	ulimit -s unlimited && ./$<

p%: p%.cpp
	g++ -o $@ $< -std=gnu++17 -Wall -Wextra -Wshadow \
	-fsanitize=address -fsanitize=undefined

init:
	for i in a b c d e f g h; do \
		cp default.cpp "p$$i.cpp"; \
	done
