#! /bin/bash
#
cp ccs_to_st.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include ccs_to_st.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ccs_to_st.o ~/libcpp/ccs_to_st.o
#
echo "Normal end of execution."
