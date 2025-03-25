echo off
set TMP=R:\
set TEMP=R:\
set srcdir=.2001-3000\25*.cpp
set choice=0

echo %time%
if %choice% == 0 (
	if not defined VSCMD_ARG_TGT_ARCH ( call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat" )
	echo #include "leetcode.hpp" > precomp.cpp
	cl.exe /nologo /EHsc /arch:AVX2 /W4 /WX /Z7 /MDd /fsanitize=address /Ycleetcode.hpp /Foleetcode.obj /c precomp.cpp
	del precomp.cpp
	for %%w in (%srcdir%) do (
		cl.exe /nologo /EHsc /arch:AVX2 /W4 /WX /Z7 /MDd /fsanitize=address /FdR:\ /FoR:\ /FeR:\main.exe /I. /Yuleetcode.hpp leetcode.obj %%w
	)
) else if %choice% == 1 (
	clang++.exe -mavx2 -masm=intel -O0 -Wall -Wextra -pedantic -Werror -Wcast-align -Wconversion -Wpointer-arith -Wshadow -Wreturn-type -Wno-sign-conversion -fsanitize=undefined -fsanitize=address -o leetcode.pch -c leetcode.hpp
	for %%w in (%srcdir%) do (
		echo %%w
		clang++.exe -mavx2 -masm=intel -O0 -Wall -Wextra -pedantic -Werror -Wcast-align -Wconversion -Wpointer-arith -Wshadow -Wreturn-type -Wno-sign-conversion -fsanitize=undefined -fsanitize=address -include-pch leetcode.pch -o R:\main.exe %%w -I.
	)
) else if %choice% == 2 (
	for %%w in (%srcdir%) do (
		echo %%w
		clang-format.exe -i %%w
	)
) else (
	echo choice %choice%
)
echo %time% 
