#pragma once

#include "BlankPage.g.h"

namespace winrt::MyAppWinUI3::implementation
{
    struct BlankPage : BlankPageT<BlankPage>
    {
        BlankPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::MyAppWinUI3::factory_implementation
{
    struct BlankPage : BlankPageT<BlankPage, implementation::BlankPage>
    {
    };
}
