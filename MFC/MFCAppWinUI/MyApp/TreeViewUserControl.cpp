#include "pch.h"
#include "TreeViewUserControl.h"
#if __has_include("TreeViewUserControl.g.cpp")
#include "TreeViewUserControl.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::MyApp::implementation
{
    TreeViewUserControl::TreeViewUserControl()
    {
        InitializeComponent();
    }

    int32_t TreeViewUserControl::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void TreeViewUserControl::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void TreeViewUserControl::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
        winrt::Microsoft::UI::Xaml::Controls::TreeViewNode tn = winrt::Microsoft::UI::Xaml::Controls::TreeViewNode{};
        tn.Content(winrt::box_value(L"Clicked"));
        WinUITreeView().RootNodes().First().Current().Children().Append(tn);
    }
}
