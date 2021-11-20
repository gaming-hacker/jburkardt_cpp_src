#! /bin/bash
#
g++ -c -Wall gasket_points_3d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#g++ gasket_points_3d.o -framework GLUT -framework OpenGL
g++ gasket_points_3d.o -lm -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm gasket_points_3d.o
mv a.out ~/bincpp/gasket_points_3d
#
echo "Normal end of execution."
