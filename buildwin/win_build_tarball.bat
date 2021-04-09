call "win_deps.bat"

cd ../

mkdir  build
cd build
cmake -T v141_xp ..
cmake -G "Visual Studio 15 2017" --config release  ..
cmake --build . --target tarball --config release

cmd /k
