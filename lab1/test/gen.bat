@echo off
setlocal
for /l %%i in (1, 1, 10) do (
	getrandom
)
pause