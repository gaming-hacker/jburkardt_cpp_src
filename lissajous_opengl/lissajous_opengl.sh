#! /bin/bash
#
g++ -c -Wall lissajous_opengl.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  Here is the load statement for Apple's OS X.
#
#g++ lissajous_opengl.o -lm -framework GLUT -framework OpenGL
#
#  Here is the load statement for a normal UNIX system!
#
g++ lissajous_opengl.o -lm -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm lissajous_opengl.o
mv a.out ~/bincpp/lissajous_opengl
#
echo "Normal end of execution."
