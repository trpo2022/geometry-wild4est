CC = g++

APP_NAME = geometry
LIB_NAME = libgeometry

CFLAGS = -Wall -Wextra -lstdc++ -lm
CPPFLAGS = -I src -MP -MMD
LDFLAGS =
LDLIBS =

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_DIR)

SRC_EXT = cpp

APP_SRC = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJ = $(APP_SRC:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SRC = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJ = $(LIB_SRC:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)


DEPS = $(APP_OBJ:.o=.d) $(LIB_OBJ:.o=.d) $(TEST_OBJ:.o=.d)

.PHONY: all clean
all: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJ) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(LIB_PATH): $(LIB_OBJ)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@


clean:
	$(RM) $(APP_PATH) $(LIB_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
	
