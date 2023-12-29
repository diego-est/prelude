.POSIX:

CXX=g++
CXXFLAGS=-fipa-pure-const -O0 -Wall -Werror -Wextra --std=gnu++2b -Wsuggest-attribute=pure -Wsuggest-attribute=const
SRC=src/*.cpp
BUILD=build

build: src/main.cpp
	$(CXX) $(SRC) -o $(BUILD)/a.out $(CXXFLAGS)

run: build
	./$(BUILD)/a.out

format:
	clang-format -i $(SRC)

.PHONY: build run format
