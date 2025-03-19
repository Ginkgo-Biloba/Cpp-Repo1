echo off
set TMP=R:\
set TEMP=R:\
set srcdir=.0001-1000
set choise=2

if %choise% == 0 (
	call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
	for %%w in (%srcdir%\*.cpp) do (
		cl.exe /nologo /EHsc /arch:AVX2 /W4 /O1 /Fo:R:\ /Fe:R:\main.exe /I. %%w
	)
) else if %choise% == 1 (
	for %%w in (%srcdir%\*.cpp) do (
		echo %%w
		clang++.exe -mavx2 -masm=intel -O0 -Wall -Wextra -pedantic -Werror -Wcast-align -Wconversion -Wpointer-arith -Wshadow -Wreturn-type -Wno-sign-conversion -fsanitize=undefined -fsanitize=address -include-pch leetcode.hpp.pch -o R:\main.exe %%w -I.
	)
) else if %choise% == 2 (
	for %%w in (%srcdir%\*.cpp) do (
		echo %%w
		clang-format.exe -i %%w
	)
) else (
	echo choise %choise%
)

