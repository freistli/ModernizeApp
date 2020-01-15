#include "pch.h"

#include "App.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Windows::Foundation;

namespace winrt::MyAppWinUI3::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    fire_and_forget MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
        Microsoft::UI::Xaml::Controls::ContentDialog cd;
        cd.Content(box_value(L"Hello from WinUI3"));
        auto result = co_await cd.ShowAsync();
    }


    // Add a new Tab to the TabView
     void MainPage::Tabs_AddTabButtonClick(TabView sender, IInspectable e)
    {
        
        TabViewItem newTab;
        newTab.IconSource();
        newTab.Header(box_value(L"New Document"));
        Microsoft::UI::Xaml::Controls::Frame rootFrame;
        newTab.Content(rootFrame);
        rootFrame.Navigate(winrt::xaml_typename<MyAppWinUI3::BlankPage>());
        sender.TabItems().Append(newTab);
       
    }

    // Remove the requested tab from the TabView
     void MainPage::Tabs_TabCloseRequested(TabView sender, TabViewTabCloseRequestedEventArgs args)
     {
         uint32_t tabIndexFromControl = 0;
         sender.TabItems().IndexOf(args.Item(), tabIndexFromControl);
         sender.TabItems().RemoveAt(tabIndexFromControl);
     }

}
