#!/bin/bash
# To be run via travis-ci.org
set -ev
echo "Build each of the snippets in the project"
cd C++/max-age
mkdir build
cd build
cmake ../
make

