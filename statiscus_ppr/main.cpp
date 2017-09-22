//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::butdatetimesetClick(TObject *Sender)
{
	this->DateEdit1->Date = Date();
	this->TimeEdit1->Time = Time();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::butsetnewvalueClick(TObject *Sender)
{
	this->SQLConnection1->Connected = true;

    			TStringList* names;
			TField* currentField;
			String currentLine;

	try
	{
		// Assign the query to the object SQLQuery1.
		 SQLQuery1->SQL->Text = "SELECT * FROM controls";
		 SQLQuery1->Active = true;


		  /*

				if (!SQLQuery1->IsEmpty()) {
	  SQLQuery1->First();
	  names = new TStringList          ;

		SQLQuery1->GetFieldNames(names);
		while (!SQLQuery1->Eof) {
		  currentLine = "";
		  for (int i = 0; i < names->Count; ++i) {
			currentField = SQLQuery1->FieldByName(names->Strings[i]);
			currentLine = currentLine + " " + currentField->AsString;
		  }
		   logmemo->Lines->Add(currentLine);
		   SQLQuery1->Next();
		}
	   }
			*/
		if (!SQLQuery1->IsEmpty()) {
			SQLQuery1->First();
			while (!SQLQuery1->Eof) {

			  TField* currentField = SQLQuery1->FieldByName("name");

			   logmemo->Lines->Add(currentField->AsAnsiString);
			   SQLQuery1->Next();
			}
		} else {
			logmemo->Lines->Add("no items found");
			this->tabsc->ActiveTab = this->tabsettings;
		}



	}
	catch (Exception& E)
	{
		logmemo->Text = "Exception raised with message" + E.Message;
	 }
	// Show the results of the query in a TMemo control.

}
//---------------------------------------------------------------------------

void __fastcall TForm1::butaddnewcontrolClick(TObject *Sender)
{
	this->SQLConnection1->Connected = true;

	String insertstr;

	insertstr = "INSERT INTO controls (name) ";
	insertstr = insertstr + "VALUES (" + this->editaddnewcontrol->Text + ");" ;
	logmemo->Lines->Add(insertstr);

	SQLQuery1->SQL->Text = insertstr;
	SQLQuery1->Active = true;


}
//---------------------------------------------------------------------------

