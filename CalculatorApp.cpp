#include "CalculatorApp.h"
#include <wx/tokenzr.h>
#include <cmath>


wxBEGIN_EVENT_TABLE(CalculatorWindow, wxFrame)
EVT_BUTTON(1000, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1001, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1002, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1003, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1004, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1005, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1006, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1007, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1008, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1009, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1010, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1011, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1012, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1013, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1014, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1015, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1016, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1017, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1018, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1019, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1020, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1021, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(1022, CalculatorWindow::OnButtonClicked)
wxEND_EVENT_TABLE()

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

	wxPanel* calc_Panel = new wxPanel(this);

	calc_TextCtrl = new wxTextCtrl(calc_Panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_RIGHT);

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
		int buttonID = 1000;
		calc_Buttons->Add(new wxButton(calc_Panel, buttonID, label), 0, wxEXPAND);
		buttonID++;
	}
	calc_ButtonGrid->Add(calc_Panel, 1, wxEXPAND | wxALL, 5);

	SetSizer(calc_ButtonGrid);
}

void CalculatorWindow::OnButtonClicked(wxCommandEvent& event) {

	int id = event.GetId();
	wxString value = calc_TextCtrl->GetValue();
	wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
	wxString label = button->GetLabel();


	try {
		if (label == "Clear") {
			calc_TextCtrl->Clear();
		}
		else if (label == "Delete") {
			
			if (!value.IsEmpty()) {
				value.RemoveLast();
				calc_TextCtrl->SetValue(value);
			}
		}
		else if (label == "=") {
			
			if (value.IsEmpty()) {
				wxMessageBox("Textbox is empty.");
				return;
			}
			
		wxStringTokenizer tokenizer(value, "+-*/%", wxTOKEN_DEFAULT);
		std::vector<wxString> tokens;

		while (tokenizer.HasMoreTokens()) {
			tokens.push_back(tokenizer.GetNextToken());
		}

		double result = 0.0;
		bool hasOperator = false;
		double currentNum = 0;
		char currentOp = '+';
		
		for (const wxString& token : tokens) {
			if (token.IsNumber() || (token.Length() > 1 && token[0] == '-' && token.SubString(1,token.Length() - 1).IsNumber())) {
				currentNum = std::stod(std::string(token.mb_str()));
			}
			else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%") {

			}
		}
		}
		else {
			calc_TextCtrl->AppendText(label);
		}
	}
	catch (const std::exception& error) {
		wxMessageBox("Error: " + wxString(error.what()));
	}
}