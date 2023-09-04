REM Replace with your actual folder paths
SET source_folder=C:\dev\CodeByteEngine\CodeByteEngine\
SET destination_folder=C:\dev\CodeByteEngine\bin\Release-windows-x86_64\Sandbox

REM Copy the entire folder and its contents
for %%i in ("%source_folder%\*.hlsl") do (
    xcopy /Y "%%i" "%destination_folder%\"
)
PAUSE