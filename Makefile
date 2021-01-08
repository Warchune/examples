.PHONY: build test install uninstall clean

build:
	mkdir -p build
	touch ./build/examples.txt
	gcc -Wall -o ./build/Creating_examples main.c

test:
	./build/Creating_examples

install: build
	cp ./build/Creating_examples /usr/bin/Creating_examples

uninstall: build
	rm -f  /usr/bin/Creating_examples

clean:
	rm -Rf ./build/*