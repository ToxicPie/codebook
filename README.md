# ICPC Codebook for Team NCTU_A

### **IMPORTANT NOTICE**: This codebook is not complete (in fact, not anywhere near completion). Do not clone this repository. **ETA is early September, 2020.**



This document ("codebook") is a collection of various C++ code templates we find necessary for programming contests. All code and content are compatible with the rules of ICPC World Finals:

> (*Your team reference document*) may contain up to 25 pages of reference materials, single-sided, letter or A4 size, with pages numbered in the upper right-hand corner and your university name and team name printed in the upper left-hand corner. Text and illustrations must be readable by a person with correctable eyesight without magnification from a distance of 1/2 meter. 

## Note

All code are tested individually for major issues and can be compiled successfully using C++17. C++17 is used in many contests (e.g. most regionals), and some others use recent versions of GCC, which support several C++17 syntaxes with `-std=c++14`. **However, there is no guarantee that everything in this codebook works everywhere.**

## Usage

Usage: Print it out and bring it to a contest. It is recommended that you change the team name and rebuild before doing this. You should also check if this codebook follow the contest's rules.

### Building

To re-generate the PDF file, run:
```
make codebook
```

Here is a list of dependencies:

- GNU Make
- A TeX distribution, preferably `texlive-full`
- [Fira Code](https://github.com/tonsky/FiraCode) and [Noto Sans CJK](https://www.google.com/get/noto/) fonts
- Python 2.6+/3.x and the Pygments package

### Testing

To compile and run tests for each material, do:
```
make tests
./tests.out
```

The test program will indicate success or failure for each individual test.

## Modifying

### Add / Edit Code

You can add or edit any file inside the `content` directory, then add to / change the sections in which they appear in `codebook.tex`. If it is not in C++, you should use `\lstinputlisting[language=your-language]{your-file}` instead.

### Add / Edit Tests

To add or edit a test for code templates, you should add or edit a `.cpp` file in the `tests/` directory. Here are the guidelines for a test unit:

1. It should include the files you want to test. It is recommended that you wrap them in an individual namespace to avoid redefinition errors.
2. It should provide a function that takes an `int` as parameter and returns `void`. The parameter indicates the number of test cases run. The function can take any name (as long as it does not conflict with others).
3. The function should end without doing anything if all test cases are passed. If something is not correct, it should throw a `wrong_answer_error` indicating the test case that failed.
4. There is a custom `assert` function provided; you should not `#include <cassert>`.

Your test function then should be added to `main.cpp` and `tests.hpp`. See any test file for an example.

## License

All C++ code (content and test programs) and the latex package (`codebookpkg.sty`) are released under the MIT License.
