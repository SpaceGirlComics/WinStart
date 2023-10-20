#include "FileDialog.h"

FileDialog::FileDialog()
{
}

FileDialog::FileDialog(String _id) : Wnd(_id)
{
}

FileDialog::FileDialog(const FileDialog& _cpy) : Wnd((Wnd)_cpy)
{

}

void FileDialog::open()
{
	fName = "";
	char file[256];
	file[0] = '\0';

	OPENFILENAME fileName;
	ZeroMemory(&fileName, sizeof(OPENFILENAME));
	fileName.lStructSize = sizeof(OPENFILENAME);
	fileName.lpstrFile = file;
	fileName.nMaxFile = 256;
	fileName.lpstrFilter = "Portable Network Graphics\0*.png\0Targa Graphics\0*.tga\0Bitmap\0*.bmp\0\0";
	fileName.hInstance = GetModuleHandle(NULL);
	fileName.Flags = OFN_DONTADDTORECENT | OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	GetOpenFileName(&fileName);

	fName += file;
}

void FileDialog::save()
{
	fName = "";
	char file[256];
	file[0] = '\0';

	OPENFILENAME fileName;
	ZeroMemory(&fileName, sizeof(OPENFILENAME));
	fileName.lStructSize = sizeof(OPENFILENAME);
	fileName.lpstrFile = file;
	fileName.nMaxFile = 256;
	fileName.lpstrFilter = "Portable Network Graphics\0*.png\0Targa Graphics\0*.tga\0Bitmap\0*.bmp\0\0";
	fileName.hInstance = GetModuleHandle(NULL);
	fileName.Flags = OFN_DONTADDTORECENT | OFN_EXPLORER;
	GetSaveFileName(&fileName);
	fName += file;
}

String FileDialog::get()
{
	return(fName);
}


