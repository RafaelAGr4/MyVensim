all:
	g++ -Wall -Wextra src/*.cpp test/funcional/*.cpp -o bin/funcional_tests.exe
	bin\funcional_tests.exe
