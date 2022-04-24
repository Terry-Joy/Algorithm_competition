@echo off  
:loop  
    data.exe>data.in  
    my.exe<data.in>my.out  
    std.exe<data.in>std.out
    fc my.out std.out  
if not errorlevel 1 goto loop  
pause  
goto loop