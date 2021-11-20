#! /bin/bash
#
g++ -c -Wall -I/$HOME/include ccs_to_st_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ ccs_to_st_test.o /$HOME/libcpp/ccs_to_st.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ccs_to_st_test.o
#
mv a.out ccs_to_st_test
./ccs_to_st_test > ccs_to_st_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ccs_to_st_test
#
echo "Normal end of execution."
