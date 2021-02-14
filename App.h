//---------------------------------------------------------------------------

#ifndef AppH
#define AppH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>

//---------------------------------------------------------------------------
class TApp : public TForm
{
__published:	// IDE-managed Components
	TImage *AppCanvas;
	TRadioGroup *Figure;
	TRadioGroup *Line;
	void __fastcall AppCanvasMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall AppCanvasMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall AppCanvasMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall FigureClick(TObject *Sender);
	void __fastcall LineClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);

    void __fastcall DrawFigure(int X, int Y);

private:	// User declarations
public:		// User declarations
	__fastcall TApp(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TApp *App;
//---------------------------------------------------------------------------
#endif
