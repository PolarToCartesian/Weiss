:: Open the "x64 Native Tools Command Prompt for VS 2019"
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"

:: Compile
call "scripts/internal/win.bat" win64.exe "C:\VulkanSDK\Lib"

:: Run
call "bin/win64.exe"

pause