IDIR = src
CC = gcc
CFLAGS = -I$(IDIR) -Wall -Wpedantic

ODIR = obj
$(info $(shell [ -d $(ODIR) ] || mkdir $(ODIR)))

LDIR = lib

LIBS = -lvlc

_DEPS = media.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o media.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(IDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o *~ $(IDIR)/*~
