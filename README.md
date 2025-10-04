# Collatz Solver

I wrote this after seeing [Veritasium's video](youtu.be/094y1Z2wpJg) on the problem, and thought it would be a good exercise.

If you run this long enough and prove the conjecture wrong, please credit me in whatever paper you write.

you need to install boost for this, as I started it on the largest number tested for the problem using computers.

To build Boost C++ libraries with Visual Studio, follow these steps:

1. Download and Extract Boost

First, download the latest version of Boost from the official website and extract it to a directory, e.g., C:\boost_1_82_0.

2. Open Developer Command Prompt

Open the Developer Command Prompt for Visual Studio. You can find it in the Start menu under Visual Studio Tools.

3. Bootstrap Boost.Build

Navigate to the Boost directory and run the bootstrap script to prepare the build system:
cd C:\boost_1_82_0
bootstrap.bat

4. Build Boost Libraries

Run the following command to build the Boost libraries:
b2

This command will build all the necessary Boost libraries.

5. Configure Visual Studio Project

In your Visual Studio project, configure the include directories and library directories:

    Include Directories: Add C:\boost_1_82_0 to your project's include directories.

    Library Directories: Add C:\boost_1_82_0\libs to your project's library directories.

Important Considerations

    Toolset Compatibility: Ensure that you are using a compatible toolset with your version of Boost

    Build Variants: You can specify different build variants (e.g., debug, release) and architectures (e.g., x86, x64) by adding appropriate flags to the b2 command

By following these steps, you can successfully build and integrate Boost C++ libraries with Visual Studio.



Visual Studio Include Directories

Include directories in Visual Studio specify the paths where the compiler searches for header files during the build process. These settings are essential for projects that rely on external libraries or SDKs.

Adding Include Directories to a Project

To add include directories for a specific project:

    Right-click on the project in Solution Explorer and select Properties.

    Navigate to Configuration Properties > VC++ Directories > Include Directories.

    Add the desired paths, separated by semicolons (;).

Example
C:\Libraries\MyLibrary\include;C:\SDKs\Windows\v10.0\Include

Setting Global Include Directories

For global settings across all projects:

    Go to Tools > Options > Projects and Solutions > VC++ Directories.

    Modify the Include Files section to add global paths.

Using Property Sheets for Reusability

To share include paths across multiple projects:

    Open the Property Manager (View > Other Windows > Property Manager).

    Add a new property sheet and configure the include directories under VC++ Directories.

    Attach this property sheet to all relevant projects.

Example of XML Configuration

You can also edit the .props file directly:
<PropertyGroup>
<IncludePath>C:\Libraries\MyLibrary\include;$(IncludePath)</IncludePath>
</PropertyGroup>

Important Considerations

    Use macros like $(ProjectDir) or $(SolutionDir) for portability.

    Avoid hardcoding paths when possible to ensure compatibility across different environments.

    For large projects, exclude stable directories from timestamp checks to improve build performance
    1
    .