#! /bin/bash
#
$HOME/bincpp/tet_mesh_refine cube > tet_mesh_refine_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
