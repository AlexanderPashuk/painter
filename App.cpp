//---------------------------------------------------------------------------

#include <vcl.h>
#include <pngimage.hpp>

#pragma hdrstop

#include "App.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TApp *App;

//---------------------------------------------------------------------------
__fastcall TApp::TApp(TComponent* Owner): TForm(Owner) {
	Image = new PainterImage(ImageEl);
	LastPoint = TPoint(0, 0);
	ClearTimer = new TTimer(this);

	// Add action
	ClearTimer->Enabled = false;
	ClearTimer->OnTimer = &ClearImageRow;
	ClearTimer->Interval = 1;
}
//---------------------------------------------------------------------------
void __fastcall TApp::ImageElMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	if (!LastPoint.IsEmpty()) {
		TPoint NewPoint = TPoint(X, Y);
		switch(Figure->ItemIndex) {
			case 0:
			case 1:
				Image->DrawLine(LastPoint, NewPoint);
                LastPoint.SetLocation(X, Y);
				break;
			case 2:
				Image->DrawEllipse(LastPoint, NewPoint);
				LastPoint.SetLocation(0, 0);
				break;
			case 3:
				Image->DrawRect(LastPoint, NewPoint);
                LastPoint.SetLocation(0, 0);
				break;
		}
	} else {
		LastPoint.SetLocation(X, Y);
	}
}

void __fastcall TApp::ImageElMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if (Figure->ItemIndex == 0) {
		LastPoint.SetLocation(0, 0);
	}
}
//---------------------------------------------------------------------------
void __fastcall TApp::ImageElMouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	if (Figure->ItemIndex == 0) {
		if (Shift.Contains(ssLeft)) {
			Image->DrawLine(LastPoint, TPoint(X, Y));
		}
        LastPoint.SetLocation(X, Y);
	}
}
//---------------------------------------------------------------------------
void __fastcall TApp::FigureClick(TObject *Sender)
{
	LastPoint.SetLocation(0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TApp::LineClick(TObject *Sender)
{
	TPenStyle Style;
	switch (Line->ItemIndex) {
		case 0: Style = psSolid; break;
		case 1: Style = psDash; break;
		case 2: Style = psDot; break;
		case 3: Style = psDashDot; break;
		default: Style = psSolid; break;
	}
    Image->UpdatePenStyle(Style);
}
//---------------------------------------------------------------------------

void __fastcall TApp::FormCreate(TObject *Sender)
{
	Image->ClearCanvas();
}

//---------------------------------------------------------------------------

void __fastcall TApp::OpenButtonClick(TObject *Sender)
{
	TOpenDialog* OpenDialog = new TOpenDialog(App);
	OpenDialog->Filter = "Image Files (*.png)|*.PNG";

	if (OpenDialog->Execute()) {
		if (FileExists(OpenDialog->FileName)) {
			Image->Load(OpenDialog->FileName);
		} else {
			// TODO: Show error: no file exists
		}
	}
	OpenDialog->Free();
}
//---------------------------------------------------------------------------

void __fastcall TApp::SaveButtonClick(TObject *Sender)
{
    TSaveDialog* SaveDialog = new TSaveDialog(App);
	SaveDialog->Filter="Save(*.png)|*.PNG";

	if (SaveDialog->Execute()) {
		Image->Save(SaveDialog->FileName);
	}
    SaveDialog->Free();
}
//---------------------------------------------------------------------------

void __fastcall TApp::FormResize(TObject *Sender)
{
	Image->Resize();
}
//---------------------------------------------------------------------------
void __fastcall TApp::ClearImageRow(TObject *Sender) {
	TPoint NextPixel = Image->GetNextPixel();
	do {
		Image->FillPixel(NextPixel, clWhite);
		NextPixel = Image->GetNextPixel();
	} while(NextPixel.X);

	if (!NextPixel.X && !NextPixel.Y)
		ClearTimer->Enabled = false;
}

void __fastcall TApp::ClearButtonClick(TObject *Sender)
{
	ClearTimer->Enabled = true;
}
//---------------------------------------------------------------------------

