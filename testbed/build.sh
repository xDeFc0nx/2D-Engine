#!/bin/fish

# Building testbed
echo "Building testbed..."

mkdir -p ../bin

set cFilenames (find . -type f -name "*.c")

#echo "Files:" $cFilenames

set assembly testbed
set compilerFlags -g -fdeclspec -fPIC
set includeFlags -Isrc -I../engine/src/
set linkerFlags -L../bin/ -lengine -Wl,-rpath,.
set defines "-D_DEBUG -DKIMPORT"

echo "Building $assembly..."

# Use string splitting to pass compiler flags correctly
set -l compilerFlagsArray $compilerFlags
clang $cFilenames $compilerFlagsArray -o ../bin/$assembly $defines $includeFlags $linkerFlags
