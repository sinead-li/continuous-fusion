CC = g++
CFLAGS = -g -Wall
OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)
.RECIPEPREFIX +=
SOURCEDIR = src/
BUILDDIR = build/

main: main.o kittireader.o calibration.o
    $(CC) $(CFLAGS) -o main main.o kittireader.o calibration.o $(LIBS)

catchmain:
    $(CC) $(CFLAGS) catchmain.cpp -c

catchtests:
    $(CC) $(CFLAGS) -o tests catchmain.o iotests.cpp calibration.cpp kittireader.cpp $(LIBS)

clean:
   -rm -f build/main build/*.o