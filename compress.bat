@echo off

cmake -S . -B build
cmake --build build

rmdir /s /q temp-%1
mkdir temp-%1
cd build/%1

for /r %%i in (*.dll) do (
    copy "%%i" ..\..\temp-%1\
)

for /r ..\..\temp-%1\ %%i in (*.dll) do (
    move "%%i" "%%~dpi\command.dll"
)

copy %1\app.shfl ..\..\temp-%1\

cd ..\..\temp-%1
powershell Compress-Archive -Path .\ -DestinationPath %1.zip
move %1.zip ..\%1_windows.shflapp
cd ..
rmdir /s /q temp-%1
