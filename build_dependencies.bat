@echo off

:: Set the script variable space to local
SETLOCAL

:: Check if vcpkg is on the path
where vcpkg.exe >nul 2>&1
if %errorlevel% neq 0 (
    echo vcpkg.exe not found. Please ensure it is in your PATH.
    PAUSE
    exit /b 1
)

:: Install the dependencies for the proper triplet (windows)
set triplet=x64-windows-static
echo Running command vcpkg install --triplet %triplet%
vcpkg.exe install --triplet %triplet%

if %errorlevel% neq 0 (
    echo Failed to install packages.
    PAUSE
    exit /b 1
)

pause
ENDLOCAL
