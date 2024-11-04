EVENT=./Event
TIME=./Time
TIMING=./Timing
COMPIL=g++ -Wall -I $(EVENT) -I $(TIME) -I $(TIMING)
OBJS=$(EVENT)/Event.o $(TIME)/Time.o $(TIMING)/Timing.o
EXEC=Test3
ECHO=echo Creation de

.SILENT:

Test3:	Test3.cpp $(TIME)/Time.o $(TIMING)/Timing.o $(EVENT)/Event.o
		$(ECHO) Test3
		$(COMPIL) Test3.cpp $(TIME)/Time.o $(TIMING)/Timing.o $(EVENT)/Event.o -o Test3

$(TIME)/Time.o:	$(TIME)/Time.cpp $(TIME)/Time.h
				$(ECHO) Time.o 
				$(COMPIL) $(TIME)/Time.cpp -c -o $(TIME)/Time.o

$(TIMING)/Timing.o: $(TIMING)/Timing.cpp $(TIMING)/Timing.h
					$(ECHO) Timing.o
					$(COMPIL) $(TIMING)/Timing.cpp -c -o $(TIMING)/Timing.o

$(EVENT)/Event.o: 	$(EVENT)/Event.cpp $(EVENT)/Event.h
					$(ECHO) Event.o
					$(COMPIL) $(EVENT)/Event.cpp -c -o $(EVENT)/Event.o

clean:
	rm -f $(OBJS) core
	
clobber: clean
	rm -f $(EXEC)