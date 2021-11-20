#! /bin/bash
#
$HOME/bincpp/tet_mesh_boundary p04 > p04_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
$HOME/bincpp/tet_mesh_boundary cube > cube_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
