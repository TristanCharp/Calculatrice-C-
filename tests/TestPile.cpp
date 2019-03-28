#define CATCH_CONFIG_MAIN
#include "../headers/catch.hpp"

#include "../headers/Pile.hpp"
#include <string>


#include <iostream>



TEST_CASE( "Pile", "Everything" ){
	Pile pStack;

	pStack.push("1");
	CHECK(pStack.top() == "1");
	pStack.push("2");
	CHECK(pStack.top() == "2");
	CHECK(pStack.size() == 2);
	CHECK(pStack.empty() == false);
	pStack.pop();
	CHECK(pStack.top() == "1");
	pStack.pop();
	CHECK(pStack.empty() == true);

}