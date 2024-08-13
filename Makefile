all:
	mkdir bin
	g++ ./src/main.cpp --std=c++20 -Iinclude -o ./bin/main.exe

run:
	./bin/main.exe

clean:
	rm ./bin/main.exe