@echo off
copy cmddraw\*.cpp *.cpp >NUL
if not exist x86\ mkdir x86
if not exist x64\ mkdir x64
g++ -Os -s -m64 cmddraw.cpp -o cmddraw.exe -lgdiplus -municode
copy cmddraw.exe x64\ >Nul
del *.exe
g++ -Os -s -m32 cmddraw.cpp -o cmddraw.exe -lgdiplus -municode
copy cmddraw.exe x86\ >Nul
del *.exe
del *.cpp
echo Done!
pause>Nul
