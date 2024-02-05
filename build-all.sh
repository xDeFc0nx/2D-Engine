#!/bin/fish
# Build script for rebuilding everything
echo "Building everything..."

pushd engine
source build.sh
popd

set ERRORLEVEL $status
if test $ERRORLEVEL -ne 0
    echo "Error: $ERRORLEVEL"
    exit
end

pushd testbed
source build.sh
popd

set ERRORLEVEL $status
if test $ERRORLEVEL -ne 0
    echo "Error: $ERRORLEVEL"
    exit
end

echo "All assemblies built successfully."
