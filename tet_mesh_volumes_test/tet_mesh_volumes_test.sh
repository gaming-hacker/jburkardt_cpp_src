#! /bin/bash
#
$HOME/bincpp/tet_mesh_volumes cube > tet_mesh_volumes_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
$HOME/bincpp/tet_mesh_volumes twenty >> tet_mesh_volumes_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
