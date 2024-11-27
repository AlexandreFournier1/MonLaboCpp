CLASSES=./Classes
OBJETS=./Objets

COMPIL=g++ -Wall -I $(CLASSES) -I $(OBJETS)
FICHIERS_OBJS=$(OBJETS)/Event.o \
			$(OBJETS)/Time.o \
			$(OBJETS)/Timing.o \
			$(OBJETS)/Schedulable.o \
			$(OBJETS)/Professor.o \
			$(OBJETS)/Group.o \
			$(OBJETS)/Classroom.o \
			$(OBJETS)/Exception.o \
			$(OBJETS)/TimeException.o \
			$(OBJETS)/TimingException.o
EXEC=Test5
ECHO=echo Creation de

############################################################################################
############################################################################################

.SILENT:

Test5:	Test5.cpp $(FICHIERS_OBJS)
		$(ECHO) Test5
		$(COMPIL) Test5.cpp $(FICHIERS_OBJS) -o Test5

############################################################################################
############################################################################################

$(OBJETS)/Time.o:	$(CLASSES)/Time.cpp $(CLASSES)/Time.h
					$(ECHO) Time.o 
					$(COMPIL) $(CLASSES)/Time.cpp -c -o $(OBJETS)/Time.o

############################################################################################
############################################################################################

$(OBJETS)/Timing.o: $(CLASSES)/Timing.cpp $(CLASSES)/Timing.h
					$(ECHO) Timing.o
					$(COMPIL) $(CLASSES)/Timing.cpp -c -o $(OBJETS)/Timing.o

############################################################################################
############################################################################################

$(OBJETS)/Event.o: 	$(CLASSES)/Event.cpp $(CLASSES)/Event.h
					$(ECHO) Event.o
					$(COMPIL) $(CLASSES)/Event.cpp -c -o $(OBJETS)/Event.o

############################################################################################
############################################################################################

$(OBJETS)/Schedulable.o:	$(CLASSES)/Schedulable.cpp $(CLASSES)/Schedulable.h
							$(ECHO) Schedulable.o
							$(COMPIL) $(CLASSES)/Schedulable.cpp -c -o $(OBJETS)/Schedulable.o

############################################################################################
############################################################################################

$(OBJETS)/Professor.o:	$(CLASSES)/Professor.cpp $(CLASSES)/Professor.h
						$(ECHO) Professor.o
						$(COMPIL) $(CLASSES)/Professor.cpp -c -o $(OBJETS)/Professor.o 

############################################################################################
############################################################################################

$(OBJETS)/Group.o:	$(CLASSES)/Group.cpp $(CLASSES)/Group.h
					$(ECHO) Group.o
					$(COMPIL) $(CLASSES)/Group.cpp -c -o $(OBJETS)/Group.o

############################################################################################
############################################################################################

$(OBJETS)/Classroom.o:	$(CLASSES)/Classroom.cpp $(CLASSES)/Classroom.h
						$(ECHO) Classroom.o
						$(COMPIL) $(CLASSES)/Classroom.cpp -c -o $(OBJETS)/Classroom.o

############################################################################################
############################################################################################

$(OBJETS)/Exception.o:	$(CLASSES)/Exception.cpp $(CLASSES)/Exception.h
						$(ECHO) Exception.o
						$(COMPIL) $(CLASSES)/Exception.cpp -c -o $(OBJETS)/Exception.o

############################################################################################
############################################################################################

$(OBJETS)/TimeException.o:	$(CLASSES)/TimeException.cpp $(CLASSES)/TimeException.h
							$(ECHO) TimeException.o
							$(COMPIL) $(CLASSES)/TimeException.cpp -c -o $(OBJETS)/TimeException.o

############################################################################################
############################################################################################

$(OBJETS)/TimingException.o:	$(CLASSES)/TimingException.cpp $(CLASSES)/TimingException.h
								$(ECHO) TimingException.o
								$(COMPIL) $(CLASSES)/TimingException.cpp -c -o $(OBJETS)/TimingException.o

clean:
	rm -f $(FICHIERS_OBJS) core
	
clobber: clean
	rm -f $(EXEC)