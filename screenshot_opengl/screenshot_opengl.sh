#! /bin/bash
#
g++ -c -Wall screenshot_opengl.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  Here is the load statement for Apple's OS X.
#
#g++ screenshot.o -lm -framework GLUT -framework OpenGL
#
#  Here is the load statement for a normal UNIX system!
#
g++ screenshot_opengl.o -lm -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm screenshot_opengl.o
mv a.out ~/bincpp/screenshot_opengl
#
echo "Normal end of execution."
