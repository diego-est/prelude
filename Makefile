.POSIX:

CXX=g++
COMPATFLAGS=-fipa-pure-const
WARNFLAGS=-Wall -Werror -Wextra -Wsuggest-attribute=pure -Wsuggest-attribute=const
CXXFLAGS=-O0 --std=gnu++2b $(COMPATFLAGS) $(WARNFLAGS)
SRC=src/prelude.cpp src/main.cpp
BUILD=build

build: src/main.cpp
	$(CXX) $(SRC) -o $(BUILD)/a.out $(CXXFLAGS)

run: build
	./$(BUILD)/a.out

format:
	clang-format -i $(SRC)

modules:
	echo "modules.sh should be executable"
	./modules.sh

.PHONY: build run format
