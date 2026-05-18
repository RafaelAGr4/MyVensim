all:
	g++ -Wall -Wextra -std=c++11 test/funcional/main.cpp test/funcional/funcional_tests.cpp src/mySim.cpp -o bin/funcional_tests.exe
	bin\funcional_tests.exe
