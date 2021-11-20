#! /bin/bash
#
g++ -c -Wall -I/$HOME/include image_denoise_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ image_denoise_test.o /$HOME/libcpp/image_denoise.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm image_denoise_test.o
#
mv a.out image_denoise_test
./image_denoise_test > image_denoise_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm image_denoise_test
#
echo "Normal end of execution."
