#include "pch.h"
#include "../../Calculator-Lab2/ButtonFactory.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorDesignUIEventHandlingTest 
{

	TEST_CLASS(ButtonFactoryTest) {
public:
	TEST_METHOD(TestCreateButton) 
	{
		wxString label = "Button";
		wxButton* button = ButtonFactory::CreateButton(nullptr, 1001, label);
		Assert::IsNotNull(button);
		Assert::AreEqual(button->GetLabel(), label);
		delete button;
	
	};
	TEST_METHOD(TestCreateAddButton) 
	{
	
		wxButton* button = ButtonFactory::CreateAddButton(nullptr, 1002);
		Assert::IsNotNull(button);
		Assert::AreEqual(button->GetLabel(), "+");
		delete button;
	
	};
	TEST_METHOD(TestCreateSubtractButton)
	{
		wxButton* button = ButtonFactory::CreateSubtractButton(nullptr, 1003);
		Assert::IsNotNull(button);
		Assert::AreEqual(button->GetLabel(), "-");
		delete button;
	};
	TEST_METHOD(TestCreateMultiplyButton)
	{
		wxButton* button = ButtonFactory::CreateMultiplyButton(nullptr, 1004);
		Assert::IsNotNull(button);
		Assert::AreEqual(button->GetLabel(), "*");
		delete button;
	};
	TEST_METHOD(TestCreateDivideButton)
	{
		wxButton* button = ButtonFactory::CreateDivideButton(nullptr, 1005);
		Assert::IsNotNull(button);
		Assert::AreEqual(button->GetLabel(), "/");
		delete button;
	};
	TEST_METHOD(TestCreateModuloButton)
	{
		wxButton* button = ButtonFactory::CreateModuloButton(nullptr, 1006);
		Assert::IsNotNull(button);
		Assert::AreEqual(button->GetLabel(), "%");
		delete button;
	};
	TEST_METHOD(TestCreateDecimalButton)
	{
		wxButton* button = ButtonFactory::CreateDecimalButton(nullptr, 1007);
		Assert::IsNotNull(button);
		Assert::AreEqual(button->GetLabel(), ".");
		delete button;
	};
	TEST_METHOD(TestCreateSignageButton)
	{
		wxButton* button = ButtonFactory::CreateSignageButton(nullptr, 1008);
		Assert::IsNotNull(button);
		Assert::AreEqual(button->GetLabel(), "+/-");
		delete button;
	};
	TEST_METHOD(TestCreateClearButton)
	{
		wxButton* button = ButtonFactory::CreateClearButton(nullptr, 1009);
		Assert::IsNotNull(button);
		Assert::AreEqual(button->GetLabel(), "Clear");
		delete button;
	};
	TEST_METHOD(TestCreateDeleteButton)
	{
		wxButton* button = ButtonFactory::CreateDeleteButton(nullptr, 1010);
		Assert::IsNotNull(button);
		Assert::AreEqual(button->GetLabel(), "Delete");
		delete button;
	};

	};

}