IDIR = src
CC = gcc
CFLAGS = -I$(IDIR) -Wall -Wpedantic

ODIR = obj
$(info $(shell [ -d $(ODIR) ] || mkdir $(ODIR)))

LDIR = lib

LIBS = -lvlc -lX11 -lXtst

_DEPS = media.h socketserver.h inputevent.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o inputevent.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(IDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o *~ $(IDIR)/*~
