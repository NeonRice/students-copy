CXX = g++
FILENAME = Students
TEST_FILENAME = test
CXXFLAGS = -pedantic -std=c++17 -O3
EXCLUDE_FILES = main.cpp
EXCLUDE_TEST_FILES = test.cpp
src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)
external = $(subst $(EXCLUDE_FILES),, ${src})
source = $(subst $(EXCLUDE_TEST_FILES),, ${src})

Students: $(source)
	$(CXX) -o $@ $^ $(CXXFLAGS)
.PHONY: build
build: $(src)
	$(CXX) -c $^ $(CXXFLAGS)
.PHONY: extern
extern: $(external)
	$(CXX) -c $^ $(CXXFLAGS)
.PHONY: clean
clean:
	rm -f $(obj) $(FILENAME)
test: $(external)
	$(CXX) -o $@ $^ $(CXXFLAGS)
testclean:
	rm -f *.txt $(TEST_FILENAME)
