:: Open the "x86 Native Tools Command Prompt for VS 2019"
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat"

cd ../

:: Compile
call "win_cl.bat" win32.exe "C:\VulkanSDK\Lib32"

:: Run
call "bin/win32.exe"

pause