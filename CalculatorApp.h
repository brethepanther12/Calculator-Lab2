#pragma once
#include "wx/wx.h"
class CalculatorWindow: public wxFrame {
public:
	CalculatorWindow(const wxString& title);

private:
	wxTextCtrl* calc_TextCtrl;

	void CalculatorUI();
};
class CalculatorApp : public wxApp
{
public:
	virtual bool OnInit();
};

