//---------------------------------------------------------------------------

#ifndef AppH
#define AppH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "Image.h"

//---------------------------------------------------------------------------
class TApp : public TForm
{
__published:	// IDE-managed Components
	TImage *ImageEl;
	TRadioGroup *Figure;
	TRadioGroup *Line;
	TButton *OpenButton;
	TButton *SaveButton;
	TButton *ClearButton;
	void __fastcall ImageElMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall ImageElMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall ImageElMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall FigureClick(TObject *Sender);
	void __fastcall LineClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);

	// void __fastcall DrawFigure(int X, int Y);
	void __fastcall OpenButtonClick(TObject *Sender);
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall ClearButtonClick(TObject *Sender);
	void __fastcall ClearImageRow(TObject *Sender);


private:	// User declarations
    TTimer* ClearTimer;
    TPoint LastPoint;
	PainterImage* Image;
public:		// User declarations
	__fastcall TApp(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TApp *App;
//---------------------------------------------------------------------------
#endif
