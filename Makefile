# .cpp files used for codebook
CODE_SRC = $(shell find ./content -type f -name '*.cpp')
# files used for testing
TEST_SRC = $(shell find ./tests -type f -name '*.cpp')
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TEST_DEPS = $(shell find ./tests -type f -name '*.hpp')
TEST_EXE = tests.out

# compile / link flags
# === NOTE / WARNING ===
# These are the flags used in ICPC as of the 2019 season. You may want to
# change it according to the rules of other contests (e.g. -std=c++17 for
# Taiwan regionals), however, the code may not compile successfully. See
# `README.md` for more details.
CXX_FLAGS = -g -O2 -std=gnu++17
LD_FLAGS = -static

# pdf build related
TEX_FILE = codebook.tex
PDF_FILE = $(TEX_FILE:.tex=.pdf)
TEX_BUILD_DIR = tex_build
LATEX = xelatex -shell-escape -output-directory $(TEX_BUILD_DIR)


.PHONY: all clean codebook tests cleantests cleanlatex

all: codebook

codebook: $(TEX_FILE) $(CODE_SRC)
	mkdir -p $(TEX_BUILD_DIR)
	$(LATEX) $(TEX_FILE) && $(LATEX) $(TEX_FILE)
	mv $(TEX_BUILD_DIR)/$(PDF_FILE) $(PDF_FILE)

tests: $(TEST_OBJ)
	$(CXX) $(LD_FLAGS) $(TEST_OBJ) -o $(TEST_EXE)

%.o: %.cpp
	$(CXX) -I ./content -c $(CXX_FLAGS) $< -o $@

tests/main.o: tests/main.cpp $(TEST_DEPS)
	$(CXX) -c $(CXX_FLAGS) $< -o $@

clean: cleantests cleanlatex

# remove all testing objects
cleantests:
	find tests -name '*.o' -delete
	rm $(TEST_EXE) -f

# remove codebook stuff
cleanlatex:
	rm $(TEX_BUILD_DIR) -rf
	rm $(PDF_FILE) -f
