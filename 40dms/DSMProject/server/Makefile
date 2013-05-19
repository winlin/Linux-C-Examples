HEADERS=dmsserver.h  clientaccepter.h  dmsdao.h idao.h dmsexception.h clientrecver.h
SOURCES=dmsserver.cpp  clientaccepter.cpp  dmsdao.cpp clientrecver.cpp
LIB=-lpthread 
dmsserver:$(SOURCES) $(HEADERS)
	@g++ $(SOURCES) $(LIB) -o dmsserver

clean:
	@rm -f *.o *.gch   dmsserver
