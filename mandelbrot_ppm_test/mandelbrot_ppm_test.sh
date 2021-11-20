#! /bin/bash
#
$HOME/bincpp/mandelbrot_ppm > mandelbrot_ppm_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
