ifeq ($(shell uname), Darwin)
    CXX       := g++
    CXXVER    := --version 2>&1 | grep c++
    GTESTVER  := head -1 /usr/local/src/gtest-1.7.0/CHANGES
    GCOV      := gcov
    GCOVFLAGS := -fprofile-arcs -ftest-coverage
    GCOVVER   := -version | grep version
    BOOST     := /usr/local/src/boost_1_57_0/boost
    LDFLAGS   := -lgtest_main
    VALGRIND  :=
else ifeq ($(CXX), clang++)
    CXXVER    := --version 2>&1 | grep clang
    GTESTVER  := dpkg -l libgtest-dev | grep libgtest
    GCOV      := gcov-4.6
    GCOVFLAGS := --coverage
    GCOVVER   := -v | grep gcov
    BOOST     := /usr/include/boost
    LDFLAGS   := -lgtest -lgtest_main -pthread
    VALGRIND  := valgrind
else
    CXX       := g++-4.8
    CXXVER    := --version 2>&1 | grep g++
    GTESTVER  := dpkg -l libgtest-dev | grep libgtest
    GCOV      := gcov-4.8
    GCOVFLAGS := -fprofile-arcs -ftest-coverage
    GCOVVER   := -v | grep gcov
    BOOST     := /usr/include/boost
    LDFLAGS   := -lgtest -lgtest_main -pthread
    VALGRIND  := valgrind
endif

CXXFLAGS := -pedantic -std=c++11 -Wall

.PRECIOUS: %.app

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f TestGraph
	rm -f TestGraph.out

sync:
	make clean
	@echo `pwd`
	@rsync -r -t -u -v --delete \
    --include "Graph.h"         \
    --include "makefile"        \
    --include "TestGraph.c++"   \
    --exclude "*"               \
    . downing@$(CS):cs/cs378/github/c++/graph/

test: TestGraph.out

versions:
	uname -a
	@echo
	printenv
	@echo
	which $(CXX)
	@echo hi
	$(CXX) $(CXXVER)
	@echo hi
	$(GTESTVER)
	@echo
	which $(GCOV)
	@echo
	$(GCOV) $(GCOVVER)
	@echo
	grep "#define BOOST_VERSION " $(BOOST)/version.hpp
ifdef VALGRIND
	@echo
	which $(VALGRIND)
	@echo
	$(VALGRIND) --version
endif
	@echo
	which doxygen
	@echo
	doxygen --version

TestGraph: Graph.h TestGraph.c++
	$(CXX) $(GCOVFLAGS) $(CXXFLAGS) TestGraph.c++ -o TestGraph $(LDFLAGS)

TestGraph.out: TestGraph
	$(VALGRIND) ./TestGraph  >  TestGraph.out 2>&1
	$(GCOV) -b TestGraph.c++ >> TestGraph.out
	cat TestGraph.out
