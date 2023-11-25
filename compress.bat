@echo off

cmake -S . -B build
cmake --build build

rmdir /s /q temp
mkdir temp\lib
cd build\%1

for /r %%i in (*.dll) do (
    copy "%%i" ..\..\temp\lib\
)

for /r ..\..\temp\lib\ %%i in (*.dll) do (
    move "%%i" "%%~dpi\command.dll"
)

cd ..\..

copy %1\app.shfl temp\

cd temp
powershell Compress-Archive -Path .\ -DestinationPath %1.zip
move %1.zip ..\%1_windows.shflapp
cd ..
