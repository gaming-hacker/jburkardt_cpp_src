#! /bin/bash
#
g++ -c -Wall life_opengl.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#g++ life_opengl.o -framework OpenGL -framework GLUT
#
g++ life_opengl.o -lm -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm life_opengl.o
mv a.out ~/bincpp/life_opengl
#
echo "Normal end of execution."
