# emscriptmake
buildable example to produces a JS bounded cpp lib 

what shoud be enough to build is:
cmake --build .
or
cmake --build .\cmake-build-emscripten\

there should be a bunch of files produced, notably the cpp2wasm.js file

To test you can start an http server where the html example file test.html is and check that the path to cpp2wasm.js is correct
using python start a http local server is dead simple as : 
  python -m http.server -d .
  
using nodejs:
  #install globally
  npm install -g http-server
  #go to directory 
  cd path-where-you-want-to-serve-from
  #start the server
  http-server
  
  
