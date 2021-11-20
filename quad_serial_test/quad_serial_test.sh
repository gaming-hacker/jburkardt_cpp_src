#! /bin/bash
#
$HOME/bincpp/quad_serial > quad_serial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
