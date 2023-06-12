CC = cc
CFLAGS = -Wall -std=c99 -I/usr/local/include -Imodule-library/src
LDFLAGS = -L/usr/local/lib -lcheck -lm -lsubunit
OBJDIR = dist
OBJS = $(addprefix $(OBJDIR)/, module-library/lib.o module-main/main.o)

.PHONY: all clean

all: check

check: $(OBJS)
	$(CC) -o $(OBJDIR)/$@ $^ $(LDFLAGS)

$(OBJDIR)/module-library/lib.o: module-library/src/lib.c | $(OBJDIR)/module-library
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/module-main/main.o: module-main/src/main.c | $(OBJDIR)/module-main
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/module-library:
	mkdir -p $@

$(OBJDIR)/module-main:
	mkdir -p $@

clean:
	rm -rf $(OBJDIR)/*.o
	rm -rf $(OBJDIR)/check

