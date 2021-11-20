#! /bin/bash
#
$HOME/bincpp/fem2d_project_function > fem2d_project_function_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
