#! /bin/bash
#
g++ -c -Wall predator_plot3d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ predator_plot3d.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm predator_plot3d.o
#
mv a.out predator_plot3d
./predator_plot3d > predator_plot3d.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm predator_plot3d
#
#  Call gnuplot.
#
gnuplot < predator_commands.txt
#
echo "Normal end of execution."
