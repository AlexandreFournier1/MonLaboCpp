CLASSES=./Classes
OBJETS=./Objets

COMPIL=g++ -Wall -I $(CLASSES) -I $(OBJETS)
FICHIERS_OBJS=$(OBJETS)/Event.o $(OBJETS)/Time.o $(OBJETS)/Timing.o
EXEC=Test3
ECHO=echo Creation de

############################################################################################
############################################################################################

.SILENT:

Test3:	Test3.cpp $(OBJETS)/Time.o $(OBJETS)/Timing.o $(OBJETS)/Event.o
		$(ECHO) Test3
		$(COMPIL) Test3.cpp $(FICHIERS_OBJS) -o Test3

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

clean:
	rm -f $(FICHIERS_OBJS) core
	
clobber: clean
	rm -f $(EXEC)