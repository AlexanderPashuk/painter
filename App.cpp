//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "App.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
USEFORM("Unit2.cpp", Form2);
TApp *App;

int lastX = -1, lastY = -1;

//---------------------------------------------------------------------------
__fastcall TApp::TApp(TComponent* Owner)
	: TForm(Owner)
{}
//---------------------------------------------------------------------------
void __fastcall TApp::AppCanvasMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	if (lastX > 0 && lastY > 0) {
		DrawFigure(X, Y);
	} else {
		AppCanvas->Canvas->MoveTo(X, Y);
		lastX = X; lastY = Y;
	}
}

void __fastcall TApp::AppCanvasMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if (Figure->ItemIndex == 0) {
		lastX = -1;
		lastY = -1;
	}
}
//---------------------------------------------------------------------------
void __fastcall TApp::AppCanvasMouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	if (Figure->ItemIndex == 0) {
		if (Shift.Contains(ssLeft)){
            DrawFigure(X, Y);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TApp::FigureClick(TObject *Sender)
{
	// reset last position
	lastX = -1;
    lastY = -1;
}
//---------------------------------------------------------------------------

void __fastcall TApp::LineClick(TObject *Sender)
{
	TPenStyle style;
	switch (Line->ItemIndex) {
		case 0: style = psSolid; break;
		case 1: style = psDash; break;
		case 2: style = psDot; break;
		case 3: style = psDashDot; break;
		default: style = psSolid; break;
	}
	AppCanvas->Canvas->Pen->Style = style;
}
//---------------------------------------------------------------------------

void __fastcall TApp::FormCreate(TObject *Sender)
{
//	AppCanvas->Canvas->Brush->Color = clRed;
	AppCanvas->Canvas->FillRect(
		AppCanvas->Canvas->ClipRect
	);
}
//---------------------------------------------------------------------------
void __fastcall TApp::DrawFigure(int X, int Y) {
	switch(Figure->ItemIndex) {
        case 0:
		case 1:
			AppCanvas->Canvas->LineTo(X, Y);
			break;
		case 2:
			AppCanvas->Canvas->Ellipse(lastX, lastY, X, Y);
			lastX = -1; lastY = -1;
			break;
		case 3:
			AppCanvas->Canvas->Rectangle(lastX, lastY, X, Y);
			lastX = -1; lastY = -1;
			break;
	}
}

//---------------------------------------------------------------------------

