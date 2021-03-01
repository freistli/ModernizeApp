#pragma once

#include "resource.h"
//Build in VS 16.8.6, reported std::back_insert error. Add additional headers
#include <algorithm>
#include <iterator>
#include <set>

#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.system.h>
#include <winrt/windows.ui.xaml.hosting.h>
#include <windows.ui.xaml.hosting.desktopwindowxamlsource.h>
#include <winrt/windows.ui.xaml.controls.h>
#include <winrt/Windows.ui.xaml.media.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/myapp.h>
