@echo off  
:loop  
    data.exe>data.in  
    std.exe<data.in>std.out  
    real_std.exe<data.in>real_std.out
    fc std.out real_std.out  
if not errorlevel 1 goto loop  
pause  
goto loop