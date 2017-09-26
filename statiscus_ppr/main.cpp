//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "main.h"
#include "HardSettingsDefines.h"
#include <System.IOUtils.hpp>
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
	setCurrentDateTime();
}
//---------------------------------------------------------------------------
//===========================================================================
void TForm1::connectToDB(){
	if (this->SQLConnection1->Connected != true){
		this->SQLConnection1->Connected = true;
	}
}
//===========================================================================
void TForm1::updateControlsFromDB(){

	connectToDB();

	SQLQuery1->SQL->Text = "SELECT * FROM controls";
	SQLQuery1->Active = true;

	//ShowMessage("SQLQuery1 executed!");

	this->listboxdeletecontrol->Items->Clear();
    this->listboxselectcontrol->Items->Clear();

	if (!SQLQuery1->IsEmpty()) {

		//TStringList* names;
		//names = new TStringList;
		//SQLQuery1->GetFieldNames(names);

		//for (int i = 0; i < names->Count; ++i){
		//	logmemo->Lines->Add(names->operator [](i));
		//}

		SQLQuery1->First();
		while (!SQLQuery1->Eof){
			SQLQuery1->FieldByName("name");
			logmemo->Lines->Add(SQLQuery1->FieldByName("name")->AsString);
			this->listboxdeletecontrol->Items->Add(SQLQuery1->FieldByName("name")->AsString);
			this->listboxselectcontrol->Items->Add(SQLQuery1->FieldByName("name")->AsString);
			SQLQuery1->Next();
		}
	}
	SQLQuery1->Active = false;

	//this->listboxselectcontrol->Selected[0] = true;
}
//===========================================================================
void TForm1::setCurrentDateTime(){
	this->DateEdit1->Date = Date();
	this->TimeEdit1->Time = Time();
}
//===========================================================================
void TForm1::createClearDB(){
	//ShowMessage("createClearDB()");
	this->FDConnection1->Params->Database = _db_path + _db_name;
	this->FDConnection1->Connected = true;
	this->FDConnection1->ExecSQL(_db_create_sql);
	//System::Sysutils::Sleep(2000);
	this->FDConnection1->Connected = false;
	//ShowMessage("finish createClearDB()");

}
//===========================================================================
void TForm1::afterFormCreate(){

	SQLConnection1->Params->Add("Database=" + _db_path + _db_name);

	if (!System::Ioutils::TDirectory::Exists(_db_path)){
		System::Ioutils::TDirectory::CreateDirectory(_db_path);
	};

	if (!System::Ioutils::TFile::Exists(_db_path + _db_name)) {
		createClearDB();
		this->tabsc->ActiveTab = this->tabsettings;
	}else{
		this->tabsc->ActiveTab = this->tabmain;
    }

	setCurrentDateTime();
	updateControlsFromDB();
}
//===========================================================================

void __fastcall TForm1::butsetnewvalueClick(TObject *Sender)
{
	connectToDB();

	try
	{
		SQLQuery1->SQL->Text = "select controlid from controls where name = :name";
		SQLQuery1->Params->ParamByName("name")->Value =
			this->listboxselectcontrol->Selected->Text;
		SQLQuery1->Active = true;

		SQLQuery1->First();

		int q_control_id;

		while (!SQLQuery1->Eof){
			logmemo->Lines->Add(SQLQuery1->FieldByName("controlid")->AsString);
			q_control_id = SQLQuery1->FieldByName("controlid")->AsInteger;
			SQLQuery1->Next();

		}

		//ShowMessage("controlid = " + q_control_id);

		SQLQuery1->Active = false;

		SQLQuery1->SQL->Text = "INSERT INTO vals(control_id, val, date_str, time_str, timestamp, description) VALUES (:control_id, :val, :date_str, :time_str, :timestamp, :descr)";
		SQLQuery1->Params->ParamByName("control_id")->Value = q_control_id;

		SQLQuery1->Params->ParamByName("val")->Value = this->editnewvalue->Text.ToDouble();

		SQLQuery1->Params->ParamByName("date_str")->Value = this->DateEdit1->Date.DateString();
		SQLQuery1->Params->ParamByName("time_str")->Value = this->TimeEdit1->Time.TimeString();

		//logmemo->Lines->Add("date == " + this->DateEdit1->Date.DateString());
		//logmemo->Lines->Add("time == " + this->TimeEdit1->Time.TimeString());

		SQLQuery1->Params->ParamByName("timestamp")->Value =
			this->DateEdit1->Date.Val +  this->TimeEdit1->Time.Val;

		SQLQuery1->Params->ParamByName("descr")->Value =
			this->editdescr->Text;

		SQLQuery1->Active = true;



	}
	catch (Exception& E)
	{
		if (ContainsText(E.Message, "Cursor not returned from Query")){
			;
		}else{
			logmemo->Lines->Add("Exception raised with message:: " + E.Message);
			this->tabsc->ActiveTab = this->tabsettings;
		}
	}

	SQLQuery1->Active = false;

	this->editnewvalue->Text = "";
	this->editdescr->Text = "";
	setCurrentDateTime();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::butaddnewcontrolClick(TObject *Sender)
{
	this->connectToDB();

	SQLQuery1->SQL->Text = "INSERT INTO controls(name) VALUES (:name)";
	SQLQuery1->Params->ParamByName("name")->Value = this->editaddnewcontrol->Text;
	SQLQuery1->ExecSQL();

	updateControlsFromDB();

	this->editaddnewcontrol->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::butdbconnectClick(TObject *Sender)
{
	this->updateControlsFromDB();

	/*
	SQLQuery1->Active = false;
	SQLQuery1->SQL->Text = "select * from vals ";
	SQLQuery1->Active = true;

	SQLQuery1->First();

	while (!SQLQuery1->Eof){
		logmemo->Lines->Add(SQLQuery1->FieldByName("timestamp")->AsString);
		TDateTime dt;
		dt.Val = SQLQuery1->FieldByName("timestamp")->AsFloat;
		logmemo->Lines->Add(dt.DateTimeString());
		SQLQuery1->Next();

	}
    */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::butdeleteselectedcontrolClick(TObject *Sender)
{
	this->SQLConnection1->Connected = true;
	SQLQuery1->SQL->Text = "delete from controls where name = :name";
	SQLQuery1->Params->ParamByName("name")->Value =
		this->listboxdeletecontrol->Selected->Text;

	SQLQuery1->ExecSQL();

	updateControlsFromDB();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	this->afterFormCreate();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::butexitClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::butstatClick(TObject *Sender)
{
	connectToDB();

	this->memostat->Lines->Clear();
	this->servals->Clear();
	this->servals->Repaint();

	try
	{
		SQLQuery1->SQL->Text = "select controlid from controls where name = :name";
		SQLQuery1->Params->ParamByName("name")->Value =
			this->listboxselectcontrol->Selected->Text;
		SQLQuery1->Active = true;

		SQLQuery1->First();

		int q_control_id;

		while (!SQLQuery1->Eof){
			q_control_id = SQLQuery1->FieldByName("controlid")->AsInteger;
			SQLQuery1->Next();
		}

		//ShowMessage("controlid = " + q_control_id);

		SQLQuery1->Active = false;

		SQLQuery1->SQL->Text = "select * from vals where control_id = :control_id order by timestamp";
		SQLQuery1->Params->ParamByName("control_id")->Value = q_control_id;
		SQLQuery1->Active = true;

		memostat->Lines->Add("Statistic for: " +
			this->listboxselectcontrol->Selected->Text
		);

		while (!SQLQuery1->Eof){
			TDateTime dt;
			dt.Val = SQLQuery1->FieldByName("timestamp")->AsFloat;
			logmemo->Lines->Add(dt.DateTimeString());

			memostat->Lines->Add(
				SQLQuery1->FieldByName("val")->AsString +
				" at " +
				dt.DateTimeString() +
				" :: " +
				SQLQuery1->FieldByName("description")->AsString
			);

			//this->servals->AddY(SQLQuery1->FieldByName("val")->AsFloat);
			this->servals->AddXY(
				SQLQuery1->FieldByName("timestamp")->AsFloat,
				SQLQuery1->FieldByName("val")->AsFloat
			);

			SQLQuery1->Next();

		}
	}
	catch (Exception& E)
	{
		logmemo->Lines->Add("Exception raised with message:: " + E.Message);
		this->tabsc->ActiveTab = this->tabsettings;
	}


}
//---------------------------------------------------------------------------

