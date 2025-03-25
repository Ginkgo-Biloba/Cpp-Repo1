
@echo off
if defined VSCMD_ARG_TGT_ARCH ( exit /b 0 )
echo set clenv
set CommandPromptType=Native
set DevEnvDir=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\
set ExtensionSdkDir=C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs
set Framework40Version=v4.0
set FrameworkDir=C:\Windows\Microsoft.NET\Framework64\
set FrameworkDir64=C:\Windows\Microsoft.NET\Framework64\
set FrameworkVersion=v4.0.30319
set FrameworkVersion64=v4.0.30319
set FSHARPINSTALLDIR=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\FSharp\Tools
set HTMLHelpDir=C:\Program Files (x86)\HTML Help Workshop
set INCLUDE=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\ATLMFC\include;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\include;C:\Program Files (x86)\Windows Kits\NETFXSDK\4.8\include\um;C:\Program Files (x86)\Windows Kits\10\include\10.0.19041.0\ucrt;C:\Program Files (x86)\Windows Kits\10\include\10.0.19041.0\shared;C:\Program Files (x86)\Windows Kits\10\include\10.0.19041.0\um;C:\Program Files (x86)\Windows Kits\10\include\10.0.19041.0\winrt;C:\Program Files (x86)\Windows Kits\10\include\10.0.19041.0\cppwinrt
set LIB=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\ATLMFC\lib\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\lib\x64;C:\Program Files (x86)\Windows Kits\NETFXSDK\4.8\lib\um\x64;C:\Program Files (x86)\Windows Kits\10\lib\10.0.19041.0\ucrt\x64;C:\Program Files (x86)\Windows Kits\10\lib\10.0.19041.0\um\x64
set LIBPATH=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\ATLMFC\lib\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\lib\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\lib\x86\store\references;C:\Program Files (x86)\Windows Kits\10\UnionMetadata\10.0.19041.0;C:\Program Files (x86)\Windows Kits\10\References\10.0.19041.0;C:\Windows\Microsoft.NET\Framework64\v4.0.30319
set NETFXSDKDir=C:\Program Files (x86)\Windows Kits\NETFXSDK\4.8\
set Path=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\bin\HostX64\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\VC\VCPackages;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\TeamFoundation\Team Explorer;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\bin\Roslyn;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Team Tools\Performance Tools\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Team Tools\Performance Tools;C:\Program Files (x86)\Microsoft Visual Studio\Shared\Common\VSPerfCollectionTools\vs2019\x64;C:\Program Files (x86)\Microsoft Visual Studio\Shared\Common\VSPerfCollectionTools\vs2019\;C:\Program Files (x86)\Microsoft SDKs\Windows\v10.0A\bin\NETFX 4.8 Tools\x64\;C:\Program Files (x86)\HTML Help Workshop;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\FSharp\Tools;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\devinit;C:\Program Files (x86)\Windows Kits\10\bin\10.0.19041.0\x64;C:\Program Files (x86)\Windows Kits\10\bin\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin;C:\Windows\Microsoft.NET\Framework64\v4.0.30319;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\;%Path%;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\VC\Linux\bin\ConnectionManagerExe
set Platform=x64
set UCRTVersion=10.0.19041.0
set UniversalCRTSdkDir=C:\Program Files (x86)\Windows Kits\10\
set VCIDEInstallDir=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\VC\
set VCINSTALLDIR=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\
set VCToolsInstallDir=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\
set VCToolsRedistDir=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Redist\MSVC\14.29.30133\
set VCToolsVersion=14.29.30133
set VisualStudioVersion=16.0
set VS160COMNTOOLS=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\
set VSCMD_ARG_app_plat=Desktop
set VSCMD_ARG_HOST_ARCH=x64
set VSCMD_ARG_TGT_ARCH=x64
set VSCMD_VER=16.11.45
set VSINSTALLDIR=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\
set WindowsLibPath=C:\Program Files (x86)\Windows Kits\10\UnionMetadata\10.0.19041.0;C:\Program Files (x86)\Windows Kits\10\References\10.0.19041.0
set WindowsSdkBinPath=C:\Program Files (x86)\Windows Kits\10\bin\
set WindowsSdkDir=C:\Program Files (x86)\Windows Kits\10\
set WindowsSDKLibVersion=10.0.19041.0\
set WindowsSdkVerBinPath=C:\Program Files (x86)\Windows Kits\10\bin\10.0.19041.0\
set WindowsSDKVersion=10.0.19041.0\
set WindowsSDK_ExecutablePath_x64=C:\Program Files (x86)\Microsoft SDKs\Windows\v10.0A\bin\NETFX 4.8 Tools\x64\
set WindowsSDK_ExecutablePath_x86=C:\Program Files (x86)\Microsoft SDKs\Windows\v10.0A\bin\NETFX 4.8 Tools\
