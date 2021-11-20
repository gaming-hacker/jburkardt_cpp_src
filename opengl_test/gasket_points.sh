#! /bin/bash
#
g++ -c -Wall gasket_points.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  Here is the load statement for Apple's OS X.
#
#g++ gasket_points.o -lm -framework GLUT -framework OpenGL
#
#  Here is the load statement for a normal UNIX system!
#
g++ gasket_points.o -lm -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm gasket_points.o
mv a.out ~/bincpp/gasket_points
#
echo "Normal end of execution."
