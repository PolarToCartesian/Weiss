![Weiss Logo](logo.png)

> Weiss is a cross-platform, api-agnostic and header-only rendering engine built with c++17. It is intended to be a wrapper around low-level apis to make the developpement of 2D and 3D applications simpler and faster.

## Contributions

Many thanks to :

  + [Red-Rapious](https://github.com/Red-Rapious) for the amazing logo!

## Current Support

| Icon    | :heavy_check_mark:         | :x:                   | :warning:         | :small_red_triangle: |
| ------- | -------------------------- | --------------------- | ----------------- | -------------------- |
| Meaning | Fully Integrated & Working | Haven't Started (yet) | Being Implemented | Triangle Rendering   |

| Render API | Status                            | Operating System | Status             |
| ---------- | --------------------------------- | ---------------- | ------------------ |
| DirectX 11 | :warning: (:small_red_triangle:)  | Windows          | :heavy_check_mark: |
| DirectX 12 | :warning: (:small_red_triangle:)  | Linux            | :x:                |
| OpenGL     | :x:                               | Mac OSX          | :x:                |
| Vulkan     | :warning:                         | | |

## Getting Started

Dependencies :

+ Install the [Vulkan SDK](https://www.lunarg.com/vulkan-sdk/)
+ Download the [d3dx12.h file](https://github.com/microsoft/DirectX-Graphics-Samples/blob/master/Libraries/D3DX12/d3dx12.h) from microsoft's official github
+ Download & Install the [DirectX SDK](https://www.microsoft.com/en-us/download/details.aspx?id=6812)
+ On Windows, download & install [Visual Studio](https://visualstudio.microsoft.com/)
+ Download & Install **CMake**
  + **Windows:** [CMake](https://cmake.org/download/)
  + **Linux:** ```sudo apt-get install cmake```

In order to build the static library, you must follow the following instructions if you with to build it with cmake:

+ Clone the repository with [Git](https://git-scm.com/) and type ```git clone https://github.com/PolarToCartesian/Weiss-II```
+ Open the **Root Weiss Directory** and type ```cmake .```
+ On Windows, open the "Weiss.sln" file in **visual studio and hit build**
+ On Linux ```make```
+ The static library should be in the **"WeissEngine.dir/Release" folder**