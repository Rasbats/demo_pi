call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars32.bat"
set WXWIN=C:\wxWidgets-3.1.2
set wxWidgets_ROOT_DIR=%WXWIN%
set wxWidgets_LIB_DIR=%WXWIN%\lib\vc_dll
set wxWidgets_INCLUDE_DIRS=%WXWIN%\include

set PATH=%PATH%;%WXWIN%;%wxWidgets_LIB_DIR%;%wxWidgets_INCLUDE_DIRS%;C:\Program Files (x86)\Poedit\Gettexttools\bin;
set PATH=C:\Program Files\Cmake\bin;%PATH%

cd ../

mkdir  build
cd build
cmake -T v141_xp ..
cmake -G "Visual Studio 15 2017" --config release  ..
cmake --build . --target tarball --config release

cmd /k
