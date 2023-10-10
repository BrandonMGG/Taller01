@echo off
setlocal enabledelayedexpansion

rem Number of times to run the program
set num_loops=100

rem Output directory for results
set results_dir=resultsDaxpy

rem Create the results directory if it doesn't exist
if not exist %results_dir% mkdir %results_dir%

rem Loop to run the program multiple times
for /l %%i in (1, 1, %num_loops%) do (
    echo Running iteration %%i
    daxpy.exe > %results_dir%\daxpy_%%i.txt
)

echo All iterations completed.