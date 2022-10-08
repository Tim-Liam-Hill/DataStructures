SRC_DIR := ./
OBJ_DIR := ./obj
WIN_OBJ_DIR := %OBJ_DIR:~2%
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
CFLAGS := -I. -Wall
CXX := g++
TARGET := main.exe

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	del -f $(TARGET) 
	del %OBJ_DIR:~2%\*.o
	