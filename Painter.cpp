//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("App.cpp", App);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TApp), &App);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}

	return 0;
}
//---------------------------------------------------------------------------
