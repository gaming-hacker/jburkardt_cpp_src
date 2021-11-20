#! /bin/bash
#
g++ -c -Wall mandelbrot_ppm.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ mandelbrot_ppm.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm mandelbrot_ppm.o
#
mv a.out ~/bincpp/mandelbrot_ppm
#
echo "Normal end of execution."
