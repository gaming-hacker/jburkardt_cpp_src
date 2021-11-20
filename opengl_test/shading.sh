#! /bin/bash
#
g++ -c -Wall shading.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#g++ shading.o -framework GLUT -framework OpenGL
g++ shading.o -lm -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm shading.o
mv a.out ~/bincpp/shading
#
echo "Normal end of execution."
