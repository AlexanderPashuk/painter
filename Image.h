//---------------------------------------------------------------------------

#ifndef ImageH
#define ImageH
//---------------------------------------------------------------------------
#endif

#include <vcl.h>


class PainterImage {
	private:
		TImage* Element;
        TPoint CurrentPixel;
	public:
		PainterImage(TImage* ImageElement);
		void ClearCanvas();
		TPoint GetNextPixel();
        void FillPixel(TPoint Pixel, TColor Color);
		void DrawLine(TPoint FirstPoint, TPoint SecondPoint);
		void DrawRect(TPoint FirstPoint, TPoint SecondPoint);
		void DrawEllipse(TPoint FirstPoint, TPoint SecondPoint);
		void UpdatePenStyle(TPenStyle Style);
        void Resize();
		void Save(TFileName FileName);
		void Load(TFileName FileName);
		~PainterImage();
};