#include "../headers/MainFrame.hpp"

MainFrame::~MainFrame(){
}

MainFrame::MainFrame(const wxString title,const wxPoint& pos, const wxSize& size) : wxFrame(NULL,wxID_ANY,title,pos,size){


	sizer_principal = new wxBoxSizer(wxVERTICAL);
 
	txtCalcInput = new wxTextCtrl(this, ID_TXT_CALCINPUT, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_RIGHT);
	txtCalcInput->SetEditable(false); //On rend la zone de text non editable au clavier


	sizer_principal->Add(txtCalcInput, 0, wxEXPAND | wxTOP | wxBOTTOM, 4); //Ajout de la zone de txt

	gridButton = new wxGridSizer(5, 5, 3, 4); //Grille 5 lignes 5 colonnes 3 d'espacement en haut et en bas

	btnMclear = new wxButton(this, ID_BTN_MCLEAR, _T("MC")); // Création du bouton MCLEAR
	btnMclear->Disable();
	btnMplus = new wxButton(this, ID_BTN_MPLUS, _T("M+")); // Création du bouton MPLUS, 
	btnMr = new wxButton(this, ID_BTN_MR, _T("MR")); // Création du bouton MR
	btnMr->Disable();

	
	btnMclear->SetBackgroundColour(wxColour(255,255,0,100));
	btnMplus->SetBackgroundColour(wxColour(255,255,0,100));
	btnMr->SetBackgroundColour(wxColour(255,255,0,100));
	


	
	gridButton->Add(btnMclear,0,wxEXPAND);
	gridButton->Add(btnMplus,0,wxEXPAND);
	gridButton->Add(btnMr,0,wxEXPAND);
	

	btnPG = new wxButton(this, ID_BTN_PG, _T("^2")); // Création du bouton ^2


	
	
	btnPi = new wxButton(this, ID_BTN_PI, wxString::FromUTF8("\xF0\x9D\x9B\x91")); // Création du bouton Pi

	btnPG->SetBackgroundColour(wxColour(255,255,0,100));
	
	
	btnPi->SetBackgroundColour(wxColour(255,255,0,100));


	gridButton->Add(btnPG,0,wxEXPAND);

	
	gridButton->Add(btnPi,0,wxEXPAND);


	btn7 = new wxButton(this, ID_BTN_7, _T("7")); // Création du bouton 7
	btn8 = new wxButton(this, ID_BTN_8, _T("8")); // Création du bouton 8
	btn9 = new wxButton(this, ID_BTN_9, _T("9")); // Création du bouton 9
	btnDel = new wxButton(this, ID_BTN_DEL, _T("DEL")); // Création du bouton DEL
	btnAc = new wxButton(this, ID_BTN_AC, _T("AC")); // Création du bouton AC

	btnDel->SetBackgroundColour(wxColour(255,0,0,100));
	btnAc->SetBackgroundColour(wxColour(255,0,0,100));

	gridButton->Add(btn7,0,wxEXPAND);
	gridButton->Add(btn8,0,wxEXPAND);
	gridButton->Add(btn9,0,wxEXPAND);
	gridButton->Add(btnDel,0,wxEXPAND);
	gridButton->Add(btnAc,0,wxEXPAND);


	btn4 = new wxButton(this, ID_BTN_4, _T("4")); // Création du bouton 4
	btn5 = new wxButton(this, ID_BTN_5, _T("5")); // Création du bouton 5
	btn6 = new wxButton(this, ID_BTN_6, _T("6")); // Création du bouton 6
	btnX = new wxButton(this, ID_BTN_X, _T("X")); // Création du bouton Multiplication
	btnDiv = new wxButton(this, ID_BTN_DIV, _T("/")); // Création du bouton Division


	btnX->SetBackgroundColour(wxColour(0,255,0,100));
	btnDiv->SetBackgroundColour(wxColour(0,255,0,100));



	gridButton->Add(btn4,0,wxEXPAND);
	gridButton->Add(btn5,0,wxEXPAND);
	gridButton->Add(btn6,0,wxEXPAND);
	gridButton->Add(btnX,0,wxEXPAND);
	gridButton->Add(btnDiv,0,wxEXPAND);


	btn1 = new wxButton(this, ID_BTN_1, _T("1")); // Création du bouton "1"
	btn2 = new wxButton(this, ID_BTN_2, _T("2")); // Création du bouton "2"
	btn3 = new wxButton(this, ID_BTN_3, _T("3")); // Création du bouton "3"
	btnPlus = new wxButton(this, ID_BTN_PLUS, _T("+")); // Création du bouton "+"
	btnMoins = new wxButton(this, ID_BTN_MOINS, _T("-")); // Création du bouton "-"

	btnPlus->SetBackgroundColour(wxColour(0,255,0,100));
	btnMoins->SetBackgroundColour(wxColour(0,255,0,100));

	gridButton->Add(btn1,0,wxEXPAND);
	gridButton->Add(btn2,0,wxEXPAND);
	gridButton->Add(btn3,0,wxEXPAND);
	gridButton->Add(btnPlus,0,wxEXPAND);
	gridButton->Add(btnMoins,0,wxEXPAND);


	btn0 = new wxButton(this, ID_BTN_0, _T("0")); // Création du bouton "0"
	btnPoint = new wxButton(this, ID_BTN_POINT, _T(".")); // Création du bouton "."
	btnNeg = new wxButton(this, ID_BTN_NEG, _T("(-)")); // Création du bouton "(-)"
	btnEgal = new wxButton(this, ID_BTN_EGAL, _T("=")); // Création du bouton "Egale"	
	btnEnter = new wxButton(this, ID_BTN_ENTER, _T("ENTER")); // Création du bouton "Enter"	

	btnEgal->SetBackgroundColour(wxColour(0,255,0,100));
	btnEnter->SetBackgroundColour(wxColour(0,255,0,100));

	gridButton->Add(btn0,0,wxEXPAND);
	gridButton->Add(btnPoint,0,wxEXPAND);
	gridButton->Add(btnNeg,0,wxEXPAND);
	gridButton->Add(btnEgal,0,wxEXPAND);
	gridButton->Add(btnEnter,0,wxEXPAND);


/**************************************************/

	
	sizer_principal->Add(gridButton, 1, wxEXPAND); //Ajoute la grille au size principal
	SetSizer(sizer_principal); //Le sizer principal prend toute la fenêtre
	SetMinSize(wxSize(400, 400)); //Taille minimal de la fenêtre

	Centre(); //Centre
}

void MainFrame::OnButton_X_Clicked(wxCommandEvent &event){
	*txtCalcInput << "*";
	calcul+="*";
}
void MainFrame::OnButton_DIV_Clicked(wxCommandEvent &event){
	*txtCalcInput << "/";
	calcul+="/";
}
void MainFrame::OnButton_PLUS_Clicked(wxCommandEvent &event){
	*txtCalcInput << "+";
	calcul+="+";
}
void MainFrame::OnButton_MOINS_Clicked(wxCommandEvent &event){
	*txtCalcInput << "-";
	calcul+="-";
}
void MainFrame::OnButton_POINT_Clicked(wxCommandEvent &event){
	*txtCalcInput << ".";
	calcul+=".";
}
void MainFrame::OnButton_NEG_Clicked(wxCommandEvent &event){
	*txtCalcInput << "-"; //Affiche (-) sur l'affichage
	calcul+="n"; //Mais écrit n dans le calcul
}
void MainFrame::OnButton_0_Clicked(wxCommandEvent &event){
	*txtCalcInput << "0.0";
	calcul+="0";
}
void MainFrame::OnButton_1_Clicked(wxCommandEvent &event){
	*txtCalcInput << "1.0";
	calcul+="1";
}
void MainFrame::OnButton_2_Clicked(wxCommandEvent &event){
	*txtCalcInput << "2.0";
	calcul+="2";
}
void MainFrame::OnButton_3_Clicked(wxCommandEvent &event){
	*txtCalcInput << "3.0";
	calcul+="3";
}
void MainFrame::OnButton_4_Clicked(wxCommandEvent &event){
	*txtCalcInput << "4.0";
	calcul+="4";
}
void MainFrame::OnButton_5_Clicked(wxCommandEvent &event){
	*txtCalcInput << "5.0";
	calcul+="5";
}
void MainFrame::OnButton_6_Clicked(wxCommandEvent &event){
	*txtCalcInput << "6.0";
	calcul+="6";
}
void MainFrame::OnButton_7_Clicked(wxCommandEvent &event){
	*txtCalcInput << "7.0";
	calcul+="7";
}
void MainFrame::OnButton_8_Clicked(wxCommandEvent &event){
	*txtCalcInput << "8";
	calcul+="8";
}
void MainFrame::OnButton_9_Clicked(wxCommandEvent &event){
	*txtCalcInput << "9.0";
	calcul+="9";
}
void MainFrame::OnButton_PI_Clicked(wxCommandEvent &event){
	*txtCalcInput << wxString::FromUTF8("\xF0\x9D\x9B\x91"); //Affiche PI
	calcul+=PI; //Mais ecrit 3.14 entre parenthèse pour protéger la valeur
}
void MainFrame::OnButton_PG_Clicked(wxCommandEvent &event){
	*txtCalcInput << "^2";
	calcul+="^2";
}

void MainFrame::OnButton_DEL_Clicked(wxCommandEvent &event){

	if(!calcul.empty()){
		calcul.pop_back();
		txtCalcInput->Clear();
		*txtCalcInput << calcul;	
	}
	
}
void MainFrame::OnButton_AC_Clicked(wxCommandEvent &event){
	txtCalcInput->Clear();
	c.flushPile();
	calcul.clear();
}
void MainFrame::OnButton_EGAL_Clicked(wxCommandEvent &event){
	if(!calcul.empty()){
		c.appendPile(calcul);
		//Calculator c(calcul); //Effectue le calcul
		txtCalcInput->Clear(); //Efface la zone d'affichage
		*txtCalcInput << c.getResult(); //Affiche le resultat
		calcul=c.getResult(); //Stock le resultat dans calcul pour faire un nouveau calcul avec le resultat
	}
}

void MainFrame::OnButton_ENTER_Clicked(wxCommandEvent &event){

}

void MainFrame::OnButton_MCLEAR_Clicked(wxCommandEvent &event){
	//La touche MC permet d’effacer la mémoire.
	if(!save.empty())
		{save.clear();}
		btnMclear->Disable();
		btnMr->Disable();
	//Penser à déactiver un bouton MC dans le cas où y a rien dans la mémoire (regarder comment le déactiver )
	
}
void MainFrame::OnButton_MPLUS_Clicked(wxCommandEvent &event){ 
	//La touche M+ permet d’ajouter le nombre actuellement affiché sur l'écran de la calculatrice à la mémoire
	double val;
	if(txtCalcInput->GetValue() .ToDouble(&val))
    {   
	 	if(!save.empty()){
	    		save.clear(); //effacer le contenu de la chaine si la varaibale save n'est pas vide.
	    	}
	    	save <<val;
	    btnMclear->Enable();
   		btnMr->Enable();
	}	
}
void MainFrame::OnButton_MR_Clicked(wxCommandEvent &event){

	 //La touche MR permet d'afficher la valeur de la mémoire
   txtCalcInput->SetValue(save);
   calcul+=save; //sauvgarder l'element stoker en mémoire dans Calcul
}



BEGIN_EVENT_TABLE(MainFrame,wxFrame)
	EVT_BUTTON(ID_BTN_X, MainFrame::OnButton_X_Clicked)
	EVT_BUTTON(ID_BTN_DIV, MainFrame::OnButton_DIV_Clicked)
	EVT_BUTTON(ID_BTN_PLUS, MainFrame::OnButton_PLUS_Clicked)
	EVT_BUTTON(ID_BTN_MOINS, MainFrame::OnButton_MOINS_Clicked)

	EVT_BUTTON(ID_BTN_POINT, MainFrame::OnButton_POINT_Clicked)
	EVT_BUTTON(ID_BTN_NEG, MainFrame::OnButton_NEG_Clicked)

	EVT_BUTTON(ID_BTN_0, MainFrame::OnButton_0_Clicked)
	EVT_BUTTON(ID_BTN_1, MainFrame::OnButton_1_Clicked)
	EVT_BUTTON(ID_BTN_2, MainFrame::OnButton_2_Clicked)
	EVT_BUTTON(ID_BTN_3, MainFrame::OnButton_3_Clicked)
	EVT_BUTTON(ID_BTN_4, MainFrame::OnButton_4_Clicked)
	EVT_BUTTON(ID_BTN_5, MainFrame::OnButton_5_Clicked)
	EVT_BUTTON(ID_BTN_6, MainFrame::OnButton_6_Clicked)
	EVT_BUTTON(ID_BTN_7, MainFrame::OnButton_7_Clicked)
	EVT_BUTTON(ID_BTN_8, MainFrame::OnButton_8_Clicked)
	EVT_BUTTON(ID_BTN_9, MainFrame::OnButton_9_Clicked)
	EVT_BUTTON(ID_BTN_PI, MainFrame::OnButton_PI_Clicked)

	EVT_BUTTON(ID_BTN_PG, MainFrame::OnButton_PG_Clicked)

	EVT_BUTTON(ID_BTN_DEL, MainFrame::OnButton_DEL_Clicked)
	EVT_BUTTON(ID_BTN_AC, MainFrame::OnButton_AC_Clicked)
	EVT_BUTTON(ID_BTN_EGAL, MainFrame::OnButton_EGAL_Clicked)
	EVT_BUTTON(ID_BTN_ENTER, MainFrame::OnButton_ENTER_Clicked)

	EVT_BUTTON(ID_BTN_MPLUS, MainFrame::OnButton_MPLUS_Clicked)
	EVT_BUTTON(ID_BTN_MCLEAR, MainFrame::OnButton_MCLEAR_Clicked)
	EVT_BUTTON(ID_BTN_MR, MainFrame::OnButton_MR_Clicked)

END_EVENT_TABLE()
