#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include "Wnd.h"

class FileDialog : public Wnd
{
public:
	FileDialog();
	FileDialog(String _id);
	FileDialog(const FileDialog& _cpy);

	void open();
	void save();
	String get();

protected:
	String fName;
};

#endif
