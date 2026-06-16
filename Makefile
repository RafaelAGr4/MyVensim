func:
	g++ -Wall -Wextra src/*.cpp test/funcional/*.cpp -o bin/funcional_tests.exe
	./bin/funcional_tests.exe

unit:
	g++ -Wall -Wextra src/*.cpp test/unit/*.cpp -o bin/unit_tests.exe
	./bin/unit_tests.exe