#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
CFLAGS = -w -std=c++11

#LINKER_FLAGS specifies the libraries we're linking against
LFLAGS = -lGLEW -lglfw -lGL -lX11 -lpthread -lXrandr -lXi

SRCS = shader.cpp
OBJS = main.cpp shader.o 

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = hello

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(CFLAGS) -o $(OBJ_NAME) $(OBJS) $(LFLAGS)
	\rm *.o

shader.o : shader.h
	$(CC) $(CFLAGS) $(LFLAGS) -c shader.cpp
