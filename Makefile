# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 

# Directories
SRC_DIR = ./src
TEST_DIR = ./tests
BUILD_DIR = ./build

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_FILES))

# Executable names
EXECUTABLE = tri_tree
TEST_EXECUTABLE = test_tri_tree

# Google Test settings
GTEST_DIR = ./googletest/googletest
GTEST_LIB_DIR = ./googletest/build/googlemock/gtest
GTEST_FLAGS = -isystem $(GTEST_DIR)/include -L$(GTEST_LIB_DIR) -lgtest -lgtest_main -pthread 

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: clean $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_OBJ_FILES) $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(BUILD_DIR)/test.o $(BUILD_DIR)/impl.o -o $@ $(GTEST_FLAGS)

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE) $(TEST_EXECUTABLE)

.PHONY: all clean test
