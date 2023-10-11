# define the C compiler to use
CC       = gcc
# define comipler flags
CFLAGS   = -std=c11 -Wall -fmax-errors=10 -Wextra
# define library paths in addition to /usr/lib
LFLAGS   =
# define libraries to use
LIBS     =
# define the object files that this project needs
OBJFILES = main.o data.o
# define the name of the executable file
MAIN     = main 

# all of the below is generic - one typically only adjusts the above

all: $(MAIN)

$(MAIN): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJFILES)
	$(MAKE) clean-obj

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJFILES) $(MAIN)

clean-obj:
	rm -f $(OBJFILES)

launch:
	./$(MAIN)
