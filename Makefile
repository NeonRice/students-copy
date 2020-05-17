CXX = g++
FILENAME = Students
TEST_FILENAME = test

CXXFLAGS = -pedantic -std=c++17 -O3
LD_FLAGS = -lgtest -lpthread

SRC_PATH := src/
TEST_PATH := tests/

TEST_DEP = $(SRC_PATH)Student.cpp $(SRC_PATH)Input.cpp

EXCLUDE_FILES = $(SRC_PATH)main.cpp

src = $(wildcard $(SRC_PATH)*.cpp)
tests = $(wildcard $(TEST_PATH)*.cpp)
obj = $(src:$(SRC_PATH)%.cpp=%.o)

external = $(subst $(EXCLUDE_FILES),, ${src})

Students: $(src)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LD_FLAGS)

.PHONY: build
build: $(src)
	mkdir -p build
	$(CXX) -c $^ $(CXXFLAGS)
	mv $(obj) build

.PHONY: clean
clean:
	rm -f $(FILENAME) *.txt
	rm -r build

.PHONY: test
test: $(tests)
	$(CXX) -o $@ $^ $(TEST_DEP) $(CXXFLAGS) $(LD_FLAGS)

.PHONY: testclean
testclean:
	rm -f *.txt $(TEST_FILENAME)
