//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <FMX.DateTimeCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.DbxSqlite.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TTabControl *tabsc;
	TTabItem *tabmain;
	TTabItem *tabstatistics;
	TTabItem *tabsettings;
	TTabItem *tabdb;
	TListBox *listboxselectcontrol;
	TEdit *editaddnewcontrol;
	TButton *butaddnewcontrol;
	TListBox *listboxdeletecontrol;
	TButton *butdeleteselectedcontrol;
	TButton *butdbcreatenew;
	TButton *butdbexporttofile;
	TLayout *Layout1;
	TDateEdit *DateEdit1;
	TTimeEdit *TimeEdit1;
	TButton *butdatetimeset;
	TButton *butsetnewvalue;
	TEdit *editnewvalue;
	TSQLConnection *SQLConnection1;
	TSQLQuery *SQLQuery1;
	TLayout *Layout2top;
	TMemo *logmemo;
	TButton *butdbconnect;
	void __fastcall butdatetimesetClick(TObject *Sender);
	void __fastcall butsetnewvalueClick(TObject *Sender);
	void __fastcall butaddnewcontrolClick(TObject *Sender);
	void __fastcall butdbconnectClick(TObject *Sender);
	void __fastcall butdeleteselectedcontrolClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
	void updateControlsFromDB();
	void setCurrentDateTime();
	void afterFormCreate();
    void connectToDB();
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
