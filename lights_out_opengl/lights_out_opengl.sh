#! /bin/bash
#
g++ -c -Wall lights_out_opengl.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#g++ lights_out_opengl.o -framework OpenGL -framework GLUT
#
g++ lights_out_opengl.o -lm -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm lights_out_opengl.o
mv a.out ~/bincpp/lights_out_opengl
#
echo "Normal end of execution."
