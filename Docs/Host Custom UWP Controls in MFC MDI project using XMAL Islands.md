# Host Custom UWP Controls in MFC MDI Project using XAML Islands

This article explains how to modernize MFC MDI project with custom UWP Controls through XAML Islands. With custom UWP controls, it allows us to define control layout easily through XAML pages. Not only putting standard UWP controls into the custom control, we can also integrate other custom controls as well, such as latest WinUI controls. We will use a new Xaml Application project to bring the custom UWP controls into our MFC project. This [article](https://docs.microsoft.com/en-us/windows/apps/desktop/modernize/using-the-xaml-hosting-api#host-a-custom-uwp-control) has mentioned how to use the new XAML application in Win32 C++ application, we will give more detailed steps for MFC project.

Overall, in our MFC project, we will have two parts to demonstrate this method:

* MFC MDI Project
* A companion UWP app project that defines a XamlApplication object.  
  In this project, we will define a custom UWP control and export it so that MFC can use the custom UWP control.

## Development Environment  

* Visual Studio 2019 (16.3.6)  
* Windows 10 1909 (18363.476)  
* Windows 10 SDK (10.0.18362.1)  

## Configure MFC Project

1. Create MFC App in Visual Studio 2019, will name it MFCAPP

    <img src="../images/MFC/0.png" width="400">

    Use below configuration to create the MFCAPP project
    
    <img src="../images/MFC/1.png" width="400">

    click **Finish** Build and Run it, here is its default UI

    ![image](../images/MFC/2.png) 

    
  
2. In Solution Explorer, right-click the MFCAPP project node,    click **Retarget Project**, select the **10.0.18362.0** or    a later SDK release, and then click OK.
 
   <img src="../images/MFC/3.png" width="300">

   <img src="../images/MFC/4.png" width="300">
 
3.	Install the Microsoft.Windows.CppWinRT NuGet package:

    a.	Right-click the project in Solution Explorer and choose Manage NuGet Packages.
    b.	Select the Browse tab, search for the **Microsoft.Windows.CppWinRT** package, and install the latest version of this package.  

    ![image](../images/MFC/5.png)  


    After install the nuget package, check the MFC project properties, you will notice its C++ version is ISO C++17, which is required by C++/WinRT:

    ![image](../images/MFC/6.png)
 
    Build this MFCApp, we can see winrt projected files are generated in the “Generated Files\winrt” folder:

    ![image](../images/MFC/7.png)
 

4.	Install the **Microsoft.Toolkit.Win32.UI.SDK** NuGet          package:

    a.	In the NuGet Package Manager window, make sure that Include prerelease is selected.  
    b.	Select the Browse tab, search for the **Microsoft.Toolkit.Win32.UI.SDK** package, and install version v6.0.0 (or Later) of this package.

    ![image](../images/MFC/8.png)

## Configure UWP Project

