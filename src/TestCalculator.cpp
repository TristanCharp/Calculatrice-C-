#define CATCH_CONFIG_MAIN
#include "../headers/catch.hpp"

#include "../headers/calculator.hpp"


#include <iostream>



TEST_CASE( "Calculator", "Plus" ){
	Calculator calculator;
	calculator.appendPile("2.0");
	calculator.appendPile("3.0");
	calculator.appendPile("+");

	CHECK(calculator.calcule() == "5.000000");

}

TEST_CASE( "Calculator2", "Moins" ){
	Calculator calculator;
	calculator.appendPile("3.0");
	calculator.appendPile("2.0");
	calculator.appendPile("-");
	
	CHECK(calculator.calcule() == "1.000000");

}

TEST_CASE( "Calculator3", "Multiplier" ){
	Calculator calculator;
	calculator.appendPile("2.0");
	calculator.appendPile("3.0");
	calculator.appendPile("*");
	
	CHECK(calculator.calcule() == "6.000000");

}

TEST_CASE( "Calculator4", "Diviser" ){
	Calculator calculator;
	calculator.appendPile("4.0");
	calculator.appendPile("2.0");
	calculator.appendPile("/");
	
	CHECK(calculator.calcule() == "2.000000");

}