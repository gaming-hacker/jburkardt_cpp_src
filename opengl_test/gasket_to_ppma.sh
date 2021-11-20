#! /bin/bash
#
g++ -c -Wall gasket_to_ppma.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#g++ gasket_to_ppma.o -framework GLUT -framework OpenGL
g++ gasket_to_ppma.o -lm -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm gasket_to_ppma.o
mv a.out ~/bincpp/gasket_to_ppma
#
echo "Normal end of execution."
