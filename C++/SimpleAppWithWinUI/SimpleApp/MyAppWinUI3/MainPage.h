#pragma once
#include "MainPage.g.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml::Controls;

namespace winrt::MyAppWinUI3::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        fire_and_forget  ClickHandler(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        void Tabs_AddTabButtonClick(Microsoft::UI::Xaml::Controls::TabView sender, IInspectable e);


        void Tabs_TabCloseRequested(TabView sender, TabViewTabCloseRequestedEventArgs args);
    };
}

namespace winrt::MyAppWinUI3::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
