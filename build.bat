@echo off
for /D %%i in (*) do (
    cd %%i
    tar.exe --exclude="%%i.sapp" -cf "%%i.sapp" *
    move "%%i.sapp" ..
    cd ..
)