CC = g++
CFLAGS = -std=c++11
OBJDIR = target/obj
TARGET = target/ABB

all::	$(TARGET);

$(TARGET): $(OBJDIR)/main.o $(OBJDIR)/ABB.o $(OBJDIR)/NodoBB.o $(OBJDIR)/DNI.o $(OBJDIR)/Colision.o
	$(CC) $^ -o $@ $(CFLAGS)

$(OBJDIR)/ABB.o:	entities/ABB/ABB.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/Colision.o:	entities/Colision/Colision.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/NodoBB.o:	entities/NodoBB/NodoBB.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/DNI.o:	entities/DNI/DNI.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/main.o: main/main.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm $(TARGET) $(OBJDIR)/*;


# CC = g++
# CFLAGS = -std=c++11
# TARGET = target/Langston
# OBJPATH = target/obj
# ENTPATH = entities
#
# all::	$(TARGET);
#
# $(TARGET): $(OBJPATH)/Hormiga.o $(OBJPATH)/Maquina.o $(OBJPATH)/Rejilla.o $(OBJPATH)/main.o
# 	$(CC) $^ -o $@ $(CFLAGS)
#
# $(OBJPATH)/%.o:	$(ENTPATH)/%/%.cpp
# 	$(CC) -c -o $@ $< $(CFLAGS)
#
# $(OBJPATH)/main.o: main/main.cpp
# 	$(CC) -c -o $@ $< $(CFLAGS)
#
# clean:
# 	rm $(TARGET) $(OBJPATH)/*;
