#pragma once
#include <wx/wx.h>

class ButtonFactory
{ public:
	static wxButton* CreateButton(wxWindow* parent, int id, const wxString& label);

	
	static wxButton* CreateNumbersButton(wxWindow* parent, int id, const wxString& label);
	static wxButton* CreateAddButton(wxWindow* parent, int id);
	static wxButton* CreateSubtractButton(wxWindow* parent, int id);
	static wxButton* CreateMultiplyButton(wxWindow* parent, int id);
	static wxButton* CreateDivideButton(wxWindow* parent, int id);
	static wxButton* CreateModuloButton(wxWindow* parent, int id);

	static wxButton* CreateClearButton(wxWindow* parent, int id);
	static wxButton* CreateDeleteButton(wxWindow* parent, int id);
	static wxButton* CreateEqualsButton(wxWindow* parent, int id);
	static wxButton* CreateSignageButton(wxWindow* parent, int id);

	static wxButton* CreateSinButton(wxWindow* parent, int id);
	static wxButton* CreateCosButton(wxWindow* parent, int id);
	static wxButton* CreateTanButton(wxWindow* parent, int id);
};

