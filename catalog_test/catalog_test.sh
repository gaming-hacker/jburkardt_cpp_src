#! /bin/bash
#
$HOME/bin/catalog ../catalog/catalog.cpp > catalog_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
