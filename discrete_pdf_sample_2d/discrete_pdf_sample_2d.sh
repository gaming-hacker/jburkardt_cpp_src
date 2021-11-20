#! /bin/bash
#
g++ -c -Wall discrete_pdf_sample_2d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ discrete_pdf_sample_2d.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm discrete_pdf_sample_2d.o
#
mv a.out ~/bincpp/discrete_pdf_sample_2d
#
echo "Normal end of execution."
