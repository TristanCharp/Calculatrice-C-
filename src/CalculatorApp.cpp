// On appelle le fichier de déclaration de notre classe
#include "../headers/CalculatorApp.hpp"


IMPLEMENT_APP(MyApp); //Macro redirige le main


bool MyApp::OnInit(){
	wxSize default_size(400,400);
	myWindow=new MainFrame(_T("Calculator"),wxDefaultPosition, default_size);
	myWindow->Show();
	return true; //Pour que le programme ne se termine pas
}