#include "MyForm.h"



using namespace System;

//int main(array<System::String ^> ^args)
//{
//    return 0;
//}

#include "MyForm.h"

using namespace System::Windows::Forms;

[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm::Form1());
	return 0;
}
