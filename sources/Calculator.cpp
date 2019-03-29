////////////JACQUES///////////////////////
void Calculator::appendPile(string calcul){
	this->operandes.push(calcul);
}

void Calculator::flushPile(){
	while(!(this->operandes.empty())){
		this->operandes.pop();
	}
}
//////////////////////////////////////////
