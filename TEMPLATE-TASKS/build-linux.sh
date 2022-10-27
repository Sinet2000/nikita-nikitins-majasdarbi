#!/bin/sh
# g++ -o out -I . -I ./utils *.cpp utils/*.cpp

g++ -o out -I . -I ./main-tasks -I ./main-tasks/enums -I ./additional-tasks -I ./utils *.cpp utils/*.cpp