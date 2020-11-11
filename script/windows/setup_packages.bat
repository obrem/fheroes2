@echo off

if not exist "..\zlib"         mkdir "..\zlib"
if not exist "..\zlib\include" mkdir "..\zlib\include"
if not exist "..\zlib\lib"     mkdir "..\zlib\lib"
if not exist "..\zlib\lib\x86" mkdir "..\zlib\lib\x86"
if not exist "..\zlib\lib\x64" mkdir "..\zlib\lib\x64"
if not exist "..\sdl"          mkdir "..\sdl"
if not exist "..\sdl\include"  mkdir "..\sdl\include"
if not exist "..\sdl\lib"      mkdir "..\sdl\lib"
if not exist "..\sdl2"         mkdir "..\sdl2"
if not exist "..\sdl2\include" mkdir "..\sdl2\include"
if not exist "..\sdl2\lib"     mkdir "..\sdl2\lib"

xcopy /Y /s /Q "sdl\SDL-1.2.15\include"  "..\sdl\include"
xcopy /Y /s /Q "sdl\SDL-1.2.15\lib"      "..\sdl\lib"
xcopy /Y /s /Q "sdl\SDL2-2.0.12\include" "..\sdl2\include"
xcopy /Y /s /Q "sdl\SDL2-2.0.12\lib"     "..\sdl2\lib"

xcopy /Y /s /Q "sdl_mixer\SDL_mixer-1.2.12\include"                "..\sdl\include"
xcopy /Y /s /Q "sdl_mixer\SDL_mixer-1.2.12\lib\x86\SDL_mixer.dll"  "..\sdl\lib\x86"
xcopy /Y /s /Q "sdl_mixer\SDL_mixer-1.2.12\lib\x86\SDL_mixer.lib"  "..\sdl\lib\x86"
xcopy /Y /s /Q "sdl_mixer\SDL_mixer-1.2.12\lib\x86\libogg-0.dll" "..\sdl\lib\x86"
xcopy /Y /s /Q "sdl_mixer\SDL_mixer-1.2.12\lib\x86\libvorbis-0.dll" "..\sdl\lib\x86"
xcopy /Y /s /Q "sdl_mixer\SDL_mixer-1.2.12\lib\x86\libvorbisfile-3.dll" "..\sdl\lib\x86"
xcopy /Y /s /Q "sdl_mixer\SDL_mixer-1.2.12\lib\x64\SDL_mixer.dll"  "..\sdl\lib\x64"
xcopy /Y /s /Q "sdl_mixer\SDL_mixer-1.2.12\lib\x64\SDL_mixer.lib"  "..\sdl\lib\x64"
xcopy /Y /s /Q "sdl_mixer\SDL_mixer-1.2.12\lib\x64\libogg-0.dll" "..\sdl\lib\x64"
xcopy /Y /s /Q "sdl_mixer\SDL_mixer-1.2.12\lib\x64\libvorbis-0.dll" "..\sdl\lib\x64"
xcopy /Y /s /Q "sdl_mixer\SDL_mixer-1.2.12\lib\x64\libvorbisfile-3.dll" "..\sdl\lib\x64"
xcopy /Y /s /Q "sdl_mixer\SDL2_mixer-2.0.4\include"                "..\sdl2\include"
xcopy /Y /s /Q "sdl_mixer\SDL2_mixer-2.0.4\lib\x86\SDL2_mixer.dll" "..\sdl2\lib\x86"
xcopy /Y /s /Q "sdl_mixer\SDL2_mixer-2.0.4\lib\x86\SDL2_mixer.lib" "..\sdl2\lib\x86"
xcopy /Y /s /Q "sdl_mixer\SDL2_mixer-2.0.4\lib\x86\libogg-0.dll" "..\sdl2\lib\x86"
xcopy /Y /s /Q "sdl_mixer\SDL2_mixer-2.0.4\lib\x86\libvorbis-0.dll" "..\sdl2\lib\x86"
xcopy /Y /s /Q "sdl_mixer\SDL2_mixer-2.0.4\lib\x86\libvorbisfile-3.dll" "..\sdl2\lib\x86"
xcopy /Y /s /Q "sdl_mixer\SDL2_mixer-2.0.4\lib\x64\SDL2_mixer.dll" "..\sdl2\lib\x64"
xcopy /Y /s /Q "sdl_mixer\SDL2_mixer-2.0.4\lib\x64\SDL2_mixer.lib" "..\sdl2\lib\x64"
xcopy /Y /s /Q "sdl_mixer\SDL2_mixer-2.0.4\lib\x64\libogg-0.dll" "..\sdl2\lib\x64"
xcopy /Y /s /Q "sdl_mixer\SDL2_mixer-2.0.4\lib\x64\libvorbis-0.dll" "..\sdl2\lib\x64"
xcopy /Y /s /Q "sdl_mixer\SDL2_mixer-2.0.4\lib\x64\libvorbisfile-3.dll" "..\sdl2\lib\x64"

xcopy /Y /s /Q "zlib\include" "..\zlib\include"
xcopy /Y /s /Q "zlib\lib\x86" "..\zlib\lib\x86"
xcopy /Y /s /Q "zlib\lib\x64" "..\zlib\lib\x64"
