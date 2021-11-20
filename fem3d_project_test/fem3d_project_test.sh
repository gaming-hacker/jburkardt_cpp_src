#! /bin/bash
#
$HOME/bincpp/fem3d_project r8x8x8_t4 r4x4x4_t4 > fem3d_project_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
