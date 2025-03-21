#pragma once
#include <wx/wx.h>
#include <vector>
#include <string>
#include <exception>
#include <wx/tokenzr.h>
#include "ButtonFactory.h"

class CalculatorWindow : public wxFrame {
public:
    CalculatorWindow(const wxString& title);
    ~CalculatorWindow();

private:
    wxPanel* calc_Panel;
    wxTextCtrl* calc_TextCtrl;
    wxGridSizer* calc_ButtonGrid;

    static const int BUTTON_BASE_ID = 1000;

    void OnButtonClicked(wxCommandEvent& event);
    std::vector<wxString> Tokenize(const wxString& input);
    double EvaluateExpression(const std::vector<wxString>& tokens);

    wxDECLARE_EVENT_TABLE();
};
class CalculatorApp : public wxApp
{
public:
	virtual bool OnInit();
};

