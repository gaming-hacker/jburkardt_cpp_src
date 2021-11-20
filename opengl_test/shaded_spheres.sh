#! /bin/bash
#
g++ -c -Wall shaded_spheres.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#g++ shaded_spheres.o -framework GLUT -framework OpenGL
g++ shaded_spheres.o -lm -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm shaded_spheres.o
mv a.out ~/bincpp/shaded_spheres
#
echo "Normal end of execution."
