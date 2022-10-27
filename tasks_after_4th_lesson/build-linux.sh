#!/bin/sh
# g++ -o out -I . -I ./utils *.cpp utils/*.cpp

g++ -o out -I . -I ./utils -I ./main-tasks -I ./main-tasks/enums *.cpp utils/*.cpp