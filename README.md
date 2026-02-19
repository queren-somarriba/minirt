# miniRT - @42Paris
### 📸 Project Overview
miniRT is a basic Raytracer written in C. It generates 2D images from a 3D scene description by simulating the way light interacts with objects. The project is a deep dive into vector mathematics, coordinate systems, and physics-based rendering. Unlike traditional rasterization, raytracing produces highly realistic results by calculating shadows, reflections, and light refraction.

### 💡 Key Features
* Shapes: Renders Spheres, Planes, and Cylinders with correct intersection math.
* Lighting: Implementation of Ambient and Diffuse lighting.
* Shadows: Hard shadows calculated by tracing rays from intersection points to the light source.
* Coordinate Transformation: Converting 3D coordinates to a 2D viewport with adjustable Camera FOV.

### 🎮 Dynamic Scene Editor
I have implemented a dynamic object management system that allows you to interact with and modify the scene in real-time without reloading the .rt file.

### 🕹️ Controls
Once the scene is rendered, use the following keys to manipulate objects:
| Category | Keys | Action |
| :--- | :--- | :--- |
| **Selection** | `N` / `P` | Select **N**ext or **P**revious object |
| **Resize** | `Up` / `Down` | Increase/Decrease object size |
| | `Right` / `Left` | Adjust Cylinder height |
| **Translate** | `A` / `D` | Move on **X** axis |
| | `W` / `S` | Move on **Z** axis |
| | `E` / `Q` | Move on **Y** axis |
| **Rotate** | `1` / `2` | Rotate on **X** axis |
| | `3` / `4` | Rotate on **Y** axis |
| | `5` / `6` | Rotate on **Z** axis |
| **System** | `ESC` | Exit the program |
Note: Planes, cameras, and lights are fixed in size. Spheres cannot be rotated as they are symmetrical from all angles.

### 🛠️ Technical Implementation
* Vector Library: A custom library to handle vector operations (addition, subtraction, normalization, dot product, cross product).
* Intersection Algorithms: Solving quadratic equations for spheres and cylinders, and linear equations for planes.
* Color Management: Handling RGB values, ensuring they are clamped within the $[0, 255]$ range after lighting calculations.

### 🚀 Getting Started
```Bash
# Compilation
make
# Execution
./miniRT scenes/1.rt

# Provide a scene file with the .rt extension:
```

### 📂 Scene Format (.rt)
The scene is defined by a text file containing:
* A (Ambient light)
* C (Camera)
* L (Light)
* sp (Sphere)
* pl (Plane)
* cy (Cylinder)

###  📬 Contact
Login: qsomarri

School: 42 Paris

![Screenshot from 2025-04-25 16-34-05](https://github.com/user-attachments/assets/92a7eeba-3021-4a2c-8614-1125b329f84f)
