#include "pch.h"
#include "MainUserControl.h"
#if __has_include("MainUserControl.g.cpp")
#include "MainUserControl.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::MyApp::implementation
{
    MainUserControl::MainUserControl()
    {
        InitializeComponent();
        ic().InkPresenter().InputDeviceTypes((winrt::Windows::UI::Core::CoreInputDeviceTypes)7);
        it().TargetInkCanvas(ic());
    }

    int32_t MainUserControl::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainUserControl::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    /*
    void MainUserControl::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
    */
}
