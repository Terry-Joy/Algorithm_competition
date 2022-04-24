@echo off
:loop
    c > data.in
    a < data.in > a.out
    b < data.in > b.out
    fc a.out b.out
if not errorlevel 1 goto loop
pause
goto loop