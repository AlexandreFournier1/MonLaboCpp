EVENT=./Event
TIME=./Time
TIMING=./Timing
COMPIL=g++ -Wall -I $(EVENT) -I $(TIME) -I $(TIMING)
OBJS=$(EVENT)/Event.o $(TIME)/Time.o $(TIMING)/Timing.o
EXEC=Test2

Test2:	Test2.cpp $(TIME)/Time.o $(TIMING)/Timing.o $(EVENT)/Event.o
		$(COMPIL) Test2.cpp $(TIME)/Time.o $(TIMING)/Timing.o $(EVENT)/Event.o -o Test2

$(TIME)/Time.o:	$(TIME)/Time.cpp $(TIME)/Time.h
				$(COMPIL) $(TIME)/Time.cpp -c -o $(TIME)/Time.o

$(TIMING)/Timing.o: $(TIMING)/Timing.cpp $(TIMING)/Timing.h
					$(COMPIL) $(TIMING)/Timing.cpp -c -o $(TIMING)/Timing.o

$(EVENT)/Event.o: 	$(EVENT)/Event.cpp $(EVENT)/Event.h
					$(COMPIL) $(EVENT)/Event.cpp -c -o $(EVENT)/Event.o

clean:
	rm -f $(OBJS) core
	
clobber: clean
	rm -f $(EXEC)