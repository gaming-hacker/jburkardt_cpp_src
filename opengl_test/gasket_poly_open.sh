#! /bin/bash
#
g++ -c -Wall gasket_poly_open.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  Commands for the awful Mac OSX system:
#
#g++ gasket_poly_open.o -framework GLUT -framework OpenGL
#
#  Commands for normal systems.
#
g++ gasket_poly_open.o -lm -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm gasket_poly_open.o
mv a.out ~/bincpp/gasket_poly_open
#
echo "Normal end of execution."
