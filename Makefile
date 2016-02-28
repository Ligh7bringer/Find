# compiler to use
CC = clang

# flags to pass compiler
CFLAGS = -std=c99

# name for executable
EXE = find

# space-separated list of header files
HDRS = load.h 

# space-separated list of source files
SRCS = main.c load.c 

# automatically generated list of object files
OBJS = $(SRCS:.c=.o)

# default target
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# dependencies 
$(OBJS): $(HDRS) Makefile

# clean
clean:
	rm -f core $(EXE) *.o
