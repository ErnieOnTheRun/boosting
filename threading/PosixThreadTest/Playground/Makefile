CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -pthread

OBJS =		Playground1.o
SRCS = 		Playground1.cpp

LIBS =
TARGET =	Playground1

BINDIR =	bin
OBJDIR =	obj
SRCDIR =	src

$(BINDIR)/$(TARGET):	$(OBJDIR)/$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$(TARGET) $(OBJDIR)/$(OBJS) $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$(SRCS) -o $@
    
all:	$(BINDIR)/$(TARGET)

clean:
	rm -f $(OBJDIR)/* $(BINDIR)/*