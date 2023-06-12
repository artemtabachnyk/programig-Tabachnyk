CC = cc
CFLAGS = -Wall -std=c99 -I../module-library/src
OBJDIR = bin

OBJS = $(OBJDIR)/main.o

.PHONY: all clean

all: main

main: $(OBJS)
	$(CC) -o $(OBJDIR)/$@ $^ -L../module-library/lib -llib

$(OBJDIR)/main.o: src/main.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)/*.o

doxygen:
	doxygen

