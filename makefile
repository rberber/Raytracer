#Makefile for Ray Tracer

OBJS= ray.o light.o plane.o sphere.o vector.o object.o
CC= g++
CFLAGS= -lm

ray: ${OBJS}
	$(CC) -o ray $(OBJS) $(CFLAGS)

clean:
	rm -rf ray $(OBJS)
