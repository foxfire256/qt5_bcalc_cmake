# Qt5 BCalc CMake

This is a simple Qt5 application that takes two numbers, performs a calculation, and shows the result.

## Installing Qt5 on Windows

Download the opensource version of the Qt Toolkit. You will need to create an account to install. Don't install the preview builds of Qt in the installer. Install Qt->Qt 5.15.2->MSVC 2019 64-bit.

Add the bin directory of the install directory to your PATH variable. An example is: C:\usr\Qt\5.15.2\msvc2019_64\bin.

## Installing CMake

Install the latest stable, 64 bit version of CMake. Add the bin directory to the PATH variable.

## Building

Create a directory named 'build' in the source directory. Open a command shell or Powershell and change to this build directory. Execute the following:

```
cmake .. -G "Visual Studio 16 2019" -A x64
```

This should create a Visual Studio project file in the build directory. 
