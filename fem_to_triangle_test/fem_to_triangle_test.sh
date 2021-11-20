#! /bin/bash
#
$HOME/bincpp/fem_to_triangle < input.txt > fem_to_triangle_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
