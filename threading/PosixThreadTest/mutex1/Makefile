CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -pthread

OBJS =		mutex1.o
SRCS = 		mutex1.cpp

LIBS =

TARGET =	mutex1

BINDIR =	bin
OBJDIR =	obj
SRCDIR =	src

$(BINDIR)/$(TARGET):	$(OBJDIR)/$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$(TARGET) $(OBJDIR)/$(OBJS) $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$(SRCS) -o $@
    
all:	$(BINDIR)/$(TARGET)

clean:
	rm -f $(OBJDIR)/$(OBJS) $(BINDIR)/$(TARGET)
