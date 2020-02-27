CXX = g++
FILENAME = Utility
CXXFLAGS = -pedantic -std=c++17
EXCLUDE_FILES = main.cpp
src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)
external = $(subst $(EXCLUDE_FILES),, ${src})

Students: $(obj)
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