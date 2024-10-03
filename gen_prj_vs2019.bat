@echo off

if exist "Builds" (
    echo Directory builds\ already exists.
) else (
    echo Creating builds directory...
    mkdir builds
)


pushd Builds
cmake -G "Visual Studio 16 2019" -A x64 ..
popd