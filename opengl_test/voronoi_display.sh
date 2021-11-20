#! /bin/bash
#
g++ -c -Wall voronoi_display.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  Here is the load statement for Apple's OS X.
#
#g++ voronoi_display.o -lm -framework GLUT -framework OpenGL
#
#  Here is the load statement for a normal UNIX system!
#
g++ voronoi_display.o -lm -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm voronoi_display.o
mv a.out ~/bincpp/voronoi_display
#
echo "Normal end of execution."
