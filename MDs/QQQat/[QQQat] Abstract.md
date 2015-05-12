# [QQQat] Abstract
## Goal of the project
The aim is to build a end-to-end OTR encrypted chat which can be deployed on a personnal server.

## Technologies
The chat will be build on multiple layers :
- Engine ([ELECTRON](http://electron.atom.io))
  - Desktop application made easy

- Transmission ([socket.io](http://socket.io/))
  - Easy tranmission of data
  - Cross-platform
  - Event-based
  - Can send binaries (Files, Pictures, ...)

- EllypticJS ([ElipticJS](https://github.com/indutny/elliptic))
  - Generates key with curves
  - High security

- Cryptographic library ([CryptoJS 3.1](https://code.google.com/p/crypto-js/))
  - Encryption
  - Decryption
  - Hash

- React ([React](https://facebook.github.io/react/))
  - Facebook's front-end engine

- RequireJs ([requirejs.org](http://requirejs.org/))
- Sass ([sass-lang.com](http://sass-lang.com/))
- CoffeeScript ([coffeescript.org](http://coffeescript.org/))
- CSS Framework ([Foundation by Zurb](http://foundation.zurb.com/))
  - Responsive
  - Full-Featured
  - Hackable

- Tests
  - PhantomJS ([phantomjs.org](http://phantomjs.org/screen-capture.html))
    - To emulate a browser and test the client side

  - Jasime ([jasmine.github.io](http://jasmine.github.io/edge/introduction.html))
    - Writing test suite easily

## DevOps
A server with [Drone](drone.io) will test the server and the client side on each build as integration test. This server will be connectde to a [GitHub](https://github.com/) which will handle the code. There will be a developpment server on each developper's PC. A single test server and a sigle production server handling a stable version of the software, to demonstrate what QQQCat can do !

## Under MIT License
The MIT License (MIT)

Copyright (c) 2015 Kevin BACAS & Louis DELBOSC

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Contact
**TODO**
