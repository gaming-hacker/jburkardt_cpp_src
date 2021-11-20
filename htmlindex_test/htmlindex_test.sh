#! /bin/bash
#
$HOME/bincpp/htmlindex walsh.cpp > walsh.html
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
