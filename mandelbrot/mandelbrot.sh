#! /bin/bash
#
g++ -c -Wall mandelbrot.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ mandelbrot.o
if [ $? -ne 0 ]; then
  echo "Errors linking and loading mandelbrot.o"
  exit
fi
rm mandelbrot.o
#
mv a.out ~/bincpp/mandelbrot
#
echo "Normal end of execution."
