CC := g++

SRCDIR := src
BUILDDIR := build
TARGET := bin
	
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g
LIB := -lsfml-graphics -lsfml-window -lsfml-system
INC := -I"/usr/local/include" -I"/usr/local/lib" -I include

RESET_COLOR := \033[0m
BUILD_COLOR := \033[0;34m
MESSAGE_COLOR := \033[1;33m

$(TARGET): $(OBJECTS)
	@echo "$(MESSAGE_COLOR) Linking... $(RESET_COLOR)"
	@echo "$(BUILD_COLOR) $(CC) $^ -o $(TARGET) $(LIB) $(RESET_COLOR)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo "$(BUILD_COLOR) $(CC) $(CFLAGS) $(INC) -c -o $@ $< $(RESET_COLOR)"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "$(MESSAGE_COLOR) Cleaning... $(RESET_COLOR)"; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

# Spikes
ticket:
	$(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean
