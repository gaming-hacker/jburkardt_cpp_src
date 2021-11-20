#! /bin/bash
#
g++ -c -Wall -I/$HOME/include stochastic_diffusion_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ stochastic_diffusion_test.o /$HOME/libcpp/stochastic_diffusion.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm stochastic_diffusion_test.o
#
mv a.out stochastic_diffusion_test
./stochastic_diffusion_test > stochastic_diffusion_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm stochastic_diffusion_test
#
echo "Normal end of execution."
