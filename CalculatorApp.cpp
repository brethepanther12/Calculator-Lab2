#include "CalculatorApp.h"

wxIMPLEMENT_APP(CalculatorApp);

bool CalculatorApp::OnInit() {
	CalculatorWindow* calc_window = new CalculatorWindow("Calculator");
	calc_window->Show(true);
	return true;
}

CalculatorWindow::CalculatorWindow(const wxString& title) : wxFrame (nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(300, 400)) {
	CalculatorUI();
}

void CalculatorWindow::CalculatorUI() {
	wxBoxSizer* calc_ButtonGrid = new wxBoxSizer(wxVERTICAL);

	calc_TextCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_RIGHT);

	calc_ButtonGrid->Add(calc_TextCtrl, 0, wxEXPAND | wxALL, 5);

	wxGridSizer* calc_Buttons = new wxGridSizer(5, 5, 5, 5);

	const std::vector<wxString> calc_button_labels =
	{
		"7","8","9","/","sin",
		"4","5","6", "*", "cos",
		"1","2","3", "-","tan",
		"0", ".", "=","+", "%",
		"Clear", "Delete", "+/-"
	};

	for (const auto& label : calc_button_labels) {
		calc_Buttons->Add(new wxButton(this, wxID_ANY, label), 0, wxEXPAND);
	}
	calc_ButtonGrid->Add(calc_Buttons, 1, wxEXPAND | wxALL, 5);

	SetSizer(calc_ButtonGrid);
}
