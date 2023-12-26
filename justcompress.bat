@echo off

rmdir /s /q temp
mkdir temp

copy %1\app.shfl temp\

powershell Compress-Archive -Path .\temp\* -DestinationPath %1.zip
move %1.zip %1_windows.shflapp
