CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		ThreadSafeResourceAccess.o
SRCS = 		ThreadSafeResourceAccess.cpp

INCLUDES=  
#-I/usr/lib64/
LIBS =		-lboost_thread -lboost_system
TARGET =	ThreadSafeResourceAccess

BINDIR =	bin
OBJDIR =	obj
SRCDIR =	src

$(BINDIR)/$(TARGET):	$(OBJDIR)/$(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(BINDIR)/$(TARGET) $(OBJDIR)/$(OBJS) $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$(SRCS) -o $@
    
all:	$(BINDIR)/$(TARGET)

clean:
	rm -f $(OBJDIR)/* $(BINDIR)/*