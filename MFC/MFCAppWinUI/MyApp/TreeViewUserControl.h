#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "TreeViewUserControl.g.h"

namespace winrt::MyApp::implementation
{
    struct TreeViewUserControl : TreeViewUserControlT<TreeViewUserControl>
    {
        TreeViewUserControl();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::MyApp::factory_implementation
{
    struct TreeViewUserControl : TreeViewUserControlT<TreeViewUserControl, implementation::TreeViewUserControl>
    {
    };
}
