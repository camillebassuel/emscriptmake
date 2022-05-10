## emscriptmake

# IN BRIEF
simple example to produces a JS bounded cpp lib 
# BUILDING & TESTING  -  INSTRUCTIONS
CMake have to be installed as it's a CMake project :)
After installation and environment variables settings created, the EMSDK directory contains all that is needed to compile the project
#create the target directory called 'thetarget'
mkdir cmake-build-emscripten
## to configure 
emcmake cmake . -B thetarget -G Ninja
## to build
cmake --build .\thetarget
## to test ...
to test the api the test.html file is provided which link to the cmake-build-emscripten/cpp2wasm.js file produced by the compilation

as of security reasons SharedBufferArray and CORS stuffs are now deactivated in browser, in order to the wasm to be loaded  properly , it is better to first start a local server to serve the pages

## ... from python:
python -m http.server -d .

## ...from node.js
npm install -g http-server
cd /targetPAth/thetarget
http-server
