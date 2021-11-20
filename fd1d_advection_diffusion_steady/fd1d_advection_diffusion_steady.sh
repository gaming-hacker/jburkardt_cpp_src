#! /bin/bash
#
g++ -c -Wall fd1d_advection_diffusion_steady.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fd1d_advection_diffusion_steady.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fd1d_advection_diffusion_steady.o
mv a.out ~/bincpp/fd1d_advection_diffusion_steady
#
echo "Normal end of execution."
