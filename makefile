# Compiler
CXX = g++

# Flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
LIB_DIR = lib
INCLUDE_ASIO_DIR = include/asio/include

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Targets
all: $(LIB_DIR)/trig.lib $(LIB_DIR)/compound_interest.dll calculator

calculator: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ -L$(LIB_DIR)

# This rule means: "For any .cpp file in src/, compile it into an .o file in build/."
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -I$(INCLUDE_ASIO_DIR) -c -o $@ $<

# Rule to create the compound interest DLL
$(LIB_DIR)/compound_interest.dll: $(BUILD_DIR)/compound_interest.o
	$(CXX) -shared -o $@ $^

# Rule to create the trigonometric static library
$(LIB_DIR)/trig.lib: $(BUILD_DIR)/trig_operations.o
	lib /OUT:$@ $^

clean:
	rm -rf $(BUILD_DIR)/*.o calculator $(LIB_DIR)/compound_interest.dll $(LIB_DIR)/trig.lib

.PHONY: all clean