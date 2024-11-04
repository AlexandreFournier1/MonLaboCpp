EVENT=./Event
TIME=./Time
TIMING=./Timing
SCHEDULABLE=./Schedulable
PROFESSOR=./Professor

COMPIL=g++ -Wall -I $(EVENT) -I $(TIME) -I $(TIMING) -I $(SCHEDULABLE) -I $(PROFESSOR)
OBJS=$(EVENT)/Event.o $(TIME)/Time.o $(TIMING)/Timing.o $(SCHEDULABLE)/Schedulable.o $(PROFESSOR)/Professor.o
EXEC=Test4
ECHO=echo Creation de

############################################################################################
############################################################################################

.SILENT:

Test4:	Test4.cpp $(TIME)/Time.o $(TIMING)/Timing.o $(EVENT)/Event.o $(SCHEDULABLE)/Schedulable.o $(PROFESSOR)/Professor.o
		$(ECHO) Test4
		$(COMPIL) Test4.cpp $(TIME)/Time.o $(TIMING)/Timing.o $(EVENT)/Event.o $(SCHEDULABLE)/Schedulable.o $(PROFESSOR)/Professor.o -o Test4

############################################################################################
############################################################################################

$(TIME)/Time.o:	$(TIME)/Time.cpp $(TIME)/Time.h
				$(ECHO) Time.o 
				$(COMPIL) $(TIME)/Time.cpp -c -o $(TIME)/Time.o

############################################################################################
############################################################################################

$(TIMING)/Timing.o: $(TIMING)/Timing.cpp $(TIMING)/Timing.h
					$(ECHO) Timing.o
					$(COMPIL) $(TIMING)/Timing.cpp -c -o $(TIMING)/Timing.o

############################################################################################
############################################################################################

$(EVENT)/Event.o: 	$(EVENT)/Event.cpp $(EVENT)/Event.h
					$(ECHO) Event.o
					$(COMPIL) $(EVENT)/Event.cpp -c -o $(EVENT)/Event.o

############################################################################################
############################################################################################

$(SCHEDULABLE)/Schedulable.o:	$(SCHEDULABLE)/Schedulable.cpp $(SCHEDULABLE)/Schedulable.h
								$(ECHO) Schedulable.o
								$(COMPIL) $(SCHEDULABLE)/Schedulable.cpp -c -o $(SCHEDULABLE)/Schedulable.o

############################################################################################
############################################################################################

$(PROFESSOR)/Professor.o:	$(PROFESSOR)/Professor.cpp $(PROFESSOR)/Professor.h
							$(ECHO) Professor.o
							$(COMPIL) $(PROFESSOR)/Professor.cpp -c -o $(PROFESSOR)/Professor.o 

############################################################################################
############################################################################################

clean:
	rm -f $(OBJS) core
	
clobber: clean
	rm -f $(EXEC)