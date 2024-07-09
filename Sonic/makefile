CC = gcc
CFLAG = -Wall
TARGET = us
OBJS = us1.o us2.o us3.o song.o
LIBS = wiringPi

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -l$(LIBS)

us1.o : Usonic.c
	gcc -c -o us1.o Usonic.c

us2.o : Us.c
	gcc -c -o us2.o Us.c

us3.o : Trig.c
	gcc -c -o us3.o Trig.c 

d :
	rm -f *.o

song.o : song.c
	gcc -c -o song.o song.c

