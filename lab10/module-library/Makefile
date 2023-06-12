CCC = cc
CFLAGS = -Wall -std=c99
OBJDIR = lib

OBJS = $(OBJDIR)/lib.o $(OBJDIR)/test.o

.PHONY: all clean

all: check

check: $(OBJS)
	$(CC) -o $(OBJDIR)/$@ $^

$(OBJDIR)/lib.o: src/lib.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/test.o: test/test.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)/*.o
doxygen:
	doxygen


