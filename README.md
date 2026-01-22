# Qt WebAssembly Hello World

A simple "Hello World" application built with Qt 6 and compiled to WebAssembly, demonstrating how to create and deploy Qt applications to run in web browsers using GitHub Pages.

## 🌐 Live Demo

Visit the live application at: **https://axeljaeger.github.io/axeljaeger-qt-wasm-hello-world/**

## 📋 Description

This project showcases a minimal Qt Widgets application that:
- Displays a "Hello World" message
- Features an interactive button that counts clicks
- Runs entirely in the browser using WebAssembly
- Automatically builds and deploys via GitHub Actions

## ✨ Features

- **Qt 6.5.3** with WebAssembly support
- **CMake** build system
- **GitHub Actions** workflow for automated build and deployment
- **Responsive UI** with styled Qt Widgets
- **Cross-platform** - runs in any modern web browser

## 🛠️ Prerequisites

To build this project locally, you need:

### Required Software

1. **Qt 6.5+ for WebAssembly**
   - Download from [Qt Online Installer](https://www.qt.io/download-qt-installer)
   - During installation, select:
     - Qt 6.5.3 or later
     - WebAssembly single-threaded component
     - Qt Creator (optional, but recommended)

2. **Emscripten SDK 3.1.25**
   ```bash
   # Clone the Emscripten SDK
   git clone https://github.com/emscripten-core/emsdk.git
   cd emsdk
   
   # Install and activate version 3.1.25
   ./emsdk install 3.1.25
   ./emsdk activate 3.1.25
   source ./emsdk_env.sh
   ```

3. **CMake 3.16+**
   ```bash
   # On Ubuntu/Debian
   sudo apt-get install cmake
   
   # On macOS
   brew install cmake
   
   # On Windows
   # Download from https://cmake.org/download/
   ```

4. **Build Tools**
   - Linux: `sudo apt-get install build-essential`
   - macOS: Xcode Command Line Tools
   - Windows: Visual Studio or MinGW

## 🚀 Building Locally

### Step 1: Clone the Repository

```bash
git clone https://github.com/axeljaeger/axeljaeger-qt-wasm-hello-world.git
cd axeljaeger-qt-wasm-hello-world
```

### Step 2: Set up Environment

Ensure Emscripten is activated in your current shell:

```bash
source /path/to/emsdk/emsdk_env.sh
```

### Step 3: Configure with CMake

```bash
# Create build directory
mkdir build
cd build

# Configure with qt-cmake (replace paths with your Qt installation)
/path/to/Qt/6.5.3/wasm_singlethread/bin/qt-cmake .. \
  -DCMAKE_BUILD_TYPE=Release
```

Example paths:
- Linux: `~/Qt/6.5.3/wasm_singlethread/bin/qt-cmake`
- macOS: `~/Qt/6.5.3/wasm_singlethread/bin/qt-cmake`
- Windows: `C:/Qt/6.5.3/wasm_singlethread/bin/qt-cmake.bat`

### Step 4: Build

```bash
cmake --build . --parallel
```

### Step 5: Run Locally

After building, you'll find these files in the `build` directory:
- `HelloWorldWasm.html`
- `HelloWorldWasm.js`
- `HelloWorldWasm.wasm`
- `qtloader.js`

To run the application locally, you need to serve it with a web server (WebAssembly requires proper MIME types):

```bash
# Using Python 3
python3 -m http.server 8000

# Using Python 2
python -m SimpleHTTPServer 8000

# Using Node.js http-server
npx http-server -p 8000
```

Then open your browser and navigate to:
```
http://localhost:8000/HelloWorldWasm.html
```

## 🏗️ Project Structure

```
.
├── .github/
│   └── workflows/
│       └── deploy.yml          # GitHub Actions workflow for build & deploy
├── src/
│   ├── main.cpp                # Application entry point
│   ├── mainwindow.h            # Main window header
│   └── mainwindow.cpp          # Main window implementation with UI
├── CMakeLists.txt              # CMake build configuration
├── .gitignore                  # Git ignore patterns
└── README.md                   # This file
```

## 🔄 GitHub Actions Workflow

The project includes an automated CI/CD pipeline that:

1. **Installs Dependencies**
   - Qt 6.5.3 for WebAssembly
   - Emscripten SDK 3.1.25

2. **Builds the Application**
   - Configures CMake with WebAssembly toolchain
   - Compiles C++ code to WebAssembly

3. **Deploys to GitHub Pages**
   - Uploads build artifacts
   - Deploys to `gh-pages` branch
   - Makes the app available at the GitHub Pages URL

### Triggering the Workflow

The workflow automatically runs on:
- Push to `main` branch
- Manual trigger via GitHub Actions UI

## 🌍 Deployment

### GitHub Pages Setup

1. Go to your repository Settings → Pages
2. Under "Build and deployment":
   - Source: **GitHub Actions**
3. The workflow will automatically deploy on the next push to `main`

### Viewing Deployment Status

- Check the "Actions" tab in your GitHub repository
- Each push creates a new workflow run
- Successful builds are automatically deployed

## 🎨 Customization

### Modifying the UI

Edit `src/mainwindow.cpp` to customize:
- Window title and size
- Label text and styling
- Button appearance and behavior
- Layout and spacing

### Adding Qt Modules

Update `CMakeLists.txt` and `.github/workflows/deploy.yml`:

```cmake
# In CMakeLists.txt
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network)
target_link_libraries(HelloWorldWasm Qt6::Network)
```

```yaml
# In deploy.yml
modules: 'qtbase qtdeclarative qtnetwork'
```

## 🐛 Troubleshooting

### Build Fails with "Qt not found"
- Ensure Qt for WebAssembly is installed
- Verify `qt-cmake` path is correct
- Check Qt version compatibility (6.5+)

### WebAssembly doesn't load in browser
- Ensure you're using a web server (not `file://` protocol)
- Check browser console for errors
- Verify all `.wasm`, `.js`, and `.html` files are present
- Use a modern browser (Chrome 70+, Firefox 65+, Safari 14+)

### Emscripten version mismatch
- Qt 6.5.3 requires Emscripten 3.1.25
- Check Emscripten version: `emcc --version`
- Reactivate the correct version: `emsdk activate 3.1.25`

### GitHub Pages not updating
- Check Actions tab for workflow errors
- Ensure GitHub Pages is enabled in repository settings
- Wait a few minutes for deployment to propagate

## 📚 Resources

- [Qt for WebAssembly Documentation](https://doc.qt.io/qt-6/wasm.html)
- [Emscripten Documentation](https://emscripten.org/docs/getting_started/index.html)
- [Qt WebAssembly Examples](https://doc.qt.io/qt-6/examples-webassembly.html)
- [CMake Documentation](https://cmake.org/documentation/)

## 📝 License

This project is provided as-is for educational and demonstration purposes.

## 🤝 Contributing

Feel free to open issues or submit pull requests for improvements!

## 👤 Author

Created as a demonstration of Qt WebAssembly deployment to GitHub Pages.