mkdir bin

:: You can modify :
:: - the "LIBPATH" option
:: - The "/I" options
cl Source.cpp /I "C:\VulkanSDK\Include" ^
              /I "C:\Code\3D Engines\Realtime\Weiss\Weiss\d3dx12" ^
              /fp:fast /O2 /Ot /Ob3 /EHsc /std:c++17 ^
              /link /LIBPATH:%2 /OUT:bin/%1

del Source.obj