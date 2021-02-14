//---------------------------------------------------------------------------

#pragma hdrstop

#include <pngimage.hpp>
#include "Image.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PainterImage::PainterImage(TImage* ImageElement): Element(ImageElement) {}

void PainterImage::DrawLine(TPoint FirstPoint, TPoint SecondPoint) {
	Element->Canvas->MoveTo(FirstPoint.X, FirstPoint.Y);
	Element->Canvas->LineTo(SecondPoint.X, SecondPoint.Y);
}

void PainterImage::DrawEllipse(TPoint FirstPoint, TPoint SecondPoint) {
	Element->Canvas->Ellipse(
		FirstPoint.X, FirstPoint.Y,
		SecondPoint.X, SecondPoint.Y);
}

void PainterImage::DrawRect(TPoint FirstPoint, TPoint SecondPoint) {
	Element->Canvas->Rectangle(
		FirstPoint.X, FirstPoint.Y,
		SecondPoint.X, SecondPoint.Y);
}

void PainterImage::ClearCanvas() {
	Element->Canvas->FillRect(
		Element->Canvas->ClipRect
	);
}

TPoint PainterImage::GetNextPixel() {
	// Move right by X-axis
	CurrentPixel.Offset(1, 0);

	if (CurrentPixel.X > Element->Picture->Width)
		CurrentPixel.SetLocation(0, CurrentPixel.Y+1);

	if (CurrentPixel.Y > Element->Picture->Height)
		CurrentPixel.SetLocation(0, 0);

	return CurrentPixel;
}

void PainterImage::FillPixel(TPoint Pixel, TColor Color) {
	Element->Canvas->Pixels[Pixel.X][Pixel.Y] = Color;
}



void PainterImage::UpdatePenStyle(TPenStyle Style) {
	Element->Canvas->Pen->Style = Style;
}

void PainterImage::Resize() {
	Element->Picture->Bitmap->Width = Element->Width;
	Element->Picture->Bitmap->Height = Element->Height;
}

void PainterImage::Save(TFileName FileName) {
	TPngImage* PNGImage = new TPngImage();
	PNGImage->Assign(Element->Picture->Graphic);
	PNGImage->SaveToFile(FileName + ".png");
	delete PNGImage;
}

void PainterImage::Load(TFileName FileName) {
	TPngImage* PNGImage = new TPngImage();
	PNGImage->LoadFromFile(FileName);
	Element->Canvas->Draw(0, 0, PNGImage);
	delete PNGImage;
}

PainterImage::~PainterImage() {}
