#include "../headers/Pile.hpp"

Pile::Pile(){}

void Pile::pop(){
	sPile.pop();
}

void Pile::push(string value){
	sPile.push(value);
}
 
string Pile::top(){
	return sPile.top();
}

size_t Pile::size(){
	return sPile.size();
}

bool Pile::empty(){
	return sPile.empty();
}