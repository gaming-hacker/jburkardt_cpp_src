#! /bin/bash
#
g++ -c -Wall tet_mesh_display_opengl.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  Here is the load statement for Apple's OS X.
#
#g++ tet_mesh_display_opengl.o -lm -framework GLUT -framework OpenGL
#
#  Here is the load statement for a normal UNIX system!
#
g++ tet_mesh_display_opengl.o -lm -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm tet_mesh_display_opengl.o
mv a.out ~/bincpp/tet_mesh_display_opengl
#
echo "Normal end of execution."
