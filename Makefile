#################
MAKEFILE      = Makefile
RM            = rm -f
CP            = cp
CXX           = g++
LD            = $(CXX)
COMPFLAGS     = -I.
LDFLAGS       = 
DEPENDFLAGS   = -MM
LIBS          =
OBJDIR		  = ./obj
OTHER         =	-W -Wall


#################
TARGET    = turing.exe

OBJS = \
	main.o \
	run.o \
	ValidateArguments.o \
	TuringMachine.o \
	DataReaderTxt.o \
	DataReaderJson.o


#################
# Target Rules
#################
.SUFFIXES :
.SUFFIXES : .h .cpp .o
.cpp.o:
	@echo "------------------"
	$(RM) $*.o
#	$(CXX) $(DEPENDFLAGS) $<
	$(CXX) $(COMPFLAGS) $(OPT_LEVEL_FLAG) $(OTHER) -c $<

#################
all:	perfo

help:
	@echo "USAGE : "
	@echo "  TBD"

perfo: 		$(TARGET)

#################
$(TARGET):	$(OBJS) $(LIBS) $(MAKEFILE)
		@echo "=================="
		$(RM) $(TARGET)
		$(LD) -o $(TARGET) $(LDFLAGS) $(OBJS) $(LIBS)
		@echo " "


#################
cleano:	        
	$(RM) $(OBJS)
	$(RM) *.ii
	$(RM) *.s
	$(RM) *.o
	$(RM) core

cleane:
	$(RM) $(TARGET)
	$(RM) *.exe
	$(RM) *.exe*

clean:	cleano cleane

#################

main.o: main.cpp run.h 
run.o: run.cpp run.h ValidateArguments.h
ValidateArguments.o: ValidateArguments.cpp ValidateArguments.h
TuringMachine.o: TuringMachine.cpp TuringMachine.h
DataReaderTxt.o: DataReaderTxt.cpp DataReaderTxt.h json.hpp DataReaderInterface.h
DataReaderJson.o: DataReaderJson.cpp DataReaderJson.h json.hpp DataReaderInterface.h