@echo off
setlocal

cd. > %2

for %%i in (%1\*.txt) do (
	echo %%~ni >> %2
)

sort %2

echo New file has been created