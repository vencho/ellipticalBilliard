CC = g++
LIBS = -lSDL2
FLAGS = -O2 -w
SRCDIR = ./src
BINDIR = ./bin
OBJDIR = ./obj
INCDIR = ./include
LIBDIR = /usr/include/SDL2

OBJECTS = \
./$(OBJDIR)/Point.o \
./$(OBJDIR)/MovingPoint.o \
./$(OBJDIR)/Ellipse.o \
./$(OBJDIR)/Model.o \
./$(OBJDIR)/View.o

all : main 

main : $(OBJECTS)
	$(CC) $(FLAGS) -I$(INCDIR) -I$(LIBDIR) $(SRCDIR)/main.cpp $(OBJECTS) -o $(BINDIR)/main $(LIBS)

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(INCDIR)/Global.h
	$(CC) $(FLAGS) -I$(INCDIR) -I$(LIBDIR) -c $< -o $@ $(LIBS)

clean :
	rm -f $(OBJDIR)/* ;
	rm -f $(BINDIR)/* ;
	rm -f $(SRCDIR)/*~;
	rm -f $(INCDIR)/*~;
	rm -f *~

