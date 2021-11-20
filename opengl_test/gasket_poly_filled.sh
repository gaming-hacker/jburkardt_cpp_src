#! /bin/bash
#
g++ -c -Wall gasket_poly_filled.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#g++ gasket_poly_filled.o -framework GLUT -framework OpenGL
g++ gasket_poly_filled.o -lm -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm gasket_poly_filled.o
mv a.out ~/bincpp/gasket_poly_filled
#
echo "Normal end of execution."
