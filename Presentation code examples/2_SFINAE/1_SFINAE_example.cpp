#include <utility>
#include <iostream>

template<class T>
std::enable_if_t<std::is_same_v<T,int>, void> foo(const T&) {
	std::cout<<"I'm foo(int)\n";
}

template<class T>
std::enable_if_t<std::is_same_v<T,char>, void> foo(const T&) {
	std::cout<<"I'm foo(char)\n";
}

int main() {
	foo(5); 	//I'm foo(int)
	foo('x'); 	//I'm foo(char)
}
