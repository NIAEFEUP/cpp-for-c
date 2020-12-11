.PHONY: all clean
all: build/vector-c build/vector-cpp-class build/vector-cpp-template \
	build/vector-cpp-std build/shopping-cart build/shopping-cart-solution

build:
	mkdir build

build/vector-c:	build vector-c/main.c vector-c/vector.c vector-c/vector.h
	gcc -o build/vector-c vector-c/main.c vector-c/vector.c

build/vector-cpp-class: build vector-cpp-class/main.cpp vector-cpp-class/vector.h \
						vector-cpp-class/vector.cpp
	g++ -o build/vector-cpp-class vector-cpp-class/main.cpp vector-cpp-class/vector.cpp

build/vector-cpp-template: build vector-cpp-template/main.cpp vector-cpp-template/vector.h
	g++ -o build/vector-cpp-template vector-cpp-template/main.cpp

build/vector-cpp-std: build vector-std.cpp
	g++ -o build/vector-cpp-std vector-std.cpp

build/shopping-cart:	build shopping-cart/main.cpp shopping-cart/shopping-cart.h \
						shopping-cart/shopping-cart.cpp
	c++ -o build/shopping-cart shopping-cart/main.cpp shopping-cart/shopping-cart.cpp

build/shopping-cart-solution:	build shopping-cart-solution/main.cpp \
								shopping-cart-solution/shopping-cart.h \
								shopping-cart-solution/shopping-cart.cpp
	c++ -o build/shopping-cart-solution shopping-cart-solution/main.cpp \
		shopping-cart-solution/shopping-cart.cpp

clean:
	rm -rf build
