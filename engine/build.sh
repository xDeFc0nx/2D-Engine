#!/bin/fish

# Build script for engine

echo "Building engine..."

mkdir -p ../bin

# Get a list of all the .c files.
set cFilenames (find . -type f -name "*.c")

echo "Files:" $cFilenames

set assembly engine
set compilerFlags -g -shared -fdeclspec -fPIC
set includeFlags -Isrc
set linkerFlags "-L/usr/lib -L/usr/X11R6/lib -lGL -lX11"
set defines "-D_DEBUG -DKEXPORT"

echo "Building $assembly..."

# Use string splitting to pass compiler flags correctly
set -l compilerFlagsArray $compilerFlags
clang $cFilenames $compilerFlagsArray -o ../bin/lib$assembly.so $defines $includeFlags $linkerFlags
