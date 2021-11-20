#! /bin/bash
#
cp r8st.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include r8st.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r8st.o ~/libcpp/r8st.o
#
echo "Normal end of execution."
