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
#include <FMXTee.Chart.hpp>
#include <FMXTee.Engine.hpp>
#include <FMXTee.Procs.hpp>
#include <FMXTee.Series.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <FireDAC.Comp.UI.hpp>
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
	TButton *butexit;
	TChart *Chart1;
	TLayout *laystatistic;
	TButton *butstat;
	TMemo *memostat;
	TBarSeries *servals;
	TEdit *editdescr;
	TFDConnection *FDConnection1;
	TFDQuery *FDQuery1;
	TFDGUIxWaitCursor *FDGUIxWaitCursor1;
	void __fastcall butdatetimesetClick(TObject *Sender);
	void __fastcall butsetnewvalueClick(TObject *Sender);
	void __fastcall butaddnewcontrolClick(TObject *Sender);
	void __fastcall butdbconnectClick(TObject *Sender);
	void __fastcall butdeleteselectedcontrolClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall butexitClick(TObject *Sender);
	void __fastcall butstatClick(TObject *Sender);
private:	// User declarations
	void updateControlsFromDB();
	void setCurrentDateTime();
	void afterFormCreate();
	void connectToDB();
    void createClearDB();
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
