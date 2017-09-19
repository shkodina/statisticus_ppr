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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TTabControl *tabsc;
	TTabItem *main;
	TTabItem *statistics;
	TTabItem *settings;
	TTabItem *db;
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
	TSQLDataSet *SQLDataSet1;
	TSQLTable *SQLTable1;
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
