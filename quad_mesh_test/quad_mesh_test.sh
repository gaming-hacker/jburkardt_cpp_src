#! /bin/bash
#
g++ -c -Wall -I/$HOME/include quad_mesh_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ quad_mesh_test.o /$HOME/libcpp/quad_mesh.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm quad_mesh_test.o
#
mv a.out quad_mesh_test
./quad_mesh_test > quad_mesh_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quad_mesh_test
#
#  Convert graphics.
#
gs -dSAFER -dBATCH -dNOPAUSE -dEPSCrop -r300 -sDEVICE=png16 -sOutputFile=q4_mesh_ex1.png q4_mesh_ex1.eps
gs -dSAFER -dBATCH -dNOPAUSE -dEPSCrop -r300 -sDEVICE=png16 -sOutputFile=q4_mesh_ex2.png q4_mesh_ex2.eps
#
echo "Normal end of execution."
