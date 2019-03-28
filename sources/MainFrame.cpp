void MainFrame::OnButton_AC_Clicked(wxCommandEvent &event){
	txtCalcInput->Clear();
	//////JACQUES///////
	c.flushPile();
	////////////////////
	calcul.clear();

}
void MainFrame::OnButton_EGAL_Clicked(wxCommandEvent &event){
	if(!calcul.empty()){
		//////JACQUES///////
		c.appendPile(calcul);
		////////////////////

		txtCalcInput->Clear(); //Efface la zone d'affichage
		*txtCalcInput << c.getResult(); //Affiche le resultat
		calcul=c.getResult(); //Stock le resultat dans calcul pour faire un nouveau calcul avec le resultat

	}
}