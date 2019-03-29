#include "../headers/calculator.hpp"
#include <vector> 
float resultat;
	vector<string> operators;
	vector <float> chiffres;
	
Calculator::Calculator(string calcul){
	this->calcul=calcul;
	this->calc_postfix=new list<string>;
	if(this->bad_input()){
		this->calc_to_postfix();
		/*list<string> cp_calc_postfix=*calc_postfix;
		while(!cp_calc_postfix.empty()){
			cout << cp_calc_postfix.front() << endl;
			cp_calc_postfix.pop_front();
		}
		cout << endl;
		*/
		this->postfix_eval();
		this->erase_zero();
	}
	else{
		this->result="Synthaxe Error";
	}

}

Calculator::Calculator(){
	
}


////////  A C C E S S E U R  /////////////////////////////
string Calculator::getCalcul(){
	return this->calcul;
}

string Calculator::getResult(){
	return this->result;
}
//////////////////////////////////////////////////////////

float Calculator::moinss(int i, bool isFirts){
    cout << "moins" << endl;
    if(i > 0){
        if(operators[i-1] == "+"){
           if(isFirts){
                return chiffres[i + 1] - pluss(i - 1, false);
            }else{
                return chiffres[i + 1] - pluss(i - 1, false);
            } 
        }else if(operators[i-1] == "-"){
            if(isFirts){
                return chiffres[i + 1] - moinss(i - 1, false) ;
            }else{
                return chiffres[i + 1] - moinss(i - 1, false);
            }
        }else if(operators[i-1] == "*"){
            if(isFirts){
                return chiffres[i + 1] - mult(i - 1, false) ;
            }else{
                return chiffres[i + 1] - mult(i - 1, false);
            }   
        }else if(operators[i-1] == "/"){
            if(isFirts){
                return chiffres[i + 1] - divi(i - 1, false) ;
            }else{
                
                return chiffres[i + 1] - divi(i - 1, false);
            }
        }
    }
    else{
       return chiffres[i+1] - chiffres[i];
    }
}

float Calculator::divi(int i, bool isFirts){
    cout << "Divi" << endl;
    if(i > 0){
        if(operators[i-1] == "+"){
           if(isFirts){
                return chiffres[i + 1] / pluss(i - 1, false);
            }else{
                return chiffres[i + 1] / pluss(i - 1, false);
            } 
        }else if(operators[i-1] == "-"){
            if(isFirts){
                return chiffres[i + 1] / moinss(i - 1, false) ;
            }else{
                return chiffres[i + 1] / moinss(i - 1, false);
            }
        }else if(operators[i-1] == "*"){
            if(isFirts){
                return chiffres[i + 1] / mult(i - 1, false);
            }else{
                return chiffres[i + 1] / mult(i - 1, false);
            }   
        }else if(operators[i-1] == "/"){
            if(isFirts){
                return chiffres[i + 1] / divi(i - 1, false) ;
            }else{
                return chiffres[i + 1] / divi(i - 1, false);
            }
        }
    }
    else{
       return chiffres[i+1] / chiffres[i];
    }
}

float Calculator::mult(int i, bool isFirts){
    cout << "multi" << endl;
    if(i > 0){
        if(operators[i-1] == "+"){
           if(isFirts){
                return chiffres[i + 1] * pluss(i - 1, false);
            }else{
                return chiffres[i + 1] * pluss(i - 1, false);
            } 
        }else if(operators[i-1] == "-"){
            if(isFirts){
                return chiffres[i + 1] * moinss(i - 1, false);
            }else{
                return chiffres[i + 1] * moinss(i - 1, false);
            }
        }else if(operators[i-1] == "*"){
            if(isFirts){
                return chiffres[i + 1] * mult(i - 1, false);
            }else{
                return chiffres[i + 1] * mult(i - 1, false);
            }   
        }else if(operators[i-1] == "/"){
            if(isFirts){
                return chiffres[i + 1] * divi(i - 1, false);
            }else{
                return chiffres[i + 1] * divi(i - 1, false);
            }
        }
    }
    else{
       return chiffres[i+1] * chiffres[i];
    }
}

float Calculator::pluss(int i, bool isFirts){
    cout << "plus i :" << i << "plus : isfirst" << isFirts << endl;
    if(i > 0){
        if(operators[i-1] == "+"){
           if(isFirts){
                return chiffres[i + 1] + pluss(i - 1, false);
            }else{
                return chiffres[i + 1] + pluss(i - 1, false);
            } 
        }else if(operators[i-1] == "-"){
            if(isFirts){
                return chiffres[i + 1] + moinss(i - 1, false);
            }else{
                return chiffres[i + 1] + moinss(i - 1, false);
            }
        }else if(operators[i-1] == "*"){
            if(isFirts){
                return chiffres[i + 1] + mult(i - 1, false);
            }else{
                return chiffres[i + 1] + mult(i - 1, false);
            }   
        }else if(operators[i-1] == "/"){
            if(isFirts){
                return chiffres[i + 1] + divi(i - 1, false);
            }else{
                return chiffres[i + 1] + divi(i - 1, false);
            }
        }
    }
    else{
		cout << "res : " << chiffres.size() << endl;
        return chiffres[i+1] + chiffres[i];
    }
}

bool Calculator::isOperator(string buffer)
{
	if(buffer.compare("*") == 0
	   || buffer.compare("+") == 0
	   || buffer.compare("-") == 0
	   || buffer.compare("/") == 0
	   || buffer.compare("^") == 0
	   || buffer.compare("%") == 0
	   || buffer.compare("exp") == 0
	   || buffer.compare("log") == 0)
		return true;
	else
		return false;
}

string Calculator::calcule()	// fonction de calcul par notation polonaise postfixée empile dépile
{
	cout << operandes.size() << "test" << endl;
	

	if(operandes.size() < 2){
		return "Bad input";
	}
	if (!isOperator(operandes.top())) {
		return "Bad input";
	}

	while(operandes.size() > 0){
		if (isOperator(operandes.top())) {
			operators.push_back(operandes.top());
			operandes.pop();
		}else
		{
			cout << "is a chiffre" << endl;
			chiffres.push_back(stof(operandes.top()));
			operandes.pop();
		}
	}

    sizeO = operators.size() - 1;
    //sizeC = chiffres.size();    

    if(operators[sizeO] == "+")
    {
        return to_string(pluss(sizeO, true));
    }else if(operators[sizeO] == "-")
    {
        return to_string(moinss(sizeO, true));
    }else if(operators[sizeO] == "*")
    {
        return to_string(mult(sizeO, true));
    }else if(operators[sizeO] == "/")
    {
        return to_string(divi(sizeO, true));
    }
	
return "error";

	// if(input == "+")
	// {
	// 	if(operandes.size() < 2)
	// 		return "NOT ENOUGH OPERANDS";
	// 	else
	// 	{
	// 		operande2 = operandes.top();
	// 		operandes.pop();
	// 		operande1 = operandes.top();
	// 		operandes.pop();
	// 		cout << "operande1 : " << operande1 << endl;
	// 		cout << "operande2 : " << operande2 << endl;
	// 		cout << "resultat : " << operande1 + operande2 << endl;
	// 		return to_string(operande1 + operande2);
	// 	}
	// }
	// else if(input == "-")
	// {
	// 	if(operandes.size() < 2)
	// 		return "NOT ENOUGH OPERANDS";
	// 	else
	// 	{
	// 		operande2 = operandes.top();
	// 		operandes.pop();
	// 		operande1 = operandes.top();
	// 		operandes.pop();
	// 		cout << "operande1 : " << operande1 << endl;
	// 		cout << "operande2 : " << operande2 << endl;
	// 		cout << "resultat : " << operande1 - operande2 << endl;
	// 		return to_string(operande1 - operande2);
	// 	}
	// }
	// else if(input == "*")
	// {
	// 	if(operandes.size() < 2)
	// 		return "NOT ENOUGH OPERANDS";
	// 	else
	// 	{
	// 		operande2 = operandes.top();
	// 		operandes.pop();
	// 		operande1 = operandes.top();
	// 		operandes.pop();
	// 		cout << "operande1 : " << operande1 << endl;
	// 		cout << "operande2 : " << operande2 << endl;
	// 		cout << "resultat : " << operande1 * operande2 << endl;
	// 		return to_string(operande1 * operande2);
	// 	}
	// }
	// else if(input == "/")
	// {
	// 	if(operandes.size() < 2)
	// 		return "NOT ENOUGH OPERANDS";
	// 	else
	// 	{
	// 		operande2 = operandes.top();
	// 		operandes.pop();
	// 		operande1 = operandes.top();
	// 		operandes.pop();
	// 		cout << "operande1 : " << operande1 << endl;
	// 		cout << "operande2 : " << operande2 << endl;
	// 		cout << "resultat : " << operande1 / operande2 << endl;
	// 		return to_string(operande1 / operande2);
	// 	}
	// }
	// else if(input == "^")
	// {
	// 	if(operandes.size() < 2)
	// 		return "NOT ENOUGH OPERANDS";
	// 	else
	// 	{
	// 		operande2 = operandes.top();
	// 		operandes.pop();
	// 		operande1 = operandes.top();
	// 		operandes.pop();
	// 		cout << "operande1 : " << operande1 << endl;
	// 		cout << "resultat : " << pow(operande1, operande2) << endl;
	// 		return to_string(pow(operande1, operande2));
	// 	}
	// }
	// else if(input == "%")
	// {
	// 	if(operandes.size() < 1)
	// 		return "NOT ENOUGH OPERANDS";
	// 	else
	// 	{
	// 		operande1 = operandes.top();
	// 		operandes.pop();
	// 		cout << "operande1 : "<< operande1 << endl;
	// 		cout << "resultat : "<< operande1 / 100 << endl;
	// 		return to_string(operande1 / 100);
	// 	}
	// }
	// else if(input == "exp")
	// {
	// 	if(operandes.size() < 1)
	// 		return "NOT ENOUGH OPERANDS";
	// 	else
	// 	{
	// 		operande1 = operandes.top();
	// 		operandes.pop();
	// 		cout << "operande1 : "<< operande1 << endl;
	// 		cout << "resultat : "<< exp(operande1) << endl;
	// 		return to_string(exp(operande1));
	// 	}
	// }
	// else if(input == "log")
	// {
	// 	if(operandes.size() < 1)
	// 		return "NOT ENOUGH OPERANDS";
	// 	else
	// 	{
	// 		operande1 = operandes.top();
	// 		operandes.pop();
	// 		cout << "operande1 : "<< operande1 << endl;
	// 		cout << "resultat : "<< log10(operande1) << endl;
	// 		return to_string(log10(operande1));
	// 	}
	// }
	// else
	// 	return "Error";
}

bool Calculator::bad_input(){
	bool f_operator=true, f_point=false, f_par=false;
	Pile p;

	//Si on commence par un opérateur simple c'est faux
	if(op_size_1.find(this->calcul.at(0)) != string::npos) return false;

	for(unsigned int i=0; i< this->calcul.size();i++){
		if(isdigit(this->calcul.at(i))){
			f_operator=false;
		}
		else if(this->calcul.at(i)=='.'){
			if(f_point == true) return false;
			f_point=true;
		}
		else if(this->calcul.at(i)=='.' and f_point )
			return false;

		else if(this->calcul.at(i) == '('){
			f_par=true;
			//f_operator=false;
			p.push("(");
		}
		else if(this->calcul.at(i) == ')'){
			if(p.empty()) return false;
			p.pop();
			//f_operator=false;
			f_point=false;
		}

		else if(i>0 and this->calcul.at(i)=='n'){
			if(!f_operator){
				if(f_par) f_par=false;
				else return false;
			}
		}

		else if(op_size_1_spec.find(this->calcul.at(i)) != string::npos){
			//f_operator=true;
			f_point=false;
		}
		else if(op_size_1.find(this->calcul.at(i)) != string::npos && !f_operator){
			f_operator=true;
			f_point=false;
		}
		else if(op_size_2.find(this->calcul.substr(i,2)) != string::npos){
			if(i>0 and (op_size_1.find(this->calcul.at(i-1)) == string::npos and (this->calcul.at(i-1)!='(') and this->calcul.at(i-1)!='n')){return false;} 
			i+=1;
			
			f_operator=true;
			f_point=false;
			
		}
		else if(op_size_3.find(this->calcul.substr(i,3)) != string::npos){
			if(i>0 and (op_size_1.find(this->calcul.at(i-1)) == string::npos  and (this->calcul.at(i-1)!='(') and this->calcul.at(i-1)!='n') ){cout <<"erro" <<endl;return false;} 
			i+=2;
			
			f_operator=true;
			f_point=false;
			
		}
		else if(op_size_4.find(this->calcul.substr(i,4)) != string::npos){
			if(i>0 and (op_size_1.find(this->calcul.at(i-1)) == string::npos and (this->calcul.at(i-1)!='(') and this->calcul.at(i-1)!='n')){return false;} 
			i+=3;
			
			f_operator=true;
			f_point=false;
			
		}
		else if(op_size_5.find(this->calcul.substr(i,5)) != string::npos){
			if(i>0 and (op_size_1.find(this->calcul.at(i-1)) == string::npos and (this->calcul.at(i-1)!='(') and this->calcul.at(i-1)!='n')){return false;} 
			i+=4;
			
			f_operator=true;
			f_point=false;
			
		}
		else{
			return false;
		}


	}
	if(f_operator==true) return false; 
	if(!p.empty()) return false;
	return true;
}

///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////

list<string> Calculator::split_calc(string s){
	unsigned int i=0;
	string buff;
	list<string> l;


	for(i=0; i<s.size();i++){
		buff.clear();

		if(i<s.size() and (isdigit(s.at(i)) or s.at(i)=='.')){
			while(i<s.size() and (isdigit(s.at(i)) or s.at(i)=='.')){
				buff.push_back((s.at(i)));
				i++;
			} i--;
		}
		else if(i<s.size() and op_size_2.find(s.substr(i,2)) != string::npos) { buff=s.substr(i,2); i+=1; }
		else if(i<s.size() and op_size_3.find(s.substr(i,3)) != string::npos) { buff=s.substr(i,3); i+=2; }
		else if(i<s.size() and op_size_4.find(s.substr(i,4)) != string::npos) { buff=s.substr(i,4); i+=3; }
		else if(i<s.size() and op_size_5.find(s.substr(i,5)) != string::npos) { buff=s.substr(i,5); i+=4; }
		else if(i<s.size()) buff.push_back(s.at(i));

		l.push_back(buff);
	}

	return l;
}

//////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////

void Calculator::calc_to_postfix(){
	list<string> e;
	Pile p;
	string buff;

	Priority priority;
	priority.fill_priority();

	e=split_calc(this->calcul);
	while(!e.empty()){
		buff=e.front();
		e.pop_front();
		if(is_operand(buff)) this->calc_postfix->push_back(buff);
		else if(buff == "(") p.push(buff);
		else if(buff == ")"){
			while(!p.empty() && p.top()!="("){ 
				this->calc_postfix->push_back(p.top());
				p.pop();
			}
			if(p.empty()) throw Erreur(1,"Synthaxe Error",2); else p.pop();
		}
		else{
			if(op_size_2.find(buff) != string::npos) p.push(buff);
			else if(op_size_3.find(buff) != string::npos) p.push(buff);
			else if(op_size_4.find(buff) != string::npos) p.push(buff);
			else if(op_size_5.find(buff) != string::npos) p.push(buff);
			else{
				while(!p.empty() && p.top()!="(" && priority.op[buff] <= priority.op[p.top()]){
					this->calc_postfix->push_back(p.top());
					p.pop();
				}
				p.push(buff);
			}
		}
	}
	while(!p.empty()){
		this->calc_postfix->push_back(p.top());
		p.pop();

	}
}

void Calculator::postfix_eval(){
	Pile operandStack;
	string buff, a,b,r;

	while(!this->calc_postfix->empty()){
		buff=this->calc_postfix->front();
		//cout << buff << endl;
		if(!this->calc_postfix->empty()) this->calc_postfix->pop_front();


		if((is_operand(buff))){
			operandStack.push(buff);
			//cout << "operand" << endl;
		}
		else{
			if(op_size_5.find(buff) != string::npos or op_size_4.find(buff) != string::npos 
			or op_size_3.find(buff) != string::npos or op_size_2.find(buff) != string::npos){
				//cout << "fonction" << endl;
				a=operandStack.top(); if(!operandStack.empty()) operandStack.pop();
				r=exec_calc(a,b,buff);
				operandStack.push(r);
			}
			else{
				//cout << "operateur" << endl;
				if(!operandStack.empty()){ b=operandStack.top(); operandStack.pop(); }
				if(!operandStack.empty()){ a=operandStack.top(); operandStack.pop(); }
				//cout << "operateur" << endl;
				r=exec_calc(a,b,buff);
				operandStack.push(r);
			}
		}
		//cout << "Top operand = " << operandStack.top() << endl << endl;
	}
	this->result=operandStack.top();
}

void Calculator::erase_zero(){
	for(unsigned int i=this->result.size()-1; i>0 && this->result.at(i)=='0'; i--){
		this->result.erase(i);
	}
	if(this->result.at(this->result.size()-1)=='.') this->result.erase(this->result.size()-1);



}

void Calculator::appendPile(string calcul){
	this->operandes.push(calcul);
}

void Calculator::flushPile(){
	operators.clear();
	chiffres.clear();
	while(!(this->operandes.empty())){
		this->operandes.pop();
	}
}