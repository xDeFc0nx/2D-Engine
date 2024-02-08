#!/bin/fish

# Building testbed
echo "Building testbed..."

mkdir -p ../bin

set cFilenames (find . -type f -name "*.c")

#echo "Files:" $cFilenames

set assembly testbed
set compilerFlags -g -fPIC
set includeFlags -Isrc -I../engine/src/ -I../engine/src/core/
set linkerFlags -L../bin/ -lengine -L/usr/lib -L/usr/X11R6/lib -lGL -lX11 -lglfw -lGLEW -Wl,-rpath,.

set defines "-D_DEBUG -DKIMPORT"

echo "Building $assembly..."

# Use string splitting to pass compiler flags correctly
set -l compilerFlagsArray $compilerFlags
clang $cFilenames $compilerFlagsArray -o ../bin/$assembly $defines $includeFlags $linkerFlags
