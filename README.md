# emscriptmake
buildable example to produces a JS bounded cpp lib 

llvm has to be installed anbd environnment variable has to be set 

#create the target directory called 'cmake-build-emscripten'
mkdir cmake-build-emscripten
#to configure 
emcmake cmake . -B cmake-build-emscripten -G Ninja
#to build
cmake --build .\cmake-build-emscripten

to test the api the test.html file is provided which link to the cmake-build-emscripten/cpp2wasm.js file produced by the compilation

as of security reasons SharedBufferArray and CORS stuffs are now deactivated in browser, in order to the wasm to be loaded  properly , it is better to first start a local server to serve the pages
so using python:

python -m http.server -d .

using node.js:
#first install module
npm install -g http-server
cd /where-the-top-file-is
http-server

browe to the test.html and open the Console: you should see results
