#! /bin/bash
#
g++ -c -Wall turtle.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#g++ turtle.o -framework GLUT -framework OpenGL
g++ turtle.o -lm -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm turtle.o
mv a.out ~/bincpp/turtle
#
echo "Normal end of execution."
