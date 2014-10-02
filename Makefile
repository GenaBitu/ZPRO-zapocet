LD = $(CXX)

CFLAGS = -Wnon-virtual-dtor -Winit-self -Wredundant-decls -Wcast-align -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -std=c++11 -Wfatal-errors -Wextra -Wall
LIB =
SRCDIR = src
OBJDIR = obj
BINDIR = bin

CFLAGS_DEBUG = $(CFLAGS) -g
LIB_DEBUG = $(LIB)
SRCDIR_DEBUG = $(SRCDIR)
OBJDIR_DEBUG = $(OBJDIR)/Debug
BINDIR_DEBUG = $(BINDIR)/Debug
OUT_DEBUG = $(BINDIR_DEBUG)/LinkedList

CFLAGS_RELEASE = $(CFLAGS) -s -O3
LIB_RELEASE = $(LIB)
SRCDIR_RELEASE = $(SRCDIR)
OBJDIR_RELEASE = $(OBJDIR)/Release
BINDIR_RELEASE = $(BINDIR)/Release
OUT_RELEASE = $(BINDIR_RELEASE)/LinkedList

OBJ_DEBUG = $(OBJDIR_DEBUG)/Main.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/Main.o

all: debug release

clean: clean_debug clean_release

before_debug:
	test -d $(BINDIR_DEBUG) || mkdir -p $(BINDIR_DEBUG)
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

debug: before_debug out_debug

Debug: debug

out_debug: $(OBJ_DEBUG)
	$(LD) -o $(OUT_DEBUG) $(OBJ_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/Main.o: Main.cpp
	$(CXX) $(CFLAGS_DEBUG) -c Main.cpp -o $(OBJDIR_DEBUG)/Main.o

clean_debug:
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf $(OBJDIR_DEBUG)

before_release:
	test -d $(BINDIR_RELEASE) || mkdir -p $(BINDIR_RELEASE)
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

release: before_release out_release

Release: release

out_release: before_release $(OBJ_RELEASE)
	$(LD) -o $(OUT_RELEASE) $(OBJ_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/Main.o: Main.cpp
	$(CXX) $(CFLAGS_RELEASE) -c Main.cpp -o $(OBJDIR_RELEASE)/Main.o

clean_release:
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_debug clean_debug before_release clean_release clean
