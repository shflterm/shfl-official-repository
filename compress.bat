@echo off

cmake -S . -B build
cmake --build build

rmdir /s /q temp
mkdir temp
cd build\%1

for /r %%i in (*.dll) do (
    set filename=%%~ni
    mkdir ..\..\temp\lib\%%~ni
    copy "%%i" ..\..\temp\lib\%%~ni\command.dll
)

cd ..\..

copy %1\app.shfl temp\

cd temp
powershell Compress-Archive -Path .\ -DestinationPath %1.zip
move %1.zip ..\%1_windows.shflapp
cd ..
