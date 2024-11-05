EVENT=./Event
TIME=./Time
TIMING=./Timing
SCHEDULABLE=./Schedulable
PROFESSOR=./Professor
GROUP=./Group
CLASSROOM=./Classroom
EXCEPTION=./Exception
TIMEEXCEPTION=./TimeException

COMPIL=g++ -Wall -I $(EVENT) -I $(TIME) -I $(TIMING) -I $(SCHEDULABLE) -I $(PROFESSOR) -I $(GROUP) -I $(CLASSROOM) -I $(EXCEPTION) -I $(TIMEEXCEPTION)
OBJS=$(EVENT)/Event.o $(TIME)/Time.o $(TIMING)/Timing.o $(SCHEDULABLE)/Schedulable.o $(PROFESSOR)/Professor.o $(GROUP)/Group.o $(CLASSROOM)/Classroom.o $(EXCEPTION)/Exception.o $(TIMEEXCEPTION)/TimeException.o
EXEC=Test5
ECHO=echo Creation de

############################################################################################
############################################################################################

.SILENT:

Test5:	Test5.cpp $(TIME)/Time.o $(TIMING)/Timing.o $(EVENT)/Event.o $(SCHEDULABLE)/Schedulable.o $(PROFESSOR)/Professor.o $(GROUP)/Group.o $(CLASSROOM)/Classroom.o $(EXCEPTION)/Exception.o $(TIMEEXCEPTION)/TimeException.o
		$(ECHO) Test5
		$(COMPIL) Test5.cpp $(TIME)/Time.o $(TIMING)/Timing.o $(EVENT)/Event.o $(SCHEDULABLE)/Schedulable.o $(PROFESSOR)/Professor.o $(GROUP)/Group.o $(CLASSROOM)/Classroom.o $(EXCEPTION)/Exception.o $(TIMEEXCEPTION)/TimeException.o -o Test5

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

$(GROUP)/Group.o:	$(GROUP)/Group.cpp $(GROUP)/Group.h
					$(ECHO) Group.o
					$(COMPIL) $(GROUP)/Group.cpp -c -o $(GROUP)/Group.o

############################################################################################
############################################################################################

$(CLASSROOM)/Classroom.o:	$(CLASSROOM)/Classroom.cpp $(CLASSROOM)/Classroom.h
							$(ECHO) Classroom.o
							$(COMPIL) $(CLASSROOM)/Classroom.cpp -c -o $(CLASSROOM)/Classroom.o

############################################################################################
############################################################################################

$(EXCEPTION)/Exception.o:	$(EXCEPTION)/Exception.cpp $(EXCEPTION)/Exception.h
							$(ECHO) Exception.o
							$(COMPIL) $(EXCEPTION)/Exception.cpp -c -o $(EXCEPTION)/Exception.o

############################################################################################
############################################################################################

$(TIMEEXCEPTION)/TimeException.o:	$(TIMEEXCEPTION)/TimeException.cpp $(TIMEEXCEPTION)/TimeException.h
									$(ECHO) TimeException.o
									$(COMPIL) $(TIMEEXCEPTION)/TimeException.cpp -c -o $(TIMEEXCEPTION)/TimeException.o

clean:
	rm -f $(OBJS) core
	
clobber: clean
	rm -f $(EXEC)