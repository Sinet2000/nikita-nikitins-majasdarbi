
@REM g++ -o out -I . -I ./main-tasks -I ./main-tasks/enums -I ./additional-tasks additional-tasks/*.cpp -I ./utils *.cpp utils/*.cpp
g++ -o out -I . -I ./main-tasks -I ./utils -I ./utils/enums -I ./additional-tasks  *.cpp utils/*.cpp