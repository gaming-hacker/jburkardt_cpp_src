#! /bin/bash
#
$HOME/bincpp/fem1d_project < input > fem1d_project_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
