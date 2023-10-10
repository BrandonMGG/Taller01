@echo off
setlocal enabledelayedexpansion

rem Number of times to run the program
set num_loops=100

rem Output directory for results
set resultsTaylor_dir=resultsTaylor

rem Create the results directory if it doesn't exist
if not exist %resultsTaylor_dir% mkdir %resultsTaylor_dir%

rem Loop to run the program multiple times
for /l %%i in (1, 1, %num_loops%) do (
    echo Running iteration %%i
    taylor.exe > %resultsTaylor_dir%\taylor_%%i.txt
)

echo All iterations completed.