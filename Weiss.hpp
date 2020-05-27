#pragma once

/*  
 *   /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\
 *  / /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\ \
 *  | |           ██          ██    ██████████████      ██████████      ██████████████    ██████████████           | |
 *  | |           ██          ██    ██                      ██          ██                ██                       | |
 *  | |           ██          ██    ██                      ██          ██                ██                       | |
 *  | |           ██    ██    ██    ██████████████          ██          ██████████████    ██████████████           | |
 *  | |           ██    ██    ██    ██                      ██                      ██                ██           | |
 *  | |           ██  ██  ██  ██    ██                      ██                      ██                ██           | |
 *  | |             ██      ██      ██████████████      ██████████      ██████████████    ██████████████           | |
 *  | |                                                                                                            | |
 *  | |  ██████████████    ██          ██    ██████████████      ██████████      ██          ██    ██████████████  | |
 *  | |  ██                ████        ██    ██                      ██          ████        ██    ██              | |
 *  | |  ██                ██  ██      ██    ██                      ██          ██  ██      ██    ██              | |
 *  | |  ██████████████    ██    ██    ██    ██    ██████            ██          ██    ██    ██    ██████████████  | |
 *  | |  ██                ██      ██  ██    ██          ██          ██          ██      ██  ██    ██              | |
 *  | |  ██                ██        ████    ██          ██          ██          ██        ████    ██              | |
 *  | |  ██████████████    ██          ██    ████████████        ██████████      ██          ██    ██████████████  | |
 *  \ \____________________________________________________________________________________________________________/ /
 *   \______________________________________________________________________________________________________________/
 * 
 * // ////////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
 * // ||-----------------------------INFO-----------------------------|| \\
 * // |\______________________________________________________________/| \\
 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--//////////////////////////////// \\ 
 * 
 * Project    : Weiss Engine
 * Author     : Henry LE BERRE (PolarToCartesian)
 * Repository : https://github.com/PolarToCartesian/Weiss
 */

#ifdef _WIN32

	#define _CRT_SECURE_NO_WARNINGS

	#define __WEISS__OS_WINDOWS

	#ifdef _WIN64

		#define __WEISS__PLATFORM_X64
	
	#else // End Of #ifdef _WIN64
	
		#define __WEISS__PLATFORM_X86
	
	#endif

	#define _WINSOCKAPI_					// Stops Windows.h from including winsock2
	#define _WINSOCK_DEPRECATED_NO_WARNINGS // Lets us use htons()
	#define NOMINMAX						// Stops The Importing Of min() And max() From Windef.h

	// Windows Includes
	#include <wrl.h>
	#include <strsafe.h>
	#include <Windows.h>
	#include <windowsx.h>

	// Windows Networking Includes
	#include <winhttp.h>
	#include <winsock2.h>
	#include <ws2tcpip.h>

	// Windows Image Includes
	#include <wincodec.h>

	// Windows DirectX 11 Includes
	#include <d3d11.h>

	// Windows DirectX 12 Includes
	#include <d3d12.h>
	#include <d3dx12.h> // from https://github.com/Microsoft/DirectX-Graphics-Samples/tree/master/Libraries/D3DX12
	#include <dxgi1_6.h>

	// Windows DirectX 11/12 Includes
	#include <d3dcompiler.h>
	#include <DirectXMath.h>

	// Vulkan
	#define VK_USE_PLATFORM_WIN32_KHR

	// Linking
	#pragma comment(lib, "dxgi.lib")
	#pragma comment(lib, "winmm.lib")
	#pragma comment(lib, "d3d11.lib")
	#pragma comment(lib, "d3d12.lib")
	#pragma comment(lib, "dxguid.lib")
	#pragma comment(lib, "user32.lib")
	#pragma comment(lib, "Ws2_32.lib")
	#pragma comment(lib, "Mswsock.lib")
	#pragma comment(lib, "winhttp.lib")
	#pragma comment(lib, "kernel32.lib")
	#pragma comment(lib, "AdvApi32.lib")
	#pragma comment(lib, "D3DCompiler.lib")
	#pragma comment(lib, "windowscodecs.lib")

	#undef _WINSOCKAPI_
	#undef _WINSOCK_DEPRECATED_NO_WARNINGS
	#undef NOMINMAX

	// Windows Macros
	#define WIN_ENABLE_CONSOLE()                            \
	{                                                       \
		AllocConsole();                                     \
		freopen_s((FILE **)stdout, "CONOUT$", "w", stdout); \
	}

#elif defined(__ANDROID__)

	#define WEISS__OS_ANDROID

#elif defined(__linux__)

	#define WEISS__OS_LINUX

#elif defined(__APPLE__) && defined(__MACH__)

	#include <TargetConditionals.h>

	#if TARGET_IPHONE_SIMULATOR
		#define __WEISS__OS_IOS
	#elif TARGET_OS_IPHONE == 1
		#define __WEISS__OS_IOS
	#elif TARGET_OS_MAC == 1
		#defined __WEISS__OS_OSX
	#else
		#error You Target Apple Device's OS Could Not Be Resolved
	#endif

#else

	#error The Weiss Engine Is Not (Yet) Supported On Your Platform

#endif

// Vulkan Includes
#include <vulkan/vulkan.h>

#pragma comment(lib, "vulkan-1.lib")

/*
 * // ////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
 * // ||------------------C++17 STL Includes------------------|| \\
 * // |\______________________________________________________/| \\
 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\--//////////////////////////// \\
 */

#include <map>
#include <list>
#include <array>
#include <queue>
#include <mutex>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <memory>
#include <bitset>
#include <numeric>
#include <codecvt>
#include <variant>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <optional>
#include <exception>
#include <algorithm>
#include <functional>
#include <immintrin.h>

/*
 * // //////////////////--\\\\\\\\\\\\\\\\\\ \\
 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
 * // ||--------------UNDEFS--------------|| \\
 * // |\__________________________________/| \\
 * // \\\\\\\\\\\\\\\\\\--////////////////// \\
 */

#ifdef _CRT_SECURE_NO_WARNINGS

	#undef _CRT_SECURE_NO_WARNINGS

#endif // _CRT_SECURE_NO_WARNINGS

/*
 * // ////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
 * // ||--------------RELEASE / DEBUG MODE CHECK--------------|| \\
 * // |\______________________________________________________/| \\
 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\--//////////////////////////// \\
 */

#if defined(_NDEBUG) || defined(NDEBUG)

	#define __WEISS__RELEASE_MODE

#else // end of #if defined(_NDEBUG) || defined(NDEBUG)

	#define __WEISS__DEBUG_MODE

#endif

/*
 * // /////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
 * // ||-----------------------SSE CHECK-----------------------|| \\
 * // |\_______________________________________________________/| \\
 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\-///////////////////////////// \\
 */

#ifdef __WEISS__DISABLE_SIMD

#pragma message("[WEISS] Vector Math Will Be Slower Since __WEISS__DISABLE__SIMD is defined")

#endif

/*
 * // //////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
 * // ||-------------TO THROW OR NOT TO THROW------------|| \\
 * // |\_________________________________________________/| \\
 * // \\\\\\\\\\\\\\\\\\\\\\\\\\-////////////////////////// \\
 * 
 * The use of noexcept can speed up execution but exceptions are needed in debug mode
 * The "WS_THROW" macro can be used to track exceptions even in release mode (i.e logging..)
 */

#ifdef __WEISS__DEBUG_MODE

	#define __WEISS__THROWS true
	#define WS_THROW(errorMsg) (throw std::runtime_error(errorMsg)) 

#else

	#define __WEISS__THROWS false
	#define WS_THROW(errorMsg) {}

#endif

#define WS_NOEXCEPT noexcept(!__WEISS__THROWS)

/*
 * // //////////////////////-\\\\\\\\\\\\\\\\\\\\\\ \\
 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
 * // ||--------------HELPER MACROS--------------|| \\
 * // |\_________________________________________/| \\
 * // \\\\\\\\\\\\\\\\\\\\\\-////////////////////// \\
 */

#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))

#define VK_FAILED(vkResult) ((vkResult) != VK_SUCCESS)

#ifdef __WEISS__OS_WINDOWS

	#define DX_FAILED(hResult)  FAILED(hResult)
	#define WIN_FAILED(hResult) FAILED(hResult)

	#define WS_ERROR_MESSAGE(message) MessageBoxA(NULL, message, "Weiss Engine Error", MB_TOPMOST | MB_ICONERROR);

#endif // __WEISS__OS_WINDOWS

/*
 * // ///////////////////////-\\\\\\\\\\\\\\\\\\\\\\\ \\
 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
 * // ||--------------WEISS NAMESPACE--------------|| \\
 * // |\___________________________________________/| \\
 * // \\\\\\\\\\\\\\\\\\\\\\\-/////////////////////// \\
 *
 * The "WS" namespace contains all of Weiss's classes, functions and variables
 * in order to avoid namespace leaks and conflicts with other libraries
 */
namespace WS
{
	/*
	* // ////////////////////-\\\\\\\\\\\\\\\\\\\\ \\
	* // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	* // ||--------------CONSTANTS--------------|| \\
	* // |\_____________________________________/| \\
	* // \\\\\\\\\\\\\\\\\\\\-//////////////////// \\
	*/

	constexpr const float PI             = 3.14159265359f;
	constexpr const float TWO_PI         = 2.0f * PI;
	constexpr const float HALF_PI        = PI / 2.0f;
	constexpr const float QUARTER_PI     = PI / 4.0f;
	constexpr const float PI_DIV_180     = PI / 180.0f;
	constexpr const float PI_DIV_180_INV = 180.0f / PI;

	constexpr const float TAU         = TWO_PI;
	constexpr const float HALF_TAU    = PI;
	constexpr const float QUARTER_TAU = HALF_PI;

	static constexpr const size_t WEISS__FRAME_BUFFER_COUNT = 2u;

#ifdef __WEISS__OS_WINDOWS

	static constexpr const uint32_t WEISS__D3D12_MAX_DESCRIPTORS_PER_HEAP = 1024u;

#endif // __WEISS__OS_WINDOWS

	/*
	* // //////////////////-\\\\\\\\\\\\\\\\\\ \\
	* // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	* // ||--------------ENUMS--------------|| \\
	* // |\_________________________________/| \\
	* // \\\\\\\\\\\\\\\\\\-////////////////// \\
	*/

	enum class ShaderInputElementType
	{
		FLOAT_32,
		UINT_32,
		VECTOR_2D_FLOAT_32,
		VECTOR_3D_FLOAT_32,
		VECTOR_4D_FLOAT_32
	};

	enum class TextureFilter
	{
		POINT,
		BILINEAR,
		TRILINEAR
	};

	enum class PrimitiveTopology
	{
		TRIANGLES,
		TRIANGLE_STRIP
	};

	enum class RenderAPIName
	{
		DIRECTX11,
		DIRECTX12,
		VULKAN
	};

	/*
	 * We have to prexif the codes with LOG_ because the "ERROR"
	 * Keyword is defined by a windows header "wingdi.h"
	 */
	enum class LOG_TYPE {
		LOG_NORMAL,
		LOG_SUCCESS,
		LOG_WARNING,
		LOG_ERROR
	};

	// //////////////--\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |------------Rect------------| \\
	// |\__________________________/| \\
	// \\\\\\\\\\\\\\--////////////// \\

	struct Rect
	{ // basicly Window's RECT
		uint16_t left   = 0u;
		uint16_t top    = 0u;
		uint16_t right  = 0u;
		uint16_t bottom = 0u;

		Rect() = default;

#ifdef __WEISS__OS_WINDOWS

		Rect(const RECT &rect) noexcept;

		inline operator const RECT&() const WS_NOEXCEPT { return RECT{ left, top, right, bottom }; }

#endif // __WEISS__OS_WINDOWS
	};

	struct ShaderInputElement
	{
		const char *name;
		ShaderInputElementType type;
	};

	// ////////////////-\\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |------------Coloru8------------| \\
	// |\_____________________________/| \\
	// \\\\\\\\\\\\\\\\-//////////////// \\

	struct Coloru8
	{
		union {
			struct
			{
				uint8_t r;
				uint8_t g;
				uint8_t b;
				uint8_t a;
			};

			struct
			{
				uint8_t red;
				uint8_t green;
				uint8_t blue;
				uint8_t alpha;
			};

			uint32_t color32;
		};
	};

	constexpr const Coloru8 COLOR_U8_RED   = Coloru8{ 255u, 0u,   0u,   255u };
	constexpr const Coloru8 COLOR_U8_GREEN = Coloru8{ 0u,   255u, 0u,   255u };
	constexpr const Coloru8 COLOR_U8_BLUE  = Coloru8{ 0u,   0u,   255u, 255u };
	constexpr const Coloru8 COLOR_U8_WHITE = Coloru8{ 255u, 255u, 255u, 255u };
	constexpr const Coloru8 COLOR_U8_BLACK = Coloru8{ 0u,   0u,   0u,   255u };

	// ////////////////--\\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |------------Colorf32------------| \\
	// |\______________________________/| \\
	// \\\\\\\\\\\\\\\\--//////////////// \\

	struct Colorf32
	{
		/*
		 * The union of the two anonymous structs lets the caller
		 * use either shorter or longer names for the same color values
		 */
		union {
			struct
			{
				float r;
				float g;
				float b;
				float a;
			};

			struct
			{
				float red;
				float green;
				float blue;
				float alpha;
			};
		};
	};

	constexpr const Colorf32 COLOR_F32_RED   = Colorf32{1.f, 0.f, 0.f, 1.f};
	constexpr const Colorf32 COLOR_F32_GREEN = Colorf32{0.f, 1.f, 0.f, 1.f};
	constexpr const Colorf32 COLOR_F32_BLUE  = Colorf32{0.f, 0.f, 1.f, 1.f};
	constexpr const Colorf32 COLOR_F32_WHITE = Colorf32{1.f, 1.f, 1.f, 1.f};
	constexpr const Colorf32 COLOR_F32_BLACK = Colorf32{0.f, 0.f, 0.f, 1.f};

	class _WS_TYPE_DOESNT_EXIST
	{
	};

#ifndef __WEISS__DISABLE_SIMD

	template <typename _T>
	using GET_SIMD_TYPE = typename std::conditional_t<
		std::is_same_v<_T, float>, __m128,
		typename std::conditional_t<
		std::is_same_v<_T, int32_t>, __m128i,
		typename std::conditional_t<
		std::is_same_v<_T, int16_t>, __m128i,
		typename std::conditional_t<
		std::is_same_v<_T, double>, __m256d, _WS_TYPE_DOESNT_EXIST>>>>;

#define WS_CAN_PERFORM_SIMD(_T) \
	(!std::is_same_v<GET_SIMD_TYPE<_T>, _WS_TYPE_DOESNT_EXIST>)

#define WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)            \
	(WS_CAN_PERFORM_SIMD(_T) && WS_CAN_PERFORM_SIMD(_T_2) && \
	std::is_same_v<_T, _T_2>)

#else

	template <typename _T>
	using GET_SIMD_TYPE = _WS_TYPE_DOESNT_EXIST;

#define WS_CAN_PERFORM_SIMD(_T) false
#define WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2) false

#endif

#ifndef __WEISS__DISABLE_SIMD

	template <typename _T>
	static inline GET_SIMD_TYPE<_T> SIMDAdd(const GET_SIMD_TYPE<_T>& vecA,
		const GET_SIMD_TYPE<_T>& vecB) noexcept
	{
		if constexpr (std::is_same_v<_T, float>)
			return _mm_add_ps(vecA, vecB);
		else if constexpr (std::is_same_v<_T, int32_t>)
			return _mm_add_epi32(vecA, vecB);
		else if constexpr (std::is_same_v<_T, int16_t>)
			return _mm_add_epi16(vecA, vecB);
		else if constexpr (std::is_same_v<_T, double>)
			return _mm256_add_pd(vecA, vecB);
	}

	template <typename _T>
	static inline GET_SIMD_TYPE<_T> SIMDSub(const GET_SIMD_TYPE<_T>& vecA,
		const GET_SIMD_TYPE<_T>& vecB) noexcept
	{
		if constexpr (std::is_same_v<_T, float>)
			return _mm_sub_ps(vecA, vecB);
		else if constexpr (std::is_same_v<_T, int32_t>)
			return _mm_sub_epi32(vecA, vecB);
		else if constexpr (std::is_same_v<_T, int16_t>)
			return _mm_sub_epi16(vecA, vecB);
		else if constexpr (std::is_same_v<_T, double>)
			return _mm256_sub_pd(vecA, vecB);
	}

	template <typename _T>
	static inline GET_SIMD_TYPE<_T> SIMDMul(const GET_SIMD_TYPE<_T>& vecA,
		const GET_SIMD_TYPE<_T>& vecB) noexcept
	{
		if constexpr (std::is_same_v<_T, float>)
			return _mm_mul_ps(vecA, vecB);
		else if constexpr (std::is_same_v<_T, int32_t>)
			return _mm_mul_epi32(vecA, vecB);
		else if constexpr (std::is_same_v<_T, int16_t>)
			return _mm_mul_epi16(vecA, vecB);
		else if constexpr (std::is_same_v<_T, double>)
			return _mm256_mul_pd(vecA, vecB);
	}

	template <typename _T>
	static inline GET_SIMD_TYPE<_T> SIMDDiv(const GET_SIMD_TYPE<_T>& vecA,
		const GET_SIMD_TYPE<_T>& vecB) noexcept
	{
		if constexpr (std::is_same_v<_T, float>)
			return _mm_div_ps(vecA, vecB);
		else if constexpr (std::is_same_v<_T, int32_t>)
			return _mm_div_epi32(vecA, vecB);
		else if constexpr (std::is_same_v<_T, int16_t>)
			return _mm_div_epi16(vecA, vecB);
		else if constexpr (std::is_same_v<_T, double>)
			return _mm256_div_pd(vecA, vecB);
	}

	template <typename _T>
	static inline GET_SIMD_TYPE<_T> SIMDSet(const _T& x, const _T& y, const _T& z,
		const _T& w) noexcept
	{
		if constexpr (std::is_same_v<_T, float>)
			return _mm_set_ps(w, z, y, x);
		else if constexpr (std::is_same_v<_T, int32_t>)
			return _mm_set_epi32(w, z, y, x);
		else if constexpr (std::is_same_v<_T, int16_t>)
			return _mm_set_epi16(w, z, y, x, 0, 0, 0, 0);
		else if constexpr (std::is_same_v<_T, double>)
			return _mm256_set_pd(w, z, y, x);
	}

	template <typename _T>
	static inline void SIMDStore(_T* src, const GET_SIMD_TYPE<_T>& sseVec) noexcept
	{
		if constexpr (std::is_same_v<_T, float>)
			_mm_store_ps(src, sseVec);
		else if constexpr (std::is_same_v<_T, int32_t> || std::is_same_v<_T, int16_t>)
			_mm_store_si128((__m128i*)src, sseVec);
		else if constexpr (std::is_same_v<_T, double>)
			_mm256_store_pd(src, sseVec);
	}

	template <typename _T>
	static inline GET_SIMD_TYPE<_T> SIMDLoad(_T* src) noexcept
	{
		if constexpr (std::is_same_v<_T, float>)
			return _mm_load_ps(src);
		else if constexpr (std::is_same_v<_T, int32_t> || std::is_same_v<_T, int16_t>)
			return _mm_load_si128((__m128i*)src);
		else if constexpr (std::is_same_v<_T, double>)
			return _mm256_load_pd(src);
	}

	template <typename _T, int INDEX>
	static inline _T SIMDExtractElement(const GET_SIMD_TYPE<_T>& sseVector) noexcept
	{
		if constexpr (std::is_same_v<_T, float>) {
			const int l = _mm_extract_ps(sseVector, INDEX);
			return *reinterpret_cast<const _T*>(&l);
		}
		else if constexpr (std::is_same_v<_T, int32_t>) {
			const int l = _mm_extract_epi16(sseVector, INDEX);
			return *reinterpret_cast<_T*>(&l);
		}
		else if constexpr (std::is_same_v<_T, int16_t>) {
			const int l = _mm_extract_epi16(sseVector, INDEX);
			return *reinterpret_cast<_T*>(&l);
		}
		else if constexpr (std::is_same_v<_T, double>) {
			if constexpr (INDEX <= 1) {
				return _mm256_cvtsd_f64(_mm256_shuffle_pd(sseVector, sseVector,
					_MM_SHUFFLE(INDEX, INDEX, INDEX, INDEX)));
			}
			else {
				return _mm_cvtsd_f64(_mm_shuffle_pd(_mm256_extractf128_pd(sseVector, 1), // I am
					_mm256_extractf128_pd(sseVector, 1), // proud of
					_MM_SHUFFLE(INDEX, INDEX, INDEX, INDEX))); // this magic
			}
		}
	}

	template <typename _T>
	static inline _T SIMDDotProduct(const GET_SIMD_TYPE<_T>& a,
		const GET_SIMD_TYPE<_T>& b) noexcept
	{
		if constexpr (std::is_same_v<_T, float>)
			return SIMDExtractElement<_T, 0>(_mm_dp_ps(a, b, 0xFF));
		else if constexpr (std::is_same_v<_T, int32_t>)
			return 0;
		else if constexpr (std::is_same_v<_T, int16_t>)
			return 0;
		else if constexpr (std::is_same_v<_T, double>)
			return SIMDExtractElement<_T, 0>(_mm256_dp_ps(a, b, 0xFF));
	}

#endif // #ifndef __WEISS__DISABLE_SIMD

	template <typename _T>
	struct Vector
	{
		union {
			GET_SIMD_TYPE<_T> m_sseVector; // Is a "_WS_TYPE_DOESNT_EXIST" if no intrinsic type can be created
			struct
			{
				_T x, y, z, w;
			};
			_T m_arr[4u];
		};

		inline Vector(const _T& x = 0, const _T& y = 0, const _T& z = 0, const _T& w = 0) noexcept
		{
			this->Set(x, y, z, w);
		}

		inline Vector(const Vector<_T>& other) noexcept
		{
			if constexpr (WS_CAN_PERFORM_SIMD(_T)) {
#ifndef __WEISS__DISABLE_SIMD
				SIMDStore<_T>((_T*)&other.m_arr,
					this->m_sseVector);
#endif
			}
			else {
				std::memcpy(&this->m_arr, &other.m_arr,
					sizeof(_T) * 4u);
			}
		}

#ifndef __WEISS__DISABLE_SIMD

		template <typename _T_2 = _T>
		inline Vector(const GET_SIMD_TYPE<_T_2>& other) noexcept
		{
			static_assert(WS_CAN_PERFORM_SIMD(_T));

			if constexpr (std::is_same_v<_T, _T_2>) {
				this->m_sseVector = other;
			}
			else {
				this->m_sseVector = SIMDSet(
					static_cast<_T>(SIMDExtractElement<_T_2, 0u>(this->m_sseVector)),
					static_cast<_T>(SIMDExtractElement<_T_2, 1u>(this->m_sseVector)),
					static_cast<_T>(SIMDExtractElement<_T_2, 2u>(this->m_sseVector)),
					static_cast<_T>(SIMDExtractElement<_T_2, 3u>(this->m_sseVector)));
			}
		}

#endif

		inline void Set(const _T& x = 0.0f, const _T& y = 0.0f,
			const _T& z = 0.0f, const _T& w = 0.0f) noexcept
		{
			if constexpr (WS_CAN_PERFORM_SIMD(_T)) {
#ifndef __WEISS__DISABLE_SIMD
				this->m_sseVector = SIMDSet<_T>(x, y, z, w);
#endif // #ifndef __WEISS__DISABLE_SIMD
			}
			else {
				this->x = x;
				this->y = y;
				this->z = z;
				this->w = w;
			}
		}

		template <typename _T_2>
		inline void operator+=(const Vector<_T_2>& other) noexcept
		{
			if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
#ifndef __WEISS__DISABLE_SIMD
				this->m_sseVector = SIMDAdd<_T>(
					this->m_sseVector, other.m_sseVector);
#endif // #ifndef __WEISS__DISABLE_SIMD
			}
			else {
				this->x += other.x;
				this->y += other.y;
				this->z += other.z;
				this->w += other.w;
			}
		}

		template <typename _T_2>
		inline void operator-=(const Vector<_T_2>& other) noexcept
		{
			if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
#ifndef __WEISS__DISABLE_SIMD
				this->m_sseVector = SIMDSub<_T>(
					this->m_sseVector, other.m_sseVector);
#endif // #ifndef __WEISS__DISABLE_SIMD
			}
			else {
				this->x -= other.x;
				this->y -= other.y;
				this->z -= other.z;
				this->w -= other.w;
			}
		}

		template <typename _T_2>
		inline void operator*=(const Vector<_T_2>& other) noexcept
		{
			if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
#ifndef __WEISS__DISABLE_SIMD
				this->m_sseVector = SIMDMul<_T>(
					this->m_sseVector, other.m_sseVector);
#endif // #ifndef __WEISS__DISABLE_SIMD
			}
			else {
				this->x *= other.x;
				this->y *= other.y;
				this->z *= other.z;
				this->w *= other.w;
			}
		}

		template <typename _T_2>
		inline void operator/=(const Vector<_T_2>& other) noexcept
		{
			if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
#ifndef __WEISS__DISABLE_SIMD
				this->m_sseVector = SIMDDiv<_T>(
					this->m_sseVector, other.m_sseVector);
#endif // #ifndef __WEISS__DISABLE_SIMD
			}
			else {
				this->x /= other.x;
				this->y /= other.y;
				this->z /= other.z;
				this->w /= other.w;
			}
		}

		template <typename _T_2>
		inline bool operator==(const Vector<_T_2>& other) const noexcept
		{
			if constexpr (std::is_same_v<_T, _T_2>) {
				return std::memcmp(this->m_arr, other.m_arr, 4u * sizeof(_T)) == 0;
			}
			else {
				return this->x == other.x && this->y == other.y &&
					this->z == other.z && this->w == other.w;
			}
		}

		template <typename _T_2>
		inline bool operator!=(const Vector<_T_2>& other) const noexcept
		{
			if constexpr (std::is_same_v<_T, _T_2>) {
				return std::memcmp(this->m_arr, other.m_arr, 4u * sizeof(_T)) != 0;
			}
			else {
				return this->x != other.x || this->y != other.y ||
					this->z != other.z || this->w != other.w;
			}
		}

		template <typename _T_2, typename = std::enable_if_t<std::is_arithmetic_v<_T_2>, void>>
		inline void operator+=(const _T_2& n) noexcept
		{
			this->operator+=(Vector<_T_2>(n, n, n, n));
		}

		template <typename _T_2>
		inline void operator-=(const _T_2& n) noexcept
		{
			this->operator-=(Vector<_T_2>(n, n, n, n));
		}

		template <typename _T_2>
		inline void operator*=(const _T_2& n) noexcept
		{
			this->operator*=(Vector<_T_2>(n, n, n, n));
		}

		template <typename _T_2>
		inline void operator/=(const _T_2& n) noexcept
		{
			this->operator/=(Vector<_T_2>(n, n, n, n));
		}
	};

	template <typename _T, typename _T_2>
	inline auto VectorDotProduct(const Vector<_T>& a,
		const Vector<_T_2>& b) noexcept
		-> decltype(a.x + b.x)
	{
		if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
			return SIMDDotProduct<_T>(a.m_sseVector, b.m_sseVector);
		}
		else {
			return a.x * b.x + a.y * b.y
				+ a.z * b.z + a.w * b.w;
		}
	}

	template <typename _T, typename _T_2>
	[[nodiscard]] inline auto operator+(const Vector<_T>& a,
		const Vector<_T_2>& b) noexcept
		-> Vector<decltype(a.x + b.x)>
	{
		if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
#ifndef __WEISS__DISABLE_SIMD
			return Vector<_T>(
				SIMDAdd<_T>(a.m_sseVector, b.m_sseVector));
#endif // #ifndef __WEISS__DISABLE_SIMD
		}
		else {
			return Vector<decltype(a.x + b.x)>(a.x + b.x, a.y + b.y,
				a.z + b.z, a.w + b.w);
		}
	}

	template <typename _T, typename _T_2>
	[[nodiscard]] inline auto operator-(const Vector<_T>& a,
		const Vector<_T_2>& b) noexcept
		-> Vector<decltype(a.x - b.x)>
	{
		if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
#ifndef __WEISS__DISABLE_SIMD
			return Vector<_T>(
				SIMDSub<_T>(a.m_sseVector, b.m_sseVector));
#endif // #ifndef __WEISS__DISABLE_SIMD
		}
		else {
			return Vector<decltype(a.x - b.x)>(a.x - b.x, a.y - b.y,
				a.z - b.z, a.w - b.w);
		}
	}

	template <typename _T, typename _T_2>
	[[nodiscard]] inline auto operator*(const Vector<_T>& a,
		const Vector<_T_2>& b) noexcept
		-> Vector<decltype(a.x* b.x)>
	{
		if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
#ifndef __WEISS__DISABLE_SIMD
			return Vector<_T>(
				SIMDMul<_T>(a.m_sseVector, b.m_sseVector));
#endif // #ifndef __WEISS__DISABLE_SIMD
		}
		else {
			return Vector<decltype(a.x* b.x)>(a.x * b.x, a.y * b.y,
				a.z * b.z, a.w * b.w);
		}
	}

	template <typename _T, typename _T_2>
	[[nodiscard]] inline auto operator/(const Vector<_T>& a,
		const Vector<_T_2>& b) noexcept
		-> Vector<decltype(a.x / b.x)>
	{
		if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
#ifndef __WEISS__DISABLE_SIMD
			return Vector<_T>(
				SIMDDiv<_T>(a.m_sseVector, b.m_sseVector));
#endif // #ifndef __WEISS__DISABLE_SIMD
		}
		else {
			return Vector<decltype(a.x / b.x)>(a.x / b.x, a.y / b.y,
				a.z / b.z, a.w / b.w);
		}
	}

	template <typename _T, typename _T_2>
	inline auto operator+(const Vector<_T>& vec, const _T_2& n) noexcept
		-> Vector<decltype(vec.x + n)>
	{
		return vec + Vector<_T>(n, n, n, n);
	}

	template <typename _T, typename _T_2>
	inline auto operator-(const Vector<_T>& vec, const _T_2& n) noexcept
		-> Vector<decltype(vec.x - n)>
	{
		return vec - Vector<_T>(n, n, n, n);
	}

	template <typename _T, typename _T_2>
	inline auto operator*(const Vector<_T>& vec, const _T_2& n) noexcept
		-> Vector<decltype(vec.x * n)>
	{
		return vec * Vector<_T>(n, n, n, n);
	}

	template <typename _T, typename _T_2>
	inline auto operator/(const Vector<_T>& vec, const _T_2& n) noexcept
		-> Vector<decltype(vec.x / n)>
	{
		return vec / Vector<_T>(n, n, n, n);
	}

	template <typename _T>
	inline std::ostream& operator<<(std::ostream& stream, const Vector<_T>& vec) noexcept
	{
		stream << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";

		return stream;
	}

	typedef Vector<int16_t> Veci16;
	typedef Vector<int32_t> Veci32;

	typedef Vector<uint16_t> Vecu16;
	typedef Vector<uint32_t> Vecu32;

	typedef Vector<std::enable_if_t<std::numeric_limits<float>::is_iec559, float>>   Vecf32;
	typedef Vector<std::enable_if_t<std::numeric_limits<double>::is_iec559, double>> Vecd64;

	template <typename _T>
	class Matrix
	{
	private:
		_T m[16] = { 0 };

	public:
		Matrix() = default;

		inline Matrix(const _T* buff)                 noexcept { std::memcpy(this->m, buff, sizeof(_T) * 16u); }
		inline Matrix(const std::array<_T, 16u>& arr) noexcept { std::memcpy(this->m, arr.data(), sizeof(_T) * 16u); }

		inline Matrix(const Matrix<_T>& other) noexcept { std::memcpy(this->m, other.m, sizeof(_T) * 16u); }

		inline _T& operator[](const size_t i) noexcept { return this->m[i]; }

		inline const _T& operator[](const size_t i) const noexcept { return this->m[i]; }

		inline _T& operator()(const size_t r, const size_t c) noexcept { return this->m[r * 4u + c]; }

		inline const _T& operator()(const size_t r, const size_t c) const noexcept { return this->m[r * 4u + c]; }

		// --- Static Functions --- //

		static inline Matrix<_T> MakeZeros()    noexcept { return Matrix<_T>(); }
		static inline Matrix<_T> MakeIdentity() noexcept {
			return Matrix<_T>(std::array<_T, 16u>{1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1});
		}

		static inline Matrix<_T> MakeRotationX(const float radX = 0.0f) noexcept
		{
			const _T sinX = std::sin(radX);
			const _T cosX = std::cos(radX);

			return Matrix<_T>(std::array<_T, 16u>{
				1, 0, 0, 0,
					0, cosX, -sinX, 0,
					0, sinX, cosX, 0,
					0, 0, 0, 1
			});
		}

		static inline Matrix<_T> MakeRotationY(const float radY = 0.0f) noexcept
		{
			const _T sinY = std::sin(radY);
			const _T cosY = std::cos(radY);

			return Matrix<_T>(std::array<_T, 16u>{
				cosY, 0, 0, sinY,
					0, 1, 0, 0,
					0, 0, 1, 0,
					-sinY, 0, 0, cosY
			});
		}

		static inline Matrix<_T> MakeRotationZ(const float radZ = 0.0f) noexcept
		{
			const _T sinZ = std::sin(radZ);
			const _T cosZ = std::cos(radZ);

			return Matrix<_T>(std::array<_T, 16u>{
				cosZ, -sinZ, 0, 0,
					sinZ, cosZ, 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1
			});
		}

		static inline Matrix<_T> MakeRotation(const float radX = 0.0f, const float radY = 0.0f, const float radZ = 0.0f) noexcept
		{
			return MakeRotationX(radX) * MakeRotationY(radY) * MakeRotationZ(radZ);
		}

		static inline Matrix<_T> MakeRotation(const Vector<_T>& radians) noexcept
		{
			return Matrix<_T>::MakeRotation(radians.x, radians.y, radians.z);
		}

		static inline Matrix<_T> MakeTranslation(const float x = 0.0f, const float y = 0.0f, const float z = 0.0f) noexcept
		{
			return Matrix<_T>(std::array<_T, 16u>{
				1, 0, 0, x,
				0, 1, 0, y,
				0, 0, 1, z,
				0, 0, 0, 1,
			});
		}

		static inline Matrix<_T> MakeTranslation(const Vector<_T>& translation) noexcept
		{
			return Matrix<_T>::MakeTranslation(translation.x, translation.y, translation.z);
		}

		static inline Matrix<_T> MakePerspective(const float zNear, const float zFar, const float fovRad, const float aspectRatio)
		{
			return Matrix<_T>(std::array<_T, 16u>{
				aspectRatio* fovRad, 0, 0, 0,
					0, fovRad, 0, 0,
					0, 0, zFar / (zFar - zNear), 1,
					0, 0, (-zFar * zNear) / (zFar - zNear), 0,
			});
		}

		static inline Matrix<_T> MakeScaling(const float scaleX = 1.0f, const float scaleY = 1.0f, const float scaleZ = 1.0f, const float scaleW = 1.0f) noexcept
		{
			return Matrix<_T>(std::array<_T, 16u>{
				scaleX, 0, 0, 0,
				0, scaleY, 0, 0,
				0, 0, scaleZ, 0,
				0, 0, 0, scaleW
			});
		}

		static inline Matrix<_T> MakeTransposed(const Matrix<_T>& mat) noexcept
		{
			return Matrix<_T>(std::array<_T, 16u>{
				mat(0, 0), mat(1, 0), mat(2, 0), mat(3, 0),
				mat(0, 1), mat(1, 1), mat(2, 1), mat(3, 1),
				mat(0, 2), mat(1, 2), mat(2, 2), mat(3, 2),
				mat(0, 3), mat(1, 3), mat(2, 3), mat(3, 3)
			});
		}
	};

	template <typename _T, typename _T_2>
	inline auto operator*(const Matrix<_T>& matA, const Matrix<_T_2>& matB) noexcept
		-> Matrix<decltype(matA[0] + matB[0])>
	{
		Matrix<decltype(matA[0] + matB[0])> matResult;

		for (size_t r = 0u; r < 4u; r++) {
			for (size_t c = 0u; c < 4u; c++) {
				const Vector<_T>   vecA = Vector<_T>(matA(r, 0), matA(r, 1), matA(r, 2), matA(r, 3));
				const Vector<_T_2> vecB = Vector<_T_2>(matB(0, c), matB(1, c), matB(2, c), matB(3, c));

				matResult(r, c) = VectorDotProduct(vecA, vecB);
			}
		}

		return matResult;
	}

	template <typename _T>
	inline std::ostream& operator<<(std::ostream& stream,
		const Matrix<_T>& mat) noexcept
	{
		constexpr const size_t MAX_DIGITS = 5u;

		stream << std::setprecision(MAX_DIGITS) << '|';

		for (size_t i = 0u; i < 4u * ((MAX_DIGITS + 1u) + 1u) + 1u; i++)
			stream << '-';

		stream << "|\n";
		for (size_t r = 0u; r < 4u; r++) {
			stream << "| ";

			for (size_t c = 0u; c < 4u; c++)
				stream << std::setw(MAX_DIGITS + 1u) << mat(r, c) << ' ';

			stream << "|\n";
		}

		stream << '|';

		for (size_t i = 0u; i < 4u * ((MAX_DIGITS + 1u) + 1u) + 1u; i++)
			stream << '-';

		stream << "|\n";

		return stream;
	}

	typedef Matrix<std::enable_if_t<std::numeric_limits<float>::is_iec559, float>> MatrixFloat32;

	template <typename _T, typename _T_2>
	inline auto operator*(const Vector<_T>& vec, const Matrix<_T_2>& mat) noexcept
		-> Vector<decltype(vec.x + mat[0])>
	{
		return Vector<decltype(vec.x + mat[0])>(
			VectorDotProduct(vec, Vector<_T_2>(mat(0, 0), mat(0, 1), mat(0, 2), mat(0, 3))),
			VectorDotProduct(vec, Vector<_T_2>(mat(1, 0), mat(1, 1), mat(1, 2), mat(1, 3))),
			VectorDotProduct(vec, Vector<_T_2>(mat(2, 0), mat(2, 1), mat(2, 2), mat(2, 3))),
			VectorDotProduct(vec, Vector<_T_2>(mat(3, 0), mat(3, 1), mat(3, 2), mat(3, 3)))
		);
	}

	// ///////////////-\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |----------Transform----------| \\
	// |\___________________________/| \\
	// \\\\\\\\\\\\\\\-/////////////// \\

	struct Transform
	{
	private:
		Vecf32 m_rotation;
		Vecf32 m_translation;

		MatrixFloat32 m_transform = MatrixFloat32::MakeIdentity();

	public:
		Transform() = default;

		[[nodiscard]] inline Vecf32 GetRotation()    const WS_NOEXCEPT { return this->m_rotation;    }
		[[nodiscard]] inline Vecf32 GetTranslation() const WS_NOEXCEPT { return this->m_translation; }

		inline void SetRotation   (const Vecf32 &rotation)    WS_NOEXCEPT { this->m_rotation    = rotation;    }
		inline void SetTranslation(const Vecf32 &translation) WS_NOEXCEPT { this->m_translation = translation; }

		inline void Rotate   (const Vecf32 &delta) WS_NOEXCEPT { this->m_rotation    += delta; }
		inline void Translate(const Vecf32 &delta) WS_NOEXCEPT { this->m_translation += delta; }

		[[nodiscard]] inline MatrixFloat32 GetTransform()           const WS_NOEXCEPT { return this->m_transform;                 }
		[[nodiscard]] inline MatrixFloat32 GetTransposedTransform() const WS_NOEXCEPT { return Matrix<float>::MakeTransposed(this->m_transform); }

		void CalculateTransform() WS_NOEXCEPT;
	};

	// ////////////////-\\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |----------Conversions----------| \\
	// |\_____________________________/| \\
	// \\\\\\\\\\\\\\\\-//////////////// \\

	[[nodiscard]] inline float DegreesToRadians(const float degrees);
	[[nodiscard]] inline float RadiansToDegrees(const float radians);

	// If a polar point is stored as (θ, r)
	[[nodiscard]] inline Vecf32 PolarToCartesian(const Vecf32& polar);

	[[nodiscard]] inline Vecf32 CartesianToPolar(const Vecf32& cartesian);

	[[nodiscard]] inline Vecf32 GetTriangleSurfaceNormal(const Vecf32 &a, const Vecf32 &b, const Vecf32 &c);

	/*
	 * The "LOG" static class implements Thread Safe Logging Functions
	 * that can be colored (see LOG_TYPE enum class)
	 */ 

	class LOG
	{
	private:
		static std::mutex m_sPrintMutex;

	private:
		template <typename T, typename ...Args>
		static void __Print(const LOG_TYPE logType, const T& message0, Args... args) WS_NOEXCEPT;

	public:
		template <typename T, typename ...Args>
		static inline void Print(const LOG_TYPE logType,   const T& message0, Args... args) WS_NOEXCEPT;

		template <typename T, typename ...Args>
		static inline void Println(const LOG_TYPE logType, const T& message0, Args... args) WS_NOEXCEPT;

	};

	/*
	 * Any object, function or variable in the "Internal" namespace shall
	 * not be used by a user of the library and only used by the Weiss Engine
	 */

	namespace Internal
	{
		/* 
		 * We use a per platform image loading system to use
		 * their platform's preexisting libraries to improve
		 * performance and use less 3rd party libraries
		 * 
		 * This system uses a few virtual function calls but they aren't a big nuisance
		 * 
		 * Any child class shall have the following constructors :
		 * - Image()
		 * - Image(Image&& other)
		 * - Image(const Image& other)
		 * - Image(const char* filename)
		 * - Image(const uint16_t width, const uint16_t height, const Coloru8& fillColor = { 255u,255u,255u,255u })
		 * 
		 * And the following operators : 
		 * - ImageClassName& operator=(ImageClassName&& other)
		 */

		class ImageBase
		{
		protected:
			std::unique_ptr<Coloru8[]> m_buff;

			uint16_t m_width = 0, m_height = 0;
			uint32_t m_nPixels = 0;

		public:
			[[nodiscard]] inline uint16_t GetWidth()      const WS_NOEXCEPT { return this->m_width;      }
			[[nodiscard]] inline uint16_t GetHeight()     const WS_NOEXCEPT { return this->m_height;     }
			[[nodiscard]] inline uint32_t GetPixelCount() const WS_NOEXCEPT { return this->m_nPixels;    }
			[[nodiscard]] inline Coloru8* GetBuffer()     const WS_NOEXCEPT { return this->m_buff.get(); }

			[[nodiscard]] inline Coloru8  Sample(const uint16_t x, const uint16_t y) const WS_NOEXCEPT { return this->m_buff[y * this->m_width + x]; }

			inline void Set(const uint16_t x, const uint16_t y, const Coloru8 &color) WS_NOEXCEPT { this->m_buff[y * this->m_width + x] = color; }

			virtual void Write(const char *filename) const WS_NOEXCEPT = 0;
		};

#ifdef __WEISS__OS_WINDOWS

		// ////////////-\\\\\\\\\\\\ \\
		// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
		// |----------WIN----------| \\
		// |\_____________________/| \\
		// \\\\\\\\\\\\-//////////// \\

		namespace WIN
		{

			// ////////////////--\\\\\\\\\\\\\\\\ \\
			// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			// |----------WindowsImage----------| \\
			// |\______________________________/| \\
			// \\\\\\\\\\\\\\\\--//////////////// \\

			class WindowsImage : public ImageBase
			{
			public:
				WindowsImage() = default;

				WindowsImage(WindowsImage &&other) noexcept;

				WindowsImage(const WindowsImage &other) noexcept;

				WindowsImage(const char *filename) WS_NOEXCEPT;

				WindowsImage(const uint16_t width, const uint16_t height, const Coloru8 &fillColor = {255u, 255u, 255u, 255u}) WS_NOEXCEPT;

				WindowsImage& operator=(const WindowsImage& other) WS_NOEXCEPT;

				virtual void Write(const char *filename) const WS_NOEXCEPT override;
			};

		}; // namespace WIN

#endif // __WEISS__OS_WINDOWS

	}; // namespace Internal

#ifdef __WEISS__OS_WINDOWS

	typedef Internal::WIN::WindowsImage Image;

#endif // __WEISS__OS_WINDOWS

	// ///////////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	// |----------------------------------------------------------------------| \\
	// |--------------------------PERIPHERAL DEVICES--------------------------| \\
	// |----------------------------------------------------------------------| \\
	// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--/////////////////////////////////// \\

	class PeripheralDevice
	{
	public:
		virtual void __OnWindowUpdateBegin() {}
		virtual void __OnWindowUpdateEnd()   {}
	};

	// ////////////////////-\\\\\\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |----------MouseEventInterface----------| \\
	// |\_____________________________________/| \\
	// \\\\\\\\\\\\\\\\\\\\-//////////////////// \\

	class MouseEventInterface
	{
	protected:
		std::vector<std::function<void(const Vecu16)>> m_onLeftButtonUpFunctors;
		std::vector<std::function<void(const Vecu16)>> m_onLeftButtonDownFunctors;

		std::vector<std::function<void(const Vecu16)>> m_onRightButtonUpFunctors;
		std::vector<std::function<void(const Vecu16)>> m_onRightButtonDownFunctors;

		std::vector<std::function<void(const int16_t)>> m_onWheelTurnFunctors;

		std::vector<std::function<void(const Vecu16, const Veci16)>> m_onMouseMoveFunctors;
		std::vector<std::function<void(const Vecu16, const Veci16)>> m_onCursorMoveFunctors;

	public:
		inline void OnLeftButtonUp   (const std::function<void(Vecu16)>& functor) WS_NOEXCEPT { this->m_onLeftButtonUpFunctors.push_back(functor);    }
		inline void OnLeftButtonDown (const std::function<void(Vecu16)>& functor) WS_NOEXCEPT { this->m_onLeftButtonDownFunctors.push_back(functor);  }
		inline void OnRightButtonUp  (const std::function<void(Vecu16)>& functor) WS_NOEXCEPT { this->m_onRightButtonUpFunctors.push_back(functor);   }
		inline void OnRightButtonDown(const std::function<void(Vecu16)>& functor) WS_NOEXCEPT { this->m_onRightButtonDownFunctors.push_back(functor); }

		inline void OnWheelTurn (const std::function<void(const int16_t)> &functor)                WS_NOEXCEPT { this->m_onWheelTurnFunctors.push_back(functor); }
		inline void OnMouseMove (const std::function<void(const Vecu16, const Veci16)>& functor) WS_NOEXCEPT { this->m_onMouseMoveFunctors.push_back(functor);  }
		inline void OnCursorMove(const std::function<void(const Vecu16, const Veci16)>& functor) WS_NOEXCEPT { this->m_onCursorMoveFunctors.push_back(functor); }
	};

	// ////////////////////-\\\\\\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |-----------------Mouse-----------------| \\
	// |\_____________________________________/| \\
	// \\\\\\\\\\\\\\\\\\\\-//////////////////// \\

	class Mouse : public MouseEventInterface
	{
	protected:
		Vecu16 m_position      { 0, 0 };
		Veci16 m_deltaPosition { 0, 0 };

		int16_t m_wheelDelta = 0;

		bool m_isLeftButtonDown  = false;
		bool m_isRightButtonDown = false;

		bool m_wasMouseMovedDuringUpdate  = false;
		bool m_wasCursorMovedDuringUpdate = false;

		bool m_isCursorInWindow = false;

	public:
		Mouse() = default;

		virtual ~Mouse() = default;

		[[nodiscard]] inline bool IsLeftButtonUp()   const WS_NOEXCEPT { return !this->m_isLeftButtonDown; }
		[[nodiscard]] inline bool IsLeftButtonDown() const WS_NOEXCEPT { return this->m_isLeftButtonDown;  }

		[[nodiscard]] inline bool IsRightButtonUp()   const WS_NOEXCEPT { return !this->m_isRightButtonDown; }
		[[nodiscard]] inline bool IsRightButtonDown() const WS_NOEXCEPT { return this->m_isRightButtonDown;  }

		[[nodiscard]] inline bool IsCursorInWindow() const WS_NOEXCEPT { return this->m_isCursorInWindow; }

		virtual inline void Show() const WS_NOEXCEPT = 0;
		virtual inline void Hide() const WS_NOEXCEPT = 0;

		/*
		 * Limits the mouse movements to a specific "Rect"
		 * This may be used in games to make the cursor stay
		 * inside of the window
		*/
		virtual void Clip(const Rect &rect) const WS_NOEXCEPT = 0;
	};

	// ////////////////////--\\\\\\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |---------KeyboardEventInterface---------| \\
	// |\______________________________________/| \\
	// \\\\\\\\\\\\\\\\\\\\--//////////////////// \\

	class KeyboardEventInterface
	{
	protected:
		std::vector<uint8_t> m_downKeys;

		std::vector<std::function<void(const uint8_t)>> m_onKeyUpFunctors;
		std::vector<std::function<void(const uint8_t)>> m_onKeyDownFunctors;

	public:
		inline void OnKeyUp  (const std::function<void(const uint8_t)>& functor) WS_NOEXCEPT { this->m_onKeyUpFunctors.push_back(functor);   }
		inline void OnKeyDown(const std::function<void(const uint8_t)>& functor) WS_NOEXCEPT { this->m_onKeyDownFunctors.push_back(functor); }
	};

	// ////////////////////--\\\\\\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |----------------Keyboard----------------| \\
	// |\______________________________________/| \\
	// \\\\\\\\\\\\\\\\\\\\--//////////////////// \\

	class Keyboard : public KeyboardEventInterface
	{
	protected:
		std::vector<uint8_t> m_downKeys;

	public:
		Keyboard() = default;

		virtual ~Keyboard() = default;

		[[nodiscard]] inline bool IsKeyDown(const uint8_t key) const WS_NOEXCEPT
		{
			return this->m_downKeys.end() != std::find(this->m_downKeys.begin(), this->m_downKeys.end(), key);
		}
	};

	// //////////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	// |-------------------------------------------------------------------| \\
	// |------------------------------WINDOWS------------------------------| \\
	// |-------------------------------------------------------------------| \\
	// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-////////////////////////////////// \\

	struct WindowDescriptor
	{
		uint16_t width = 500u, height = 500u;
		uint16_t x = 0u;
		uint16_t y = 0u;
		const char *title = "Weiss Engine";
		const char *iconPath = nullptr;
		bool isResizable = true;
	};

	struct WindowHandle;

	class Window
	{
	protected:
		Mouse *m_pMouse = nullptr;
		Keyboard *m_pKeyboard = nullptr;

		bool m_isRunning = false;
		bool m_isMinimized = false;

		std::vector<std::function<void(const Vecu16)>> m_onResizeFunctors;

	public:
		Window() = default;

		virtual ~Window() WS_NOEXCEPT;

		// <<<<---- Events ---->>>> \\

		inline void OnResize(const std::function<void(const Vecu16)> &functor) WS_NOEXCEPT { this->m_onResizeFunctors.push_back(functor); }

		// <<<<---- Getters ---->>>> \\

		[[nodiscard]] inline bool IsRunning() const WS_NOEXCEPT { return this->m_isRunning; }

		[[nodiscard]] inline Mouse&    GetMouse()    WS_NOEXCEPT { return *this->m_pMouse;    }
		[[nodiscard]] inline Keyboard& GetKeyboard() WS_NOEXCEPT { return *this->m_pKeyboard; }

		[[nodiscard]] inline uint16_t GetWindowPositionX() const WS_NOEXCEPT { return static_cast<uint16_t>(this->GetWindowRectangle().left);   }
		[[nodiscard]] inline uint16_t GetWindowPositionY() const WS_NOEXCEPT { return static_cast<uint16_t>(this->GetWindowRectangle().top);    }
		[[nodiscard]] inline uint16_t GetClientWidth()     const WS_NOEXCEPT { return static_cast<uint16_t>(this->GetClientRectangle().right);  }
		[[nodiscard]] inline uint16_t GetClientHeight()    const WS_NOEXCEPT { return static_cast<uint16_t>(this->GetClientRectangle().bottom); }

		[[nodiscard]] inline uint16_t GetWindowWidth() const WS_NOEXCEPT
		{
			const Rect rect = this->GetWindowRectangle();

			return static_cast<uint16_t>(rect.right - rect.left);
		}

		[[nodiscard]] inline uint16_t GetWindowHeight() const WS_NOEXCEPT
		{
			const Rect rect = this->GetWindowRectangle();

			return static_cast<uint16_t>(rect.bottom - rect.top);
		}

		[[nodiscard]] virtual Rect GetWindowRectangle() const WS_NOEXCEPT = 0;
		[[nodiscard]] virtual Rect GetClientRectangle() const WS_NOEXCEPT = 0;

		// <<<<---- Setters ---->>>> \\

		virtual void SetWindowSize(const uint16_t width, const uint16_t height) WS_NOEXCEPT = 0;
		virtual void SetClientSize(const uint16_t width, const uint16_t height) WS_NOEXCEPT = 0;
		virtual void SetTitle(const char *title) const WS_NOEXCEPT = 0;
		virtual void SetIcon (const char *pathname) WS_NOEXCEPT = 0;

		// <<<<---- Msc ---->>>> \\

		virtual void Update() = 0;

	public:
		// To Be Defined Per Platform
		static WindowHandle Create(const WindowDescriptor &descriptor = WindowDescriptor{}) WS_NOEXCEPT;
	};

	/*
	 * The "WindowHandle" struct contains a pointer to the "Window" object and handles
	 * its proper destruction in order to "free" the user of needing to avoid memory
	 * leaks when creating windows. The user can access the window's methods by using
	 * the "->" operator like he would do with a generic "Window*".
	 */
	struct WindowHandle
	{
		Window* pWindow;

		~WindowHandle() { delete pWindow; }

		inline Window *operator->() const WS_NOEXCEPT { return this->pWindow; }
		inline operator Window *()  const WS_NOEXCEPT { return this->pWindow; }
	};

	// /////////////////////--\\\\\\\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |-----------------Internal-----------------| \\
	// |\________________________________________/| \\
	// \\\\\\\\\\\\\\\\\\\\\--///////////////////// \\

	namespace Internal {

#ifdef __WEISS__OS_WINDOWS

		// /////////////////////-\\\\\\\\\\\\\\\\\\\\\ \\
		// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
		// |-------------------WIN-------------------| \\
		// |\_______________________________________/| \\
		// \\\\\\\\\\\\\\\\\\\\\-///////////////////// \\

		namespace WIN
		{

			// ///////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			// |-------------------WindowsPeripheralDevice-------------------| \\
			// |\___________________________________________________________/| \\
			// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-/////////////////////////////// \\

			class WindowsPeripheralDevice : public PeripheralDevice
			{
			public:
				virtual bool __HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam) WS_NOEXCEPT = 0;
			};

			// ///////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			// |-------------------------WindowsMouse-------------------------| \\
			// |\____________________________________________________________/| \\
			// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--/////////////////////////////// \\

			class WindowsMouse : public Mouse,
								 public WindowsPeripheralDevice
			{
			public:
				WindowsMouse() WS_NOEXCEPT;

				virtual inline void Show() const WS_NOEXCEPT override { ShowCursor(true);  }
				virtual inline void Hide() const WS_NOEXCEPT override { ShowCursor(false); }

				virtual void Clip(const Rect &rect) const WS_NOEXCEPT override;

				virtual void __OnWindowUpdateBegin() WS_NOEXCEPT override;

				virtual bool __HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam) WS_NOEXCEPT override;

				virtual void __OnWindowUpdateEnd() WS_NOEXCEPT override;
			};

			// /////////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			// |-------------------------WindowsKeyboard-------------------------| \\
			// |\_______________________________________________________________/| \\
			// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-///////////////////////////////// \\

			class WindowsKeyboard : public Keyboard,
									public WindowsPeripheralDevice
			{
			public:
				virtual bool __HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam) WS_NOEXCEPT override;
			};

			LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lparam);

			class WindowsWindow : public Window
			{
				friend LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lparam);

			private:
				HWND m_handle = 0;

			public:
				WindowsWindow(const WindowDescriptor &descriptor) WS_NOEXCEPT;

				// <<<<---- Getters ---->>>> //

				[[nodiscard]] inline HWND GetHandle()              const WS_NOEXCEPT { return this->m_handle;        }
				[[nodiscard]] inline HDC  GetDeviceContextHandle() const WS_NOEXCEPT { return GetDC(this->m_handle); }

				[[nodiscard]] virtual Rect GetWindowRectangle() const WS_NOEXCEPT override;

				[[nodiscard]] virtual Rect GetClientRectangle() const WS_NOEXCEPT override;

				// <<<<---- Setters ---->>>> //

				virtual void SetWindowSize(const uint16_t width, const uint16_t height) WS_NOEXCEPT override;

				virtual void SetClientSize(const uint16_t width, const uint16_t height) WS_NOEXCEPT override;

				virtual void SetTitle(const char *title) const WS_NOEXCEPT override;

				virtual void SetIcon(const char *pathname) WS_NOEXCEPT override;

				// <<<<---- Misc ---->>>> //

				[[nodiscard]] LRESULT HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam) WS_NOEXCEPT;

				virtual void Update() WS_NOEXCEPT override;

				void Destroy() WS_NOEXCEPT;

				~WindowsWindow() WS_NOEXCEPT;
			};

			LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

		}; // namespace WIN

#endif // __WEISS__OS_WINDOWS

	}; // namespace Internal

	// //////////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	// |-------------------------------------------------------------------| \\
	// |------------------------------CAMERAS------------------------------| \\
	// |-------------------------------------------------------------------| \\
	// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-////////////////////////////////// \\

	class Camera
	{
	protected:
		MatrixFloat32 m_transform = MatrixFloat32::MakeIdentity();

		Vecf32 m_position;
		Vecf32 m_rotation;

	public:
		Camera() = default;

		Camera(const Vecf32& position, const Vecf32& rotation) : m_position(position), m_rotation(rotation) { }

		[[nodiscard]] inline MatrixFloat32 GetTransform()           const WS_NOEXCEPT { return this->m_transform;                 }
		[[nodiscard]] inline MatrixFloat32 GetTransposedTransform() const WS_NOEXCEPT { return MatrixFloat32::MakeTransposed(this->m_transform); }

		[[nodiscard]] inline const Vecf32& GetPosition() const WS_NOEXCEPT { return this->m_position; }
		[[nodiscard]] inline const Vecf32& GetRotation() const WS_NOEXCEPT { return this->m_rotation; }

		inline void Rotate     (const Vecf32 &delta)    WS_NOEXCEPT { this->m_rotation += delta;   }
		inline void SetRotation(const Vecf32 &rotation) WS_NOEXCEPT { this->m_rotation = rotation; }

		inline void Translate  (const Vecf32 &delta)    WS_NOEXCEPT { this->m_position += delta;   }
		inline void SetPosition(const Vecf32 &position) WS_NOEXCEPT { this->m_position = position; }

		virtual void CalculateTransform() = 0;

		virtual void HandleMouseMovements(Mouse &mouse, const float sensitivity) WS_NOEXCEPT = 0;
		virtual void HandleKeyboardInputs(Keyboard &keyboard, const float speed, const char forward, const char backward, const char left, const char right, const char up, const char down) WS_NOEXCEPT = 0;
	};

	// ///////////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |--------------------------PerspectiveCamera--------------------------| \\
	// |\___________________________________________________________________/| \\
	// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-/////////////////////////////////// \\

	struct PerspectiveCameraDescriptor
	{
		const Vecf32 position;
		const Vecf32 rotation;

		const float fov = 90.0f;
		const float zNear = 0.1f;
		const float zFar = 1000.0f;
	};

	class PerspectiveCamera : public Camera
	{
	private:
		const Vecf32 UP_VECTOR{0.0f, 1.0f, 0.0f};
		const Vecf32 FORWARD_VECTOR{0.0f, 0.0f, 1.0f};
		const Vecf32 RIGHT_VECTOR{1.0f, 0.0f, 0.0f};

		Vecf32 m_forwardVector = FORWARD_VECTOR;
		Vecf32 m_rightVector = RIGHT_VECTOR;

		float m_fov = 0.0f, m_aspectRatio = 0.0f, m_zNear = 0.0f, m_zFar = 0.0f;

	public:
		PerspectiveCamera(Window *pWindow, const PerspectiveCameraDescriptor &descriptor) WS_NOEXCEPT;

		virtual void CalculateTransform() WS_NOEXCEPT override;

		virtual void HandleMouseMovements(Mouse &mouse, const float sensitivity) WS_NOEXCEPT override;

		virtual void HandleKeyboardInputs(Keyboard &keyboard, const float speed, const char forward, const char backward, const char left, const char right, const char up, const char down) WS_NOEXCEPT override;
	};

	// //////////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |-------------------------OrthographicCamera-------------------------| \\
	// |\__________________________________________________________________/| \\
	// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--////////////////////////////////// \\

	struct OrthographicCameraDescriptor
	{
		const Vecf32 position;
		const float ratation;
	};

	class OrthographicCamera : public Camera
	{
	private:
		float m_InvAspectRatio = 0.0f;

	public:
		OrthographicCamera(Window *pWindow, const OrthographicCameraDescriptor &descriptor) WS_NOEXCEPT;

		virtual void CalculateTransform() WS_NOEXCEPT override;

		virtual void HandleMouseMovements(Mouse &mouse, const float sensitivity) WS_NOEXCEPT override;

		virtual void HandleKeyboardInputs(Keyboard &keyboard, const float speed, const char forward, const char backward, const char left, const char right, const char up, const char down) WS_NOEXCEPT override;
	};

	// //////////////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |------------------------------GENERIC BUFFERS------------------------------| \\
	// |\_________________________________________________________________________/| \\
	// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-////////////////////////////////////// \\

	class VertexBuffer
	{
	protected:
		std::vector<int8_t> m_vertexData;

	public:
		virtual void Update() WS_NOEXCEPT = 0;

		inline void Set(const void *buff, const size_t bufferSize) WS_NOEXCEPT
		{
			std::memcpy(this->m_vertexData.data(), buff, bufferSize);
		}

		template <typename CONTAINER>
		inline void Set(const CONTAINER &container) WS_NOEXCEPT
		{
			this->Set(container.data(), container.size() * sizeof(container[0]));
		}

		template <typename T>
		inline T& GetVertex(const size_t vertexIndex) WS_NOEXCEPT
		{
			return *(((T *)(this->m_vertexData.data())) + vertexIndex);
		}

		template <typename T>
		inline void SetVertex(const size_t vertexIndex, const T &vertex) WS_NOEXCEPT
		{
			this->GetVertex<T>(vertexIndex) = vertex;
		}
	};

	// ////////////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |------------------------------IndexBuffer------------------------------| \\
	// |\_____________________________________________________________________/| \\
	// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-//////////////////////////////////// \\

	class IndexBuffer
	{
	protected:
		std::vector<uint32_t> m_indexData;

	public:
		virtual void Update() WS_NOEXCEPT = 0;

		inline void Set(const void *buff, const size_t nIndices) WS_NOEXCEPT
		{
			std::memcpy(this->m_indexData.data(), buff, nIndices * sizeof(uint32_t));
		}

		template <typename CONTAINER>
		inline void Set(const CONTAINER &container) WS_NOEXCEPT
		{
			this->Set(container.data(), container.size());
		}

		inline uint32_t &GetIndex(const size_t indexIndex) WS_NOEXCEPT
		{
			return this->m_indexData[indexIndex];
		}

		inline void SetIndex(const size_t indexIndex, const uint32_t index) WS_NOEXCEPT
		{
			this->GetIndex(indexIndex) = index;
		}
	};

	// /////////////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |------------------------------ConstantBuffer------------------------------| \\
	// |\________________________________________________________________________/| \\
	// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--///////////////////////////////////// \\

	class ConstantBuffer
	{
	protected:
		std::vector<int8_t> m_constantBufferData;

	public:
		virtual void Update() WS_NOEXCEPT = 0;

		template <typename T>
		inline T &Get() WS_NOEXCEPT
		{
			return *((T *)this->m_constantBufferData.data());
		}

		template <typename T>
		inline void Set(const T &obj) WS_NOEXCEPT
		{
			this->Get<T>() = obj;
		}
	};

	// //////////////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	// |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |------------------------------GENERIC TEXTURES------------------------------| \\
	// |\__________________________________________________________________________/| \\
	// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--////////////////////////////////////// \\

	class Texture
	{
	protected:
		Image m_image;

	public:
		virtual void Update() = 0;

		[[nodiscard]] inline const Image& GetImage() const WS_NOEXCEPT { return this->m_image; }

		[[nodiscard]] inline void SetImage(const Image& image) WS_NOEXCEPT { this->m_image = image; }
	};

	// ///////////////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	// |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |------------------------------GENERIC RENDER API------------------------------| \\
	// |\____________________________________________________________________________/| \\
	// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--/////////////////////////////////////// \\

	struct Drawable
	{
		size_t pipelineIndex;
		size_t vertexBufferIndex;

		std::optional<size_t> indexBufferIndex;
	};

	struct RenderPipelineDesc
	{
		const char *vsFilename;
		std::vector<ShaderInputElement> sies;
		const char *psFilename;
		std::vector<uint32_t> constantBufferIndices;
		std::vector<uint32_t> textureIndices;
		std::vector<uint32_t> textureSamplerIndices;
		PrimitiveTopology topology = PrimitiveTopology::TRIANGLES;
	};

	class RenderAPIHandle;

	// ///////////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |------------------------------RenderAPI------------------------------| \\
	// |\___________________________________________________________________/| \\
	// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-/////////////////////////////////// \\

	class RenderAPI
	{
	private:
		RenderAPIName m_apiName;

	protected:
		std::vector<VertexBuffer*>   m_pVertexBuffers;
		std::vector<IndexBuffer*>    m_pIndexBuffers;
		std::vector<ConstantBuffer*> m_pConstantBuffers;
		std::vector<Texture*>        m_pTextures;

	public:
		RenderAPI(const RenderAPIName &apiName) : m_apiName(apiName) {  }

		virtual ~RenderAPI() WS_NOEXCEPT { }

		// ----- Virtual Functions ----- //

		virtual void InitRenderAPI(Window *pWindow, const uint16_t maxFps = 144u) WS_NOEXCEPT = 0;
		virtual void InitPipelines(const std::vector<RenderPipelineDesc> &pipelineDescs) WS_NOEXCEPT = 0;

		virtual void Draw(const Drawable &drawable, const size_t nVertices) WS_NOEXCEPT = 0;

		/*
		 * This structure is used to take advantage of recent rendering apis such as directx12 and vulkan.
		 * By submitting draw commands to the GPU asynchronously while other functions can be called on the cpu side
		 * (such as game logic and physics). The present method is then called to swap buffers.
		 * This is why dealing with gpu memory after calling "EndFrame()" is undefined behavior.
		 */
		virtual void BeginDrawing() WS_NOEXCEPT = 0;
		virtual void EndDrawing()   WS_NOEXCEPT = 0;

		virtual void Present(const bool vSync) = 0;

		virtual size_t CreateVertexBuffer  (const size_t nVertices,      const size_t vertexSize) WS_NOEXCEPT = 0;
		virtual size_t CreateIndexBuffer   (const size_t nIndices) WS_NOEXCEPT = 0;
		virtual size_t CreateConstantBuffer(const size_t objSize,        const size_t slot) WS_NOEXCEPT = 0;
		virtual size_t CreateTexture       (const size_t width,          const size_t height, const size_t slot, const bool useMipmaps = false) WS_NOEXCEPT = 0;
		virtual size_t CreateTextureSampler(const TextureFilter& filter, const size_t slot) WS_NOEXCEPT = 0;

		virtual void Fill(const Colorf32 &color = {1.f, 1.f, 1.f, 1.f}) = 0;

		// ----- Non-Virtual Functions ----- //

		inline VertexBuffer&   GetVertexBuffer  (const size_t vertexBufferIndex)   WS_NOEXCEPT { return *this->m_pVertexBuffers[vertexBufferIndex];     }
		inline IndexBuffer&    GetIndexBuffer   (const size_t indexBufferIndex)    WS_NOEXCEPT { return *this->m_pIndexBuffers[indexBufferIndex];       }
		inline ConstantBuffer& GetConstantBuffer(const size_t constantBufferIndex) WS_NOEXCEPT { return *this->m_pConstantBuffers[constantBufferIndex]; }
		inline Texture&        GetTexture       (const size_t textureIndex)        WS_NOEXCEPT { return *this->m_pTextures[textureIndex];               }

		// ----- Non-Virtual Virtual Overloads ----- //

		inline size_t CreateVertexBuffer(const void *buff, const size_t nVertices, const size_t vertexSize) WS_NOEXCEPT
		{
			const size_t i = this->CreateVertexBuffer(nVertices, vertexSize);

			this->GetVertexBuffer(i).Set(buff, nVertices * vertexSize);
			this->GetVertexBuffer(i).Update();

			return i;
		}

		template <typename CONTAINER>
		inline size_t CreateVertexBuffer(const CONTAINER &container) WS_NOEXCEPT
		{
			return this->CreateVertexBuffer(container.data(), container.size() * sizeof(container[0]), sizeof(container[0]));
		}

		inline size_t CreateIndexBuffer(const void *buff, const size_t nIndices) WS_NOEXCEPT
		{
			const size_t i = this->CreateIndexBuffer(nIndices);

			this->GetIndexBuffer(i).Set(buff, nIndices);
			this->GetIndexBuffer(i).Update();

			return i;
		}

		template <typename CONTAINER>
		inline size_t CreateIndexBuffer(const CONTAINER &container) WS_NOEXCEPT
		{
			return this->CreateIndexBuffer(container.data(), container.size());
		}

		template <typename T>
		inline size_t CreateConstantBuffer(const T &obj, const size_t slotVS, const size_t slotPS) WS_NOEXCEPT
		{
			const size_t constantBufferIndex = this->CreateConstantBuffer(sizeof(T), slotVS, slotPS);
			this->GetConstantBuffer(constantBufferIndex).Set(obj);
			this->GetConstantBuffer(constantBufferIndex).Update();

			return constantBufferIndex;
		}

		inline size_t CreateTexture(Image &image, const size_t slot, const bool useMipmaps = false) WS_NOEXCEPT
		{
			const size_t textureIndex = this->CreateTexture(image.GetWidth(), image.GetHeight(), false);
			this->GetTexture(textureIndex).SetImage(image);
			this->GetTexture(textureIndex).Update();

			return textureIndex;
		}

		// ----- Getter Functions ----- //

		[[nodiscard]] RenderAPIName GetRenderAPIName() const WS_NOEXCEPT { return this->m_apiName; }

		// ----- Creation ----- //
		static RenderAPIHandle Create(const RenderAPIName &apiName) WS_NOEXCEPT;
	};

	/*
	 * The "RenderAPIHandle" struct contains a pointer to the "RenderAPI" object and handles
	 * its proper destruction in order to "free" the user of needing to avoid memory
	 * leaks when creating a derived class of "RenderAPI". The user can access the api's methods by using
	 * the "->" operator like he would do with a generic "RenderAPI*".
	 */
	class RenderAPIHandle
	{
	private:
		RenderAPI *m_pRenderAPI = nullptr;

	public:
		RenderAPIHandle() = default;
		RenderAPIHandle(RenderAPI* pRenderAPI) WS_NOEXCEPT : m_pRenderAPI(pRenderAPI) {  }

		~RenderAPIHandle() WS_NOEXCEPT { delete this->m_pRenderAPI; }

		inline operator RenderAPI*  () WS_NOEXCEPT { return this->m_pRenderAPI; }
		inline RenderAPI* operator->() WS_NOEXCEPT { return this->m_pRenderAPI; }
	};

	namespace Internal {

		// //////////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
		// |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
		// ||------------------------------VULKAN-----------------------------|| \\
		// |\_________________________________________________________________/| \\
		// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--///////////////////////////////// \\

		namespace VK {

			/*
			* To prevent a "use after free" (and many mental breakdowns) please overload
			* the "void operator=" function with an r-value reference (like the one for this class)
			* in any class that inherits from this base class.
			* it can also be used to track object life-time
			*/
			template <typename T>
			class VKObjectWrapper {
			protected:
				T m_object = VK_NULL_HANDLE;

			public:
				VKObjectWrapper() = default;

				VKObjectWrapper<T>& operator=(VKObjectWrapper<T>&& other) WS_NOEXCEPT;

				inline operator T&() WS_NOEXCEPT;
				inline operator T() const WS_NOEXCEPT;

				inline T& GetRef() WS_NOEXCEPT;
				inline T* GetPtr() WS_NOEXCEPT;
				inline const T* GetPtr() const WS_NOEXCEPT;

				~VKObjectWrapper();
			};

			/*
			 * // ///////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------------validationLayerCallback------------------|| \\
			 * // |\___________________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-/////////////////////////////// \\
			 */

			static VKAPI_ATTR VkBool32 VKAPI_CALL validationLayerCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
																		  VkDebugUtilsMessageTypeFlagsEXT messageType,
																		  const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
																		  void* pUserData);

			/*
			 * // ///////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||-------------------------VKInstance-------------------------|| \\
			 * // |\____________________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--/////////////////////////////// \\
			 */

			class VKInstance : public VKObjectWrapper<VkInstance> {
			public:
				VKInstance() = default;

				VKInstance(const char* appName);

				VKInstance& operator=(VKInstance&& other) WS_NOEXCEPT;

				~VKInstance();
			};

			/*
			 * // ///////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||-------------------------VKSurface-------------------------|| \\
			 * // |\___________________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-/////////////////////////////// \\
			 */

			class VKSurface : public VKObjectWrapper<VkSurfaceKHR> {
			private:
				const VKInstance* m_pInstance = nullptr;

				Vecu16 m_dimensions{ 0u, 0u };

			public:
				VKSurface() = default;

				VKSurface(const VKInstance& instance, Window* pWindow) WS_NOEXCEPT;

				VKSurface& operator=(VKSurface&& other) WS_NOEXCEPT;

				[[nodiscard]] inline Vecu16 GetDimensions() const WS_NOEXCEPT;

				~VKSurface();
			};

			/*
			 * // ///////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------------------VKPhysicalDeviceData--------------------|| \\
			 * // |\____________________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--/////////////////////////////// \\
			 */

			struct VKPhysicalDeviceData {
				VkPhysicalDevice                     physicalDevice{};
				VkPhysicalDeviceFeatures             features{};
				VkPhysicalDeviceProperties           propreties{};
				std::vector<VkQueueFamilyProperties> queueFamilyPropreties{};
				std::vector<VkExtensionProperties>   extensionPropreties{};

				uint32_t rating = 0u;

				union {
					struct
					{
						std::optional<uint32_t> graphicsQueueIndex;
						std::optional<uint32_t> presentQueueIndex;
					};
					struct
					{
						std::optional<uint32_t> queueIndices[2];
					};
				};

				VKPhysicalDeviceData() WS_NOEXCEPT {  }

				VKPhysicalDeviceData(const VkPhysicalDevice& physicalDevice, const VKSurface& surface) WS_NOEXCEPT;
			};

			/*
			 * // /////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------------------VKDevice--------------------|| \\
			 * // |\________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\--///////////////////////// \\
			 */

			class VKDevice : public VKObjectWrapper<VkDevice> {
			private:				
				const VKInstance* m_pInstance = nullptr;

				VKPhysicalDeviceData m_physicalDeviceData;

			public:
				VKDevice() = default;

				VKDevice(const VKInstance& instance, const VKSurface& surface) WS_NOEXCEPT;

				[[nodiscard]] inline VKPhysicalDeviceData GetPhysicalDeviceData() const WS_NOEXCEPT;

				VKDevice& operator=(VKDevice&& other) WS_NOEXCEPT;

				~VKDevice();
			};

			/*
			 * // ///////////////////////-\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------------VKQueue------------------|| \\
			 * // |\___________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\-/////////////////////// \\
			 */

			class VKQueue : public VKObjectWrapper<VkQueue> {
			public:
				VKQueue() = default;

				VKQueue(const VKDevice& device, const size_t queueIndex) WS_NOEXCEPT;

				VKQueue& operator=(VKQueue&& other) WS_NOEXCEPT;

				~VKQueue() = default;
			};
			
			/*
			 * // /////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------------VKSemaphore------------------|| \\
			 * // |\_______________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\-///////////////////////// \\
			 */

			class VKSemaphore : public VKObjectWrapper<VkSemaphore> {
			private:
				const VKDevice* m_pDevice = nullptr;

			public:
				VKSemaphore() = default;

				VKSemaphore(const VKDevice& device) WS_NOEXCEPT;

				VKSemaphore& operator=(VKSemaphore&& other) WS_NOEXCEPT;

				~VKSemaphore();
			};

			/*
			 * // ///////////////////////-\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------------VKFence------------------|| \\
			 * // |\___________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\-/////////////////////// \\
			 */

			class VKFence : public VKObjectWrapper<VkFence> {
			private:
				const VKDevice* m_pDevice = nullptr;
			
			public:
				VKFence() = default;

				VKFence(const VKDevice& device) WS_NOEXCEPT;

				VKFence& operator=(VKFence&& other) noexcept;

				inline void Wait()  const WS_NOEXCEPT;
				inline void Reset() const WS_NOEXCEPT;

				inline void WaitAndReset() const WS_NOEXCEPT;

				~VKFence() WS_NOEXCEPT;
			};

			/*
			 * // /////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------------VKSwapChain------------------|| \\
			 * // |\_______________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\-///////////////////////// \\
			 */

			class VKSwapChain : public VKObjectWrapper<VkSwapchainKHR> {
			private:
				const VKDevice* m_pDevice = nullptr;
				const VKQueue*  m_pPresentQueue = nullptr;

				uint32_t m_currentImageIndex = 0u;
				uint32_t m_nImages = 0u;

				std::vector<VkImage>     m_images;
				std::vector<VkImageView> m_imageViews;

				std::vector<VkFramebuffer> m_frameBuffers;

				VkExtent2D         m_imageExtent2D{};
				VkSurfaceFormatKHR m_surfaceFormat{};

				VKFence     m_fence;
				VKSemaphore m_frameBufferFetchedSemaphore;

			public:
				VKSwapChain() = default;

				VKSwapChain(const VKDevice& device, const VKSurface& surface, const VKQueue& presentQueue) WS_NOEXCEPT;

				void CreateFrameBuffers() WS_NOEXCEPT;

				void GetNextFrameBuffer() WS_NOEXCEPT;

				void Present(bool useVsync, const VkSemaphore& waitSemaphore) WS_NOEXCEPT;

				VKSwapChain& operator=(VKSwapChain&& other) WS_NOEXCEPT;

				[[nodiscard]] inline VkSemaphore        GetFrameBufferFetchedSemaphore() const WS_NOEXCEPT;
				[[nodiscard]] inline VkFramebuffer      GetCurrentFrameBuffer() const WS_NOEXCEPT;
				[[nodiscard]] inline VkExtent2D         GetImageExtent() const WS_NOEXCEPT;
				[[nodiscard]] inline VkSurfaceFormatKHR GetFormat() const WS_NOEXCEPT;

				~VKSwapChain();
			
			public:
				static VkPresentModeKHR   PickPresentMode  (const VKDevice& device, const VKSurface& surface) WS_NOEXCEPT;
				static VkSurfaceFormatKHR PickSurfaceFormat(const VKDevice& device, const VKSurface& surface) WS_NOEXCEPT;
			};

			/*
			 * // /////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------------VKRenderPass------------------|| \\
			 * // |\________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\--///////////////////////// \\
			 */

			class VKRenderPass {
			public:
				static std::vector<VkRenderPass> m_renderPasses;

			public:
				static void CreateRenderPasses(const VKDevice& device, const VKSwapChain& swapChain) WS_NOEXCEPT;
			};

			/*
			 * // ///////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------------VKTextureSampler------------------|| \\
			 * // |\____________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\--/////////////////////////// \\
			 */

			class VKTextureSampler {

			};

			/*
			 * // ///////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------------VKRenderPipeline------------------|| \\
			 * // |\____________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\--/////////////////////////// \\
			 */

			class VKRenderPipeline : public VKObjectWrapper<VkPipeline>{
			private:
				const VKDevice* m_pDevice = nullptr;

				VKObjectWrapper<VkPipelineLayout> m_layout;

			public:
				VKRenderPipeline() = default;

				VKRenderPipeline(VKRenderPipeline&& other) WS_NOEXCEPT;

				VKRenderPipeline(const VKDevice& device, const VKSwapChain& swapChain, const RenderPipelineDesc& pipelineDesc,
								 std::vector<ConstantBuffer*>& pConstantBuffers, std::vector<Texture*> pTextures,
								 std::vector<VKTextureSampler> textureSamplers) WS_NOEXCEPT;
			
				VKRenderPipeline& operator=(VKRenderPipeline&& other) WS_NOEXCEPT;

				~VKRenderPipeline();

			public:
				static VkShaderModule CreateShaderModule(const VKDevice& device, const char* filename) WS_NOEXCEPT;
			};

			/*
			 * // //////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------------VKCommandPool------------------|| \\
			 * // |\_________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\\-////////////////////////// \\
			 */

			class VKCommandPool : public VKObjectWrapper<VkCommandPool> {
			private:
				const VKDevice* m_pDevice = nullptr;

			public:
				VKCommandPool() = default;

				VKCommandPool(const VKDevice& device, const uint32_t queueFamilyIndex) WS_NOEXCEPT;

				VKCommandPool& operator=(VKCommandPool&& other) WS_NOEXCEPT;

				~VKCommandPool();
			};

			/*
			 * // //////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||-----------------VKCommandBuffer-----------------|| \\
			 * // |\_________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\\-////////////////////////// \\
			 */

			class VKCommandBuffer : public VKObjectWrapper<VkCommandBuffer> {
			private:
				const VKDevice* m_pDevice = nullptr;
				const VKQueue*  m_pQueue  = nullptr;
				
				VKSemaphore m_submitedSemaphore;
				VKFence     m_submitedfence;

			public:
				VKCommandBuffer() = default;

				VKCommandBuffer(const VKDevice& device, const VKCommandPool& commandPool, const VKQueue& queue) WS_NOEXCEPT;

				VKCommandBuffer& operator=(VKCommandBuffer&& other) WS_NOEXCEPT;
			
				void BeginRecording() const WS_NOEXCEPT;

				void BeginRenderPass(const VKSwapChain& swapChain, const VkFramebuffer& frameBuffer, const VkRenderPass& renderPass) const WS_NOEXCEPT;

				void EndRenderPass() WS_NOEXCEPT;

				void EndRecording() const WS_NOEXCEPT;

				void Submit(const VkSemaphore& waitSemaphore) const WS_NOEXCEPT;

				void BindPipeline(const VKRenderPipeline& pipeline) WS_NOEXCEPT;

				void WaitForCompletion() WS_NOEXCEPT;

				[[nodiscard]] inline VkSemaphore GetSubmittedSemaphore() const WS_NOEXCEPT;
			};

			/*
			 * // ////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||-----------------VKRenderAPI-----------------|| \\
			 * // |\_____________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\-//////////////////////// \\
			 */

			class VKRenderAPI : public RenderAPI
			{
			private:
				VKInstance      m_instance;
				VKSurface       m_surface;
				VKDevice        m_device;
				VKQueue         m_gfxQueue;
				VKSwapChain     m_swapChain;
				VKQueue         m_presentQueue;
				VKCommandPool   m_commandPool;
				VKCommandBuffer m_commandBuffer;

				std::vector<VKTextureSampler> m_textureSamplers;
				std::vector<VKRenderPipeline> m_renderPipelines;

			public:
				VKRenderAPI() WS_NOEXCEPT : RenderAPI(RenderAPIName::VULKAN) {  }

				~VKRenderAPI() WS_NOEXCEPT;

				virtual void InitRenderAPI(Window* pWindow, const uint16_t maxFps) WS_NOEXCEPT override;

				virtual void InitPipelines(const std::vector<RenderPipelineDesc>& pipelineDescs) WS_NOEXCEPT override;

				virtual void Draw(const Drawable& drawable, const size_t nVertices) WS_NOEXCEPT override;

				virtual void BeginDrawing() WS_NOEXCEPT override;
				virtual void EndDrawing()   WS_NOEXCEPT override;

				virtual void Present(const bool vSync) WS_NOEXCEPT override;

				virtual size_t CreateVertexBuffer  (const size_t nVertices,      const size_t vertexSize) WS_NOEXCEPT override;
				virtual size_t CreateIndexBuffer   (const size_t nIndices) WS_NOEXCEPT override;
				virtual size_t CreateConstantBuffer(const size_t objSize,        const size_t slot) WS_NOEXCEPT override;
				virtual size_t CreateTexture       (const size_t width,          const size_t height, const size_t slot, const bool useMipmaps = false) WS_NOEXCEPT override;
				virtual size_t CreateTextureSampler(const TextureFilter& filter, const size_t slot) WS_NOEXCEPT override;

				virtual void Fill(const Colorf32& color = { 1.f, 1.f, 1.f, 1.f }) WS_NOEXCEPT override;
			};

		}; // VK

#ifdef __WEISS__OS_WINDOWS

		namespace D3D11
		{
			/*
			 * // /////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------------D3D11ObjectWrapper---------------|| \\
			 * // |\________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\--///////////////////////// \\
			 * 
			 * To prevent a "use after free" (and many mental breakdowns) please overload the "void operator=" function with an r-value reference (like the one for this class)
			 * in any class that inherits from this base class.
			*/
			template <typename T>
			class D3D11ObjectWrapper
			{
			protected:
				T *m_pObject = nullptr;

			public:
				D3D11ObjectWrapper() = default;

				/* This function overloads the assignement operator with an r-value reference to itself
				* It copies the pointer from the "other" and sets it to nullptr.
				* This is done to ensure that the resource isn't freed while this object is being created.
				* (Preventing a "use after free")
				*/
				D3D11ObjectWrapper<T> &operator=(D3D11ObjectWrapper<T> &&other);

				virtual ~D3D11ObjectWrapper();

				inline T*  Get()    WS_NOEXCEPT { return this->m_pObject;  }
				inline T** GetPtr() WS_NOEXCEPT { return &this->m_pObject; }

				inline T* operator->() WS_NOEXCEPT { return this->m_pObject; }
				inline operator T*  () WS_NOEXCEPT { return this->m_pObject; }
			};

			typedef D3D11ObjectWrapper<ID3D11Device> D3D11DeviceObjectWrapper;
			typedef D3D11ObjectWrapper<ID3D11DeviceContext> D3D11DeviceContextObjectWrapper;

			typedef D3D11ObjectWrapper<IDXGISwapChain> D3D11SwapChainObjectWrapper;

			/*
			 * // ///////////////////////--\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------------D3D11SwapChain---------------|| \\
			 * // |\____________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\--/////////////////////// \\
			 */

			class D3D11SwapChain : public D3D11SwapChainObjectWrapper
			{
			public:
				D3D11SwapChain() = default;

				D3D11SwapChain(D3D11DeviceObjectWrapper &pDevice, Window *pWindow) WS_NOEXCEPT;

				D3D11SwapChain &operator=(D3D11SwapChain &&other) WS_NOEXCEPT;

				void Present(const bool vSync) WS_NOEXCEPT;
			};

			typedef D3D11ObjectWrapper<ID3D11RenderTargetView> D3D11RenderTargetbjectWrapper;

			/*
			 * // ///////////////////////-\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||-------------D3D11RenderTarget-------------|| \\
			 * // |\___________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\-/////////////////////// \\
			 */

			class D3D11RenderTarget : public D3D11RenderTargetbjectWrapper
			{
			public:
				D3D11RenderTarget() = default;

				D3D11RenderTarget(D3D11DeviceObjectWrapper &pDevice, D3D11SwapChainObjectWrapper &pSwapChain) WS_NOEXCEPT;

				D3D11RenderTarget &operator=(D3D11RenderTarget &&other) WS_NOEXCEPT;

				void SetCurrent(D3D11DeviceContextObjectWrapper &pDeviceContext) const WS_NOEXCEPT;
			};

			/*
			 * // //////////////////////--\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||-------------D3D11DepthBuffer-------------|| \\
			 * // |\__________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\--////////////////////// \\
			 */

			class D3D11DepthBuffer
			{
			private:
				Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_pDepthStencilView;
				Microsoft::WRL::ComPtr<ID3D11DepthStencilState> m_pDepthStencilState;

			public:
				D3D11DepthBuffer() = default;

				D3D11DepthBuffer(Window *pWindow, D3D11DeviceObjectWrapper &pDevice) WS_NOEXCEPT;

				void Clear(D3D11DeviceContextObjectWrapper &pDeviceContext) WS_NOEXCEPT;

				void Bind(D3D11DeviceContextObjectWrapper &pDeviceContext, D3D11RenderTargetbjectWrapper &pRenderTarget) WS_NOEXCEPT;
			};

			/*
			 * // //////////////////////-\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------D3D11VertexShader------------|| \\
			 * // |\_________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\-////////////////////// \\
			 */

			class D3D11VertexShader
			{
			private:
				Microsoft::WRL::ComPtr<ID3D11VertexShader> m_pShader;
				Microsoft::WRL::ComPtr<ID3D11InputLayout>  m_pInputLayout;

				D3D11DeviceContextObjectWrapper *m_pDeviceContext = nullptr;

			public:
				D3D11VertexShader() = default;

				D3D11VertexShader(D3D11DeviceObjectWrapper &pDevice,
								D3D11DeviceContextObjectWrapper *pDeviceContext,
								const char *sourceFilename, const std::vector<ShaderInputElement> &sies) WS_NOEXCEPT;

				void Bind() const WS_NOEXCEPT;
			};

			/*
			 * // /////////////////////--\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------D3D11PixelShader------------|| \\
			 * // |\________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\--///////////////////// \\
			 */

			class D3D11PixelShader
			{
			private:
				Microsoft::WRL::ComPtr<ID3D11PixelShader> m_pShader;

				D3D11DeviceContextObjectWrapper *m_pDeviceContext = nullptr;

			public:
				D3D11PixelShader() = default;

				D3D11PixelShader(D3D11DeviceObjectWrapper &pDevice,
								D3D11DeviceContextObjectWrapper *pDeviceContext,
								const char *sourceFilename) WS_NOEXCEPT;

				void Bind() const WS_NOEXCEPT;
			};

			typedef D3D11ObjectWrapper<ID3D11Buffer> D3D11VertexBufferObjectWrapper;
			typedef D3D11ObjectWrapper<ID3D11Buffer> D3D11IndexBufferObjectWrapper;
			typedef D3D11ObjectWrapper<ID3D11Buffer> D3D11ConstantBufferObjectWrapper;

			/*
			 * // /////////////////////-\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||-----------D3D11VertexBuffer-----------|| \\
			 * // |\_______________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\-///////////////////// \\
			 */

			class D3D11VertexBuffer : public D3D11VertexBufferObjectWrapper,
									  public VertexBuffer
			{
			private:
				size_t m_vertexSize = 0u;

				D3D11DeviceContextObjectWrapper *m_pDeviceContext = nullptr;

			public:
				D3D11VertexBuffer() = default;

				D3D11VertexBuffer(D3D11DeviceObjectWrapper &pDevice,
								  D3D11DeviceContextObjectWrapper *pDeviceContext,
								  const size_t nVertices, const size_t vertexSize) WS_NOEXCEPT;
				
				D3D11VertexBuffer &operator=(D3D11VertexBuffer &&other) noexcept;

				void Bind() WS_NOEXCEPT;

				virtual void Update() WS_NOEXCEPT override;
			};

			/*
			 * // ////////////////////--\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||-----------D3D11IndexBuffer-----------|| \\
			 * // |\______________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\--//////////////////// \\
			 */

			class D3D11IndexBuffer : public D3D11IndexBufferObjectWrapper,
									 public IndexBuffer
			{
			private:
				size_t m_nIndices = 0u;

				D3D11DeviceContextObjectWrapper *m_pDeviceContext = nullptr;

			public:
				D3D11IndexBuffer() = default;

				D3D11IndexBuffer(D3D11DeviceObjectWrapper &pDevice,
								D3D11DeviceContextObjectWrapper *pDeviceContext,
								const size_t nIndices) WS_NOEXCEPT;

				D3D11IndexBuffer& operator=(D3D11IndexBuffer &&other) WS_NOEXCEPT;

				void Bind() WS_NOEXCEPT;

				virtual void Update() WS_NOEXCEPT override;
			};

			/*
			 * // ////////////////////-\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D11ConstantBuffer---------|| \\
			 * // |\_____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\-//////////////////// \\
			 */

			class D3D11ConstantBuffer : public D3D11ConstantBufferObjectWrapper,
										public ConstantBuffer
			{
			private:
				size_t m_objSize = 0u;

				size_t m_slot = 0u;

				D3D11DeviceContextObjectWrapper *m_pDeviceContext = nullptr;

			public:
				D3D11ConstantBuffer() = default;

				D3D11ConstantBuffer(D3D11DeviceObjectWrapper &pDevice,
									D3D11DeviceContextObjectWrapper *pDeviceContext,
									const size_t objSize, const size_t slot) WS_NOEXCEPT;

				D3D11ConstantBuffer &operator=(D3D11ConstantBuffer &&other) WS_NOEXCEPT;

				void Bind() WS_NOEXCEPT;

				virtual void Update() WS_NOEXCEPT override;
			};

			typedef D3D11ObjectWrapper<ID3D11ShaderResourceView> D3D11TextureObjectWrapper;

			/*
			 * // ////////////////--\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D11Texture---------|| \\
			 * // |\______________________________/| \\
			 * // \\\\\\\\\\\\\\\\--//////////////// \\
			 */

			class D3D11Texture : public Texture,
								 public D3D11TextureObjectWrapper
			{
			private:
				D3D11DeviceObjectWrapper *m_pDevice = nullptr;
				D3D11DeviceContextObjectWrapper *m_pDeviceContext = nullptr;

				size_t m_slot = 0u;

				Microsoft::WRL::ComPtr<ID3D11Texture2D> m_texture2D;

				bool m_useMipmaps;

			public:
				D3D11Texture() = default;

				D3D11Texture(D3D11DeviceObjectWrapper &pDevice,
							 D3D11DeviceContextObjectWrapper *pDeviceContext,
							 const size_t width, const size_t height, const size_t slot, const bool useMipmaps) WS_NOEXCEPT;

				void Bind() const WS_NOEXCEPT;

				virtual void Update() WS_NOEXCEPT override;
			};

			typedef D3D11ObjectWrapper<ID3D11SamplerState> D3D11SamplerStateObjectWrapper;

			/*
			 * // /////////////////-\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------D3D11TextureSampler------|| \\
			 * // |\_______________________________/| \\
			 * // \\\\\\\\\\\\\\\\\-///////////////// \\
			 */

			class D3D11TextureSampler : public D3D11SamplerStateObjectWrapper
			{
			private:
				D3D11DeviceContextObjectWrapper *m_pDeviceContext = nullptr;

				size_t m_slot = 0u;

			public:
				D3D11TextureSampler() = default;

				D3D11TextureSampler(D3D11DeviceObjectWrapper &pDevice,
									D3D11DeviceContextObjectWrapper *pDeviceContext,
									const TextureFilter &filter, const size_t slot) WS_NOEXCEPT;

				void Bind() const WS_NOEXCEPT;
			};

			/*
			 * // /////////////////-\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------D3D11RenderPipeline------|| \\
			 * // |\_______________________________/| \\
			 * // \\\\\\\\\\\\\\\\\-///////////////// \\
			 */

			class D3D11RenderPipeline
			{
			private:
				D3D11VertexShader m_pVertexShader;
				D3D11PixelShader m_pPixelShader;
				D3D11_PRIMITIVE_TOPOLOGY m_topology;

				D3D11DeviceContextObjectWrapper *m_pDeviceContext;

				std::vector<uint32_t> m_constantBufferIndices;
				std::vector<uint32_t> m_textureIndices;
				std::vector<uint32_t> m_textureSamplerIndices;

			public:
				D3D11RenderPipeline(D3D11DeviceObjectWrapper &pDevice,
									D3D11DeviceContextObjectWrapper *m_pDeviceContext,
									const RenderPipelineDesc &desc) WS_NOEXCEPT;

				void Bind(std::vector<ConstantBuffer *> &constantBuffers,
						std::vector<Texture *> &textures,
						std::vector<D3D11TextureSampler *> textureSamplers) WS_NOEXCEPT;
			};

			class D3D11RenderPipeline;

			/*
			 * // //////////////--\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------D3D11RenderAPI------|| \\
			 * // |\__________________________/| \\
			 * // \\\\\\\\\\\\\\--////////////// \\
			 */

			class D3D11RenderAPI : public RenderAPI
			{
			private:
				D3D11DeviceObjectWrapper m_pDevice;
				D3D11DeviceContextObjectWrapper m_pDeviceContext;
				D3D11SwapChain m_pSwapChain;
				D3D11RenderTarget m_pRenderTarget;
				D3D11DepthBuffer m_pDepthBuffer;

				std::vector<D3D11RenderPipeline> m_pRenderPipelines;
				std::vector<D3D11TextureSampler *> m_pTextureSamplers;

			public:
				D3D11RenderAPI() : RenderAPI(RenderAPIName::DIRECTX11) {}

				virtual void InitRenderAPI(Window *pWindow, const uint16_t maxFps) WS_NOEXCEPT override;

				virtual void InitPipelines(const std::vector<RenderPipelineDesc> &pipelineDescs) WS_NOEXCEPT override;

				virtual void Draw(const Drawable &drawable, const size_t nVertices) WS_NOEXCEPT override;

				virtual void BeginDrawing() WS_NOEXCEPT override;
				virtual void EndDrawing()   WS_NOEXCEPT override;

				virtual void Present(const bool vSync) WS_NOEXCEPT override;

				virtual size_t CreateVertexBuffer  (const size_t nVertices,      const size_t vertexSize) WS_NOEXCEPT override;
				virtual size_t CreateIndexBuffer   (const size_t nIndices) WS_NOEXCEPT override;
				virtual size_t CreateConstantBuffer(const size_t objSize,        const size_t slot) WS_NOEXCEPT override;
				virtual size_t CreateTexture       (const size_t width,          const size_t height, const size_t slot, const bool useMipmaps = false) WS_NOEXCEPT override;
				virtual size_t CreateTextureSampler(const TextureFilter& filter, const size_t slot) WS_NOEXCEPT override;

				virtual void Fill(const Colorf32 &color = {1.f, 1.f, 1.f, 1.f}) WS_NOEXCEPT override;
			};

		}; // namespace D3D11

		#endif // __WEISS__OS_WINDOWS

		#ifdef __WEISS__OS_WINDOWS

		namespace D3D12
		{

			/*
			 * // //////////////////-\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------D3D12ObjectWrapper<T>------|| \\
			 * // |\_________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\-////////////////// \\
			 *
			 * To prevent a "use after free" (and many mental breakdowns) please overload the "void operator=" function with an r-value reference (like the one for this class)
			 * in any class that inherits from this base class.
			*/
			template <typename T>
			class D3D12ObjectWrapper
			{
			protected:
				T* m_pObject = nullptr;

			public:
				D3D12ObjectWrapper() = default;

				/* This function overloads the assignement operator with an r-value reference to itself
				* It copies the pointer from the "other" and sets it to nullptr.
				* This is done to ensure that the resource isn't freed while this object is being created.
				* (Preventing a "use after free")
				*/
				D3D12ObjectWrapper& operator=(D3D12ObjectWrapper<T> &&other) WS_NOEXCEPT;

				~D3D12ObjectWrapper();

				[[nodiscard]] inline T*  operator->() WS_NOEXCEPT { return this->m_pObject;  }
				[[nodiscard]] inline T*  Get()        WS_NOEXCEPT { return this->m_pObject;  }
				[[nodiscard]] inline T** GetPtr()     WS_NOEXCEPT { return &this->m_pObject; }

				[[nodiscard]] inline operator IUnknown* () const WS_NOEXCEPT { return (IUnknown *)this->m_pObject; }
				[[nodiscard]] inline operator T*        () const WS_NOEXCEPT { return this->m_pObject;             }
			};

			typedef D3D12ObjectWrapper<IDXGIAdapter1> D3D12AdapterObjectWrapper;

			/*
			 * // /////////////--\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------D3D12Adapter------|| \\
			 * // |\________________________/| \\
			 * // \\\\\\\\\\\\\--///////////// \\
			 */

			class D3D12Adapter : public D3D12AdapterObjectWrapper
			{
			public:
				D3D12Adapter();

				D3D12Adapter& operator=(D3D12Adapter&& other) WS_NOEXCEPT;
			};

			typedef D3D12ObjectWrapper<ID3D12Device2> D3D12DeviceObjectWrapper;

			/*
			 * // /////////////-\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------D3D12Device------|| \\
			 * // |\_______________________/| \\
			 * // \\\\\\\\\\\\\-///////////// \\
			 */

			class D3D12Device : public D3D12DeviceObjectWrapper
			{
			public:
				D3D12Device() = default;

				D3D12Device(D3D12AdapterObjectWrapper &pAdapter) WS_NOEXCEPT;

				D3D12Device &operator=(D3D12Device &&other) WS_NOEXCEPT;
			};

			typedef D3D12ObjectWrapper<ID3D12Fence> D3D12FenceObjectWrapper;

			/*
			 * // /////////////--\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||-------D3D12Fence-------|| \\
			 * // |\________________________/| \\
			 * // \\\\\\\\\\\\\--///////////// \\
			 */

			class D3D12Fence : public D3D12FenceObjectWrapper
			{
			private:
				HANDLE m_fenceEvent = nullptr;

			public:
				D3D12Fence() = default;

				D3D12Fence(D3D12DeviceObjectWrapper &pDevice, const UINT64 initialValue, const D3D12_FENCE_FLAGS flags) WS_NOEXCEPT;

				~D3D12Fence() WS_NOEXCEPT;

				D3D12Fence &operator=(D3D12Fence &&other) WS_NOEXCEPT;

				[[nodiscard]] inline HANDLE GetEvent() const WS_NOEXCEPT { return this->m_fenceEvent; }
			};

			typedef D3D12ObjectWrapper<ID3D12CommandQueue> D3D12CommandQueueObjectWrapper;

			/*
			 * // /////////////////-\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||-------D3D12CommandQueue-------|| \\
			 * // |\_______________________________/| \\
			 * // \\\\\\\\\\\\\\\\\-///////////////// \\
			 */

			class D3D12CommandQueue : public D3D12CommandQueueObjectWrapper
			{
			public:
				D3D12CommandQueue() = default;

				D3D12CommandQueue(D3D12DeviceObjectWrapper &pDevice, const D3D12_COMMAND_LIST_TYPE& type) WS_NOEXCEPT;
			};

			typedef D3D12ObjectWrapper<IDXGISwapChain3> D3D12SwapChainObjectWrapper;

			/*
			 * // /////////////////--\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12SwapChain---------|| \\
			 * // |\________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\--///////////////// \\
			 */

			class D3D12SwapChain : public D3D12SwapChainObjectWrapper
			{
			public:
				D3D12SwapChain() = default;

				D3D12SwapChain(D3D12DeviceObjectWrapper &pDevice,
							D3D12CommandQueueObjectWrapper &pCommandQueue,
							const Window *pWindow, const uint16_t maxFps, const UINT bufferCount) WS_NOEXCEPT;

				D3D12SwapChain &operator=(D3D12SwapChain &&other) noexcept;

				void Present(const bool vSync) const WS_NOEXCEPT;

			private:
				static bool IsTearingSupported() WS_NOEXCEPT;
			};

			typedef D3D12ObjectWrapper<ID3D12DescriptorHeap> D3D12DescriptorHeapObjectWrapper;

			/*
			 * // ////////////////////-\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12DescriptorHeap---------|| \\
			 * // |\_____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\-//////////////////// \\
			 */

			class D3D12DescriptorHeap : public D3D12DescriptorHeapObjectWrapper
			{
			public:
				D3D12DescriptorHeap() = default;
				
				D3D12DescriptorHeap(D3D12DeviceObjectWrapper &pDevice, const D3D12_DESCRIPTOR_HEAP_TYPE type,
									const uint32_t numDescriptors,
									const D3D12_DESCRIPTOR_HEAP_FLAGS &flags = D3D12_DESCRIPTOR_HEAP_FLAGS::D3D12_DESCRIPTOR_HEAP_FLAG_NONE) WS_NOEXCEPT;

				D3D12DescriptorHeap &operator=(D3D12DescriptorHeap &&other) noexcept;
			};

			typedef D3D12ObjectWrapper<ID3D12Resource> D3D12RenderTargetObjectWrapper;

			/*
			 * // ///////////////////-\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12RenderTarget---------|| \\
			 * // |\___________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\-/////////////////// \\
			 */

			class D3D12RenderTarget : public D3D12RenderTargetObjectWrapper
			{
			public:
				D3D12RenderTarget() = default;

				D3D12RenderTarget(D3D12DeviceObjectWrapper &pDevice,
								D3D12SwapChainObjectWrapper &pSwapChain,
								D3D12DescriptorHeapObjectWrapper &pDescriptorHeap,
								const CD3DX12_CPU_DESCRIPTOR_HANDLE &rtvHandle,
								const uint16_t frameIndex) WS_NOEXCEPT;

				D3D12RenderTarget &operator=(D3D12RenderTarget &&other) noexcept;
			};

			typedef D3D12ObjectWrapper<ID3D12CommandAllocator> D3D12CommandAllocatorObjectWrapper;

			/*
			 * // ///////////////////-\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||-------D3D12CommandAllocator-------|| \\
			 * // |\___________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\-/////////////////// \\
			 */

			class D3D12CommandAllocator : public D3D12CommandAllocatorObjectWrapper
			{
			public:
				D3D12CommandAllocator() = default;

				D3D12CommandAllocator(D3D12DeviceObjectWrapper &pDevice, const D3D12_COMMAND_LIST_TYPE& type) WS_NOEXCEPT;

				void Reset() const WS_NOEXCEPT;
			};

			typedef D3D12ObjectWrapper<ID3D12GraphicsCommandList> D3D12CommandListObjectWrapper;

			/*
			 * // ///////////////////--\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||----------D3D12CommandList----------|| \\
			 * // |\____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\--/////////////////// \\
			 */

			class D3D12CommandList : public D3D12CommandListObjectWrapper
			{
			public:
				D3D12CommandList() = default;

				D3D12CommandList(D3D12DeviceObjectWrapper& pDevice,
								D3D12CommandAllocatorObjectWrapper& pCommandAllocator,
								const D3D12_COMMAND_LIST_TYPE& type) WS_NOEXCEPT;

				~D3D12CommandList() = default;

				D3D12CommandList &operator=(D3D12CommandList &&other) WS_NOEXCEPT;

				void Close() WS_NOEXCEPT;

				void Reset(D3D12CommandAllocatorObjectWrapper& pCommandAllocator) const WS_NOEXCEPT;
				
				void TransitionResource(ID3D12Resource *pResource, const D3D12_RESOURCE_STATES &before, const D3D12_RESOURCE_STATES &after) WS_NOEXCEPT;
			};

			/*
			 * // ///////////////////--\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||----------D3D12DepthBuffer----------|| \\
			 * // |\____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\--/////////////////// \\
			 */

			class D3D12DepthBuffer
			{
			private:
				D3D12ObjectWrapper<ID3D12DescriptorHeap> m_pDescriptorHeap;
				D3D12ObjectWrapper<ID3D12Resource>       m_pDepthStencilBuffer;

				CD3DX12_CPU_DESCRIPTOR_HANDLE m_dsvHandle;

			public:
				D3D12DepthBuffer() = default;

				D3D12DepthBuffer(D3D12Device& pDevice, Window* pWindow) WS_NOEXCEPT;

				void Clear(D3D12CommandListObjectWrapper &pCommandList) WS_NOEXCEPT;

				operator CD3DX12_CPU_DESCRIPTOR_HANDLE *() WS_NOEXCEPT;
			};

			typedef D3D12ObjectWrapper<ID3D12RootSignature> D3D12RootSignatureObjectWrapper;

			/*
			 * // ///////////////////--\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12RootSignature---------|| \\
			 * // |\____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\--/////////////////// \\
			 */

			class D3D12RootSignature : public D3D12RootSignatureObjectWrapper
			{
			public:
				D3D12RootSignature() = default;

				D3D12RootSignature(D3D12DeviceObjectWrapper &pDevice, const D3D12_ROOT_SIGNATURE_FLAGS &flags,
								   const std::vector<D3D12_ROOT_PARAMETER1> &rootParameters,
								   const std::vector<D3D12_STATIC_SAMPLER_DESC> &samplers) WS_NOEXCEPT;

				D3D12RootSignature &operator=(D3D12RootSignature &&other) noexcept;
			};

			typedef D3D12ObjectWrapper<ID3D12Resource> D3D12CommittedResourceObjectWrapper;

			/*
			 * // ///////////////////--\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||-------D3D12CommittedResource-------|| \\
			 * // |\____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\--/////////////////// \\
			 */

			class D3D12CommittedResource : public D3D12CommittedResourceObjectWrapper
			{
			private:
				D3D12_RESOURCE_STATES m_originalState = D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_COMMON;
				D3D12_RESOURCE_STATES m_currentState  = D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_COMMON;

			public:
				D3D12CommittedResource() = default;

				D3D12CommittedResource(D3D12DeviceObjectWrapper &pDevice, const D3D12_HEAP_TYPE &heapType,
									const D3D12_HEAP_FLAGS &flags, const D3D12_RESOURCE_DESC *descPtr,
									const D3D12_RESOURCE_STATES &states, const char *name = "(PLACEHOLDER NAME)") WS_NOEXCEPT;

				D3D12CommittedResource &operator=(D3D12CommittedResource &&other) WS_NOEXCEPT;

				inline void TransitionTo(D3D12CommandListObjectWrapper& pCommandList, const D3D12_RESOURCE_STATES& state) WS_NOEXCEPT
				{
					pCommandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(this->m_pObject, this->m_currentState, state));

					this->m_currentState = state;
				}

				inline void TransitionBack(D3D12CommandListObjectWrapper& pCommandList) WS_NOEXCEPT
				{
					this->TransitionTo(pCommandList, this->m_originalState);
				}
			};

			/*
			 * // ////////////////////-\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||----------D3D12VertexBuffer----------|| \\
			 * // |\_____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\-//////////////////// \\
			 */

			class D3D12VertexBuffer : public VertexBuffer
			{
			private:
				D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;

				D3D12CommittedResource m_pVertexBuffer;
				D3D12CommittedResource m_pUploadHeap;

				UINT m_vertexSize = 0u;

				D3D12CommandList *m_pCommandList = nullptr;

			public:
				D3D12VertexBuffer() = default;

				D3D12VertexBuffer(D3D12DeviceObjectWrapper &pDevice,
								  D3D12CommandList *pCommandList,
								  const size_t nVertices, const size_t vertexSize) WS_NOEXCEPT;

				void Bind() WS_NOEXCEPT;

				virtual void Update() WS_NOEXCEPT override;
			};

			/*
			 * // ///////////////////--\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||----------D3D12IndexBuffer----------|| \\
			 * // |\____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\--/////////////////// \\
			 */

			class D3D12IndexBuffer : public IndexBuffer
			{
			private:
				D3D12_INDEX_BUFFER_VIEW m_indexBufferView;

				D3D12CommittedResource m_pIndexBuffer;
				D3D12CommittedResource m_pUploadHeap;

				size_t m_nIndices = 0u;

				D3D12CommandList *m_pCommandList = nullptr;

			public:
				D3D12IndexBuffer() = default;

				D3D12IndexBuffer(D3D12DeviceObjectWrapper &pDevice,
								 D3D12CommandList *pCommandList,
								 const size_t nIndices) WS_NOEXCEPT;

				void Bind() WS_NOEXCEPT;

				virtual void Update() WS_NOEXCEPT override;
			};

			/*
			 * // ///////////////////-\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------D3D12ConstantBuffer--------|| \\
			 * // |\___________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\-/////////////////// \\
			 */

			class D3D12ConstantBuffer : public ConstantBuffer
			{
			private:
				size_t m_objSize = 0u;

				size_t m_slot = 0u;

				D3D12CommandList *m_pCommandList;

				std::array<D3D12DescriptorHeap, WEISS__FRAME_BUFFER_COUNT> m_descriptorHeaps;
				std::array<D3D12_CONSTANT_BUFFER_VIEW_DESC, WEISS__FRAME_BUFFER_COUNT> m_constantBufferViews;
				std::array<D3D12CommittedResource, WEISS__FRAME_BUFFER_COUNT> m_pUploadHeaps;

				std::array<bool, WEISS__FRAME_BUFFER_COUNT> m_bNeedsUpdating;

			public:
				D3D12ConstantBuffer() = default;

				D3D12ConstantBuffer(D3D12DeviceObjectWrapper &pDevice,
									D3D12CommandList *pCommandList,
									const size_t objSize, const size_t slot) WS_NOEXCEPT;

				[[nodiscard]] inline D3D12DescriptorHeap& GetDescriptorHeap(const size_t frameIndex) WS_NOEXCEPT { return this->m_descriptorHeaps[frameIndex]; }

				[[nodiscard]] inline size_t GetSlot() const WS_NOEXCEPT { return this->m_slot; }

				void UpdateIfNeeded(const size_t frameIndex) WS_NOEXCEPT;

				virtual void Update() WS_NOEXCEPT override;

			private:
				void UpdateHeap(const size_t heapIndex) WS_NOEXCEPT;
			};

			/*
			 * // ///////////////////--\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------D3D12Texture------------|| \\
			 * // |\____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\--/////////////////// \\
			 */

			class D3D12Texture : public Texture
			{
			private:
				D3D12CommittedResource m_textureResource;
				D3D12CommittedResource m_uploadHeap;

				D3D12DescriptorHeap m_descriptorHeap;

				D3D12_SHADER_RESOURCE_VIEW_DESC m_textureResourceView;

				D3D12CommandList *m_pCommandList = nullptr;

				size_t m_slot = 0u;

			public:
				D3D12Texture() = default;

				D3D12Texture(D3D12DeviceObjectWrapper &pDevice, D3D12CommandList *pCommandList,
							 const size_t width, const size_t height, const size_t slot, const bool useMipmaps) WS_NOEXCEPT;

				[[nodiscard]] inline D3D12DescriptorHeap& GetDescriptorHeap() WS_NOEXCEPT { return this->m_descriptorHeap; }

				[[nodiscard]] inline size_t GetSlot() const WS_NOEXCEPT { return this->m_slot; }

				virtual void Update() WS_NOEXCEPT override;
			};

			/*
			 * // ///////////////////-\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------D3D12TextureSampler--------|| \\
			 * // |\___________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\-/////////////////// \\
			 */

			class D3D12TextureSampler
			{
			private:
				D3D12_STATIC_SAMPLER_DESC m_samplerDesc;

			public:
				D3D12TextureSampler() = default;

				D3D12TextureSampler(const TextureFilter &filter) WS_NOEXCEPT;

				[[nodiscard]] inline D3D12_STATIC_SAMPLER_DESC GetSamplerDesc() const WS_NOEXCEPT { return this->m_samplerDesc; }
			};

			struct D3D12CPUDescriptorHandles {
				CD3DX12_CPU_DESCRIPTOR_HANDLE m_start;
				CD3DX12_CPU_DESCRIPTOR_HANDLE m_current;
				CD3DX12_CPU_DESCRIPTOR_HANDLE m_end;
			};

			struct D3D12GPUDescriptorHandles {
				CD3DX12_GPU_DESCRIPTOR_HANDLE m_start;
				CD3DX12_GPU_DESCRIPTOR_HANDLE m_current;
				CD3DX12_GPU_DESCRIPTOR_HANDLE m_end;
			};

			struct D3D12DescriptorHandles {
				D3D12CPUDescriptorHandles m_cpuHandles;
				D3D12GPUDescriptorHandles m_gpuHandles;

				inline void OffsetCurrent(const UINT numDescriptors, const UINT incrementSize) WS_NOEXCEPT;
			};

			/*
			 *
			 * // //////////////////--\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||----D3D12DescriptorHeapManager----|| \\
			 * // |\__________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\--////////////////// \\
			 *
			 * The goal of this class is to limit the number of calls to "SetDescriptorHeaps()" as
			 * it is a costly operation. This is done by creating descriptor heaps that are filled
			 * by every single pipeline. We need a "std::vector" of descriptor heaps because the size of a descriptor heap
			 * is limited, it's maximum descriptor count is stored in "WEISS__D3D12_MAX_DESCRIPTORS_PER_HEAP".
			 * We also need one of each frame buffer since Weiss supports "n-buffering" (see WEISS__FRAME_BUFFER_COUNT).
			 */
			class D3D12DescriptorHeapManager {
			private:
				std::vector<std::array<std::unique_ptr<D3D12DescriptorHeap>, WEISS__FRAME_BUFFER_COUNT>> m_heaps;

				std::vector<std::array<D3D12DescriptorHandles, WEISS__FRAME_BUFFER_COUNT>> m_handles;

				/*
				 * "m_nativeHeapsPtr" is a "std::array" of native "ID3D12DescriptorHeap*" used to call
				 * "SetDescriptorHeaps()" without the need to use any additionally loops at runtime to get
				 * the pointers to the needed descriptor heaps for each frame buffer.
				 */
				std::array<std::vector<ID3D12DescriptorHeap*>, WEISS__FRAME_BUFFER_COUNT> m_nativeHeapsPtr;

				D3D12Device* m_pDevice = nullptr;

				UINT m_incrementSize = 0u;

			private:
				// Adds a new array of frame buffer descriptor heaps
				void AddHeapToVector() WS_NOEXCEPT;

			public:
				D3D12DescriptorHeapManager() = default;

				D3D12DescriptorHeapManager(D3D12Device& device) WS_NOEXCEPT;

				D3D12DescriptorHeapManager& operator=(D3D12DescriptorHeapManager&& other) noexcept;

				/*
				 * Given an array of descriptor handles to a single descriptor each,
				 * the function "AddDesriptors" copies the descriptors pointed to by
				 * each of the descriptor handles into each frame buffer descriptor heap.
				 * Its return value is an array of the frame buffer descriptors' handles.
				 */
				std::array<D3D12DescriptorHandles, WEISS__FRAME_BUFFER_COUNT> AddDesriptors(const std::vector<std::array<CD3DX12_CPU_DESCRIPTOR_HANDLE, WEISS__FRAME_BUFFER_COUNT>>& descriptors) WS_NOEXCEPT;

				void Bind(D3D12CommandList& commandList, const size_t frameIndex) const WS_NOEXCEPT;

				~D3D12DescriptorHeapManager() = default;
			};

			typedef D3D12ObjectWrapper<ID3D12PipelineState> D3D12RenderPipelineObjectWrapper;

			/*
			 * // ///////////////////-\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------D3D12RenderPipeline--------|| \\
			 * // |\___________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\-/////////////////// \\
			 */

			class D3D12RenderPipeline : public D3D12RenderPipelineObjectWrapper
			{
			private:
				D3D_PRIMITIVE_TOPOLOGY m_topology;

				D3D12RootSignature m_pRootSignature;

				std::vector<uint32_t> m_constantBufferIndices;
				std::vector<uint32_t> m_textureIndices;

				std::array<D3D12DescriptorHandles, WEISS__FRAME_BUFFER_COUNT> m_handles;

				D3D12Device *m_pDevice = nullptr;
				D3D12DescriptorHeapManager* m_pDescriptorHeapManager = nullptr;

				std::vector<Texture *> m_pTextures;
				std::vector<ConstantBuffer *> m_pConstantBuffers;
				std::vector<D3D12TextureSampler *> m_pTextureSamplers;

			public:
				D3D12RenderPipeline() = default;

				D3D12RenderPipeline(D3D12RenderPipeline &&other) noexcept;

				D3D12RenderPipeline(D3D12Device &pDevice, const RenderPipelineDesc &pipelineDesc,
									std::vector<ConstantBuffer *> &pConstantBuffers, std::vector<Texture *> pTextures,
									std::vector<D3D12TextureSampler *> pTextureSamplers, D3D12DescriptorHeapManager& descriptorHeapManager) WS_NOEXCEPT;

				D3D12RenderPipeline &operator=(D3D12RenderPipeline &&other) noexcept;

				void Bind(D3D12CommandList &pCommandList, const size_t frameIndex) WS_NOEXCEPT;
			};

			/*
			 * // ///////////////////-\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||-------D3D12CommandSubmitter-------|| \\
			 * // |\___________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\-/////////////////// \\
			 */

			class D3D12CommandSubmitter
			{
			private:
				D3D12CommandList m_pCommandList;

				std::array<UINT64, WEISS__FRAME_BUFFER_COUNT> m_fenceValues;
				std::array<std::unique_ptr<D3D12Fence>, WEISS__FRAME_BUFFER_COUNT> m_pFences;

				std::array<D3D12CommandAllocator, WEISS__FRAME_BUFFER_COUNT> m_pCommandAllocators;

			public:
				D3D12CommandSubmitter() = default;

				D3D12CommandSubmitter(D3D12DeviceObjectWrapper &pDevice) WS_NOEXCEPT;

				void Close() WS_NOEXCEPT;

				void Reset(const size_t frameIndex) WS_NOEXCEPT;

				void Execute(D3D12CommandQueueObjectWrapper &pCommandQueue, const size_t frameIndex) WS_NOEXCEPT;

				void WaitForCompletion(const size_t frameIndex) WS_NOEXCEPT;

				[[nodiscard]] inline D3D12CommandList& GetCommandList()                  WS_NOEXCEPT { return this->m_pCommandList;         }
				[[nodiscard]] inline D3D12CommandList* GetCommandListPr()                WS_NOEXCEPT { return &this->m_pCommandList;        }
				[[nodiscard]] inline D3D12Fence&       GetFence(const size_t frameIndex) WS_NOEXCEPT { return *this->m_pFences[frameIndex]; }
			};

			/*
			 * // //////////////////--\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||----------D3D12RenderAPI----------|| \\
			 * // |\__________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\--////////////////// \\
			 */

			class D3D12RenderAPI : public RenderAPI
			{
			private:
				D3D12Adapter m_pAdapter;
				D3D12Device m_pDevice;
				D3D12CommandQueue m_pCommandQueue;
				D3D12SwapChain m_pSwapChain;
				D3D12DescriptorHeap m_pDescriptorHeap;
				D3D12DepthBuffer m_pDepthBuffer;
				D3D12DescriptorHeapManager m_descriptorHeapManager;

				std::array<D3D12RenderTarget, WEISS__FRAME_BUFFER_COUNT> m_pRenderTargets;

				D3D12CommandSubmitter m_commandSubmitter;

				std::vector<D3D12RenderPipeline> m_renderPipelines;

				size_t currentFrameIndex = 0u;

				CD3DX12_CPU_DESCRIPTOR_HANDLE m_currentRtvHandle;

				D3D12_RECT m_scissors;
				D3D12_VIEWPORT m_viewport;

				std::vector<D3D12TextureSampler *> m_pTextureSamplers;

			private:
				void CreateRenderTargets() WS_NOEXCEPT;

			public:
				D3D12RenderAPI() WS_NOEXCEPT : RenderAPI(RenderAPIName::DIRECTX12) {  }

				virtual void InitRenderAPI(Window *pWindow, const uint16_t maxFps = 144u) WS_NOEXCEPT override;

				virtual void InitPipelines(const std::vector<RenderPipelineDesc> &pipelineDescs) WS_NOEXCEPT override;

				virtual void Draw(const Drawable &drawable, const size_t nVertices) WS_NOEXCEPT override;

				virtual void BeginDrawing() WS_NOEXCEPT override;

				virtual void EndDrawing() WS_NOEXCEPT override;

				virtual void Present(const bool vSync) WS_NOEXCEPT override;

				virtual size_t CreateVertexBuffer  (const size_t nVertices,      const size_t vertexSize) WS_NOEXCEPT override;
				virtual size_t CreateIndexBuffer   (const size_t nIndices) WS_NOEXCEPT override;
				virtual size_t CreateConstantBuffer(const size_t objSize,        const size_t slot) WS_NOEXCEPT override;
				virtual size_t CreateTexture       (const size_t width,          const size_t height, const size_t slot, const bool useMipmaps = false) WS_NOEXCEPT override;
				virtual size_t CreateTextureSampler(const TextureFilter& filter, const size_t slot) WS_NOEXCEPT override;

				virtual void Fill(const Colorf32 &color = {1.f, 1.f, 1.f, 1.f}) WS_NOEXCEPT override;
			};

		}; // namespace D3D12

#endif // __WEISS__OS_WINDOWS

	}; // Internal

	/*
	 * // //////////////-\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||-------SceneObject-------|| \\
	 * // |\_________________________/| \\
	 * // \\\\\\\\\\\\\\-////////////// \\
	 */

	class SceneObject
	{
	private:
	};

	/*
	 * // //////////////-\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||--------SceneNode--------|| \\
	 * // |\_________________________/| \\
	 * // \\\\\\\\\\\\\\-////////////// \\
	 */

	class SceneNode
	{
	private:
	};

	/*
	 * // //////////////-\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||----------Scene----------|| \\
	 * // |\_________________________/| \\
	 * // \\\\\\\\\\\\\\-////////////// \\
	 */

	class Scene
	{
	private:
		std::unique_ptr<SceneNode *> m_pRootNode;

	public:
		Scene() = default;
	};

	/*
	 * // //////////////////--\\\\\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||----------GraphicsEngine----------|| \\
	 * // |\__________________________________/| \\
	 * // \\\\\\\\\\\\\\\\\\--////////////////// \\
	 */

	class GraphicsEngine
	{
	private:
		RenderAPIHandle m_renderHandle;

		WindowHandle m_windowHandle;

	public:
		GraphicsEngine(const RenderAPIName &apiName);

		void Init(WindowHandle windowHandle);

		void Run(const size_t fps);

		virtual void OnFrame() = 0;

		~GraphicsEngine() = default;
	};

	/*
	 * // /////////////////--\\\\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||----------ClientSocket----------|| \\
	 * // |\________________________________/| \\
	 * // \\\\\\\\\\\\\\\\\--///////////////// \\
	 */

	class ClientSocket
	{
	private:
		SOCKET m_socket = INVALID_SOCKET;

	public:
		ClientSocket() = default;

		~ClientSocket() { this->Disconnect(); }

		void Connect(const char *host, const unsigned int port);

		void Send(const char *data, int length = -1);

		[[nodiscard]] std::pair<std::array<char, 1024u>, size_t> Receive();

		void Disconnect() WS_NOEXCEPT;
	};

	/*
	 * // /////////////////--\\\\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||----------ServerSocket----------|| \\
	 * // |\________________________________/| \\
	 * // \\\\\\\\\\\\\\\\\--///////////////// \\
	 */

	class ServerSocket
	{
	private:
		SOCKET m_socket = INVALID_SOCKET;

		std::vector<SOCKET> m_clients;

	public:
		ServerSocket() = default;

		~ServerSocket() { this->Disconnect(); }

		void Bind(const unsigned int port);

		[[nodiscard]] int Accept() WS_NOEXCEPT;

		void Send(const int clientID, const char *data, int length = -1);

		[[nodiscard]] std::pair<std::array<char, 1024u>, size_t> Receive(const int clientID);

		void Disconnect() WS_NOEXCEPT;
	};

	/*
	 * To Be Declared By The User
	*/
	int WeissEntryPoint(int argc, char** argv);

}; // WS

/*
 * // ////////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
 * // ||--------------------------Entry Point--------------------------|| \\
 * // |\_______________________________________________________________/| \\
 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--///////////////////////////////// \\
 */

int main(int argc, char** argv);

// LOG Static Class
std::mutex                WS::LOG::m_sPrintMutex                         = std::mutex();
std::vector<VkRenderPass> WS::Internal::VK::VKRenderPass::m_renderPasses = { };

/* 
 * ██████████████████████████████████████████████████████████████████████████████
 * ██                                                                          ██
 * ██                                                                          ██
 * ██  //////////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  ██
 * ██  |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\|  ██
 * ██  ||--------------------------IMPLEMENTATION--------------------------||  ██
 * ██  |\__________________________________________________________________/|  ██
 * ██  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--//////////////////////////////////  ██
 * ██                                                                          ██
 * ██                                                                          ██
 * ██████████████████████████████████████████████████████████████████████████████
*/

/*
 * // ////////////--\\\\\\\\\\\\ \\
 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
 * // ||----------WS----------|| \\
 * // |\______________________/| \\
 * // \\\\\\\\\\\\--//////////// \\
 */

namespace WS {

	/*
	 * // ///////////////////////--\\\\\\\\\\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||--------------------Rect--------------------|| \\
	 * // |\____________________________________________/| \\
	 * // \\\\\\\\\\\\\\\\\\\\\\\--/////////////////////// \\
	 */

#ifdef __WEISS__OS_WINDOWS

	Rect::Rect(const RECT& rect) noexcept
	{
		this->left   = static_cast<uint16_t>(rect.left);
		this->top    = static_cast<uint16_t>(rect.top);
		this->right  = static_cast<uint16_t>(rect.right);
		this->bottom = static_cast<uint16_t>(rect.bottom);
	}

#endif // __WEISS__OS_WINDOWS

	// ///////////////-\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |----------Transform----------| \\
	// |\___________________________/| \\
	// \\\\\\\\\\\\\\\-/////////////// \\

	void Transform::CalculateTransform() WS_NOEXCEPT
	{
		this->m_transform = MatrixFloat32::MakeTranslation(this->m_translation) * MatrixFloat32::MakeRotation(this->m_rotation);
	}

	// ////////////////-\\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |----------Conversions----------| \\
	// |\_____________________________/| \\
	// \\\\\\\\\\\\\\\\-//////////////// \\

	[[nodiscard]] inline float DegreesToRadians(const float degrees)
	{
		return degrees * PI / 180.0f;
	}

	[[nodiscard]] inline float RadiansToDegrees(const float radians)
	{
		return radians / PI * 180.0f;
	}

	// If a polar point is stored as (θ, r)
	[[nodiscard]] inline Vecf32 PolarToCartesian(const Vecf32& polar) // :)
	{
		const float x = polar.y * std::cos(polar.x);
		const float y = polar.y * std::sin(polar.x);

		return Vecf32{ x, y };
	}

	[[nodiscard]] inline Vecf32 CartesianToPolar(const Vecf32& cartesian)
	{
		float a = std::atan(cartesian.y / cartesian.x);

		if (cartesian.x < 0) a += PI;
		else if (cartesian.y < 0) a += TWO_PI;

		const float r = std::sqrt(std::pow(cartesian.x, 2) + std::pow(cartesian.y, 2));

		return Vecf32{ a, r };
	}

	[[nodiscard]] inline Vecf32 GetTriangleSurfaceNormal(const Vecf32& a, const Vecf32& b, const Vecf32& c)
	{
		const Vecf32 U = b - a;
		const Vecf32 V = c - a;

		return Vecf32 {
			U.y * V.z - U.z * V.y,
			U.z * V.x - U.x * V.z,
			U.x * V.y - U.y * V.x
		};
	}

	/*
	 * // /////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||--------------------------LOG--------------------------|| \\
	 * // |\_______________________________________________________/| \\
	 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\-///////////////////////////// \\
	 */

	template <typename T, typename ...Args>
	static void LOG::__Print(const LOG_TYPE logType, const T& message0, Args... args) WS_NOEXCEPT
	{
#ifdef __WEISS__OS_WINDOWS
	
		WORD textAttributes;

		switch (logType)
		{
		case LOG_TYPE::LOG_NORMAL:
			textAttributes = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
			break;
		case LOG_TYPE::LOG_SUCCESS:
			textAttributes = FOREGROUND_INTENSITY | FOREGROUND_GREEN;
			break;
		case LOG_TYPE::LOG_WARNING:
			textAttributes = FOREGROUND_RED | FOREGROUND_GREEN;
			break;
		case LOG_TYPE::LOG_ERROR:
			textAttributes = FOREGROUND_INTENSITY | FOREGROUND_RED;
			break;
		default:
			WS_THROW("[LOG] Your Selected LOG_TYPE Could Not Be Resolved");
		}

		// Set Text Color
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textAttributes);

		std::cout << message0;

		(std::cout << ... << args);

		// Reset Text Color To White
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

#else // end of #ifdef __WEISS__OS_WINDOWS

		switch (logType)
		{
		case LOG_TYPE::LOG_NORMAL:
			std::cout << "\x1B[1;37m";
			break;
		case LOG_TYPE::LOG_SUCCESS:
			std::cout << "\x1B[1;32m";
			break;
		case LOG_TYPE::LOG_WARNING:
			std::cout << "\x1B[0;33m";
			break;
		case LOG_TYPE::LOG_ERROR:
			std::cout << "\x1B[1;31m";
			break;
		default:
			WS_THROW("[LOG] Your Selected LOG_TYPE Could Not Be Resolved");
		}

		std::cout << message << '\n' << "\x1B[0m";

#endif 
	}

	template <typename T, typename ...Args>
	static inline void LOG::Print(const LOG_TYPE logType, const T& message0, Args... args) WS_NOEXCEPT
	{
		// Lock The Mutex
		std::lock_guard<std::mutex> lock(LOG::m_sPrintMutex);

		WS::LOG::__Print(logType, message0, args...);
	}

	template <typename T, typename ...Args>
	static inline void LOG::Println(const LOG_TYPE logType, const T& message0, Args... args) WS_NOEXCEPT
	{
		// Lock The Mutex
		std::lock_guard<std::mutex> lock(LOG::m_sPrintMutex);

		WS::LOG::__Print(logType, message0, args..., '\n');
	}

	/*
	 * // ////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||-----------------------Internal-----------------------|| \\
	 * // |\______________________________________________________/| \\
	 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\--//////////////////////////// \\
	 */

	namespace Internal {

		/*
		 * // /////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
		 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
		 * // ||--------------------------WIN--------------------------|| \\
		 * // |\_______________________________________________________/| \\
		 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\-///////////////////////////// \\
		 */
		
		namespace WIN {

			/*
			* // //////////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			* // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			* // ||--------------------------WINDOWS IMAGE--------------------------|| \\
			* // |\_________________________________________________________________/| \\
			* // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-////////////////////////////////// \\
			*/

			WindowsImage::WindowsImage(WindowsImage&& other) noexcept
			{
				this->m_width = other.m_width;
				this->m_height = other.m_height;
				this->m_nPixels = other.m_nPixels;

				this->m_buff = std::move(other.m_buff);
			}

			WindowsImage::WindowsImage(const WindowsImage& other) noexcept
			{
				this->m_width = other.m_width;
				this->m_height = other.m_height;
				this->m_nPixels = other.m_nPixels;

				const size_t bufferSize = this->m_nPixels * sizeof(Coloru8);
				this->m_buff = std::make_unique<Coloru8[]>(bufferSize);
				std::memcpy(this->m_buff.get(), other.m_buff.get(), bufferSize);
			}

			WindowsImage::WindowsImage(const char* filename) WS_NOEXCEPT
			{
				Microsoft::WRL::ComPtr<IWICBitmapSource>      decodedConvertedFrame;
				Microsoft::WRL::ComPtr<IWICBitmapDecoder>     bitmapDecoder;
				Microsoft::WRL::ComPtr<IWICImagingFactory>    factory;
				Microsoft::WRL::ComPtr<IWICBitmapFrameDecode> frameDecoder;

				if (DX_FAILED(CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory))))
					WS_THROW("[WIC] Could Not Create IWICImagingFactory");

				// Convert from char* to wchar_t*
				const size_t length = mbstowcs(nullptr, filename, 0);
				wchar_t* filenameW = new wchar_t[length];
				mbstowcs(filenameW, filename, length);

				if (DX_FAILED(factory->CreateDecoderFromFilename(filenameW, NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &bitmapDecoder)))
					WS_THROW("[WIC] Could Not Read / Open Image");

				if (DX_FAILED(bitmapDecoder->GetFrame(0, &frameDecoder)))
					WS_THROW("[WIC] Could Not Get First Frame Of Image");

				if (DX_FAILED(frameDecoder->GetSize((UINT*)&this->m_width, (UINT*)&this->m_height)))
					WS_THROW("[WIC] Could Not Get Image Width/Height");

				this->m_nPixels = this->m_width * this->m_height;

				if (DX_FAILED(WICConvertBitmapSource(GUID_WICPixelFormat32bppRGBA, frameDecoder.Get(), &decodedConvertedFrame)))
					WS_THROW("[WIC] Could Not Create Bitmap Converter");

				this->m_buff = std::make_unique<Coloru8[]>(this->m_nPixels * sizeof(Coloru8));

				const WICRect sampleRect{ 0, 0, this->m_width, this->m_height };

				if (DX_FAILED(decodedConvertedFrame->CopyPixels(&sampleRect, this->m_width * sizeof(Coloru8), this->m_nPixels * sizeof(Coloru8), (BYTE*)this->m_buff.get())))
					WS_THROW("[WIC] Could Not Copy Pixels From Bitmap");
			}

			WindowsImage& WindowsImage::operator=(const WindowsImage& other) WS_NOEXCEPT
			{
				this->m_width   = other.m_width;
				this->m_height  = other.m_height;
				this->m_nPixels = other.m_nPixels;

				const size_t bufferSize = this->m_nPixels * sizeof(Coloru8);
				this->m_buff = std::make_unique<Coloru8[]>(bufferSize);

				std::memcpy(this->m_buff.get(), other.m_buff.get(), bufferSize);

				return *this;
			}

			WindowsImage::WindowsImage(const uint16_t width, const uint16_t height, const Coloru8& fillColor) WS_NOEXCEPT
			{
				this->m_width   = width;
				this->m_height  = height;
				this->m_nPixels = this->m_width * this->m_height;

				const size_t bufferSize = this->m_nPixels * sizeof(Coloru8);
				this->m_buff = std::make_unique<Coloru8[]>(bufferSize);

				std::fill_n(this->m_buff.get(), this->m_nPixels, fillColor);
			}

			void WindowsImage::Write(const char* filename) const WS_NOEXCEPT
			{
				if (DX_FAILED(CoInitialize(NULL)))
					WS_THROW("[COM] Failed To Init COM");

				Microsoft::WRL::ComPtr<IWICImagingFactory>    factory;
				Microsoft::WRL::ComPtr<IWICBitmapEncoder>     bitmapEncoder;
				Microsoft::WRL::ComPtr<IWICBitmapFrameEncode> bitmapFrame;
				Microsoft::WRL::ComPtr<IWICStream>            outputStream;

				if (DX_FAILED(CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory))))
					WS_THROW("[WIC] Could Not Create IWICImagingFactory");

				if (DX_FAILED(factory->CreateStream(&outputStream)))
					WS_THROW("[WIC] Failed To Create Output Stream");

				// Convert from char* to wchar_t*
				const size_t length = mbstowcs(nullptr, filename, 0);
				wchar_t* filenameW = new wchar_t[length];
				mbstowcs(filenameW, filename, length);
				if (DX_FAILED(outputStream->InitializeFromFilename(filenameW, GENERIC_WRITE)))
					WS_THROW("[WIC] Failed To Initialize Output Stream From Filename");

				char fileExtension[10u]; // assumes the extension has less than 10-1=9 characters
				std::memset(fileExtension, 0u, 10);
				const size_t offset = std::string_view(filename).find_last_of('.');
				std::memcpy(fileExtension, filename + offset, strlen(filename) - offset + 1);

				// This should be fine thanks to sso (small string optimization)
				const std::unordered_map<std::string, REFGUID> extensionToREFUGUIDMap{
					{ ".bmp", GUID_ContainerFormatBmp  }, { ".png",  GUID_ContainerFormatPng  },
					{ ".ico", GUID_ContainerFormatIco  }, { ".jpeg", GUID_ContainerFormatJpeg },
					{ ".jpg", GUID_ContainerFormatJpeg }, { ".tiff", GUID_ContainerFormatTiff },
					{ ".gif", GUID_ContainerFormatGif  }, { ".wmp",  GUID_ContainerFormatWmp  }
				};

				if (extensionToREFUGUIDMap.find(fileExtension) == std::end(extensionToREFUGUIDMap))
					WS_THROW("[WIC] Your Image Extension Is Not Supported");

				if (DX_FAILED(factory->CreateEncoder(extensionToREFUGUIDMap.at(fileExtension), NULL, &bitmapEncoder)))
					WS_THROW("[WIC] Failed To Create Bitmap Encoder");

				if (DX_FAILED(bitmapEncoder->Initialize(outputStream.Get(), WICBitmapEncoderNoCache)))
					WS_THROW("[WIC] Failed To Initialize Bitmap ");

				if (DX_FAILED(bitmapEncoder->CreateNewFrame(&bitmapFrame, NULL)))
					WS_THROW("[WIC] Failed To Create A New Frame");

				if (DX_FAILED(bitmapFrame->Initialize(NULL)))
					WS_THROW("[WIC] Failed To Initialize A Bitmap's Frame");

				if (DX_FAILED(bitmapFrame->SetSize(this->m_width, this->m_height)))
					WS_THROW("[WIC] Failed To Set A Bitmap's Frame's Size");

				WICPixelFormatGUID pixelFormat = GUID_WICPixelFormat32bppBGRA;
				if (DX_FAILED(bitmapFrame->SetPixelFormat(&pixelFormat)))
					WS_THROW("[WIC] Failed To Set Pixel Format On A Bitmap Frame's");

				if (!IsEqualGUID(pixelFormat, GUID_WICPixelFormat32bppBGRA))
					WS_THROW("[WIC] The Requested Pixel Format Is Not Supported");

				const UINT stride = this->m_width * sizeof(Coloru8);
				const UINT bufferSize = this->m_nPixels * sizeof(Coloru8);
				if (DX_FAILED(bitmapFrame->WritePixels(this->m_height, stride, bufferSize, (BYTE*)this->m_buff.get())))
					WS_THROW("[WIC] Failed To Write Pixels To A Bitmap's Frame");

				if (DX_FAILED(bitmapFrame->Commit()))
					WS_THROW("[WIC] Failed To Commit A Bitmap's Frame");

				if (DX_FAILED(bitmapEncoder->Commit()))
					WS_THROW("[WIC] Failed To Commit Bitmap Encoder");
			}
		}; // namespace WIN

	}; // Internal

	/*
	 * // //////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||--------------------------WINDOW--------------------------|| \\
	 * // |\__________________________________________________________/| \\
	 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--////////////////////////////// \\
	 */

	Window::~Window() WS_NOEXCEPT
	{
		if (this->m_pMouse != nullptr)
			delete this->m_pMouse;

		if (this->m_pKeyboard != nullptr)
			delete this->m_pKeyboard;
	}

	/*
	 * // ////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||-----------------------Internal-----------------------|| \\
	 * // |\______________________________________________________/| \\
	 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\--//////////////////////////// \\
	 */

	namespace Internal {

		/*
		 * // /////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
		 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
		 * // ||--------------------------WIN--------------------------|| \\
		 * // |\_______________________________________________________/| \\
		 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\-///////////////////////////// \\
		 */

#ifdef __WEISS__OS_WINDOWS

		namespace WIN {

			/*
			* // //////////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			* // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			* // ||--------------------------WINDOWS MOUSE--------------------------|| \\
			* // |\_________________________________________________________________/| \\
			* // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-////////////////////////////////// \\
			*/

			WindowsMouse::WindowsMouse() WS_NOEXCEPT
			{
				RAWINPUTDEVICE mouseInputDevice;
				mouseInputDevice.usUsagePage = 0x01;
				mouseInputDevice.usUsage = 0x02;
				mouseInputDevice.dwFlags = 0;
				mouseInputDevice.hwndTarget = nullptr;

				if (RegisterRawInputDevices(&mouseInputDevice, 1, sizeof(RAWINPUTDEVICE)) == FALSE)
					WS_THROW("[WIN] Failed To Register Mouse Raw Input Device");
			}

			void WindowsMouse::Clip(const Rect& rect) const WS_NOEXCEPT
			{
				RECT winRect{ rect.left, rect.top, rect.right, rect.bottom };

				if (ClipCursor(&winRect))
					WS_THROW("[WIN] Failed To Clip Cursor");
			}

			void WindowsMouse::__OnWindowUpdateBegin() WS_NOEXCEPT
			{
				this->m_wheelDelta = 0;
				this->m_deltaPosition = { 0, 0 };
				this->m_wasMouseMovedDuringUpdate = false;
				this->m_wasCursorMovedDuringUpdate = false;
			}

			bool WindowsMouse::__HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam) WS_NOEXCEPT
			{
				switch (msg)
				{
				case WM_INPUT:
				{
					UINT size = 0;

					if (!GetRawInputData(reinterpret_cast<HRAWINPUT>(lParam), RID_INPUT, nullptr, &size, sizeof(RAWINPUTHEADER)))
					{
						std::vector<char> rawBuffer(size);

						if (GetRawInputData(reinterpret_cast<HRAWINPUT>(lParam), RID_INPUT, rawBuffer.data(), &size, sizeof(RAWINPUTHEADER)) == size)
						{
							const RAWINPUT& ri = reinterpret_cast<const RAWINPUT&>(*rawBuffer.data());

							if (ri.header.dwType == RIM_TYPEMOUSE && (ri.data.mouse.lLastX != 0 || ri.data.mouse.lLastY != 0))
							{
								this->m_deltaPosition += Veci16{ static_cast<int16_t>(ri.data.mouse.lLastX), static_cast<int16_t>(ri.data.mouse.lLastY) };

								this->m_wasMouseMovedDuringUpdate = true;
							}
						}
					}

					return true;
				}

				break;
				case WM_MOUSELEAVE:
					this->m_isCursorInWindow = false;

					return true;
				case WM_MOUSEMOVE:
				{
					this->m_position = { static_cast<uint16_t>(GET_X_LPARAM(lParam)), static_cast<uint16_t>(GET_Y_LPARAM(lParam)) };
					this->m_wasCursorMovedDuringUpdate = true;
				}

				this->m_isCursorInWindow = true;

				return true;
				case WM_LBUTTONDOWN:
					this->m_isLeftButtonDown = true;

					for (auto& functor : this->m_onLeftButtonDownFunctors)
						functor(this->m_position);

					return true;
				case WM_LBUTTONUP:
					this->m_isLeftButtonDown = false;

					for (auto& functor : this->m_onLeftButtonUpFunctors)
						functor(this->m_position);

					return true;
				case WM_RBUTTONDOWN:
					this->m_isRightButtonDown = true;

					for (auto& functor : this->m_onRightButtonDownFunctors)
						functor(this->m_position);

					return true;
				case WM_RBUTTONUP:
					this->m_isRightButtonDown = false;

					for (auto& functor : this->m_onRightButtonUpFunctors)
						functor(this->m_position);

					return true;
				case WM_MOUSEWHEEL:
					this->m_wheelDelta += GET_WHEEL_DELTA_WPARAM(wParam);
					return true;
				default:
					return false;
				}
			}

			void WindowsMouse::__OnWindowUpdateEnd() WS_NOEXCEPT
			{
				if (this->m_wasMouseMovedDuringUpdate)
					for (auto& functor : this->m_onMouseMoveFunctors)
						functor(this->m_position, this->m_deltaPosition);

				if (this->m_wasCursorMovedDuringUpdate)
					for (auto& functor : this->m_onCursorMoveFunctors)
						functor(this->m_position, this->m_deltaPosition);

				if (this->m_wheelDelta != 0)
					for (auto& functor : this->m_onWheelTurnFunctors)
						functor(this->m_wheelDelta);
			}

			/*
			 * // //////////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||-------------------------WINDOWS KEYBOARD-------------------------|| \\
			 * // |\__________________________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--////////////////////////////////// \\
			 */

			bool WindowsKeyboard::__HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam) WS_NOEXCEPT
			{
				switch (msg)
				{
				case WM_KEYDOWN:
					{
						const uint8_t keyCode = static_cast<uint8_t>(wParam);

						// Verify that the key was not down before the message was sent
						if (!CHECK_BIT(lParam, 30))
						{
							this->m_downKeys.push_back(keyCode);

							for (auto& functor : this->m_onKeyDownFunctors)
								functor(keyCode);
						}

						return true;
					}
				case WM_KEYUP:
					{
						const uint8_t keyCode = static_cast<uint8_t>(wParam);

						this->m_downKeys.erase(std::remove(this->m_downKeys.begin(), this->m_downKeys.end(), keyCode), this->m_downKeys.end());

						for (auto& functor : this->m_onKeyUpFunctors)
							functor(keyCode);

						return true;
					}
				}

				return false;
			}

			/*
			* // //////////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			* // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			* // ||--------------------------WINDOWS WINDOW--------------------------|| \\
			* // |\__________________________________________________________________/| \\
			* // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-/////////////////////////////////// \\
			*/

			WindowsWindow::WindowsWindow(const WindowDescriptor& descriptor) WS_NOEXCEPT
			{
				WNDCLASSA wc;
				ZeroMemory(&wc, sizeof(WNDCLASSA));

				wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
				wc.lpfnWndProc = WindowProcessMessages;
				wc.hInstance = GetModuleHandle(NULL);
				wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
				wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
				wc.lpszClassName = "WEISS_WNDCLASSA";

				if (!RegisterClassA(&wc))
					WS_THROW("[WINDOW] Could Not Register Window Class");

				// CS_OWNDC For Opengl
				const uint32_t windowStyle = CS_OWNDC | (descriptor.isResizable ? WS_OVERLAPPEDWINDOW : (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX));

				RECT windowRect{ 0, 0, descriptor.width, descriptor.height };
				AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

				this->m_handle = CreateWindowA("WEISS_WNDCLASSA", descriptor.title, windowStyle,
					descriptor.x, descriptor.y,
					windowRect.right - windowRect.left,
					windowRect.bottom - windowRect.top,
					NULL, NULL, wc.hInstance, NULL);

				if (this->m_handle == NULL)
					WS_THROW("[WINDOW] Could Not Create Window");

	#ifdef __WEISS__PLATFORM_X64

				SetWindowLongPtr(this->m_handle, GWLP_USERDATA, (LONG_PTR)this);

	#else

				SetWindowLong(this->m_handle, GWLP_USERDATA, (LONG)this);

	#endif

				this->m_pMouse = new WindowsMouse();
				this->m_pKeyboard = new WindowsKeyboard();

				ShowWindow(this->m_handle, SW_SHOW);
				UpdateWindow(this->m_handle);

				this->m_isRunning = true;

				if (descriptor.iconPath != nullptr)
					this->SetIcon(descriptor.iconPath);
			}

			[[nodiscard]] Rect WindowsWindow::GetWindowRectangle() const WS_NOEXCEPT
			{
				RECT windowRect;
				if (GetWindowRect(this->m_handle, &windowRect) == FALSE)
					WS_THROW("[WIN] Failed To Get Window Rect");

				return Rect(windowRect);
			}

			[[nodiscard]] Rect WindowsWindow::GetClientRectangle() const WS_NOEXCEPT
			{
				RECT clientRect;
				if (GetClientRect(this->m_handle, &clientRect) == FALSE)
					WS_THROW("[WIN] Failed To Get Client Rect");

				return Rect(clientRect);
			}

			[[nodiscard]] LRESULT WindowsWindow::HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam) WS_NOEXCEPT
			{
				switch (msg)
				{
				case WM_SIZE:
				{
					const Vecu16 client_area_dimensions = {
						static_cast<uint16_t>(GET_X_LPARAM(lParam)),
						static_cast<uint16_t>(GET_Y_LPARAM(lParam))
					};

					this->m_isMinimized = (client_area_dimensions.x == 0 && client_area_dimensions.y == 0);

					for (auto& functor : this->m_onResizeFunctors)
						functor(client_area_dimensions);
				}

				return 0;
				case WM_DESTROY:
					this->Destroy();

					return 0;
				}

				// Dispatch Message To Peripheral Devices
				if (reinterpret_cast<WindowsMouse*>(this->m_pMouse)->__HandleMessage(msg, wParam, lParam)) return 0;
				if (reinterpret_cast<WindowsKeyboard*>(this->m_pKeyboard)->__HandleMessage(msg, wParam, lParam)) return 0;

				// Otherwise Let Windows Handle The Message
				return DefWindowProc(this->m_handle, msg, wParam, lParam);
			}

			void WindowsWindow::SetWindowSize(const uint16_t width, const uint16_t height) WS_NOEXCEPT
			{
				if (SetWindowPos(this->m_handle, NULL, 0, 0, width, height, SWP_NOMOVE | SWP_NOOWNERZORDER) == FALSE)
					WS_THROW("[WIN] Failed To Set Window Position");
			}

			void WindowsWindow::SetClientSize(const uint16_t width, const uint16_t height) WS_NOEXCEPT
			{
				const uint16_t topBottomWindowPadding = this->GetWindowHeight() - this->GetClientHeight();
				const uint16_t leftRightWindowPadding = this->GetWindowWidth() - this->GetClientWidth();

				this->SetWindowSize(width + leftRightWindowPadding, height + topBottomWindowPadding);
			}

			void WindowsWindow::SetTitle(const char* title) const WS_NOEXCEPT
			{
				if (SetWindowTextA(this->m_handle, title) == FALSE)
					WS_THROW("[WIN] Failed To Set Window Title");
			}

			void WindowsWindow::SetIcon(const char* pathname) WS_NOEXCEPT
			{
				const HICON hIcon = (HICON)LoadImageA(NULL, pathname, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);

				if (hIcon == NULL)
					WS_THROW("Could Not Load Icon");

				SendMessage(this->m_handle, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
			}

			void WindowsWindow::Update() WS_NOEXCEPT
			{
				reinterpret_cast<WindowsMouse*>(this->m_pMouse)->__OnWindowUpdateBegin();
				reinterpret_cast<WindowsKeyboard*>(this->m_pKeyboard)->__OnWindowUpdateBegin();

				MSG msg;
				while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}

				reinterpret_cast<WindowsMouse*>(this->m_pMouse)->__OnWindowUpdateEnd();
				reinterpret_cast<WindowsKeyboard*>(this->m_pKeyboard)->__OnWindowUpdateEnd();
			}

			void WindowsWindow::Destroy() WS_NOEXCEPT
			{
				this->m_isRunning = !DestroyWindow(this->m_handle);
			}

			WindowsWindow::~WindowsWindow() WS_NOEXCEPT { this->Destroy(); }

			LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
			{
	#ifdef __WEISS__PLATFORM_X64

					WindowsWindow* window = (WindowsWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);

	#else

					WindowsWindow* window = (WindowsWindow*)GetWindowLong(hwnd, GWLP_USERDATA);

	#endif

					if (window != NULL)
						return window->HandleMessage(msg, wParam, lParam);

					return DefWindowProc(hwnd, msg, wParam, lParam);
				}

		}; // namespace WIN

#endif // __WEISS__OS_WINDOWS

	}; // namespace Internal

	/*
	 * // ////////////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||--------------------------PERSPECTIVE CAMERA--------------------------|| \\
	 * // |\______________________________________________________________________/| \\
	 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-///////////////////////////////////// \\ 
	 */

	PerspectiveCamera::PerspectiveCamera(Window* pWindow, const PerspectiveCameraDescriptor& descriptor) WS_NOEXCEPT
		: Camera(descriptor.position, descriptor.rotation), m_fov(descriptor.fov), m_zNear(descriptor.zNear), m_zFar(descriptor.zFar)
	{
		auto recalculateAspectRatio = [this](const Vecu16& clientDims)
		{
			this->m_aspectRatio = clientDims.x / static_cast<float>(clientDims.y);
		};

		recalculateAspectRatio({ pWindow->GetClientWidth(), pWindow->GetClientHeight() });

		pWindow->OnResize(recalculateAspectRatio);
	}

	void PerspectiveCamera::CalculateTransform() WS_NOEXCEPT
	{
		const MatrixFloat32 rotationMatrix = MatrixFloat32::MakeIdentity();
		const Vecf32        focusPosition  = (FORWARD_VECTOR * rotationMatrix) + this->m_position;
		const Vecf32        upDirection    = UP_VECTOR * rotationMatrix;
		
		this->m_forwardVector = FORWARD_VECTOR * rotationMatrix;
		this->m_rightVector   = RIGHT_VECTOR   * rotationMatrix;

		this->m_transform = MatrixFloat32::MakeTranslation(this->m_position);

//#ifdef __WEISS__OS_WINDOWS
//		DirectX::XMMATRIX rotationMatrix = DirectX::XMMatrixRotationRollPitchYawFromVector(this->m_rotation);
//		DirectX::XMVECTOR focusPosition  = DirectX::XMVectorAdd(DirectX::XMVector3TransformCoord(FORWARD_VECTOR, rotationMatrix), this->m_position);
//		DirectX::XMVECTOR upDirection    = DirectX::XMVector3TransformCoord(UP_VECTOR, rotationMatrix);
//
//		this->m_forwardVector = DirectX::XMVector3TransformCoord(FORWARD_VECTOR, rotationMatrix);
//		this->m_rightVector   = DirectX::XMVector3TransformCoord(RIGHT_VECTOR, rotationMatrix);
//
//		this->m_transform = DirectX::XMMatrixLookAtLH(this->m_position, focusPosition, upDirection) *
//							DirectX::XMMatrixPerspectiveFovLH(this->m_fov, this->m_aspectRatio, this->m_zNear, this->m_zFar);
//#endif // __WEISS__OS_WINDOWS
	}

	void PerspectiveCamera::HandleMouseMovements(Mouse& mouse, const float sensitivity) WS_NOEXCEPT
	{
		mouse.OnMouseMove([sensitivity, this, &mouse](const Vecu16 position, const Veci16 delta)
			{
				if (mouse.IsCursorInWindow()) {
					this->Rotate({ sensitivity * delta.y, sensitivity * delta.x, 0.0f });
				}
			});
	}

	void PerspectiveCamera::HandleKeyboardInputs(Keyboard& keyboard, const float speed, const char forward, const char backward, const char left, const char right, const char up, const char down) WS_NOEXCEPT
	{
		if (keyboard.IsKeyDown(forward))
			this->m_position += this->m_forwardVector * speed;
		if (keyboard.IsKeyDown(backward))
			this->m_position += this->m_forwardVector * (-speed);

		if (keyboard.IsKeyDown(right))
			this->m_position += this->m_rightVector * speed;
		if (keyboard.IsKeyDown(left))
			this->m_position += this->m_rightVector * (-speed);

		if (keyboard.IsKeyDown(up))
			this->m_position += UP_VECTOR * speed;
		if (keyboard.IsKeyDown(down))
			this->m_position += UP_VECTOR * (-speed);
	}

	/*
	 * // /////////////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||--------------------------ORTHOGRAPHIC CAMERA--------------------------|| \\
	 * // |\_______________________________________________________________________/| \\
	 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-///////////////////////////////////// \\ 
	 */

	OrthographicCamera::OrthographicCamera(Window* pWindow, const OrthographicCameraDescriptor& descriptor) WS_NOEXCEPT
		: Camera(descriptor.position, Vecf32{ 0.0f, descriptor.ratation, 0.0f })
	{
		auto recalculateInvAspectRatio = [this](const Vecu16& clientDims)
		{
			this->m_InvAspectRatio = clientDims.y / static_cast<float>(clientDims.x);
		};

		recalculateInvAspectRatio({ pWindow->GetClientWidth(), pWindow->GetClientHeight() });

		pWindow->OnResize(recalculateInvAspectRatio);
	}

	void OrthographicCamera::CalculateTransform() WS_NOEXCEPT
	{
		this->m_transform = MatrixFloat32::MakeScaling(this->m_InvAspectRatio)
						  * MatrixFloat32::MakeTranslation(-this->m_position.x, -this->m_position.y)
						  * MatrixFloat32::MakeRotationZ(this->m_rotation.z);
	}

	void OrthographicCamera::HandleMouseMovements(Mouse& mouse, const float sensitivity) WS_NOEXCEPT
	{

	}

	void OrthographicCamera::HandleKeyboardInputs(Keyboard& keyboard, const float speed, const char forward, const char backward, const char left, const char right, const char up, const char down) WS_NOEXCEPT
	{
#ifdef __WEISS__OS_WINDOWS

		if (keyboard.IsKeyDown(right))
			this->m_position = DirectX::XMVectorSet(this->m_position.x - speed, this->m_position.y, 0.0f, 0.0f);
		if (keyboard.IsKeyDown(left))
			this->m_position = DirectX::XMVectorSet(this->m_position.x + speed, this->m_position.y, 0.0f, 0.0f);

		if (keyboard.IsKeyDown(up))
			this->m_position = DirectX::XMVectorSet(this->m_position.x, this->m_position.y - speed, 0.0f, 0.0f);
		if (keyboard.IsKeyDown(down))
			this->m_position = DirectX::XMVectorSet(this->m_position.x, this->m_position.y + speed, 0.0f, 0.0f);

#endif // __WEISS__OS_WINDOWS
	}

	/*
	 * // //////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||-------------------------Internal-------------------------|| \\
	 * // |\__________________________________________________________/| \\
	 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-/////////////////////////////// \\
	 */

	namespace Internal {

		/*
		 * // //////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
		 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
		 * // ||--------------------------VULKAN--------------------------|| \\
		 * // |\__________________________________________________________/| \\
		 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-/////////////////////////////// \\ 
		 */

		namespace VK {

			/*
			 * // //////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------------------VKObjectWrapper<T>--------------------|| \\
			 * // |\__________________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-/////////////////////////////// \\
			 */

			template <typename T>
			VKObjectWrapper<T>& VKObjectWrapper<T>::operator=(VKObjectWrapper<T>&& other) WS_NOEXCEPT
			{
				this->m_object = other.m_object;
				other.m_object = VK_NULL_HANDLE;

				return *this;
			}

			template <typename T>
			inline VKObjectWrapper<T>::operator T&() WS_NOEXCEPT { return this->m_object; }

			template <typename T>
			inline VKObjectWrapper<T>::operator T() const WS_NOEXCEPT { return this->m_object; }

			template <typename T>
			inline T& VKObjectWrapper<T>::GetRef() WS_NOEXCEPT { return this->m_object; }

			template <typename T>
			inline T* VKObjectWrapper<T>::GetPtr() WS_NOEXCEPT { return &this->m_object; }

			template <typename T>
			inline const T* VKObjectWrapper<T>::GetPtr() const WS_NOEXCEPT { return &this->m_object; }

			template <typename T>
			VKObjectWrapper<T>::~VKObjectWrapper()
			{
				if (this->m_object != VK_NULL_HANDLE)
				{
					WS::LOG::Println(WS::LOG_TYPE::LOG_WARNING, "[VULKAN] Deleting Object Of Handle (", this->m_object, ")");
					this->m_object = VK_NULL_HANDLE;
				} else {
					WS::LOG::Println(WS::LOG_TYPE::LOG_NORMAL, "[VULKAN] Deleting Object Of Handle (", this->m_object, ")");
				}
			}

			/*
			 * // /////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------------------Validation Layers--------------------|| \\
			 * // |\_________________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\--////////////////////////////// \\
			 */

			static VKAPI_ATTR VkBool32 VKAPI_CALL validationLayerCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
																		  VkDebugUtilsMessageTypeFlagsEXT messageType,
																		  const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
																		  void* pUserData)
			{
				WS_ERROR_MESSAGE(pCallbackData->pMessage);
				WS::LOG::Println(WS::LOG_TYPE::LOG_ERROR, pCallbackData->pMessage);

				return VK_FALSE;
			}

			/*
			 * // //////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------------------VKInstance--------------------|| \\
			 * // |\__________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\\-/////////////////////////// \\
			 */

			VKInstance::VKInstance(const char* appName)
			{
				std::vector<VkExtensionProperties> availableExtensions;
				{ // Fetch Available Extensions
					uint32_t extensionCount = 0;
					if (VK_FAILED(vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr)))
						WS_THROW("[VULKAN] Failed To Enumerate Instance Extension Propreties");

					availableExtensions.resize(extensionCount);
					if (VK_FAILED(vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, availableExtensions.data())))
						WS_THROW("[VULKAN] Failed To Enumerate Instance Extension Propreties");
				}

				std::vector<const char*> requiredExtensions;
				{ // Fetch Required Extensions
#ifdef __WEISS__DEBUG_MODE

					requiredExtensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

#endif // __WEISS__DEBUG_MODE

#ifdef __WEISS__OS_WINDOWS

					requiredExtensions.push_back(VK_KHR_SURFACE_EXTENSION_NAME);
					requiredExtensions.push_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);

#endif // __WEISS__OS_WINDOWS
				}

				// Check that the required extensions are supported
				for (const char* requiredExtension : requiredExtensions)
				{
					bool bFound = false;

					for (const VkExtensionProperties& availableExtension : availableExtensions)
					{
						if (strcmp(requiredExtension, availableExtension.extensionName) == 0)
						{
							bFound = true;
							break;
						}
					}

					if (!bFound)
					{
						const std::string errorString = "[VULKAN] Extension \"" + std::string(requiredExtension) + std::string("\" Is Not Supported");
						WS_THROW(errorString.c_str());
					}
				}

				VkApplicationInfo appInfo{};
				appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
				appInfo.pApplicationName   = appName;
				appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
				appInfo.pEngineName   = "Weiss Engine";
				appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
				appInfo.apiVersion    = VK_API_VERSION_1_2;

				VkInstanceCreateInfo createInfo{};
				createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
				createInfo.pApplicationInfo        = &appInfo;
				createInfo.enabledExtensionCount   = static_cast<uint32_t>(requiredExtensions.size());
				createInfo.ppEnabledExtensionNames = requiredExtensions.data();

#ifdef __WEISS__DEBUG_MODE

				std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };

				createInfo.enabledLayerCount   = validationLayers.size();
				createInfo.ppEnabledLayerNames = validationLayers.data();

				VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo;
				debugCreateInfo = {};
				debugCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
				debugCreateInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
				debugCreateInfo.messageType     = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
				debugCreateInfo.pfnUserCallback = validationLayerCallback;

				createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;

#endif // __WEISS__DEBUG_MODE


				if (VK_FAILED(vkCreateInstance(&createInfo, nullptr, this->GetPtr())))
					WS_THROW("[VULKAN] Failed To Create Instance");
			}

			VKInstance& VKInstance::operator=(VKInstance&& other) WS_NOEXCEPT
			{
				std::swap(this->m_object, other.m_object);

				return *this;
			}

			VKInstance::~VKInstance()
			{
				if (this->m_object != VK_NULL_HANDLE)
					vkDestroyInstance(this->m_object, nullptr);
			}

			/*
			 * // /////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------------------VKSurface--------------------|| \\
			 * // |\_________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\--////////////////////////// \\
			 */

			VKSurface::VKSurface(const VKInstance& instance, Window* pWindow) WS_NOEXCEPT
				: m_pInstance(&instance)
			{
#ifdef __WEISS__OS_WINDOWS

				VkWin32SurfaceCreateInfoKHR createInfo = {};
				createInfo.sType     = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
				createInfo.hwnd      = reinterpret_cast<const WS::Internal::WIN::WindowsWindow*>(pWindow)->GetHandle();
				createInfo.hinstance = GetModuleHandle(NULL);

				if (VK_FAILED(vkCreateWin32SurfaceKHR(*this->m_pInstance->GetPtr(), &createInfo, nullptr, &this->m_object)))
					WS_THROW("[VULKAN] Failed To Create Window Surface");

#endif // __WEISS__OS_WINDOWS

				this->m_dimensions = {
					pWindow->GetClientWidth(),
					pWindow->GetClientHeight()
				};
			}

			VKSurface& VKSurface::operator=(VKSurface&& other) WS_NOEXCEPT
			{
				std::swap(this->m_object,    other.m_object);
				std::swap(this->m_pInstance, other.m_pInstance);

				this->m_dimensions = std::move(other.m_dimensions);

				return *this;
			}

			[[nodiscard]] inline Vecu16 VKSurface::GetDimensions() const WS_NOEXCEPT
			{
				return this->m_dimensions;
			}

			VKSurface::~VKSurface()
			{
				if (this->m_object != VK_NULL_HANDLE)
					vkDestroySurfaceKHR(*this->m_pInstance->GetPtr(), this->m_object, nullptr);
			}

			/*
			 * // /////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------------VKPhysicalDeviceData--------------|| \\
			 * // |\________________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\\-////////////////////////// \\
			 */

			VKPhysicalDeviceData::VKPhysicalDeviceData(const VkPhysicalDevice& physicalDevice, const VKSurface& surface) WS_NOEXCEPT
				: physicalDevice(physicalDevice)
			{
				vkGetPhysicalDeviceFeatures(physicalDevice,   &this->features);
				vkGetPhysicalDeviceProperties(physicalDevice, &this->propreties);

				uint32_t familyCount;
				vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &familyCount, nullptr);

				this->queueFamilyPropreties.resize(familyCount);
				vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &familyCount, this->queueFamilyPropreties.data());

				uint32_t i = 0u;
				for (const VkQueueFamilyProperties& queueFamily : this->queueFamilyPropreties)
				{
					const VkQueueFlags queueFlags = queueFamily.queueFlags;

					if (queueFlags & VK_QUEUE_GRAPHICS_BIT)
						this->graphicsQueueIndex = i;


					VkBool32 presentSupport = false;
					vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, i, surface, &presentSupport);

					if (presentSupport)
						this->presentQueueIndex = i;

					i++;
				}

				switch (this->propreties.deviceType)
				{
				case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
					this->rating += 10u;
					break;
				case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
					this->rating += 3;
					break;
				}

				uint32_t extensionCount;
				vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extensionCount, nullptr);

				this->extensionPropreties.resize(extensionCount);
				vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extensionCount, this->extensionPropreties.data());
			}

			/*
			 * // ///////////////////-\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------------VKDevice--------------|| \\
			 * // |\____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\-//////////////////// \\
			 */

			VKDevice::VKDevice(const VKInstance& instance, const VKSurface& surface) WS_NOEXCEPT
				: m_pInstance(&instance)
			{
				std::vector<VkPhysicalDevice> physicalDevices;
				{ // Get Physical Devices
					uint32_t deviceCount = 0;
					if (VK_FAILED(vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr)))
						WS_THROW("[VULKAN] Failed To Enumerate Physical Devices");

					physicalDevices.resize(deviceCount);

					if (VK_FAILED(vkEnumeratePhysicalDevices(instance, &deviceCount, physicalDevices.data())))
						WS_THROW("[VULKAN] Failed To Enumerate Physical Devices");

					if (physicalDevices.size() == 0)
						WS_THROW("[VULKAN] Failed To Find Any Physical Devices");
				}

				{ // Pick Physical Device
					std::multimap<uint64_t, VKPhysicalDeviceData> candidates;

					for (const VkPhysicalDevice& physicalDevice : physicalDevices)
					{
						VKPhysicalDeviceData physicalDeviceData(physicalDevice, surface);

						candidates.insert(std::make_pair(physicalDeviceData.rating, physicalDeviceData));
					}

					this->m_physicalDeviceData = candidates.rbegin()->second;
				}

				{ // Create Logical Device
					const std::vector<const char*> requiredExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };

					{ // Check Extensions
						for (const char* requiredExtension : requiredExtensions)
						{
							bool bFound = false;

							for (VkExtensionProperties& availableExtensionPropreties : this->m_physicalDeviceData.extensionPropreties)
							{
								if (strcmp(requiredExtension, availableExtensionPropreties.extensionName) == 0)
								{
									bFound = true;
									break;
								}
							}

							if (!bFound)
							{
								const std::string errorString = "[VULKAN] Extension \"" + std::string(requiredExtension) + std::string("\" Is Not Supported");
								WS_THROW(errorString.c_str());
							}
						}
					}

					std::array<VkDeviceQueueCreateInfo, 2u> queueCreateInfos;

					uint32_t i = 0u;
					for (VkDeviceQueueCreateInfo& queueCreateInfo : queueCreateInfos)
					{
						queueCreateInfo = {};
						queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
						queueCreateInfo.queueCount = 1u;
						queueCreateInfo.queueFamilyIndex = this->m_physicalDeviceData.queueIndices[i++].value();

						float queuePriority = 1.0f;
						queueCreateInfo.pQueuePriorities = &queuePriority;
					}

					VkPhysicalDeviceFeatures deviceFeatures = {};

					VkDeviceCreateInfo createInfo = {};
					createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
					createInfo.pQueueCreateInfos       = queueCreateInfos.data();
					createInfo.queueCreateInfoCount    = static_cast<uint32_t>(queueCreateInfos.size());
					createInfo.pEnabledFeatures        = &deviceFeatures;
					createInfo.enabledLayerCount       = 0u;
					createInfo.ppEnabledLayerNames     = nullptr;
					createInfo.enabledExtensionCount   = static_cast<uint32_t>(requiredExtensions.size());
					createInfo.ppEnabledExtensionNames = requiredExtensions.data();

					if (VK_FAILED(vkCreateDevice(this->m_physicalDeviceData.physicalDevice, &createInfo, nullptr, &this->m_object)))
						WS_THROW("|VULKAN] Failed To Create Logical Device");
				}
			}

			[[nodiscard]] inline VKPhysicalDeviceData VKDevice::GetPhysicalDeviceData() const WS_NOEXCEPT
			{
				return this->m_physicalDeviceData;
			}

			VKDevice& VKDevice::operator=(VKDevice&& other) WS_NOEXCEPT
			{
				std::swap(this->m_object, other.m_object);
				
				this->m_pInstance          = other.m_pInstance;
				this->m_physicalDeviceData = other.m_physicalDeviceData;

				return *this;
			}

			VKDevice::~VKDevice()
			{
				if (this->m_object != VK_NULL_HANDLE)
					vkDestroyDevice(this->m_object, nullptr);
			}

			/*
			 * // //////////////////--\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------------VKQueue--------------|| \\
			 * // |\___________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\--/////////////////// \\
			 */

			VKQueue::VKQueue(const VKDevice& device, const size_t queueIndex) WS_NOEXCEPT
			{
				vkGetDeviceQueue(device, static_cast<uint32_t>(queueIndex), 0, &this->m_object);
			}

			VKQueue& VKQueue::operator=(VKQueue&& other) WS_NOEXCEPT
			{
				std::swap(this->m_object, other.m_object);

				return *this;
			}

			/*
			 * // ////////////////////--\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------------VKSemaphore--------------|| \\
			 * // |\_______________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\--///////////////////// \\
			 */

			VKSemaphore::VKSemaphore(const VKDevice& device) WS_NOEXCEPT
				: m_pDevice(&device)
			{
				VkSemaphoreCreateInfo semaphoreInfo{};
				semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

				if (VK_FAILED(vkCreateSemaphore(device, &semaphoreInfo, nullptr, &this->m_object)))
					WS_THROW("[VULKAN] Failed To Create Semaphore");
			}

			VKSemaphore& VKSemaphore::operator=(VKSemaphore&& other) WS_NOEXCEPT
			{
				std::swap(this->m_object, other.m_object);

				this->m_pDevice = std::move(other.m_pDevice);

				return *this;
			}

			VKSemaphore::~VKSemaphore()
			{
				vkDestroySemaphore(*this->m_pDevice, this->m_object, nullptr);
			}

			/*
			 * // //////////////////--\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------------VKFence--------------|| \\
			 * // |\___________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\--/////////////////// \\
			 */

			VKFence::VKFence(const VKDevice& device) WS_NOEXCEPT
				: m_pDevice(&device)
			{
				VkFenceCreateInfo fenceInfo{};
				fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
				fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

				if (VK_FAILED(vkCreateFence(device, &fenceInfo, nullptr, &this->m_object)))
					WS_THROW("[VULKAN] Failed To Create Fence");

				this->Reset();
			}

			VKFence& VKFence::operator=(VKFence&& other) noexcept
			{
				std::swap(this->m_object, other.m_object);

				this->m_pDevice = std::move(other.m_pDevice);

				return *this;
			}

			inline void VKFence::Wait() const WS_NOEXCEPT
			{
				if (VK_FAILED(vkWaitForFences(*this->m_pDevice, 1u, &this->m_object, VK_TRUE, UINT64_MAX)))
					WS_THROW("[VULKAN] Failed To Wait For Fence");
			}

			inline void VKFence::Reset() const WS_NOEXCEPT
			{
				if (VK_FAILED(vkResetFences(*this->m_pDevice, 1u, &this->m_object)))
					WS_THROW("[VULKAN] Failed To Reset Fence");
			}

			inline void VKFence::WaitAndReset() const WS_NOEXCEPT
			{
				this->Wait();
				this->Reset();
			}

			VKFence::~VKFence() WS_NOEXCEPT
			{
				vkDestroyFence(*this->m_pDevice, this->m_object, nullptr);
			}

			/*
			 * // ////////////////////--\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------------VKSwapChain--------------|| \\
			 * // |\_______________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\--///////////////////// \\
			 */

			VKSwapChain::VKSwapChain(const VKDevice& device, const VKSurface& surface, const VKQueue& presentQueue) WS_NOEXCEPT
				: m_pDevice(&device), m_pPresentQueue(&presentQueue)
			{
				{ // Create Swap Chain
					this->m_surfaceFormat = this->PickSurfaceFormat(device, surface);
					this->m_imageExtent2D.width = surface.GetDimensions().x;
					this->m_imageExtent2D.height = surface.GetDimensions().y;

					VkSwapchainCreateInfoKHR createInfo = {};
					createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
					createInfo.surface = surface;
					createInfo.minImageCount = WEISS__FRAME_BUFFER_COUNT;
					createInfo.imageFormat = this->m_surfaceFormat.format;
					createInfo.imageColorSpace = this->m_surfaceFormat.colorSpace;
					createInfo.imageExtent = this->m_imageExtent2D;
					createInfo.imageArrayLayers = 1;
					createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
					createInfo.preTransform = VkSurfaceTransformFlagBitsKHR::VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
					createInfo.compositeAlpha = VkCompositeAlphaFlagBitsKHR::VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
					createInfo.presentMode = this->PickPresentMode(device, surface);
					createInfo.clipped = VK_TRUE;
					createInfo.clipped = VK_TRUE;
					createInfo.oldSwapchain = VK_NULL_HANDLE;

					const VKPhysicalDeviceData& physicalDeviceData = device.GetPhysicalDeviceData();

					std::array<uint32_t, 2u> sharingQueueFamilyIndices{
						*physicalDeviceData.presentQueueIndex,
						*physicalDeviceData.graphicsQueueIndex
					};

					if (*physicalDeviceData.graphicsQueueIndex == *physicalDeviceData.presentQueueIndex)
					{
						createInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
						createInfo.queueFamilyIndexCount = 0u;
						createInfo.pQueueFamilyIndices = nullptr;
					} else {
						createInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
						createInfo.queueFamilyIndexCount = 2u;

						createInfo.pQueueFamilyIndices = sharingQueueFamilyIndices.data();
					}

					if (VK_FAILED(vkCreateSwapchainKHR(device, &createInfo, nullptr, &this->m_object)))
						WS_THROW("[VULKAN] Failed To Create Swap Chain");
				}

				{ // Create Images & Views
					vkGetSwapchainImagesKHR(device, this->m_object, &this->m_nImages, nullptr);
					this->m_images.resize(this->m_nImages);
					this->m_imageViews.resize(this->m_nImages);
					vkGetSwapchainImagesKHR(device, this->m_object, &this->m_nImages, this->m_images.data());

					for (size_t i = 0; i < this->m_nImages; i++)
					{
						VkImageViewCreateInfo createInfo{};
						createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
						createInfo.image = this->m_images[i];
						createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
						createInfo.format = this->m_surfaceFormat.format;
						createInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
						createInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
						createInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
						createInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
						createInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
						createInfo.subresourceRange.baseMipLevel = 0;
						createInfo.subresourceRange.levelCount = 1;
						createInfo.subresourceRange.baseArrayLayer = 0;
						createInfo.subresourceRange.layerCount = 1;

						if (VK_FAILED(vkCreateImageView(device, &createInfo, nullptr, &this->m_imageViews[i])))
							WS_THROW("[VULKAN] Failed To Create An Image View");
					}
				}

				{ // Create Synchronisation Objects
					this->m_frameBufferFetchedSemaphore = VKSemaphore(device);
					this->m_fence = VKFence(device);
				}
			}

			void VKSwapChain::CreateFrameBuffers() WS_NOEXCEPT
			{
				this->m_frameBuffers.resize(this->m_nImages);

				VkFramebufferCreateInfo framebufferInfo{};
				framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
				framebufferInfo.attachmentCount = 1;
				framebufferInfo.width  = this->m_imageExtent2D.width;
				framebufferInfo.height = this->m_imageExtent2D.height;
				framebufferInfo.layers = 1;

				for (size_t i = 0; i < this->m_nImages; i++)
				{
					VkImageView attachments[] = {
						this->m_imageViews[i]
					};

					framebufferInfo.pAttachments = attachments;
					framebufferInfo.renderPass = VKRenderPass::m_renderPasses[0];

					if (VK_FAILED(vkCreateFramebuffer(*this->m_pDevice, &framebufferInfo, nullptr, &this->m_frameBuffers[i])))
						WS_THROW("[VULKAN] Failed To Create A Frame Buffer");
				}
			}

			void VKSwapChain::GetNextFrameBuffer() WS_NOEXCEPT
			{
				if (VK_FAILED(vkAcquireNextImageKHR(*this->m_pDevice, this->m_object, UINT64_MAX, this->m_frameBufferFetchedSemaphore, this->m_fence, &this->m_currentImageIndex)))
					WS_THROW("[VULKAN] Failed To Acquire Next Swap Chain Frame Buffer");

				this->m_fence.WaitAndReset();
			}

			void VKSwapChain::Present(bool useVsync, const VkSemaphore& waitSemaphore) WS_NOEXCEPT
			{
				VkPresentInfoKHR presentInfo{};
				presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
				presentInfo.waitSemaphoreCount = 1;
				presentInfo.pWaitSemaphores    = &waitSemaphore;
				presentInfo.swapchainCount = 1;
				presentInfo.pSwapchains    = &this->m_object;
				presentInfo.pImageIndices  = &this->m_currentImageIndex;
				presentInfo.pResults = nullptr;

				if (VK_FAILED(vkQueuePresentKHR(*this->m_pPresentQueue, &presentInfo)))
					WS_THROW("[VULKAN] Failed To Present Swap Chain Frame Buffer");
			}

			VKSwapChain& VKSwapChain::operator=(VKSwapChain&& other) WS_NOEXCEPT
			{
				this->m_pDevice       = other.m_pDevice;
				this->m_pPresentQueue = std::move(other.m_pPresentQueue);
				this->m_imageExtent2D = std::move(other.m_imageExtent2D);
				this->m_surfaceFormat = std::move(other.m_surfaceFormat);
				this->m_nImages      = std::move(other.m_nImages);
				this->m_images       = std::move(other.m_images);
				this->m_imageViews   = std::move(other.m_imageViews);
				this->m_frameBuffers = std::move(other.m_frameBuffers);
				this->m_currentImageIndex = std::move(other.m_currentImageIndex);
				this->m_frameBufferFetchedSemaphore = std::move(other.m_frameBufferFetchedSemaphore);
				this->m_fence = std::move(other.m_fence);

				std::swap(this->m_object, other.m_object);

				return *this;
			}

			[[nodiscard]] inline VkSemaphore        VKSwapChain::GetFrameBufferFetchedSemaphore() const WS_NOEXCEPT { return this->m_frameBufferFetchedSemaphore;             }
			[[nodiscard]] inline VkFramebuffer      VKSwapChain::GetCurrentFrameBuffer()          const WS_NOEXCEPT { return this->m_frameBuffers[this->m_currentImageIndex]; }
			[[nodiscard]] inline VkExtent2D         VKSwapChain::GetImageExtent()                 const WS_NOEXCEPT { return this->m_imageExtent2D;                           }
			[[nodiscard]] inline VkSurfaceFormatKHR VKSwapChain::GetFormat()                      const WS_NOEXCEPT { return this->m_surfaceFormat;                           }

			VKSwapChain::~VKSwapChain()
			{
				if (this->m_object != VK_NULL_HANDLE)
					vkDestroySwapchainKHR(*this->m_pDevice, this->m_object, nullptr);
			}

			VkPresentModeKHR VKSwapChain::PickPresentMode(const VKDevice& device, const VKSurface& surface) WS_NOEXCEPT
			{
				const VkPhysicalDevice physicalDevice = device.GetPhysicalDeviceData().physicalDevice;

				uint32_t nSupportedPresentingModes;
				vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, &nSupportedPresentingModes, nullptr);

				if (nSupportedPresentingModes == 0u)
					WS_THROW("[VULKAN] No Compatible Presenting Mode Could Be Found");

				std::vector<VkPresentModeKHR> supportedPresentingModes(nSupportedPresentingModes);
				vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, &nSupportedPresentingModes, supportedPresentingModes.data());

				if (supportedPresentingModes.size() == 0u)
					WS_THROW("[VULKAN] No Compatible Presenting Mode Could Be Found");

				for (const VkPresentModeKHR mode : supportedPresentingModes)
					if (mode == VkPresentModeKHR::VK_PRESENT_MODE_MAILBOX_KHR)
						return mode;

				return supportedPresentingModes[0];
			}

			VkSurfaceFormatKHR VKSwapChain::PickSurfaceFormat(const VKDevice& device, const VKSurface& surface) WS_NOEXCEPT
			{
				const VkPhysicalDevice physicalDevice = device.GetPhysicalDeviceData().physicalDevice;

				uint32_t nSupportedFormats;
				vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, &nSupportedFormats, nullptr);

				if (nSupportedFormats == 0u) return {};

				std::vector<VkSurfaceFormatKHR> supportedFormats(nSupportedFormats);
				vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, &nSupportedFormats, supportedFormats.data());

				if (supportedFormats.size() == 0u)
					WS_THROW("[VULKAN] No Supported Surface Format Where Found");

				for (const VkSurfaceFormatKHR& surfaceFormat : supportedFormats)
					if (surfaceFormat.format == VK_FORMAT_B8G8R8A8_SRGB && surfaceFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
						return surfaceFormat;

				return supportedFormats[0];
			}

			/*
			 * // /////////////////////-\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------------VKRenderPass--------------|| \\
			 * // |\________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\-////////////////////// \\
			 */

			void VKRenderPass::CreateRenderPasses(const VKDevice& device, const VKSwapChain& swapChain) WS_NOEXCEPT
			{
				{ // Render Pass #0
					VKRenderPass::m_renderPasses.push_back(VK_NULL_HANDLE);

					VkAttachmentDescription colorAttachment{};
					colorAttachment.format  = swapChain.GetFormat().format;
					colorAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
					colorAttachment.loadOp  = VK_ATTACHMENT_LOAD_OP_CLEAR;
					colorAttachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
					colorAttachment.stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
					colorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
					colorAttachment.initialLayout  = VK_IMAGE_LAYOUT_UNDEFINED;
					colorAttachment.finalLayout    = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

					VkAttachmentReference colorAttachmentRef{};
					colorAttachmentRef.attachment = 0;
					colorAttachmentRef.layout     = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

					VkSubpassDescription subpass{};
					subpass.pipelineBindPoint    = VK_PIPELINE_BIND_POINT_GRAPHICS;
					subpass.colorAttachmentCount = 1;
					subpass.pColorAttachments    = &colorAttachmentRef;

					VkSubpassDependency dependency{};
					dependency.srcSubpass    = VK_SUBPASS_EXTERNAL;
					dependency.dstSubpass    = 0;
					dependency.srcStageMask  = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
					dependency.srcAccessMask = 0;
					dependency.dstStageMask  = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
					dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

					VkRenderPassCreateInfo renderPassInfo{};
					renderPassInfo.sType           = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
					renderPassInfo.attachmentCount = 1;
					renderPassInfo.pAttachments    = &colorAttachment;
					renderPassInfo.subpassCount    = 1;
					renderPassInfo.pSubpasses      = &subpass;
					renderPassInfo.dependencyCount = 1;
					renderPassInfo.pDependencies = &dependency;

					if (VK_FAILED(vkCreateRenderPass(device, &renderPassInfo, nullptr, &VKRenderPass::m_renderPasses[0])))
						WS_THROW("[VULKAN] Failed To Create Render Pass");
				}
			}

			/*
			 * // /////////////////////-\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------VKRenderPipeline------------|| \\
			 * // |\________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\-////////////////////// \\
			 */

			VKRenderPipeline::VKRenderPipeline(VKRenderPipeline&& other) WS_NOEXCEPT
			{
				std::swap(this->m_object, other.m_object);

				this->m_layout  = std::move(other.m_layout);
				this->m_pDevice = std::move(other.m_pDevice);
			}

			VKRenderPipeline::VKRenderPipeline(const VKDevice& device, const VKSwapChain& swapChain, const RenderPipelineDesc& pipelineDesc,
											   std::vector<ConstantBuffer*>& pConstantBuffers, std::vector<Texture*> pTextures, std::vector<VKTextureSampler> textureSamplers) WS_NOEXCEPT
				: m_pDevice(&device)
			{
				const VkShaderModule vertexShaderModule = VKRenderPipeline::CreateShaderModule(device, pipelineDesc.vsFilename);
				const VkShaderModule pixelShaderModule  = VKRenderPipeline::CreateShaderModule(device, pipelineDesc.psFilename);

				VkPipelineShaderStageCreateInfo vertShaderStageInfo{};
				vertShaderStageInfo.sType  = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
				vertShaderStageInfo.stage  = VK_SHADER_STAGE_VERTEX_BIT;
				vertShaderStageInfo.module = vertexShaderModule;
				vertShaderStageInfo.pName  = "main";

				VkPipelineShaderStageCreateInfo fragShaderStageInfo{};
				fragShaderStageInfo.sType  = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
				fragShaderStageInfo.stage  = VK_SHADER_STAGE_FRAGMENT_BIT;
				fragShaderStageInfo.module = pixelShaderModule;
				fragShaderStageInfo.pName  = "main";

				const VkPipelineShaderStageCreateInfo shaderStages[] = { vertShaderStageInfo, fragShaderStageInfo };

				VkPipelineVertexInputStateCreateInfo vertexInputInfo{};
				vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
				vertexInputInfo.vertexBindingDescriptionCount = 0;
				vertexInputInfo.pVertexBindingDescriptions = nullptr;
				vertexInputInfo.vertexAttributeDescriptionCount = 0;
				vertexInputInfo.pVertexAttributeDescriptions = nullptr;

				VkPipelineInputAssemblyStateCreateInfo inputAssembly{};
				inputAssembly.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
				inputAssembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
				inputAssembly.primitiveRestartEnable = VK_FALSE;

				VkViewport viewport{};
				viewport.x = 0.0f;
				viewport.y = 0.0f;
				viewport.width  = (float)swapChain.GetImageExtent().width;
				viewport.height = (float)swapChain.GetImageExtent().height;
				viewport.minDepth = 0.0f;
				viewport.maxDepth = 1.0f;

				VkRect2D scissor{};
				scissor.offset = { 0, 0 };
				scissor.extent = swapChain.GetImageExtent();

				VkPipelineViewportStateCreateInfo viewportState{};
				viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
				viewportState.viewportCount = 1;
				viewportState.pViewports = &viewport;
				viewportState.scissorCount = 1;
				viewportState.pScissors = &scissor;

				VkPipelineRasterizationStateCreateInfo rasterizer{};
				rasterizer.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
				rasterizer.depthClampEnable = VK_FALSE;
				rasterizer.rasterizerDiscardEnable = VK_FALSE;
				rasterizer.polygonMode = VK_POLYGON_MODE_FILL;
				rasterizer.lineWidth = 1.0f;
				rasterizer.cullMode = VK_CULL_MODE_BACK_BIT;
				rasterizer.frontFace = VK_FRONT_FACE_CLOCKWISE;
				rasterizer.depthBiasEnable = VK_FALSE;
				rasterizer.depthBiasConstantFactor = 0.0f;
				rasterizer.depthBiasClamp = 0.0f;
				rasterizer.depthBiasSlopeFactor = 0.0f;

				VkPipelineMultisampleStateCreateInfo multisampling{};
				multisampling.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
				multisampling.sampleShadingEnable = VK_FALSE;
				multisampling.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
				multisampling.minSampleShading = 1.0f;
				multisampling.pSampleMask = nullptr;
				multisampling.alphaToCoverageEnable = VK_FALSE;
				multisampling.alphaToOneEnable = VK_FALSE;

				VkPipelineColorBlendAttachmentState colorBlendAttachment{};
				colorBlendAttachment.blendEnable = VK_TRUE;
				colorBlendAttachment.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
				colorBlendAttachment.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
				colorBlendAttachment.colorBlendOp = VK_BLEND_OP_ADD;
				colorBlendAttachment.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE;
				colorBlendAttachment.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
				colorBlendAttachment.alphaBlendOp = VK_BLEND_OP_ADD;

				VkPipelineColorBlendStateCreateInfo colorBlending{};
				colorBlending.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
				colorBlending.logicOpEnable = VK_FALSE;
				colorBlending.logicOp = VK_LOGIC_OP_COPY;
				colorBlending.attachmentCount = 1;
				colorBlending.pAttachments = &colorBlendAttachment;
				colorBlending.blendConstants[0] = 0.0f;
				colorBlending.blendConstants[1] = 0.0f;
				colorBlending.blendConstants[2] = 0.0f;
				colorBlending.blendConstants[3] = 0.0f;

				VkPipelineDynamicStateCreateInfo dynamicState{};
				dynamicState.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
				dynamicState.dynamicStateCount = 0u;
				dynamicState.pDynamicStates = nullptr;

				VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
				pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
				pipelineLayoutInfo.setLayoutCount = 0;
				pipelineLayoutInfo.pSetLayouts = nullptr;
				pipelineLayoutInfo.pushConstantRangeCount = 0;
				pipelineLayoutInfo.pPushConstantRanges = nullptr;

				if (FAILED(vkCreatePipelineLayout(device, &pipelineLayoutInfo, nullptr, this->m_layout.GetPtr())))
					WS_THROW("failed to create pipeline layout!");

				VkGraphicsPipelineCreateInfo pipelineInfo{};
				pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
				pipelineInfo.stageCount = sizeof(shaderStages) / sizeof(VkPipelineShaderStageCreateInfo);
				pipelineInfo.pStages = shaderStages;
				pipelineInfo.pVertexInputState = &vertexInputInfo;
				pipelineInfo.pInputAssemblyState = &inputAssembly;
				pipelineInfo.pViewportState = &viewportState;
				pipelineInfo.pRasterizationState = &rasterizer;
				pipelineInfo.pMultisampleState = &multisampling;
				pipelineInfo.pDepthStencilState = nullptr; // Optional
				pipelineInfo.pColorBlendState = &colorBlending;
				pipelineInfo.pDynamicState = nullptr;
				pipelineInfo.layout        = this->m_layout;
				pipelineInfo.renderPass    = VKRenderPass::m_renderPasses[0];
				pipelineInfo.subpass = 0;
				pipelineInfo.basePipelineHandle = VK_NULL_HANDLE; // Optional
				pipelineInfo.basePipelineIndex  = -1; // Optional

				if (VK_FAILED(vkCreateGraphicsPipelines(device, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &this->m_object)))
					WS_THROW("[VULKAN] Failed To Create Pipeline");

				vkDestroyShaderModule(device, vertexShaderModule, nullptr);
				vkDestroyShaderModule(device, pixelShaderModule,  nullptr);
			}

			VKRenderPipeline& VKRenderPipeline::operator=(VKRenderPipeline&& other) WS_NOEXCEPT
			{
				std::swap(this->m_object, other.m_object);

				this->m_layout  = std::move(other.m_layout);
				this->m_pDevice = std::move(other.m_pDevice);

				return *this;
			}

			VKRenderPipeline::~VKRenderPipeline()
			{
				if (this->m_object != VK_NULL_HANDLE)
					vkDestroyPipeline(*this->m_pDevice, this->m_object, nullptr);

				if (this->m_layout != VK_NULL_HANDLE)
					vkDestroyPipelineLayout(*this->m_pDevice, this->m_layout, nullptr);
			}

			VkShaderModule VKRenderPipeline::CreateShaderModule(const VKDevice& device, const char* filename) WS_NOEXCEPT
			{
				std::ifstream file(filename, std::ios::ate | std::ios::binary);

				if (!file.is_open())
					WS_THROW("[VULKAN] Failed To Open Binary Shader File");

				std::vector<char> contents(file.tellg());
				file.seekg(0);
				file.read(contents.data(), contents.size());
				file.close();

				VkShaderModuleCreateInfo createInfo{};
				createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
				createInfo.codeSize = contents.size();
				createInfo.pCode    = reinterpret_cast<const uint32_t*>(contents.data());

				VkShaderModule shaderModule;
				if (VK_FAILED(vkCreateShaderModule(device, &createInfo, nullptr, &shaderModule)))
					WS_THROW("[VULKAN] Failed To Create Shader Module");

				return shaderModule;
			}

			/*
			 * // /////////////////////--\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||--------------VKCommandPool--------------|| \\
			 * // |\_________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\--////////////////////// \\
			 */

			VKCommandPool::VKCommandPool(const VKDevice& device, const uint32_t queueFamilyIndex) WS_NOEXCEPT
				: m_pDevice(&device)
			{
				VkCommandPoolCreateInfo poolInfo{};
				poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
				poolInfo.queueFamilyIndex = queueFamilyIndex;
				poolInfo.flags = VK_COMMAND_POOL_CREATE_TRANSIENT_BIT | VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;

				if (VK_FAILED(vkCreateCommandPool(device, &poolInfo, nullptr, &this->m_object)))
					WS_THROW("[VULKAN] Failed To Create Command Pool");
			}

			VKCommandPool& VKCommandPool::operator=(VKCommandPool&& other) WS_NOEXCEPT
			{
				std::swap(this->m_object, other.m_object);

				this->m_pDevice = other.m_pDevice;

				return *this;
			}

			VKCommandPool::~VKCommandPool()
			{
				if (this->m_object != VK_NULL_HANDLE)
					vkDestroyCommandPool(*this->m_pDevice, this->m_object, nullptr);
			}

			/*
			 * // /////////////////////--\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||-------------VKCommandBuffer-------------|| \\
			 * // |\_________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\--////////////////////// \\
			 */

			VKCommandBuffer::VKCommandBuffer(const VKDevice& device, const VKCommandPool& commandPool, const VKQueue& queue) WS_NOEXCEPT
				: m_pDevice(&device), m_pQueue(&queue)
			{
				VkCommandBufferAllocateInfo allocInfo{};
				allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
				allocInfo.commandPool = commandPool;
				allocInfo.commandBufferCount = 1u;
				allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;

				if (VK_FAILED(vkAllocateCommandBuffers(device, &allocInfo, &this->m_object)))
					WS_THROW("[VULKAN] Failed To Create Command Buffer");

				this->m_submitedSemaphore = VKSemaphore(device);
				this->m_submitedfence     = VKFence(device);
			}

			VKCommandBuffer& VKCommandBuffer::operator=(VKCommandBuffer&& other) WS_NOEXCEPT
			{
				std::swap(this->m_object, other.m_object);

				this->m_pDevice = other.m_pDevice;
				this->m_pQueue  = other.m_pQueue;

				this->m_submitedSemaphore = std::move(other.m_submitedSemaphore);
				this->m_submitedfence     = std::move(other.m_submitedfence);

				return *this;
			}

			void VKCommandBuffer::BeginRecording() const WS_NOEXCEPT
			{
				VkCommandBufferBeginInfo beginInfo{};
				beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

				if (VK_FAILED(vkBeginCommandBuffer(this->m_object, &beginInfo)))
					WS_THROW("[VULKAN] Failed To Begin Command Buffer Recording");
			}

			void VKCommandBuffer::BeginRenderPass(const VKSwapChain& swapChain, const VkFramebuffer& frameBuffer, const VkRenderPass& renderPass) const WS_NOEXCEPT
			{
				VkClearValue clearColor = { 1.0f, 1.0f, 1.0f, 1.0f };

				VkRenderPassBeginInfo renderPassInfo{};
				renderPassInfo.renderPass  = renderPass;
				renderPassInfo.framebuffer = frameBuffer;
				renderPassInfo.clearValueCount   = 1;
				renderPassInfo.pClearValues      = &clearColor;
				renderPassInfo.renderArea.offset = { 0, 0 };
				renderPassInfo.renderArea.extent = swapChain.GetImageExtent();
				renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;

				vkCmdBeginRenderPass(this->m_object, &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);
			}

			void VKCommandBuffer::EndRenderPass() WS_NOEXCEPT
			{
				vkCmdEndRenderPass(this->m_object);
			}

			void VKCommandBuffer::EndRecording() const WS_NOEXCEPT
			{
				if (VK_FAILED(vkEndCommandBuffer(this->m_object)))
					WS_THROW("[VULKAN] Failed To End Command Buffer Recording");
			}

			void VKCommandBuffer::Submit(const VkSemaphore& waitSemaphore) const WS_NOEXCEPT
			{
				VkPipelineStageFlags waitStages[] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };

				VkSubmitInfo submitInfo{};
				submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
				submitInfo.waitSemaphoreCount   = 1;
				submitInfo.pWaitSemaphores      = &waitSemaphore;
				submitInfo.pWaitDstStageMask    = waitStages;
				submitInfo.commandBufferCount   = 1;
				submitInfo.pCommandBuffers      = &this->m_object;
				submitInfo.signalSemaphoreCount = 1;
				submitInfo.pSignalSemaphores    = this->m_submitedSemaphore.GetPtr();

				this->m_submitedfence.Reset();

				if (VK_FAILED(vkQueueSubmit(*this->m_pQueue, 1, &submitInfo, this->m_submitedfence)))
					WS_THROW("[VULKAN] Failed To Submit CommandBuffer");
			}

			void VKCommandBuffer::BindPipeline(const VKRenderPipeline& pipeline) WS_NOEXCEPT
			{
				vkCmdBindPipeline(this->m_object, VK_PIPELINE_BIND_POINT_GRAPHICS, *pipeline.GetPtr());
			}

			void VKCommandBuffer::WaitForCompletion() WS_NOEXCEPT
			{
				this->m_submitedfence.Wait();
				this->m_submitedfence.Reset();
			}

			[[nodiscard]] inline VkSemaphore VKCommandBuffer::GetSubmittedSemaphore() const WS_NOEXCEPT { return this->m_submitedSemaphore; }

			/*
			 * // ///////////////////--\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||-------------VKRenderAPI-------------|| \\
			 * // |\_____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\--//////////////////// \\
			 */

			VKRenderAPI::~VKRenderAPI()
			{
				
			}

			void VKRenderAPI::InitRenderAPI(Window* pWindow, const uint16_t maxFps) WS_NOEXCEPT
			{
				this->m_instance      = VKInstance("App Made With Weiss Engine");
				this->m_surface       = VKSurface(this->m_instance, pWindow);
				this->m_device        = VKDevice(this->m_instance, this->m_surface);
				this->m_presentQueue  = VKQueue(this->m_device, *this->m_device.GetPhysicalDeviceData().presentQueueIndex);
				this->m_swapChain     = VKSwapChain(this->m_device, this->m_surface, this->m_presentQueue);
				this->m_commandPool   = VKCommandPool(this->m_device, *this->m_device.GetPhysicalDeviceData().graphicsQueueIndex);
				this->m_gfxQueue      = VKQueue(this->m_device, *this->m_device.GetPhysicalDeviceData().graphicsQueueIndex);
				this->m_commandBuffer = VKCommandBuffer(this->m_device, this->m_commandPool, this->m_gfxQueue);

				WS::Internal::VK::VKRenderPass::CreateRenderPasses(this->m_device, this->m_swapChain);

				this->m_swapChain.CreateFrameBuffers();
			}

			void VKRenderAPI::InitPipelines(const std::vector<RenderPipelineDesc>& pipelineDescs) WS_NOEXCEPT
			{
				for (const RenderPipelineDesc& pipelineDesc : pipelineDescs)
					this->m_renderPipelines.emplace_back(this->m_device, this->m_swapChain, pipelineDesc, this->m_pConstantBuffers, this->m_pTextures, this->m_textureSamplers);
			}

			void VKRenderAPI::Draw(const Drawable& drawable, const size_t nVertices) WS_NOEXCEPT
			{
				this->m_commandBuffer.BindPipeline(this->m_renderPipelines[0]);
				vkCmdDraw(this->m_commandBuffer, 3u, 1u, 0u, 0u);
			}

			void VKRenderAPI::BeginDrawing() WS_NOEXCEPT
			{
				this->m_commandBuffer.WaitForCompletion();

				this->m_swapChain.GetNextFrameBuffer();

				this->m_commandBuffer.BeginRecording();
				this->m_commandBuffer.BeginRenderPass(this->m_swapChain, this->m_swapChain.GetCurrentFrameBuffer(), VKRenderPass::m_renderPasses[0]);
			}

			void VKRenderAPI::EndDrawing() WS_NOEXCEPT
			{
				this->m_commandBuffer.EndRenderPass();
				this->m_commandBuffer.EndRecording();

				this->m_commandBuffer.Submit(this->m_swapChain.GetFrameBufferFetchedSemaphore());
			}

			void VKRenderAPI::Present(const bool vSync) WS_NOEXCEPT
			{
				this->m_swapChain.Present(vSync, this->m_commandBuffer.GetSubmittedSemaphore());
			}

			size_t VKRenderAPI::CreateVertexBuffer(const size_t nVertices, const size_t vertexSize) WS_NOEXCEPT
			{
				return 0u;
			}

			size_t VKRenderAPI::CreateIndexBuffer(const size_t nIndices) WS_NOEXCEPT
			{
				return 0u;
			}

			size_t VKRenderAPI::CreateConstantBuffer(const size_t objSize, const size_t slot) WS_NOEXCEPT
			{
				return 0u;
			}

			size_t VKRenderAPI::CreateTexture(const size_t width, const size_t height, const size_t slot, const bool useMipmaps) WS_NOEXCEPT
			{
				return 0u;
			}

			size_t VKRenderAPI::CreateTextureSampler(const TextureFilter& filter, const size_t slot) WS_NOEXCEPT
			{
				return 0u;
			}

			void VKRenderAPI::Fill(const Colorf32& color) WS_NOEXCEPT
			{

			}

		}; // namespace VK

		/*
		 * // /////////////////////-\\\\\\\\\\\\\\\\\\\\\ \\
		 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
		 * // ||-----------------D3D11-----------------|| \\
		 * // |\_______________________________________/| \\
		 * // \\\\\\\\\\\\\\\\\\\\\-///////////////////// \\ 
		 */

		namespace D3D11 {

			/*
			 * // /////////////////////-\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D11ObjectWrapper<T>---------|| \\
			 * // |\_______________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\-///////////////////// \\ 
			 */

			template <typename T>
			D3D11ObjectWrapper<T>& D3D11ObjectWrapper<T>::operator=(D3D11ObjectWrapper<T>&& other)
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;

				return *this;
			}

			template <typename T>
			D3D11ObjectWrapper<T>::~D3D11ObjectWrapper()
			{
				if (this->m_pObject)
				{
					this->m_pObject->Release();
					this->m_pObject = nullptr;
				}
			}

			/*
			 * // ////////////////////--\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------D3D11SwapChain------------|| \\
			 * // |\______________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\--//////////////////// \\ 
			 */

			D3D11SwapChain::D3D11SwapChain(D3D11DeviceObjectWrapper& pDevice, Window* pWindow) WS_NOEXCEPT
			{
				Microsoft::WRL::ComPtr<IDXGIDevice>  dxgiDevice;
				Microsoft::WRL::ComPtr<IDXGIAdapter> dxgiAdapter;
				Microsoft::WRL::ComPtr<IDXGIFactory> dxgiFactory;

				if (DX_FAILED(pDevice->QueryInterface(IID_PPV_ARGS(&dxgiDevice))))
					WS_THROW("Could Not Get IDXGIDevice From D3D11Device");

				if (DX_FAILED(dxgiDevice->GetAdapter(dxgiAdapter.GetAddressOf())))
					WS_THROW("Could Not Get DXGIAdapter From DXGIDevice");

				if (DX_FAILED(dxgiAdapter->GetParent(__uuidof(IDXGIFactory), &dxgiFactory)))
					WS_THROW("Could Not Get DXGIAdapter's Parent");

				DXGI_SWAP_CHAIN_DESC scd{};
				scd.BufferDesc.Width  = 0;
				scd.BufferDesc.Height = 0;
				scd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
				scd.BufferDesc.RefreshRate.Numerator   = 0;
				scd.BufferDesc.RefreshRate.Denominator = 0;
				scd.BufferDesc.Scaling          = DXGI_MODE_SCALING_UNSPECIFIED;
				scd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
				scd.SampleDesc.Count   = 1;
				scd.SampleDesc.Quality = 0;
				scd.BufferUsage  = DXGI_USAGE_RENDER_TARGET_OUTPUT;
				scd.BufferCount  = WEISS__FRAME_BUFFER_COUNT;
				scd.OutputWindow = reinterpret_cast<WS::Internal::WIN::WindowsWindow*>(pWindow)->GetHandle();
				scd.Windowed     = TRUE;
				scd.SwapEffect   = DXGI_SWAP_EFFECT_DISCARD;
				scd.Flags = 0;

				if (DX_FAILED(dxgiFactory->CreateSwapChain(pDevice, &scd, &this->m_pObject)))
					WS_THROW("[DIRECTX 11] Failed To Create Swap Chain");
			}

			D3D11SwapChain& D3D11SwapChain::operator=(D3D11SwapChain&& other) WS_NOEXCEPT
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;

				return *this;
			}

			void D3D11SwapChain::Present(const bool vSync) WS_NOEXCEPT
			{
				if (DX_FAILED(this->m_pObject->Present(vSync ? 1u : 0u, 0u)))
					WS_THROW("Failed To Swap Buffers");
			}

			/*
			 * // //////////////////////-\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------D3D11RenderTarget------------|| \\
			 * // |\_________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\-////////////////////// \\ 
			 */

			D3D11RenderTarget::D3D11RenderTarget(D3D11DeviceObjectWrapper& pDevice, D3D11SwapChainObjectWrapper& pSwapChain) WS_NOEXCEPT
			{
				Microsoft::WRL::ComPtr<ID3D11Resource> pBackBuffer;

				if (DX_FAILED(pSwapChain->GetBuffer(0, __uuidof(ID3D11Resource), &pBackBuffer)))
					WS_THROW("[DIRECTX 11] Could Not Get BackBuffer");

				if (DX_FAILED(pDevice->CreateRenderTargetView(pBackBuffer.Get(), nullptr, &this->m_pObject)))
					WS_THROW("[DIRECTX 11] Could Not Create RenderTargetView");
			}

			D3D11RenderTarget& D3D11RenderTarget::operator=(D3D11RenderTarget&& other) WS_NOEXCEPT
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;

				return *this;
			}

			void D3D11RenderTarget::SetCurrent(D3D11DeviceContextObjectWrapper& pDeviceContext) const WS_NOEXCEPT
			{
				pDeviceContext->OMSetRenderTargets(1u, &this->m_pObject, NULL);
			}

			/*
			 * // /////////////////////--\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------D3D11DepthBuffer------------|| \\
			 * // |\________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\--///////////////////// \\ 
			 */

			D3D11DepthBuffer::D3D11DepthBuffer(Window* pWindow, D3D11DeviceObjectWrapper& pDevice) WS_NOEXCEPT
			{
				D3D11_DEPTH_STENCIL_DESC dsDesc = {};
				dsDesc.DepthEnable      = TRUE;
				dsDesc.DepthWriteMask   = D3D11_DEPTH_WRITE_MASK_ALL;
				dsDesc.DepthFunc        = D3D11_COMPARISON_LESS;
				dsDesc.StencilReadMask  = 0xFF;
				dsDesc.StencilWriteMask = 0xFF;
				dsDesc.FrontFace.StencilFailOp      = D3D11_STENCIL_OP_KEEP;
				dsDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
				dsDesc.FrontFace.StencilPassOp      = D3D11_STENCIL_OP_KEEP;
				dsDesc.FrontFace.StencilFunc        = D3D11_COMPARISON_ALWAYS;
				dsDesc.BackFace.StencilFailOp       = D3D11_STENCIL_OP_KEEP;
				dsDesc.BackFace.StencilDepthFailOp  = D3D11_STENCIL_OP_DECR;
				dsDesc.BackFace.StencilPassOp       = D3D11_STENCIL_OP_KEEP;
				dsDesc.BackFace.StencilFunc         = D3D11_COMPARISON_ALWAYS;

				if (DX_FAILED(pDevice->CreateDepthStencilState(&dsDesc, &this->m_pDepthStencilState)))
					WS_THROW("Could Not Create DepthStencilState");

				Microsoft::WRL::ComPtr<ID3D11Texture2D> pDepthStencil;
				D3D11_TEXTURE2D_DESC descDepth = {};
				descDepth.Width  = pWindow->GetClientWidth();
				descDepth.Height = pWindow->GetClientHeight();
				descDepth.MipLevels = 1u;
				descDepth.ArraySize = 1u;
				descDepth.Format    = DXGI_FORMAT_D32_FLOAT;
				descDepth.SampleDesc.Count   = 1u;
				descDepth.SampleDesc.Quality = 0u;
				descDepth.Usage     = D3D11_USAGE_DEFAULT;
				descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;

				if (DX_FAILED(pDevice->CreateTexture2D(&descDepth, nullptr, &pDepthStencil)))
					WS_THROW("Could Not Create Texture2D");

				D3D11_DEPTH_STENCIL_VIEW_DESC descDSV = {};
				descDSV.Format             = DXGI_FORMAT_D32_FLOAT;
				descDSV.ViewDimension      = D3D11_DSV_DIMENSION_TEXTURE2D;
				descDSV.Texture2D.MipSlice = 0u;

				if (DX_FAILED(pDevice->CreateDepthStencilView(pDepthStencil.Get(), &descDSV, &this->m_pDepthStencilView)))
					WS_THROW("Could Not Create DepthStencilView");
			}

			void D3D11DepthBuffer::Clear(D3D11DeviceContextObjectWrapper& pDeviceContext) WS_NOEXCEPT
			{
				pDeviceContext->ClearDepthStencilView(this->m_pDepthStencilView.Get(), D3D11_CLEAR_DEPTH, 1.0f, 0u);
			}

			void D3D11DepthBuffer::Bind(D3D11DeviceContextObjectWrapper& pDeviceContext, D3D11RenderTargetbjectWrapper& pRenderTarget) WS_NOEXCEPT
			{
				pDeviceContext->OMSetRenderTargets(1u, pRenderTarget.GetPtr(), this->m_pDepthStencilView.Get());
				pDeviceContext->OMSetDepthStencilState(this->m_pDepthStencilState.Get(), 1u);
			}

			/*
			 * // //////////////////////-\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------D3D11VertexShader------------|| \\
			 * // |\_________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\-////////////////////// \\ 
			 */

			D3D11VertexShader::D3D11VertexShader(D3D11DeviceObjectWrapper& pDevice,
										         D3D11DeviceContextObjectWrapper* pDeviceContext,
										         const char* sourceFilename, const std::vector<ShaderInputElement>& sies) WS_NOEXCEPT
				: m_pDeviceContext(pDeviceContext)
			{
				Microsoft::WRL::ComPtr<ID3DBlob> pBlob;

				// Create Shader
				std::ifstream fileStream(sourceFilename);
				std::string   sourceCode((std::istreambuf_iterator<char>(fileStream)), (std::istreambuf_iterator<char>()));

				if (D3DCompile(sourceCode.c_str(), sourceCode.size(), NULL, NULL, NULL, "main", "vs_5_0", 0, 0, &pBlob, NULL) != S_OK)
					WS_THROW("Could Not Compile Vertex Shader");

				if (pDevice->CreateVertexShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &this->m_pShader) != S_OK)
					WS_THROW("Could Not Create Vertex Shader");

				// Create Input Layout
				std::vector<D3D11_INPUT_ELEMENT_DESC> inputElementDescriptors(sies.size());
				for (uint32_t i = 0; i < inputElementDescriptors.size(); i++)
				{
					inputElementDescriptors[i] = D3D11_INPUT_ELEMENT_DESC{};
					inputElementDescriptors[i].SemanticName = sies[i].name;

					switch (sies[i].type)
					{
					case ShaderInputElementType::FLOAT_32:
						inputElementDescriptors[i].Format = DXGI_FORMAT::DXGI_FORMAT_R32_FLOAT;
						break;
					case ShaderInputElementType::UINT_32:
						inputElementDescriptors[i].Format = DXGI_FORMAT::DXGI_FORMAT_R32_UINT;
						break;
					case ShaderInputElementType::VECTOR_2D_FLOAT_32:
						inputElementDescriptors[i].Format = DXGI_FORMAT::DXGI_FORMAT_R32G32_FLOAT;
						break;
					case ShaderInputElementType::VECTOR_3D_FLOAT_32:
						inputElementDescriptors[i].Format = DXGI_FORMAT::DXGI_FORMAT_R32G32B32_FLOAT;
						break;
					case ShaderInputElementType::VECTOR_4D_FLOAT_32:
						inputElementDescriptors[i].Format = DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT;
						break;
					default:
						WS_THROW("Input Element Type Not Supported");
					}

					inputElementDescriptors[i].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
					inputElementDescriptors[i].InputSlotClass = D3D11_INPUT_CLASSIFICATION::D3D11_INPUT_PER_VERTEX_DATA;
				}

				if (pDevice->CreateInputLayout(inputElementDescriptors.data(), (UINT)inputElementDescriptors.size(), pBlob->GetBufferPointer(), pBlob->GetBufferSize(), &this->m_pInputLayout) != S_OK)
					WS_THROW("Could Not Create Input Layout");
			}

			void D3D11VertexShader::Bind() const WS_NOEXCEPT
			{
				(*this->m_pDeviceContext)->IASetInputLayout(this->m_pInputLayout.Get());
				(*this->m_pDeviceContext)->VSSetShader(this->m_pShader.Get(), nullptr, 0u);
			}

			/*
			 * // /////////////////////--\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------D3D11PixelShader------------|| \\
			 * // |\________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\--///////////////////// \\ 
			 */

			D3D11PixelShader::D3D11PixelShader(D3D11DeviceObjectWrapper& pDevice,
									   D3D11DeviceContextObjectWrapper* pDeviceContext,
									   const char* sourceFilename) WS_NOEXCEPT
				: m_pDeviceContext(pDeviceContext)
			{
				Microsoft::WRL::ComPtr<ID3DBlob> pBlob;

				std::ifstream fileStream(sourceFilename);
				std::string sourceCode((std::istreambuf_iterator<char>(fileStream)), (std::istreambuf_iterator<char>()));

				if (D3DCompile(sourceCode.c_str(), sourceCode.size(), NULL, NULL, NULL, "main", "ps_5_0", 0, 0, &pBlob, NULL) != S_OK)
					WS_THROW("Could Not Compile Pixel Shader");

				if (pDevice->CreatePixelShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &this->m_pShader) != S_OK)
					WS_THROW("Could Not Create Pixel Shader");
				}

			void D3D11PixelShader::Bind() const WS_NOEXCEPT
			{
				(*this->m_pDeviceContext)->PSSetShader(this->m_pShader.Get(), nullptr, 0u);
			}

			/*
			 * // //////////////////////-\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------D3D11VertexBuffer------------|| \\
			 * // |\_________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\-////////////////////// \\ 
			 */

			D3D11VertexBuffer::D3D11VertexBuffer(D3D11DeviceObjectWrapper& pDevice,
												 D3D11DeviceContextObjectWrapper* pDeviceContext,
												 const size_t nVertices, const size_t vertexSize) WS_NOEXCEPT
				: m_vertexSize(vertexSize), m_pDeviceContext(pDeviceContext)
			{
				D3D11_BUFFER_DESC bd = {};
				bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
				bd.Usage = D3D11_USAGE_DYNAMIC;
				bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
				bd.MiscFlags = 0u;
				bd.ByteWidth = static_cast<UINT>(nVertices * this->m_vertexSize);
				bd.StructureByteStride = static_cast<UINT>(this->m_vertexSize);

				this->m_vertexData.resize(bd.ByteWidth);
				std::memset(this->m_vertexData.data(), 0, bd.ByteWidth);

				if (DX_FAILED(pDevice->CreateBuffer(&bd, nullptr, &this->m_pObject)))
					WS_THROW("Unable To Create Vertex Buffer");
			}

			D3D11VertexBuffer& D3D11VertexBuffer::operator=(D3D11VertexBuffer&& other) noexcept
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;
				this->m_vertexData = std::move(other.m_vertexData);
				this->m_vertexSize = std::move(other.m_vertexSize);

				return *this;
			}

			void D3D11VertexBuffer::Bind() WS_NOEXCEPT
			{
				const UINT stride = static_cast<UINT>(this->m_vertexSize);
				const UINT offset = 0u;

				(*this->m_pDeviceContext)->IASetVertexBuffers(0u, 1u, &this->m_pObject, &stride, &offset);
			}

			void D3D11VertexBuffer::Update() WS_NOEXCEPT
			{
				D3D11_MAPPED_SUBRESOURCE resource;
				if (DX_FAILED((*this->m_pDeviceContext)->Map(this->m_pObject, 0, D3D11_MAP_WRITE_DISCARD, 0, &resource)))
					WS_THROW("Could Not Map Vertex Buffer Memory");

				std::memcpy(resource.pData, this->m_vertexData.data(), this->m_vertexData.size());
				(*this->m_pDeviceContext)->Unmap(this->m_pObject, 0);
			}

			/*
			 * // /////////////////////--\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------D3D11IndexBuffer------------|| \\
			 * // |\________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\--///////////////////// \\ 
			 */

			D3D11IndexBuffer::D3D11IndexBuffer(D3D11DeviceObjectWrapper& pDevice,
											   D3D11DeviceContextObjectWrapper* pDeviceContext,
											   const size_t nIndices) WS_NOEXCEPT
				: m_nIndices(nIndices), m_pDeviceContext(pDeviceContext)
			{
				D3D11_BUFFER_DESC bd = {};
				bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
				bd.Usage = D3D11_USAGE_DYNAMIC;
				bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
				bd.MiscFlags = 0u;
				bd.ByteWidth = static_cast<UINT>(this->m_nIndices * sizeof(uint32_t));
				bd.StructureByteStride = static_cast<UINT>(sizeof(uint32_t));

				this->m_indexData.resize(bd.ByteWidth);
				std::memset(this->m_indexData.data(), 0, bd.ByteWidth);

				if (DX_FAILED(pDevice->CreateBuffer(&bd, nullptr, &this->m_pObject)))
					WS_THROW("Unable To Create Index Buffer");
			}

			D3D11IndexBuffer& D3D11IndexBuffer::operator=(D3D11IndexBuffer&& other) WS_NOEXCEPT
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;
			
				other.m_nIndices  = other.m_nIndices;
				other.m_indexData = std::move(other.m_indexData);

				return *this;
			}

			void D3D11IndexBuffer::Bind() WS_NOEXCEPT
			{
				(*this->m_pDeviceContext)->IASetIndexBuffer(this->m_pObject, DXGI_FORMAT_R32_UINT, 0u);
			}

			void D3D11IndexBuffer::Update() WS_NOEXCEPT
			{
				D3D11_MAPPED_SUBRESOURCE resource;
				if (DX_FAILED((*this->m_pDeviceContext)->Map(this->m_pObject, 0, D3D11_MAP_WRITE_DISCARD, 0, &resource)))
					WS_THROW("Could Not Map Index Buffer Memory");

				std::memcpy(resource.pData, this->m_indexData.data(), this->m_indexData.size());
				(*this->m_pDeviceContext)->Unmap(this->m_pObject, 0);
			}

			/*
			 * // ///////////////////////-\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------D3D11ConstantBuffer------------|| \\
			 * // |\___________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\-/////////////////////// \\ 
			 */

			D3D11ConstantBuffer::D3D11ConstantBuffer(D3D11DeviceObjectWrapper& pDevice,
													 D3D11DeviceContextObjectWrapper* pDeviceContext,
													 const size_t objSize, const size_t slot) WS_NOEXCEPT
				: m_objSize(objSize), m_slot(slot), m_pDeviceContext(pDeviceContext)
			{
				D3D11_BUFFER_DESC bd = {};
				bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
				bd.Usage = D3D11_USAGE_DYNAMIC;
				bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
				bd.MiscFlags = 0u;
				bd.ByteWidth = static_cast<UINT>(this->m_objSize);

				this->m_constantBufferData.resize(bd.ByteWidth);
				std::memset(this->m_constantBufferData.data(), 0, bd.ByteWidth);

				if (DX_FAILED(pDevice->CreateBuffer(&bd, nullptr, &this->m_pObject)))
					WS_THROW("[DIRECTX 11] Unable To Create Constant Buffer");
			}

			D3D11ConstantBuffer& D3D11ConstantBuffer::operator=(D3D11ConstantBuffer&& other) WS_NOEXCEPT
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;

				this->m_slot    = other.m_slot;
				this->m_objSize = other.m_objSize;
				this->m_constantBufferData = std::move(other.m_constantBufferData);
				
				return *this;
			}

			void D3D11ConstantBuffer::Bind() WS_NOEXCEPT
			{
				(*this->m_pDeviceContext)->VSSetConstantBuffers((UINT)this->m_slot, 1u, &this->m_pObject);
			}

			void D3D11ConstantBuffer::Update() WS_NOEXCEPT
			{
				D3D11_MAPPED_SUBRESOURCE resource;
				if (DX_FAILED((*this->m_pDeviceContext)->Map(this->m_pObject, 0u, D3D11_MAP_WRITE_DISCARD, 0u, &resource)))
					WS_THROW("[DIRECTX 11] Failed To Map Constant Buffer Memory");

				std::memcpy(resource.pData, this->m_constantBufferData.data(), this->m_objSize);
				(*this->m_pDeviceContext)->Unmap(this->m_pObject, 0u);
			}

			/*
			 * // ///////////////////--\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------D3D11Texture------------|| \\
			 * // |\____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\--/////////////////// \\ 
			 */

			D3D11Texture::D3D11Texture(D3D11DeviceObjectWrapper& pDevice,
									   D3D11DeviceContextObjectWrapper* pDeviceContext,
									   const size_t width, const size_t height, const size_t slot, const bool useMipmaps) WS_NOEXCEPT
				: m_pDeviceContext(pDeviceContext), m_pDevice(&pDevice), m_slot(slot)
			{
				D3D11_TEXTURE2D_DESC texture2DDescriptor = {};
				texture2DDescriptor.Width     = static_cast<UINT>(width);
				texture2DDescriptor.Height    = static_cast<UINT>(height);
				texture2DDescriptor.MipLevels = useMipmaps ? 0 : 1;
				texture2DDescriptor.ArraySize = 1u;
				texture2DDescriptor.Format    = DXGI_FORMAT_R8G8B8A8_UNORM;
				texture2DDescriptor.SampleDesc.Count   = 1u;
				texture2DDescriptor.SampleDesc.Quality = 0;
				texture2DDescriptor.Usage     = D3D11_USAGE_DEFAULT;
				texture2DDescriptor.BindFlags = useMipmaps ? D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET : D3D11_BIND_SHADER_RESOURCE;
				texture2DDescriptor.MiscFlags = useMipmaps ? D3D11_RESOURCE_MISC_GENERATE_MIPS : 0;

				if (DX_FAILED(pDevice->CreateTexture2D(&texture2DDescriptor, nullptr, &this->m_texture2D)))
					WS_THROW("[DIRECTX 11] Failed To Create Texture");

				D3D11_SHADER_RESOURCE_VIEW_DESC SRVDescriptor = {};
				SRVDescriptor.Format                    = DXGI_FORMAT_R8G8B8A8_UNORM;
				SRVDescriptor.ViewDimension             = D3D11_SRV_DIMENSION_TEXTURE2D;
				SRVDescriptor.Texture2D.MostDetailedMip = 0;
				SRVDescriptor.Texture2D.MipLevels       = useMipmaps ? -1 : 1;

				if (DX_FAILED(pDevice->CreateShaderResourceView(this->m_texture2D.Get(), &SRVDescriptor, &this->m_pObject)))
					WS_THROW("[DIRECTX 11] Failed To Create Shader Resource View");
			}

			void D3D11Texture::Bind() const WS_NOEXCEPT
			{
				(*this->m_pDeviceContext)->VSSetShaderResources(static_cast<UINT>(this->m_slot), 1u, &this->m_pObject);
				(*this->m_pDeviceContext)->PSSetShaderResources(static_cast<UINT>(this->m_slot), 1u, &this->m_pObject);
			}

			void D3D11Texture::Update() WS_NOEXCEPT
			{
				D3D11_SUBRESOURCE_DATA* subResourceData = new D3D11_SUBRESOURCE_DATA();
				subResourceData->pSysMem          = static_cast<void*>(this->m_image.GetBuffer());
				subResourceData->SysMemPitch      = this->m_image.GetWidth() * sizeof(Coloru8);
				subResourceData->SysMemSlicePitch = 0;

				this->m_pDeviceContext->Get()->UpdateSubresource(this->m_texture2D.Get(), 0u, nullptr, subResourceData->pSysMem, subResourceData->SysMemPitch, 0u);

				if (this->m_useMipmaps)
					this->m_pDeviceContext->Get()->GenerateMips(this->m_pObject);
			}

			/*
			 * // ////////////////////-\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D11TextureSampler---------|| \\
			 * // |\_____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\-//////////////////// \\ 
			 */

			D3D11TextureSampler::D3D11TextureSampler(D3D11DeviceObjectWrapper& pDevice,
													 D3D11DeviceContextObjectWrapper* pDeviceContext,
													 const TextureFilter& filter, const size_t slot) WS_NOEXCEPT
				: m_pDeviceContext(pDeviceContext), m_slot(slot)
			{
				D3D11_SAMPLER_DESC samplerDescriptor;

				switch (filter)
				{
				case TextureFilter::POINT:
					samplerDescriptor.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
					break;
				case TextureFilter::BILINEAR:
					samplerDescriptor.Filter = D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT;
					break;
				case TextureFilter::TRILINEAR:
					samplerDescriptor.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
					break;
				default:
					WS_THROW("[DIRECTX 11] Your Filtering Method Is Not Supported");
				}

				samplerDescriptor.AddressU = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
				samplerDescriptor.AddressV = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
				samplerDescriptor.AddressW = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
				samplerDescriptor.MaxAnisotropy = D3D11_MAX_MAXANISOTROPY;
				samplerDescriptor.ComparisonFunc = D3D11_COMPARISON_NEVER;
				samplerDescriptor.MipLODBias = 0.0f;
				samplerDescriptor.MinLOD = 0.0f;
				samplerDescriptor.MaxLOD = D3D11_FLOAT32_MAX;

				if (DX_FAILED(pDevice->CreateSamplerState(&samplerDescriptor, &this->m_pObject)))
					WS_THROW("[DIRECTX 11] Failed To Create Sampler State");
			}

			void D3D11TextureSampler::Bind() const WS_NOEXCEPT
			{
				(*this->m_pDeviceContext)->VSSetSamplers(static_cast<UINT>(this->m_slot), 1u, &this->m_pObject);
				(*this->m_pDeviceContext)->PSSetSamplers(static_cast<UINT>(this->m_slot), 1u, &this->m_pObject);
			}

			/*
			 * // ////////////////////-\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D11RenderPipeline---------|| \\
			 * // |\_____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\-//////////////////// \\ 
			 */

			D3D11RenderPipeline::D3D11RenderPipeline(D3D11DeviceObjectWrapper& pDevice,
													 D3D11DeviceContextObjectWrapper* pDeviceContext,
													 const RenderPipelineDesc& desc) WS_NOEXCEPT
				: m_pDeviceContext(pDeviceContext),      m_constantBufferIndices(desc.constantBufferIndices),
				m_textureIndices(desc.textureIndices), m_textureSamplerIndices(desc.textureSamplerIndices)
			{
				switch (desc.topology)
				{
				case PrimitiveTopology::TRIANGLES:
					this->m_topology = D3D11_PRIMITIVE_TOPOLOGY::D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
					break;
				case PrimitiveTopology::TRIANGLE_STRIP:
					this->m_topology = D3D11_PRIMITIVE_TOPOLOGY::D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;
					break;
				default:
					WS_THROW("[DIRECTX 11] Requested Primitive Topology Is Not Supported");
					break;
				}

				this->m_pVertexShader = D3D11VertexShader(pDevice, pDeviceContext, desc.vsFilename, desc.sies);
				this->m_pPixelShader  = D3D11PixelShader(pDevice, pDeviceContext, desc.psFilename);
			}

			void D3D11RenderPipeline::Bind(std::vector<ConstantBuffer*>& constantBuffers,
										   std::vector<Texture*>& textures,
										   std::vector<D3D11TextureSampler*> textureSamplers) WS_NOEXCEPT
			{
				this->m_pVertexShader.Bind();
				this->m_pPixelShader.Bind();

				for (uint32_t cbIndex : this->m_constantBufferIndices)
					dynamic_cast<D3D11ConstantBuffer*>(constantBuffers[cbIndex])->Bind();

				for (uint32_t texIndex : this->m_textureIndices)
					dynamic_cast<D3D11Texture*>(textures[texIndex])->Bind();

				for (uint32_t texSamplerIndex : this->m_textureSamplerIndices)
					textureSamplers[texSamplerIndex]->Bind();

				(*this->m_pDeviceContext)->IASetPrimitiveTopology(this->m_topology);
			}

			/*
			 * // /////////////////--\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D11RenderAPI---------|| \\
			 * // |\________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\--///////////////// \\ 
			 */

			void D3D11RenderAPI::InitRenderAPI(Window* pWindow, const uint16_t maxFps) WS_NOEXCEPT
			{
				if (D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0, D3D11_SDK_VERSION, this->m_pDevice.GetPtr(), nullptr, this->m_pDeviceContext.GetPtr()) != S_OK)
					WS_THROW("Could Not Create Device");

				this->m_pSwapChain    = D3D11SwapChain(this->m_pDevice, pWindow);
				this->m_pRenderTarget = D3D11RenderTarget(this->m_pDevice, this->m_pSwapChain);
				this->m_pDepthBuffer  = D3D11DepthBuffer(pWindow, this->m_pDevice);

				this->m_pRenderTarget.SetCurrent(this->m_pDeviceContext);

				// Create Viewport
				D3D11_VIEWPORT vp;
				vp.Width    = static_cast<FLOAT>(pWindow->GetClientWidth());
				vp.Height   = static_cast<FLOAT>(pWindow->GetClientHeight());
				vp.MinDepth = 0;
				vp.MaxDepth = 1;
				vp.TopLeftX = 0;
				vp.TopLeftY = 0;

				this->m_pDeviceContext->RSSetViewports(1u, &vp);

				this->m_pDepthBuffer.Bind(this->m_pDeviceContext, this->m_pRenderTarget);
			}

			void D3D11RenderAPI::InitPipelines(const std::vector<RenderPipelineDesc>& pipelineDescs) WS_NOEXCEPT
			{
				this->m_pRenderPipelines.reserve(pipelineDescs.size());
				for (const RenderPipelineDesc& pipelineDesc : pipelineDescs)
					this->m_pRenderPipelines.emplace_back(this->m_pDevice, &this->m_pDeviceContext, pipelineDesc);
			}

			void D3D11RenderAPI::Draw(const Drawable& drawable, const size_t nVertices) WS_NOEXCEPT
			{
				this->m_pRenderPipelines[drawable.pipelineIndex].Bind(this->m_pConstantBuffers, this->m_pTextures, this->m_pTextureSamplers);
				dynamic_cast<D3D11VertexBuffer*>(this->m_pVertexBuffers[drawable.vertexBufferIndex])->Bind();

				if (drawable.indexBufferIndex.has_value()) {
					dynamic_cast<D3D11IndexBuffer*>(this->m_pIndexBuffers[drawable.indexBufferIndex.value()])->Bind();

					this->m_pDeviceContext->DrawIndexed(static_cast<UINT>(nVertices), 0u, 0u);
				} else {
					this->m_pDeviceContext->Draw(static_cast<UINT>(nVertices), 0u);
				}
			}

			void D3D11RenderAPI::BeginDrawing() WS_NOEXCEPT
			{
				this->Fill();
			}

			void D3D11RenderAPI::EndDrawing() WS_NOEXCEPT
			{
				this->m_pDepthBuffer.Clear(this->m_pDeviceContext);
			}

			void D3D11RenderAPI::Present(const bool vSync) WS_NOEXCEPT
			{
				this->m_pSwapChain.Present(vSync);
			}

			size_t D3D11RenderAPI::CreateVertexBuffer(const size_t nVertices, const size_t vertexSize) WS_NOEXCEPT
			{
				this->m_pVertexBuffers.push_back(new D3D11VertexBuffer(this->m_pDevice, &this->m_pDeviceContext, nVertices, vertexSize));

				return this->m_pVertexBuffers.size() - 1u;
			}

			size_t D3D11RenderAPI::CreateIndexBuffer(const size_t nIndices) WS_NOEXCEPT
			{
				this->m_pIndexBuffers.push_back(new D3D11IndexBuffer(this->m_pDevice, &this->m_pDeviceContext, nIndices));

				return this->m_pIndexBuffers.size() - 1u;
			}

			size_t D3D11RenderAPI::CreateConstantBuffer(const size_t objSize, const size_t slot) WS_NOEXCEPT
			{
				this->m_pConstantBuffers.push_back(new D3D11ConstantBuffer(this->m_pDevice, &this->m_pDeviceContext, objSize, slot));

				return this->m_pConstantBuffers.size() - 1u;
			}

			size_t D3D11RenderAPI::CreateTexture(const size_t width, const size_t height, const size_t slot, const bool useMipmaps) WS_NOEXCEPT
			{
				this->m_pTextures.push_back(new D3D11Texture(this->m_pDevice, &this->m_pDeviceContext, width, height, slot, useMipmaps));

				return this->m_pTextures.size() - 1u;
			}

			size_t D3D11RenderAPI::CreateTextureSampler(const TextureFilter& filter, const size_t slot) WS_NOEXCEPT
			{
				this->m_pTextureSamplers.push_back(new D3D11TextureSampler(this->m_pDevice, &this->m_pDeviceContext, filter, slot));

				return this->m_pTextureSamplers.size() - 1u;
			}

			void D3D11RenderAPI::Fill(const Colorf32& color) WS_NOEXCEPT
			{
				this->m_pDeviceContext->ClearRenderTargetView(this->m_pRenderTarget, (float*)&color);
			}

		}; // namespace D3D11

		/*
		 * // /////////////////////-\\\\\\\\\\\\\\\\\\\\\ \\
		 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
		 * // ||-----------------D3D12-----------------|| \\
		 * // |\_______________________________________/| \\
		 * // \\\\\\\\\\\\\\\\\\\\\-///////////////////// \\ 
		 */

		namespace D3D12 {

			/*
			 * // /////////////////////-\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12ObjectWrapper<T>---------|| \\
			 * // |\_______________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\-///////////////////// \\ 
			 */

			template <typename T>
			D3D12ObjectWrapper<T>& D3D12ObjectWrapper<T>::operator=(D3D12ObjectWrapper<T>&& other) WS_NOEXCEPT
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;

				return *this;
			}

			template <typename T>
			D3D12ObjectWrapper<T>::~D3D12ObjectWrapper()
			{
				if (this->m_pObject)
				{
					this->m_pObject->Release();
					this->m_pObject = nullptr;
				}
			}

			/*
			 * // ////////////////--\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12Adapter---------|| \\
			 * // |\______________________________/| \\
			 * // \\\\\\\\\\\\\\\\--//////////////// \\ 
			 */

			D3D12Adapter::D3D12Adapter()
			{
				IDXGIFactory4* dxgiFactory;
				if (DX_FAILED(CreateDXGIFactory1(IID_PPV_ARGS(&dxgiFactory))))
					WS_THROW("[DIRECTX 12] Failed To Create DXGIFactory1");

				int adapterIndex = 0;

				while (dxgiFactory->EnumAdapters1(adapterIndex, &this->m_pObject) != DXGI_ERROR_NOT_FOUND)
				{
					DXGI_ADAPTER_DESC1 desc;
					this->m_pObject->GetDesc1(&desc);

					if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
						continue;
					
					if (SUCCEEDED(D3D12CreateDevice(this->m_pObject, D3D_FEATURE_LEVEL_12_1, _uuidof(ID3D12Device2), nullptr)))
						return;

					adapterIndex++;
				}

				WS_THROW("[DIRECTX 12] Failed To Create Adapter");
			}

			D3D12Adapter& D3D12Adapter::operator=(D3D12Adapter&& other) WS_NOEXCEPT
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;

				return *this;
			}

			/*
			 * // ////////////////-\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12Device---------|| \\
			 * // |\_____________________________/| \\
			 * // \\\\\\\\\\\\\\\\-//////////////// \\ 
			 */

			D3D12Device::D3D12Device(D3D12AdapterObjectWrapper& pAdapter) WS_NOEXCEPT
			{
				if (DX_FAILED(D3D12CreateDevice(pAdapter, D3D_FEATURE_LEVEL_12_1, IID_PPV_ARGS(&this->m_pObject))))
					WS_THROW("[D3D12] Failed To Create Device");

#ifdef __WEISS__DEBUG_MODE

				Microsoft::WRL::ComPtr<ID3D12InfoQueue> pInfoQueue;
				if (SUCCEEDED(this->m_pObject->QueryInterface(IID_PPV_ARGS(&pInfoQueue))))
				{
					pInfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_CORRUPTION, TRUE);
					pInfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_ERROR, TRUE);
					pInfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_WARNING, TRUE);

					//D3D12_MESSAGE_CATEGORY Categories[] = {};

					D3D12_MESSAGE_SEVERITY Severities[] =
					{
						D3D12_MESSAGE_SEVERITY_INFO
					};

					D3D12_MESSAGE_ID DenyIds[] = {
						D3D12_MESSAGE_ID_CLEARRENDERTARGETVIEW_MISMATCHINGCLEARVALUE,   
						D3D12_MESSAGE_ID_MAP_INVALID_NULLRANGE,                         
						D3D12_MESSAGE_ID_UNMAP_INVALID_NULLRANGE,                      
					};

					D3D12_INFO_QUEUE_FILTER NewFilter = {};
					NewFilter.DenyList.NumSeverities = _countof(Severities);
					NewFilter.DenyList.pSeverityList = Severities;
					NewFilter.DenyList.NumIDs        = _countof(DenyIds);
					NewFilter.DenyList.pIDList       = DenyIds;

					if (pInfoQueue->PushStorageFilter(&NewFilter) != S_OK)
						WS_THROW("[D3D12] Could Not Push Storage FIlter");
				}

#endif // __WEISS__DEBUG_MODE
			}

			D3D12Device& D3D12Device::operator=(D3D12Device&& other) WS_NOEXCEPT
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;

				return *this;
			}

			/*
			 * // ///////////////--\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12Fence---------|| \\
			 * // |\____________________________/| \\
			 * // \\\\\\\\\\\\\\\--/////////////// \\ 
			 */

			D3D12Fence::D3D12Fence(D3D12DeviceObjectWrapper& pDevice, const UINT64 initialValue, const D3D12_FENCE_FLAGS flags) WS_NOEXCEPT
			{
				if (pDevice->CreateFence(initialValue, flags, IID_PPV_ARGS(&this->m_pObject)) != S_OK)
					WS_THROW("[DIRECTX 12] Failed To Create Fence");

				this->m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
				if (this->m_fenceEvent == nullptr)
					WS_THROW("[DIRECTX 12] Failed To Create Fence Event");
			}

			D3D12Fence::~D3D12Fence() WS_NOEXCEPT
			{
				CloseHandle(this->m_fenceEvent);
			}

			D3D12Fence& D3D12Fence::operator=(D3D12Fence&& other) WS_NOEXCEPT
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;

				return *this;
			}

			/*
			 * // ///////////////////-\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12CommandQueue---------|| \\
			 * // |\___________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\-/////////////////// \\ 
			 */

			D3D12CommandQueue::D3D12CommandQueue(D3D12DeviceObjectWrapper& pDevice, const D3D12_COMMAND_LIST_TYPE& type) WS_NOEXCEPT
			{
				D3D12_COMMAND_QUEUE_DESC desc = {};
				desc.Type     = type;
				desc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;
				desc.Flags    = D3D12_COMMAND_QUEUE_FLAG_NONE;
				desc.NodeMask = 0;

				if (DX_FAILED(pDevice->CreateCommandQueue(&desc, IID_PPV_ARGS(&this->m_pObject))))
					WS_THROW("[D3D12] Could Not Create Command Queue");
			}

			/*
			 * // /////////////////--\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12SwapChain---------|| \\
			 * // |\________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\--///////////////// \\ 
			 */

			D3D12SwapChain::D3D12SwapChain(D3D12DeviceObjectWrapper&       pDevice,
										   D3D12CommandQueueObjectWrapper& pCommandQueue,
										   const Window* pWindow, const uint16_t maxFps, const UINT bufferCount) WS_NOEXCEPT
			{
				Microsoft::WRL::ComPtr<IDXGIFactory4> dxgiFactory4;

				UINT createFactoryFlags = 0;

		#ifdef __WEISS__DEBUG_MODE

				createFactoryFlags = DXGI_CREATE_FACTORY_DEBUG;

		#endif // __WEISS__DEBUG_MODE

				if (DX_FAILED(CreateDXGIFactory2(createFactoryFlags, IID_PPV_ARGS(&dxgiFactory4))))
					WS_THROW("[D3D12] Could Not Create DXGIFactory2");
			
				DXGI_MODE_DESC backBufferDesc = {};
				backBufferDesc.Width  = pWindow->GetClientWidth();
				backBufferDesc.Height = pWindow->GetClientHeight();
				backBufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

				DXGI_SAMPLE_DESC sampleDesc = {};
				sampleDesc.Count = 1;

				DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
				swapChainDesc.BufferCount  = WEISS__FRAME_BUFFER_COUNT;
				swapChainDesc.BufferDesc   = backBufferDesc;
				swapChainDesc.BufferUsage  = DXGI_USAGE_RENDER_TARGET_OUTPUT;
				swapChainDesc.SwapEffect   = DXGI_SWAP_EFFECT_FLIP_DISCARD;
				swapChainDesc.OutputWindow = reinterpret_cast<const WS::Internal::WIN::WindowsWindow*>(pWindow)->GetHandle();
				swapChainDesc.SampleDesc   = sampleDesc;
				swapChainDesc.Windowed     = true; 
				swapChainDesc.Flags        = D3D12SwapChain::IsTearingSupported() ? DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING : 0;

				if (DX_FAILED(dxgiFactory4->CreateSwapChain(pCommandQueue, &swapChainDesc, (IDXGISwapChain**) &this->m_pObject)))
					WS_THROW("[DIRECTX 12] Failed To Create Swap Chain");
			}

			D3D12SwapChain& D3D12SwapChain::operator=(D3D12SwapChain&& other) noexcept
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;

				return *this;
			}

			void D3D12SwapChain::Present(const bool vSync) const WS_NOEXCEPT
			{
				if (DX_FAILED(this->m_pObject->Present(vSync ? 1u : 0u, 0u)))
					WS_THROW("[DIRECTX 12] Presentation Failed");
			}

			bool D3D12SwapChain::IsTearingSupported() WS_NOEXCEPT
			{
				BOOL isTearingSupported = FALSE;

				Microsoft::WRL::ComPtr<IDXGIFactory4> factory4;
				Microsoft::WRL::ComPtr<IDXGIFactory5> factory5;

				if (DX_FAILED(CreateDXGIFactory1(IID_PPV_ARGS(&factory4))))
					WS_THROW("[DIRECTX 12] Failed To Check Tearing (While Running CreateDXGIFactory1)");

				if (DX_FAILED(factory4.As(&factory5)))
					WS_THROW("[DIRECTX 12] Failed To Check Tearing (While Running CreateDXGIFactory1)");

				if (DX_FAILED(factory5->CheckFeatureSupport(DXGI_FEATURE_PRESENT_ALLOW_TEARING, &isTearingSupported, sizeof(isTearingSupported))))
					return false;

				return true;
			}

			/*
			 * // ////////////////////-\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12DescriptorHeap---------|| \\
			 * // |\_____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\-//////////////////// \\ 
			 */

			D3D12DescriptorHeap::D3D12DescriptorHeap(D3D12DeviceObjectWrapper& pDevice, const D3D12_DESCRIPTOR_HEAP_TYPE type, const uint32_t numDescriptors, const D3D12_DESCRIPTOR_HEAP_FLAGS& flags) WS_NOEXCEPT
			{
				D3D12_DESCRIPTOR_HEAP_DESC desc = {};
				desc.NumDescriptors = numDescriptors;
				desc.Type  = type;
				desc.Flags = flags;

				if (DX_FAILED(pDevice->CreateDescriptorHeap(&desc, IID_PPV_ARGS(&this->m_pObject))))
					WS_THROW("[D3D12] Could Not Create Descriptor Heap");
			}

			D3D12DescriptorHeap& D3D12DescriptorHeap::operator=(D3D12DescriptorHeap&& other) noexcept
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;

				return *this;
			}

			/*
			 * // ///////////////////-\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12RenderTarget---------|| \\
			 * // |\___________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\-/////////////////// \\ 
			 */

			D3D12RenderTarget::D3D12RenderTarget(D3D12DeviceObjectWrapper& pDevice,
												 D3D12SwapChainObjectWrapper& pSwapChain,
												 D3D12DescriptorHeapObjectWrapper& pDescriptorHeap,
												 const CD3DX12_CPU_DESCRIPTOR_HANDLE& rtvHandle,
												 const uint16_t frameIndex) WS_NOEXCEPT
			{
				if (pSwapChain->GetBuffer(frameIndex, IID_PPV_ARGS(&this->m_pObject)) != S_OK)
					WS_THROW("[DIRECTX 12] Failed To Get Back Buffer");

				pDevice->CreateRenderTargetView(this->m_pObject, nullptr, rtvHandle);
			}

			D3D12RenderTarget& D3D12RenderTarget::operator=(D3D12RenderTarget&& other) noexcept
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;

				return *this;
			}

			/*
			 * // /////////////////////-\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12CommandAllocator---------|| \\
			 * // |\_______________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\-///////////////////// \\ 
			 */

			D3D12CommandAllocator::D3D12CommandAllocator(D3D12DeviceObjectWrapper& pDevice, const D3D12_COMMAND_LIST_TYPE& type) WS_NOEXCEPT
			{
				if (pDevice->CreateCommandAllocator(type, IID_PPV_ARGS(&this->m_pObject)) != S_OK)
					WS_THROW("[DIRECTX 12] Could Not Create Command Allocator");
			}

			void D3D12CommandAllocator::Reset() const WS_NOEXCEPT
			{
				if (DX_FAILED(this->m_pObject->Reset()))
					WS_THROW("[DIRECTX 12] Could Not Reset Command Allocator");
			}

			/*
			 * // ////////////////////-\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12CommandList---------|| \\
			 * // |\__________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\-///////////////// \\ 
			 */

			D3D12CommandList::D3D12CommandList(D3D12DeviceObjectWrapper& pDevice,
											   D3D12CommandAllocatorObjectWrapper& pCommandAllocator,
											   const D3D12_COMMAND_LIST_TYPE& type) WS_NOEXCEPT
			{
				if (DX_FAILED(pDevice->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, pCommandAllocator, NULL, IID_PPV_ARGS(&this->m_pObject))))
					WS_THROW("[DIRECTX 12] Failed To Create Command List");
			}

			D3D12CommandList& D3D12CommandList::operator=(D3D12CommandList&& other) WS_NOEXCEPT
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;

				return *this;
			}

			void D3D12CommandList::Close() WS_NOEXCEPT
			{
				if (DX_FAILED(this->m_pObject->Close()))
					WS_THROW("[DIRECTX 12] Failed To Close Command List");
			}

			void D3D12CommandList::Reset(D3D12CommandAllocatorObjectWrapper& pCommandAllocator) const WS_NOEXCEPT
			{
				if (DX_FAILED(this->m_pObject->Reset(pCommandAllocator, NULL)))
					WS_THROW("[DIRECTX 12] Failed To Reset Command List");
			}

			void D3D12CommandList::TransitionResource(ID3D12Resource* pResource, const D3D12_RESOURCE_STATES& before, const D3D12_RESOURCE_STATES& after) WS_NOEXCEPT
			{
				this->m_pObject->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(pResource, before, after));
			}

			/*
			 * // ////////////////////-\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12DepthBuffer---------|| \\
			 * // |\__________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\-///////////////// \\ 
			 */

			D3D12DepthBuffer::D3D12DepthBuffer(D3D12Device& pDevice, Window* pWindow) WS_NOEXCEPT
			{
				D3D12_DESCRIPTOR_HEAP_DESC dsvHeapDesc = {};
				dsvHeapDesc.NumDescriptors = 1;
				dsvHeapDesc.Type  = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
				dsvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

				if (DX_FAILED(pDevice->CreateDescriptorHeap(&dsvHeapDesc, IID_PPV_ARGS(this->m_pDescriptorHeap.GetPtr()))))
					WS_THROW("[DIRECTX 12] Failed To Create Descriptor Heap For Depth Buffer");

				D3D12_DEPTH_STENCIL_VIEW_DESC depthStencilDesc = {};
				depthStencilDesc.Format        = DXGI_FORMAT_D32_FLOAT;
				depthStencilDesc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;
				depthStencilDesc.Flags         = D3D12_DSV_FLAG_NONE;

				D3D12_CLEAR_VALUE depthOptimizedClearValue = {};
				depthOptimizedClearValue.Format               = DXGI_FORMAT_D32_FLOAT;
				depthOptimizedClearValue.DepthStencil.Depth   = 1.0f;
				depthOptimizedClearValue.DepthStencil.Stencil = 0;

				if (DX_FAILED(pDevice->CreateCommittedResource(&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT), D3D12_HEAP_FLAG_NONE,
															&CD3DX12_RESOURCE_DESC::Tex2D(DXGI_FORMAT_D32_FLOAT, pWindow->GetClientWidth(), pWindow->GetClientHeight(), 1, 0, 1, 0, D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL),
															D3D12_RESOURCE_STATE_DEPTH_WRITE, &depthOptimizedClearValue,
															IID_PPV_ARGS(this->m_pDepthStencilBuffer.GetPtr()))))
					WS_THROW("[DIRECTX 12] Failed To Create Depth Stencil Heap");
			
				this->m_pDepthStencilBuffer->SetName(L"Depth/Stencil Resource Heap");

				pDevice->CreateDepthStencilView(this->m_pDepthStencilBuffer, &depthStencilDesc, this->m_pDescriptorHeap->GetCPUDescriptorHandleForHeapStart());

				this->m_dsvHandle = CD3DX12_CPU_DESCRIPTOR_HANDLE(this->m_pDescriptorHeap->GetCPUDescriptorHandleForHeapStart());
			}

			void D3D12DepthBuffer::Clear(D3D12CommandListObjectWrapper& pCommandList) WS_NOEXCEPT
			{
				pCommandList->ClearDepthStencilView(this->m_pDescriptorHeap->GetCPUDescriptorHandleForHeapStart(), D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);
			}

			D3D12DepthBuffer::operator CD3DX12_CPU_DESCRIPTOR_HANDLE* () WS_NOEXCEPT
			{
				return &this->m_dsvHandle;
			}

			/*
			 * // /////////////////////-\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12RootSignature---------|| \\
			 * // |\____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\-////////////////// \\ 
			 */

			D3D12RootSignature::D3D12RootSignature(D3D12DeviceObjectWrapper& pDevice, const D3D12_ROOT_SIGNATURE_FLAGS& flags,
												   const std::vector<D3D12_ROOT_PARAMETER1>& rootParameters, const std::vector<D3D12_STATIC_SAMPLER_DESC>& samplers) WS_NOEXCEPT
			{
				Microsoft::WRL::ComPtr<ID3DBlob> pSignature;
				Microsoft::WRL::ComPtr<ID3DBlob> pError;

				D3D12_VERSIONED_ROOT_SIGNATURE_DESC rootSignatureDesc;
				rootSignatureDesc.Version                    = D3D_ROOT_SIGNATURE_VERSION_1_1;
				rootSignatureDesc.Desc_1_1.NumParameters     = static_cast<UINT>(rootParameters.size());
				rootSignatureDesc.Desc_1_1.Flags             = flags;
				rootSignatureDesc.Desc_1_1.pParameters       = (rootParameters.size() > 0) ? rootParameters.data() : nullptr;
				rootSignatureDesc.Desc_1_1.pStaticSamplers   = samplers.data();
				rootSignatureDesc.Desc_1_1.NumStaticSamplers = static_cast<UINT>(samplers.size());

				if (DX_FAILED(D3D12SerializeVersionedRootSignature(&rootSignatureDesc, &pSignature, &pError)))
					WS_THROW("[DIRECTX 12] Failed To Serialize Root Signature");

				if (DX_FAILED(pDevice->CreateRootSignature(0, pSignature->GetBufferPointer(), pSignature->GetBufferSize(), IID_PPV_ARGS(&this->m_pObject))))
					WS_THROW("[DIRECTX 12] Failed To Create Root Signature");
			}

			D3D12RootSignature& D3D12RootSignature::operator=(D3D12RootSignature&& other) noexcept
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;

				return *this;
			}

			/*
			 * // ///////////////////////-\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12CommittedResource---------|| \\
			 * // |\________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\-//////////////////// \\ 
			 */

			D3D12CommittedResource::D3D12CommittedResource(D3D12DeviceObjectWrapper& pDevice,   const D3D12_HEAP_TYPE& heapType,
														   const D3D12_HEAP_FLAGS& flags,       const D3D12_RESOURCE_DESC* descPtr,
														   const D3D12_RESOURCE_STATES& states, const char* name) WS_NOEXCEPT
				: m_originalState(states), m_currentState(states)
			{
				
				if (DX_FAILED(pDevice->CreateCommittedResource(&CD3DX12_HEAP_PROPERTIES(heapType), flags, descPtr, states,
															nullptr, IID_PPV_ARGS(&this->m_pObject))))
				{
					const std::string errorString = "[DIRECTX 12] Failed To Create A Committed Resource Named " + std::string(name);

					WS_THROW(errorString.c_str());
				}
			
				const std::wstring nameW(&name[0], &name[strlen(name) + 1u]);
				this->m_pObject->SetName(nameW.c_str());
			}
			
			D3D12CommittedResource& D3D12CommittedResource::operator=(D3D12CommittedResource&& other) WS_NOEXCEPT
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;

				this->m_currentState  = other.m_currentState;
				this->m_originalState = other.m_originalState;

				return *this;
			}				

			/*
			 * // ///////////////////-\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12VertexBuffer---------|| \\
			 * // |\___________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\-/////////////////// \\ 
			 */

			D3D12VertexBuffer::D3D12VertexBuffer(D3D12DeviceObjectWrapper& pDevice,
												 D3D12CommandList* pCommandList,
												 const size_t nVertices, const size_t vertexSize) WS_NOEXCEPT
				: m_vertexSize((UINT)vertexSize), m_pCommandList(pCommandList)
			{
				const UINT bufferSize = static_cast<UINT>(vertexSize * nVertices);

				this->m_pVertexBuffer = D3D12CommittedResource(pDevice, D3D12_HEAP_TYPE_DEFAULT, D3D12_HEAP_FLAG_NONE, &CD3DX12_RESOURCE_DESC::Buffer(bufferSize),
															D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, "Vertex Buffer");

				this->m_pUploadHeap = D3D12CommittedResource(pDevice, D3D12_HEAP_TYPE_UPLOAD,  D3D12_HEAP_FLAG_NONE, &CD3DX12_RESOURCE_DESC::Buffer(bufferSize),
															D3D12_RESOURCE_STATE_GENERIC_READ, "Vertex Buffer Upload Heap");

				this->m_vertexData.resize(bufferSize);
				std::memset(this->m_vertexData.data(), 0u, bufferSize);

				this->m_vertexBufferView.StrideInBytes  = this->m_vertexSize;
				this->m_vertexBufferView.SizeInBytes    = static_cast<UINT>(this->m_vertexData.size());
				this->m_vertexBufferView.BufferLocation = this->m_pVertexBuffer->GetGPUVirtualAddress();
			}

			void D3D12VertexBuffer::Bind() WS_NOEXCEPT
			{
				(*this->m_pCommandList)->IASetVertexBuffers(0u, 1u, &this->m_vertexBufferView);
			}

			void D3D12VertexBuffer::Update() WS_NOEXCEPT
			{
				this->m_pVertexBuffer.TransitionTo(*this->m_pCommandList, D3D12_RESOURCE_STATE_COPY_DEST);

				D3D12_SUBRESOURCE_DATA vertexData = {};
				vertexData.pData      = this->m_vertexData.data();
				vertexData.RowPitch   = this->m_vertexData.size();
				vertexData.SlicePitch = this->m_vertexData.size();

				UpdateSubresources(*this->m_pCommandList, this->m_pVertexBuffer, this->m_pUploadHeap, 0, 0, 1, &vertexData);

				this->m_pVertexBuffer.TransitionBack(*this->m_pCommandList);
			}

			/*
			 * // //////////////////--\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12IndexBuffer---------|| \\
			 * // |\__________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\--////////////////// \\ 
			 */

			D3D12IndexBuffer::D3D12IndexBuffer(D3D12DeviceObjectWrapper& pDevice,
											   D3D12CommandList* pCommandList,
											   const size_t nIndices) WS_NOEXCEPT
				: m_nIndices(nIndices), m_pCommandList(pCommandList)
			{
				const UINT bufferSize = static_cast<UINT>(nIndices * sizeof(uint32_t));

				this->m_pIndexBuffer = D3D12CommittedResource(pDevice, D3D12_HEAP_TYPE_DEFAULT, D3D12_HEAP_FLAG_NONE, &CD3DX12_RESOURCE_DESC::Buffer(bufferSize),
															D3D12_RESOURCE_STATE_INDEX_BUFFER, "Index Buffer");

				this->m_pUploadHeap = D3D12CommittedResource(pDevice, D3D12_HEAP_TYPE_UPLOAD,  D3D12_HEAP_FLAG_NONE, &CD3DX12_RESOURCE_DESC::Buffer(bufferSize),
															D3D12_RESOURCE_STATE_GENERIC_READ, "Index Buffer Upload Heap");

				this->m_indexData.resize(bufferSize);
				std::memset(this->m_indexData.data(), 0u, bufferSize);

				this->m_indexBufferView.Format         = DXGI_FORMAT_R32_UINT;
				this->m_indexBufferView.SizeInBytes    = static_cast<UINT>(this->m_indexData.size());
				this->m_indexBufferView.BufferLocation = this->m_pIndexBuffer->GetGPUVirtualAddress();
			}

			void D3D12IndexBuffer::Bind() WS_NOEXCEPT
			{
				(*this->m_pCommandList)->IASetIndexBuffer(&this->m_indexBufferView);
			}

			void D3D12IndexBuffer::Update() WS_NOEXCEPT
			{
				this->m_pIndexBuffer.TransitionTo(*this->m_pCommandList, D3D12_RESOURCE_STATE_COPY_DEST);

				D3D12_SUBRESOURCE_DATA indexData = {};
				indexData.pData      = this->m_indexData.data();
				indexData.RowPitch   = this->m_indexData.size();
				indexData.SlicePitch = indexData.RowPitch;

				UpdateSubresources(*this->m_pCommandList, this->m_pIndexBuffer, this->m_pUploadHeap, 0, 0, 1, &indexData);

				this->m_pIndexBuffer.TransitionBack(*this->m_pCommandList);
			}

			/*
			 * // ////////////////////-\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12ConstantBuffer---------|| \\
			 * // |\_____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\-//////////////////// \\ 
			 */

			D3D12ConstantBuffer::D3D12ConstantBuffer(D3D12DeviceObjectWrapper& pDevice,
													D3D12CommandList* pCommandList,
													const size_t objSize, const size_t slot) WS_NOEXCEPT
				: m_objSize(objSize), m_slot(slot), m_pCommandList(pCommandList)
			{
				this->m_constantBufferData.resize(objSize);
				std::memset(this->m_constantBufferData.data(), 0u, objSize);

				for (int i = 0; i < WEISS__FRAME_BUFFER_COUNT; i++)
					this->m_descriptorHeaps[i] = D3D12DescriptorHeap(pDevice, D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, 1u, D3D12_DESCRIPTOR_HEAP_FLAGS::D3D12_DESCRIPTOR_HEAP_FLAG_NONE);

				for (int i = 0; i < WEISS__FRAME_BUFFER_COUNT; i++)
				{
					this->m_pUploadHeaps[i] = D3D12CommittedResource(pDevice, D3D12_HEAP_TYPE_UPLOAD, D3D12_HEAP_FLAG_NONE, &CD3DX12_RESOURCE_DESC::Buffer(1024 * 64),
																	D3D12_RESOURCE_STATE_GENERIC_READ, "Constant Buffer Upload Heap");

					this->m_constantBufferViews[i].BufferLocation = this->m_pUploadHeaps[i]->GetGPUVirtualAddress();
					this->m_constantBufferViews[i].SizeInBytes = (objSize + 255) & ~255;

					pDevice->CreateConstantBufferView(&this->m_constantBufferViews[i], this->m_descriptorHeaps[i]->GetCPUDescriptorHandleForHeapStart());
				}
			}

			void D3D12ConstantBuffer::UpdateIfNeeded(const size_t frameIndex) WS_NOEXCEPT
			{
				if (this->m_bNeedsUpdating[frameIndex])
					this->UpdateHeap(frameIndex);
			}

			void D3D12ConstantBuffer::Update() WS_NOEXCEPT
			{
				std::fill(this->m_bNeedsUpdating.begin(), this->m_bNeedsUpdating.end(), true);
			}

			void D3D12ConstantBuffer::UpdateHeap(const size_t heapIndex) WS_NOEXCEPT
			{
				this->m_bNeedsUpdating[heapIndex] = false;

				CD3DX12_RANGE readRange(0, 0);
				CD3DX12_RANGE writtenRange(0, this->m_objSize);

				D3D12CommittedResource& uploadHeap = this->m_pUploadHeaps[heapIndex];

				uint8_t* gpuDestAddr;
				if (DX_FAILED(uploadHeap->Map(0, &readRange, reinterpret_cast<void**>(&gpuDestAddr))))
					WS_THROW("[DIRECTX 12] Failed To Map Constant Buffer Memory");

				memcpy((void*)gpuDestAddr, this->m_constantBufferData.data(), this->m_objSize);

				uploadHeap->Unmap(0, &writtenRange);
			}

			/*
			 * // ////////////////--\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12Texture---------|| \\
			 * // |\______________________________/| \\
			 * // \\\\\\\\\\\\\\\\--//////////////// \\ 
			 */

			D3D12Texture::D3D12Texture(D3D12DeviceObjectWrapper& pDevice, D3D12CommandList* pCommandList, const size_t width, const size_t height, const size_t slot, const bool useMipmaps) WS_NOEXCEPT
				: m_pCommandList(pCommandList), m_slot(slot)
			{
				D3D12_RESOURCE_DESC resourceDesc {};
				resourceDesc = {};
				resourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
				resourceDesc.Alignment = 0; 
				resourceDesc.Width  = static_cast<UINT>(width);
				resourceDesc.Height = static_cast<UINT>(height);
				resourceDesc.DepthOrArraySize = 1;
				resourceDesc.MipLevels = useMipmaps ? 0 : 1;
				resourceDesc.Format = DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_UNORM;
				resourceDesc.SampleDesc.Count   = 1;
				resourceDesc.SampleDesc.Quality = 0;
				resourceDesc.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;
				resourceDesc.Flags  = D3D12_RESOURCE_FLAG_NONE;

				this->m_textureResource = D3D12CommittedResource(pDevice, D3D12_HEAP_TYPE_DEFAULT, D3D12_HEAP_FLAG_NONE, &resourceDesc,
																D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE, "Texture Committed Resource");

				UINT64 textureUploadBufferSize;
				pDevice->GetCopyableFootprints(&resourceDesc, 0, 1, 0, nullptr, nullptr, nullptr, &textureUploadBufferSize);

				this->m_uploadHeap = D3D12CommittedResource(pDevice, D3D12_HEAP_TYPE_UPLOAD, D3D12_HEAP_FLAG_NONE, &CD3DX12_RESOURCE_DESC::Buffer(textureUploadBufferSize),
															D3D12_RESOURCE_STATE_GENERIC_READ, "Texture Upload Heap");

				this->m_descriptorHeap = D3D12DescriptorHeap(pDevice, D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, 1, D3D12_DESCRIPTOR_HEAP_FLAG_NONE);

				this->m_textureResourceView.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
				this->m_textureResourceView.Format = resourceDesc.Format;
				this->m_textureResourceView.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
				this->m_textureResourceView.Texture2D.MipLevels = useMipmaps ? 0 : 1;
				
				pDevice->CreateShaderResourceView(this->m_textureResource, &this->m_textureResourceView, this->m_descriptorHeap->GetCPUDescriptorHandleForHeapStart());
			}
			
			void D3D12Texture::Update() WS_NOEXCEPT
			{
				this->m_textureResource.TransitionTo(*this->m_pCommandList, D3D12_RESOURCE_STATE_COPY_DEST);

				D3D12_SUBRESOURCE_DATA textureData{};
				textureData.pData      = this->m_image.GetBuffer();
				textureData.RowPitch   = this->m_image.GetWidth()      * sizeof(Coloru8);
				textureData.SlicePitch = this->m_image.GetPixelCount() * sizeof(Coloru8);
		
				UpdateSubresources(*this->m_pCommandList, this->m_textureResource, this->m_uploadHeap, 0, 0, 1, &textureData);

				this->m_textureResource.TransitionBack(*this->m_pCommandList);
			}

			/*
			 * // ////////////////////-\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12TextureSampler---------|| \\
			 * // |\_____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\-//////////////////// \\ 
			 */

			D3D12TextureSampler::D3D12TextureSampler(const TextureFilter& filter) WS_NOEXCEPT
			{
				switch (filter)
				{
				case TextureFilter::POINT:
					this->m_samplerDesc.Filter = D3D12_FILTER_MIN_MAG_MIP_POINT;
					break;
				case TextureFilter::BILINEAR:
					this->m_samplerDesc.Filter = D3D12_FILTER_MIN_MAG_LINEAR_MIP_POINT;
					break;
				case TextureFilter::TRILINEAR:
					this->m_samplerDesc.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;
					break;
				default:
					WS_THROW("[DIRECTX 12] Your Filtering Method Is Not Supported");
				}
				
				this->m_samplerDesc.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
				this->m_samplerDesc.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
				this->m_samplerDesc.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
				this->m_samplerDesc.MipLODBias = 0;
				this->m_samplerDesc.MaxAnisotropy  = D3D12_MAX_MAXANISOTROPY;
				this->m_samplerDesc.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
				this->m_samplerDesc.BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;
				this->m_samplerDesc.MinLOD = 0.0f;
				this->m_samplerDesc.MaxLOD = D3D12_FLOAT32_MAX;
				this->m_samplerDesc.ShaderRegister = 0;
				this->m_samplerDesc.RegisterSpace  = 0;
				this->m_samplerDesc.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;
			}

			/*
			 * // /////////////////////--\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12DescriptorHandles---------|| \\
			 * // |\________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\--///////////////////// \\
			 */

			inline void D3D12DescriptorHandles::OffsetCurrent(const UINT numDescriptors, const UINT incrementSize) WS_NOEXCEPT
			{
				this->m_cpuHandles.m_current.Offset(numDescriptors, incrementSize);
				this->m_gpuHandles.m_current.Offset(numDescriptors, incrementSize);
			}

			/*
			 * // ///////////////////////--\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12DescriptorHeapManager---------|| \\
			 * // |\____________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\--/////////////////////// \\
			 */

			void D3D12DescriptorHeapManager::AddHeapToVector() WS_NOEXCEPT
			{
				std::array<D3D12DescriptorHandles, WEISS__FRAME_BUFFER_COUNT> handles;

				this->m_heaps.resize(this->m_heaps.size() + 1u);

				for (size_t i = 0u; i < WEISS__FRAME_BUFFER_COUNT; i++)
				{
					this->m_heaps[this->m_heaps.size() - 1u][i] = std::make_unique<D3D12DescriptorHeap>(*this->m_pDevice, D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, WEISS__D3D12_MAX_DESCRIPTORS_PER_HEAP,
																										D3D12_DESCRIPTOR_HEAP_FLAGS::D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE);

					handles[i].m_cpuHandles.m_start   = (*this->m_heaps[this->m_heaps.size() - 1u][i])->GetCPUDescriptorHandleForHeapStart();
					handles[i].m_cpuHandles.m_current = handles[i].m_cpuHandles.m_start;
					handles[i].m_cpuHandles.m_end     = handles[i].m_cpuHandles.m_start;
					handles[i].m_cpuHandles.m_end.Offset(WEISS__D3D12_MAX_DESCRIPTORS_PER_HEAP, this->m_incrementSize);

					handles[i].m_gpuHandles.m_start   = (*this->m_heaps[this->m_heaps.size() - 1u][i])->GetGPUDescriptorHandleForHeapStart();
					handles[i].m_gpuHandles.m_current = handles[i].m_gpuHandles.m_start;
					handles[i].m_gpuHandles.m_end     = handles[i].m_gpuHandles.m_start;
					handles[i].m_gpuHandles.m_end.Offset(WEISS__D3D12_MAX_DESCRIPTORS_PER_HEAP, this->m_incrementSize);

					this->m_nativeHeapsPtr[i].push_back(*this->m_heaps[this->m_heaps.size() - 1u][i]);
				}

				this->m_handles.push_back(handles);
			}

			D3D12DescriptorHeapManager::D3D12DescriptorHeapManager(D3D12Device& device) WS_NOEXCEPT
				: m_pDevice(&device)
			{
				this->m_incrementSize = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
			}

			D3D12DescriptorHeapManager& D3D12DescriptorHeapManager::operator=(D3D12DescriptorHeapManager&& other) noexcept
			{
				this->m_handles = std::move(other.m_handles);

				this->m_heaps.reserve(other.m_heaps.size());
				for (size_t i = 0u; i < this->m_heaps.size(); i++)
					for (size_t j = 0u; j < WEISS__FRAME_BUFFER_COUNT; j++)
						this->m_heaps[i][j] = std::move(other.m_heaps[i][j]);

				this->m_incrementSize = std::move(other.m_incrementSize);
				this->m_pDevice       = std::move(other.m_pDevice);

				return *this;
			}

			std::array<D3D12DescriptorHandles, WEISS__FRAME_BUFFER_COUNT> D3D12DescriptorHeapManager::AddDesriptors(const std::vector<std::array<CD3DX12_CPU_DESCRIPTOR_HANDLE, WEISS__FRAME_BUFFER_COUNT>>& descriptors) WS_NOEXCEPT
			{
				if (descriptors.size() > WEISS__D3D12_MAX_DESCRIPTORS_PER_HEAP)
					WS_THROW("[D3D12] Too Many Descriptors !");

				std::array<D3D12DescriptorHandles, WEISS__FRAME_BUFFER_COUNT> starts;

				const UINT numDescriptors = static_cast<UINT>(descriptors.size());
				const UINT totalSize      = numDescriptors * this->m_incrementSize;

				std::optional<size_t> destIndex;

				// Try to find space for the needed heaps
				for (size_t i = 0u; i < this->m_handles.size(); i++)
				{
					const D3D12CPUDescriptorHandles& cpuHandle = this->m_handles[i][0u].m_cpuHandles;

					if (cpuHandle.m_end.ptr - cpuHandle.m_current.ptr >= totalSize) {
						destIndex = i;
						break;
					}
				}

				// If no place was found in existing descriptor heaps, create a new "std::array" of frame buffer descriptor heaps
				if (!destIndex.has_value())
				{
					this->AddHeapToVector();

					destIndex = this->m_heaps.size() - 1u;
				}

				// Copy every descriptor to the correct frame buffer heaps
				for (size_t j = 0u; j < WEISS__FRAME_BUFFER_COUNT; j++) {
					starts[j] = this->m_handles[destIndex.value()][j];

					for (size_t k = 0u; k < numDescriptors; k++) {
						(*this->m_pDevice)->CopyDescriptorsSimple(1u, this->m_handles[destIndex.value()][j].m_cpuHandles.m_current,
																  descriptors[k][j], D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
						
						this->m_handles[destIndex.value()][j].OffsetCurrent(1u, this->m_incrementSize);
					}
				}

				return starts;
			}

			void D3D12DescriptorHeapManager::Bind(D3D12CommandList& commandList, const size_t frameIndex) const WS_NOEXCEPT
			{
				commandList->SetDescriptorHeaps(static_cast<UINT>(this->m_heaps.size()), this->m_nativeHeapsPtr[frameIndex].data());
			}

			/*
			 * // ////////////////////-\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12RenderPipeline---------|| \\
			 * // |\_____________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\-//////////////////// \\ 
			 */

			D3D12RenderPipeline::D3D12RenderPipeline(D3D12RenderPipeline&& other) noexcept
			{
				this->m_pObject = other.m_pObject;
				other.m_pObject = nullptr;

				this->m_topology = other.m_topology;
				this->m_pRootSignature = std::move(other.m_pRootSignature);
				this->m_constantBufferIndices = other.m_constantBufferIndices;
				this->m_textureIndices = other.m_textureIndices;
			}

			D3D12RenderPipeline::D3D12RenderPipeline(D3D12Device& pDevice, const RenderPipelineDesc& pipelineDesc,
													 std::vector<ConstantBuffer*>& pConstantBuffers, std::vector<Texture*> pTextures,
													 std::vector<D3D12TextureSampler*> pTextureSamplers, D3D12DescriptorHeapManager& descriptorHeapManager) WS_NOEXCEPT
				: m_pDevice(&pDevice), m_constantBufferIndices(pipelineDesc.constantBufferIndices), m_textureIndices(pipelineDesc.textureIndices),
				m_pConstantBuffers(pConstantBuffers), m_pTextures(pTextures), m_pTextureSamplers(pTextureSamplers), m_pDescriptorHeapManager(&descriptorHeapManager)
			{
				// Specify Compilation Flags
				UINT compileFlags = 0u;

		#ifdef __WEISS__DEBUG_MODE

				compileFlags |= D3DCOMPILE_DEBUG;

		#endif // __WEISS__DEBUG_MODE

				// Vertex Shader
				Microsoft::WRL::ComPtr<ID3DBlob> pVertexShaderByteCode;
				Microsoft::WRL::ComPtr<ID3DBlob> pErrorBuff;

				wchar_t vsFilenameW[FILENAME_MAX];
				{
					size_t convertedCharP = 0;
					mbstowcs_s(&convertedCharP, vsFilenameW, strlen(pipelineDesc.vsFilename) + 1u, pipelineDesc.vsFilename, _TRUNCATE);
				}

				if (DX_FAILED(D3DCompileFromFile(vsFilenameW, nullptr, nullptr, "main", "vs_5_0", compileFlags,
						0, &pVertexShaderByteCode, &pErrorBuff)))
				{
		#ifdef __WEISS__DEBUG_MODE
					OutputDebugStringA((char*)pErrorBuff->GetBufferPointer());
		#endif // __WEISS__DEBUG_MODE

					WS_THROW("[DIRECTX 12] Failed To Compile Vertex Shader");
				}

				D3D12_SHADER_BYTECODE vertexShaderBytecode = {};
				vertexShaderBytecode.BytecodeLength  = pVertexShaderByteCode->GetBufferSize();
				vertexShaderBytecode.pShaderBytecode = pVertexShaderByteCode->GetBufferPointer();

				// Pixel Shader
				Microsoft::WRL::ComPtr<ID3DBlob> pPixelShaderByteCode;

				wchar_t psFilenameW[FILENAME_MAX];
				{
					size_t convertedCharP = 0;
					mbstowcs_s(&convertedCharP, psFilenameW, strlen(pipelineDesc.psFilename) + 1u, pipelineDesc.psFilename, _TRUNCATE);
				}

				if (DX_FAILED(D3DCompileFromFile(psFilenameW, nullptr, nullptr, "main", "ps_5_0", compileFlags,
					0, &pPixelShaderByteCode, &pErrorBuff)))
				{
		#ifdef __WEISS__DEBUG_MODE

					OutputDebugStringA((char*)pErrorBuff->GetBufferPointer());

		#endif // __WEISS__DEBUG_MODE

					WS_THROW("[DIRECTX 12] Failed To Compile Pixel Shader");
				}

				D3D12_SHADER_BYTECODE pixelShaderBytecode = {};
				pixelShaderBytecode.BytecodeLength  = pPixelShaderByteCode->GetBufferSize();
				pixelShaderBytecode.pShaderBytecode = pPixelShaderByteCode->GetBufferPointer();

				// Input Layout
				std::vector<D3D12_INPUT_ELEMENT_DESC> inputElementDescriptors(pipelineDesc.sies.size());
				for (uint32_t i = 0; i < inputElementDescriptors.size(); i++)
				{
					inputElementDescriptors[i] = D3D12_INPUT_ELEMENT_DESC{};
					inputElementDescriptors[i].SemanticName = pipelineDesc.sies[i].name;

					switch (pipelineDesc.sies[i].type)
					{
					case ShaderInputElementType::FLOAT_32:
						inputElementDescriptors[i].Format = DXGI_FORMAT::DXGI_FORMAT_R32_FLOAT;
						break;
					case ShaderInputElementType::UINT_32:
						inputElementDescriptors[i].Format = DXGI_FORMAT::DXGI_FORMAT_R32_UINT;
						break;
					case ShaderInputElementType::VECTOR_2D_FLOAT_32:
						inputElementDescriptors[i].Format = DXGI_FORMAT::DXGI_FORMAT_R32G32_FLOAT;
						break;
					case ShaderInputElementType::VECTOR_3D_FLOAT_32:
						inputElementDescriptors[i].Format = DXGI_FORMAT::DXGI_FORMAT_R32G32B32_FLOAT;
						break;
					case ShaderInputElementType::VECTOR_4D_FLOAT_32:
						inputElementDescriptors[i].Format = DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT;
						break;
					default:
						WS_THROW("[DIRECTX 12] Input Element Type Not Supported");
					}

					inputElementDescriptors[i].AlignedByteOffset = D3D12_APPEND_ALIGNED_ELEMENT;
					inputElementDescriptors[i].InputSlotClass    = D3D12_INPUT_CLASSIFICATION::D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA;
				}

				D3D12_INPUT_LAYOUT_DESC inputLayoutDesc = {};
				inputLayoutDesc.NumElements        = static_cast<UINT>(pipelineDesc.sies.size());
				inputLayoutDesc.pInputElementDescs = inputElementDescriptors.data();

				// Pipeline
				D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
				psoDesc.InputLayout    = inputLayoutDesc;
				psoDesc.VS = vertexShaderBytecode;
				psoDesc.PS = pixelShaderBytecode;

				switch (pipelineDesc.topology)
				{
				case PrimitiveTopology::TRIANGLES:
					psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE::D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
					this->m_topology = D3D_PRIMITIVE_TOPOLOGY::D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
					break;
				case PrimitiveTopology::TRIANGLE_STRIP:
					psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE::D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
					this->m_topology = D3D_PRIMITIVE_TOPOLOGY::D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;
					break;
				default:
					WS_THROW("[DIRECTX 12] The Primitive Topology Type You Resquested Is Not Supported");
					break;
				}

				psoDesc.RTVFormats[0]    = DXGI_FORMAT_R8G8B8A8_UNORM;
				psoDesc.SampleDesc.Count = 1;
				psoDesc.SampleMask       = 0xffffffff;
				psoDesc.RasterizerState  = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
				psoDesc.BlendState       = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
				psoDesc.DepthStencilState.DepthEnable   = FALSE;
				psoDesc.DepthStencilState.StencilEnable = FALSE;
				psoDesc.NumRenderTargets = 1;

				// Root Signature
				std::vector<D3D12_DESCRIPTOR_RANGE1> descriptorRanges(pipelineDesc.constantBufferIndices.size() + pipelineDesc.textureIndices.size());

				std::vector<D3D12_ROOT_PARAMETER1> rootParameters;

				{
					size_t j = 0u;
					for (size_t i = 0; i < pipelineDesc.constantBufferIndices.size(); i++)
					{
						D3D12ConstantBuffer*     pConstantBufferX12 = dynamic_cast<D3D12ConstantBuffer*>(pConstantBuffers[pipelineDesc.constantBufferIndices[i]]);
						D3D12_DESCRIPTOR_RANGE1& cbvDescriptorRange = descriptorRanges[j++];

						cbvDescriptorRange.RangeType      = D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
						cbvDescriptorRange.NumDescriptors = 1u;
						cbvDescriptorRange.RegisterSpace  = 0u;
						cbvDescriptorRange.BaseShaderRegister = (UINT)pConstantBufferX12->GetSlot();
						cbvDescriptorRange.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
					}

					for (size_t i = 0; i < pipelineDesc.textureIndices.size(); i++)
					{
						D3D12_DESCRIPTOR_RANGE1& texDescriptorRange = descriptorRanges[j++];
						texDescriptorRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
						texDescriptorRange.NumDescriptors = 1u;
						texDescriptorRange.BaseShaderRegister = (UINT)dynamic_cast<D3D12Texture*>(pTextures[pipelineDesc.textureIndices[i]])->GetSlot();
						texDescriptorRange.RegisterSpace = 0;
						texDescriptorRange.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
					}

					D3D12_ROOT_PARAMETER1 constantBufferRootParam;
					constantBufferRootParam.ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
					constantBufferRootParam.DescriptorTable.NumDescriptorRanges = (UINT)descriptorRanges.size();
					constantBufferRootParam.DescriptorTable.pDescriptorRanges   = descriptorRanges.data();
					constantBufferRootParam.ShaderVisibility = D3D12_SHADER_VISIBILITY::D3D12_SHADER_VISIBILITY_ALL;

					rootParameters.push_back(constantBufferRootParam);
				}

				std::vector<D3D12_STATIC_SAMPLER_DESC> samplers(pipelineDesc.textureSamplerIndices.size());
				for (size_t i = 0u; i < samplers.size(); i++)
					samplers[i] = pTextureSamplers[pipelineDesc.textureSamplerIndices[i]]->GetSamplerDesc();

				this->m_pRootSignature = D3D12RootSignature(pDevice, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT, rootParameters, samplers);

				psoDesc.pRootSignature = this->m_pRootSignature;

				// create the pso
				if (DX_FAILED(pDevice->CreateGraphicsPipelineState(&psoDesc, __uuidof(ID3D12PipelineState), (void**)&this->m_pObject)))
					WS_THROW("[DIRECTX 12] Failed To Create Graphics Pipeline State");

				// Fill GPU Descriptor Heap
				std::vector<std::array<CD3DX12_CPU_DESCRIPTOR_HANDLE, WEISS__FRAME_BUFFER_COUNT>> srcCpuDescriptorHandles;
				srcCpuDescriptorHandles.resize(this->m_constantBufferIndices.size() + this->m_textureIndices.size());

				size_t i = 0u;
				for (const size_t cbIndex : this->m_constantBufferIndices) {
					D3D12ConstantBuffer& cbBuffer = *dynamic_cast<D3D12ConstantBuffer*>(pConstantBuffers[cbIndex]);

					for (size_t frameIndex = 0u; frameIndex < WEISS__FRAME_BUFFER_COUNT; frameIndex++)
						srcCpuDescriptorHandles[i][frameIndex] = cbBuffer.GetDescriptorHeap(frameIndex)->GetCPUDescriptorHandleForHeapStart();

					i++;
				}

				for (const size_t texIndex : this->m_textureIndices) {
					D3D12Texture& texture = *dynamic_cast<D3D12Texture*>(pTextures[texIndex]);

					for (size_t frameIndex = 0u; frameIndex < WEISS__FRAME_BUFFER_COUNT; frameIndex++)
						srcCpuDescriptorHandles[i][frameIndex] = texture.GetDescriptorHeap()->GetCPUDescriptorHandleForHeapStart();
						
					i++;
				}

				this->m_handles = this->m_pDescriptorHeapManager->AddDesriptors(srcCpuDescriptorHandles);
			}

			D3D12RenderPipeline& D3D12RenderPipeline::operator=(D3D12RenderPipeline&& other) noexcept
			{
				this->m_pObject = std::move(other.m_pObject);

				this->m_topology = other.m_topology;
				this->m_pRootSignature = std::move(other.m_pRootSignature);
				this->m_constantBufferIndices = other.m_constantBufferIndices;
				this->m_textureIndices = other.m_textureIndices;
				this->m_pDescriptorHeapManager = std::move(other.m_pDescriptorHeapManager);
				this->m_handles = std::move(other.m_handles);

				return *this;
			}

			void D3D12RenderPipeline::Bind(D3D12CommandList& pCommandList, const size_t frameIndex) WS_NOEXCEPT
			{
				for (uint32_t cbIndex : this->m_constantBufferIndices)
					dynamic_cast<D3D12ConstantBuffer*>(this->m_pConstantBuffers[cbIndex])->UpdateIfNeeded(frameIndex);

				pCommandList->SetGraphicsRootSignature(this->m_pRootSignature);
				pCommandList->SetPipelineState(this->m_pObject);
				pCommandList->SetGraphicsRootDescriptorTable(0u, this->m_handles[frameIndex].m_gpuHandles.m_start);
				pCommandList->IASetPrimitiveTopology(this->m_topology);
			}

			/*
			 * // /////////////////////-\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12CommandSubmitter---------|| \\
			 * // |\_______________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\-///////////////////// \\ 
			 */

			D3D12CommandSubmitter::D3D12CommandSubmitter(D3D12DeviceObjectWrapper& pDevice) WS_NOEXCEPT
			{
				for (uint16_t i = 0; i < WEISS__FRAME_BUFFER_COUNT; i++)
					this->m_pCommandAllocators[i] = D3D12CommandAllocator(pDevice, D3D12_COMMAND_LIST_TYPE_DIRECT);

				this->m_pCommandList = D3D12CommandList(pDevice, this->m_pCommandAllocators[0], D3D12_COMMAND_LIST_TYPE::D3D12_COMMAND_LIST_TYPE_DIRECT);

				for (uint16_t i = 0; i < WEISS__FRAME_BUFFER_COUNT; i++) {
					this->m_pFences[i]     = std::make_unique<D3D12Fence>(pDevice, 0u, D3D12_FENCE_FLAGS::D3D12_FENCE_FLAG_NONE);
					this->m_fenceValues[i] = 0u;
				}
			}

			void D3D12CommandSubmitter::Close() WS_NOEXCEPT
			{
				this->m_pCommandList.Close();
			}

			void D3D12CommandSubmitter::Reset(const size_t frameIndex) WS_NOEXCEPT
			{
				this->m_pCommandAllocators[frameIndex].Reset();
				this->m_pCommandList.Reset(this->m_pCommandAllocators[frameIndex]);
			}

			void D3D12CommandSubmitter::Execute(D3D12CommandQueueObjectWrapper& pCommandQueue, const size_t frameIndex) WS_NOEXCEPT
			{
				ID3D12CommandList* ppCommandLists[] = { this->m_pCommandList };
				pCommandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

				D3D12Fence& pFence     = *this->m_pFences[frameIndex];
				UINT64&     fenceValue = this->m_fenceValues[frameIndex];

				if (DX_FAILED(pCommandQueue->Signal(pFence, fenceValue)))
					WS_THROW("[DIRECTX 12] Failed To Signal The Fence");
			}

			void D3D12CommandSubmitter::WaitForCompletion(const size_t frameIndex) WS_NOEXCEPT
			{
				D3D12Fence& pFence     = *this->m_pFences[frameIndex];
				UINT64&     fenceValue = this->m_fenceValues[frameIndex];

				if (pFence->GetCompletedValue() < fenceValue) {
					if (DX_FAILED(pFence->SetEventOnCompletion(fenceValue, pFence.GetEvent())))
						WS_THROW("[DIRECTX 12] Failed To Set Event On Completion For Fence");

					WaitForSingleObject(pFence.GetEvent(), INFINITE);

				}

				fenceValue++;
			}

			/*
			 * // /////////////////--\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||---------D3D12RenderAPI---------|| \\
			 * // |\________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\--///////////////// \\ 
			 */

			void D3D12RenderAPI::CreateRenderTargets() WS_NOEXCEPT
			{
				CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(this->m_pDescriptorHeap->GetCPUDescriptorHandleForHeapStart());

				UINT rtvDescriptorSize = this->m_pDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

				for (uint16_t i = 0; i < WEISS__FRAME_BUFFER_COUNT; i++)
				{
					this->m_pRenderTargets[i] = D3D12RenderTarget(this->m_pDevice, this->m_pSwapChain, this->m_pDescriptorHeap, rtvHandle, i);
					rtvHandle.Offset(1, rtvDescriptorSize);
				}
			}

			void D3D12RenderAPI::InitRenderAPI(Window* pWindow, const uint16_t maxFps) WS_NOEXCEPT
			{
				this->m_pDevice         = D3D12Device(this->m_pAdapter);
				this->m_pDepthBuffer    = D3D12DepthBuffer(this->m_pDevice, pWindow);
				this->m_pCommandQueue   = D3D12CommandQueue(this->m_pDevice, D3D12_COMMAND_LIST_TYPE::D3D12_COMMAND_LIST_TYPE_DIRECT);
				this->m_pSwapChain      = D3D12SwapChain(this->m_pDevice, this->m_pCommandQueue, pWindow, maxFps, static_cast<UINT>(WEISS__FRAME_BUFFER_COUNT));
				this->m_pDescriptorHeap = D3D12DescriptorHeap(this->m_pDevice, D3D12_DESCRIPTOR_HEAP_TYPE_RTV, static_cast<UINT>(WEISS__FRAME_BUFFER_COUNT));

				this->CreateRenderTargets();

				this->m_commandSubmitter = D3D12CommandSubmitter(this->m_pDevice);

				this->m_viewport.TopLeftX = 0;
				this->m_viewport.TopLeftY = 0;
				this->m_viewport.Width    = pWindow->GetClientWidth();
				this->m_viewport.Height   = pWindow->GetClientHeight();
				this->m_viewport.MinDepth = 0.0f;
				this->m_viewport.MaxDepth = 1.0f;

				this->m_scissors.left   = 0;
				this->m_scissors.top    = 0;
				this->m_scissors.right  = pWindow->GetClientWidth();
				this->m_scissors.bottom = pWindow->GetClientHeight();

				this->m_descriptorHeapManager = D3D12DescriptorHeapManager(this->m_pDevice);
			}

			void D3D12RenderAPI::InitPipelines(const std::vector<RenderPipelineDesc>& pipelineDescs) WS_NOEXCEPT
			{
				// Create Pipelines
				for (const RenderPipelineDesc& pipelineDesc : pipelineDescs)
					this->m_renderPipelines.emplace_back(this->m_pDevice, pipelineDesc, this->m_pConstantBuffers, this->m_pTextures, this->m_pTextureSamplers, this->m_descriptorHeapManager);
			}

			void D3D12RenderAPI::Draw(const Drawable& drawable, const size_t nVertices) WS_NOEXCEPT
			{
				D3D12CommandList& pGfxCommandList = this->m_commandSubmitter.GetCommandList();

				this->m_renderPipelines[drawable.pipelineIndex].Bind(pGfxCommandList, this->currentFrameIndex);
				dynamic_cast<D3D12VertexBuffer*>(this->m_pVertexBuffers[drawable.vertexBufferIndex])->Bind();

				if (drawable.indexBufferIndex.has_value()) {
					dynamic_cast<D3D12IndexBuffer*>(this->m_pIndexBuffers[drawable.indexBufferIndex.value()])->Bind();

					pGfxCommandList->DrawIndexedInstanced(static_cast<UINT>(nVertices), 1, 0, 0, 0);
				} else {
					pGfxCommandList->DrawInstanced(static_cast<UINT>(nVertices), 1u, 0, 0);
				}
			}

			void D3D12RenderAPI::BeginDrawing() WS_NOEXCEPT
			{
				// Wait For Next Frame
				this->currentFrameIndex = this->m_pSwapChain->GetCurrentBackBufferIndex();

				D3D12RenderTarget& renderTarget    = this->m_pRenderTargets[this->currentFrameIndex];
				D3D12CommandList&  pGfxCommandList = this->m_commandSubmitter.GetCommandList();

				pGfxCommandList.TransitionResource(renderTarget, D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);

				this->m_currentRtvHandle = CD3DX12_CPU_DESCRIPTOR_HANDLE(this->m_pDescriptorHeap->GetCPUDescriptorHandleForHeapStart(), static_cast<INT>(this->currentFrameIndex), this->m_pDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV));

				this->m_pDepthBuffer.Clear(pGfxCommandList);
				pGfxCommandList->RSSetViewports(1u, &this->m_viewport);
				pGfxCommandList->RSSetScissorRects(1u, &this->m_scissors);
				pGfxCommandList->OMSetRenderTargets(1u, &m_currentRtvHandle, FALSE, this->m_pDepthBuffer);

				this->m_descriptorHeapManager.Bind(pGfxCommandList, this->currentFrameIndex);

				this->Fill();
			}

			void D3D12RenderAPI::EndDrawing() WS_NOEXCEPT
			{
				D3D12RenderTarget& renderTarget    = this->m_pRenderTargets[this->currentFrameIndex];
				D3D12CommandList&  pGfxCommandList = this->m_commandSubmitter.GetCommandList();
				D3D12Fence& pFence = this->m_commandSubmitter.GetFence(this->currentFrameIndex);

				pGfxCommandList.TransitionResource(renderTarget, D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);

				this->m_commandSubmitter.Close();
				this->m_commandSubmitter.Execute(this->m_pCommandQueue, this->currentFrameIndex);
			}

			void D3D12RenderAPI::Present(const bool vSync) WS_NOEXCEPT
			{
				this->m_pSwapChain.Present(vSync);

				this->m_commandSubmitter.WaitForCompletion(currentFrameIndex);
				this->m_commandSubmitter.Reset(this->currentFrameIndex);
			}

			size_t D3D12RenderAPI::CreateVertexBuffer(const size_t nVertices, const size_t vertexSize) WS_NOEXCEPT
			{
				const size_t vertexBufferIndex = this->m_pVertexBuffers.size();

				this->m_pVertexBuffers.push_back(new D3D12VertexBuffer(this->m_pDevice, this->m_commandSubmitter.GetCommandListPr(), nVertices, vertexSize));

				return vertexBufferIndex;
			}

			size_t D3D12RenderAPI::CreateIndexBuffer(const size_t nIndices) WS_NOEXCEPT
			{
				const size_t indexBufferIndex = this->m_pIndexBuffers.size();

				this->m_pIndexBuffers.push_back(new D3D12IndexBuffer(this->m_pDevice, this->m_commandSubmitter.GetCommandListPr(), nIndices));

				return indexBufferIndex;
			}

			size_t D3D12RenderAPI::CreateConstantBuffer(const size_t objSize, const size_t slot) WS_NOEXCEPT
			{
				this->m_pConstantBuffers.push_back(new D3D12ConstantBuffer(this->m_pDevice, this->m_commandSubmitter.GetCommandListPr(), objSize, slot));

				return this->m_pConstantBuffers.size() - 1u;
			}
			
			size_t D3D12RenderAPI::CreateTexture(const size_t width, const size_t height, const size_t slot, const bool useMipmaps) WS_NOEXCEPT
			{
				this->m_pTextures.push_back(new D3D12Texture(this->m_pDevice, this->m_commandSubmitter.GetCommandListPr(), width, height, slot, useMipmaps));

				return this->m_pTextures.size() - 1u;
			}

			size_t D3D12RenderAPI::CreateTextureSampler(const TextureFilter& filter, const size_t slot) WS_NOEXCEPT
			{
				this->m_pTextureSamplers.push_back(new D3D12TextureSampler(filter));

				return this->m_pTextureSamplers.size() - 1u;
			}

			void D3D12RenderAPI::Fill(const Colorf32& color) WS_NOEXCEPT
			{
				D3D12CommandList& pGfxCommandList = this->m_commandSubmitter.GetCommandList();

				pGfxCommandList->ClearRenderTargetView(this->m_currentRtvHandle, (float*)&color, 0, nullptr);
			}

		}; // namespace D3D12

	}; // namespace Internal

	/*
	 * // /////////////////--\\\\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||---------GraphicsEngine---------|| \\
	 * // |\________________________________/| \\
	 * // \\\\\\\\\\\\\\\\\--///////////////// \\ 
	 */

	GraphicsEngine::GraphicsEngine(const RenderAPIName& apiName)
	{
		this->m_renderHandle = RenderAPI::Create(apiName);
	}

	void GraphicsEngine::Init(WindowHandle windowHandle)
	{
		this->m_windowHandle = windowHandle;

		this->m_renderHandle->InitRenderAPI(windowHandle, 144u);
	}

	void GraphicsEngine::Run(const size_t fps)
	{
		while (this->m_windowHandle->IsRunning())
		{
			this->m_windowHandle->Update();

			this->m_renderHandle->BeginDrawing();
			this->m_renderHandle->EndDrawing();

			this->OnFrame();
			this->m_renderHandle->Present(false);

			// Temporary
			std::this_thread::sleep_for(std::chrono::milliseconds((unsigned int)(1 / (float)fps * 1000u)));
		}
	}

	/*
	 * // ////////////////--\\\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||---------ClientSocket---------|| \\
	 * // |\______________________________/| \\
	 * // \\\\\\\\\\\\\\\\--//////////////// \\ 
	 */

	void ClientSocket::Connect(const char* host, const unsigned int port)
	{
		sockaddr_in sockAddr;
		sockAddr.sin_addr.s_addr = inet_addr(host);
		sockAddr.sin_family      = AF_INET;
		sockAddr.sin_port        = htons(port);

		this->m_socket = socket(AF_INET, SOCK_STREAM, 0);

		if (this->m_socket == INVALID_SOCKET)
			WS_THROW("[CLIENT SOCKET] Creation Failed");

		if (connect(this->m_socket, (sockaddr*)&sockAddr, sizeof(sockAddr)) == SOCKET_ERROR)
			WS_THROW("[CLIENT SOCKET] Failed To Connect");
	}

	void ClientSocket::Send(const char* data, int length)
	{
		if (length < 0)
			length = static_cast<int>(strlen(data) + 1u);

		if (send(this->m_socket, data, length, 0) == SOCKET_ERROR)
			WS_THROW("[CLIENT SOCKET] Error While Sending Data");
	}

	[[nodiscard]] std::pair<std::array<char, 1024u>, size_t> ClientSocket::Receive()
	{
		std::array<char, 1024u> buffer;

		const int iResult = recv(this->m_socket, buffer.data(), 1024u, 0);

		if (iResult == 0 || iResult == SOCKET_ERROR)
			WS_THROW("[CLIENT SOCKET] Error While Receiving Data");

		return { buffer, (size_t)iResult };
	}

	void ClientSocket::Disconnect() WS_NOEXCEPT
	{
		this->m_socket = INVALID_SOCKET;

		closesocket(this->m_socket);
	}

	/*
	 * // ////////////////--\\\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||---------ServerSocket---------|| \\
	 * // |\______________________________/| \\
	 * // \\\\\\\\\\\\\\\\--//////////////// \\ 
	 */

	void ServerSocket::Bind(const unsigned int port)
	{
		this->m_socket = socket(AF_INET, SOCK_STREAM, 0);

		if (this->m_socket == INVALID_SOCKET)
			WS_THROW("[SERVER SOCKET] Creation Failed");

		sockaddr_in sockAddr;
		sockAddr.sin_addr.s_addr = INADDR_ANY;
		sockAddr.sin_family      = AF_INET;
		sockAddr.sin_port        = htons(5555);

		if (bind(this->m_socket, (sockaddr*)&sockAddr, sizeof(sockAddr)) == SOCKET_ERROR)
			WS_THROW("[SERVER SOCKET] Binding Failed");

		if (listen(this->m_socket, 0) == SOCKET_ERROR)
			WS_THROW("[SERVER SOCKET] Listening Failed");
	}

	[[nodiscard]] int ServerSocket::Accept() WS_NOEXCEPT
	{
		sockaddr_in clientAddr;
		int clientAddrSize = 0;

		const SOCKET client = accept(this->m_socket, (SOCKADDR*)&clientAddr, &clientAddrSize);

		if (client != INVALID_SOCKET)
		{
			this->m_clients.push_back(client);

			return static_cast<int>(this->m_clients.size() - 1u);
		}

		return -1;
	}

	void ServerSocket::Send(const int clientID, const char* data, int length)
	{
		if (length < 0)
			length = static_cast<int>(strlen(data) + 1);

		if (send(this->m_clients[clientID], data, length, 0) == SOCKET_ERROR)
			WS_THROW("[SERVER SOCKET] Could Not Send Data To Client");
	}

	[[nodiscard]] std::pair<std::array<char, 1024u>, size_t> ServerSocket::Receive(const int clientID)
	{
		std::array<char, 1024u> buffer;

		const int iResult = recv(this->m_clients[clientID], buffer.data(), 1024u, 0);

		if (iResult == 0 || iResult == SOCKET_ERROR)
			WS_THROW("[SERVER SOCKET] Error While Receiving Data From Client");

		return { buffer, (size_t)iResult };
	}

	void ServerSocket::Disconnect() WS_NOEXCEPT
	{
		this->m_socket = INVALID_SOCKET;

		closesocket(this->m_socket);
	}

	/*
	 * // ////////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||--------------------------::Create()--------------------------|| \\
	 * // |\______________________________________________________________/| \\
	 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-///////////////////////////////// \\ 
	 */

	WindowHandle Window::Create(const WindowDescriptor &descriptor) WS_NOEXCEPT
	{
#ifdef __WEISS__OS_WINDOWS

		return {new WS::Internal::WIN::WindowsWindow(descriptor)};

#endif // __WEISS__OS_WINDOWS

		WS_THROW("Could Not Create A Window For Your Operating System");
	}

	RenderAPIHandle RenderAPI::Create(const RenderAPIName &apiName) WS_NOEXCEPT
	{
		switch (apiName)
		{
		case RenderAPIName::VULKAN:
			return new WS::Internal::VK::VKRenderAPI();

#ifdef __WEISS__OS_WINDOWS

		case RenderAPIName::DIRECTX11:
			return new WS::Internal::D3D11::D3D11RenderAPI();
		case RenderAPIName::DIRECTX12:
			return new WS::Internal::D3D12::D3D12RenderAPI();

#endif // __WEISS__OS_WINDOWS
		}

		WS_THROW("[RENDER API] Your Render API Is Not Supported");
		std::exit(-1);
	}

}; // WS

/*
 * // ////////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
 * // ||--------------------------Entry Point--------------------------|| \\
 * // |\_______________________________________________________________/| \\
 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--///////////////////////////////// \\
 */

int main(int argc, char** argv)
{
#ifdef __WEISS__OS_WINDOWS

	if (WIN_FAILED(CoInitializeEx(NULL, COINIT_MULTITHREADED)))
		WS_THROW("[COM] Failed To CoInitialize");

	WSADATA wsaData;
	if (WIN_FAILED(WSAStartup(MAKEWORD(2, 0), &wsaData)))
		WS_THROW("[WINSOCK] Failed To WSAStartup");

#endif // __WEISS__OS_WINDOWS

	const int returnCode = WS::WeissEntryPoint(argc, argv);

#ifdef __WEISS__OS_WINDOWS

	if (WIN_FAILED(WSACleanup()))
		WS_THROW("[WINSOCK] Failed To WSACleanup");

	CoUninitialize();

#endif // __WEISS__OS_WINDOWS

	return returnCode;
}

/*
 * // /////////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
 * // ||-----------------------------UNDEFS-----------------------------|| \\
 * // |\________________________________________________________________/| \\
 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--///////////////////////////////// \\ 
 */

#ifdef __WEISS__OS_WINDOWS

	#undef DX_FAILED
	#undef WIN_FAILED

#endif // __WEISS__OS_WINDOWS

#undef VK_FAILED
#undef WS_THROW
#undef __WEISS__THROWS

/*
 * Let's be honest, you just came down here to see the SLOC.
 *
 * // //////////////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
 * // ||-------------------------------EOF-------------------------------|| \\
 * // |\_________________________________________________________________/| \\
 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-////////////////////////////////// \\ 
 * 
 *   /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\
 *  / /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\ \
 *  | |           ██          ██    ██████████████      ██████████      ██████████████    ██████████████           | |
 *  | |           ██          ██    ██                      ██          ██                ██                       | |
 *  | |           ██          ██    ██                      ██          ██                ██                       | |
 *  | |           ██    ██    ██    ██████████████          ██          ██████████████    ██████████████           | |
 *  | |           ██    ██    ██    ██                      ██                      ██                ██           | |
 *  | |           ██  ██  ██  ██    ██                      ██                      ██                ██           | |
 *  | |             ██      ██      ██████████████      ██████████      ██████████████    ██████████████           | |
 *  | |                                                                                                            | |
 *  | |  ██████████████    ██          ██    ██████████████      ██████████      ██          ██    ██████████████  | |
 *  | |  ██                ████        ██    ██                      ██          ████        ██    ██              | |
 *  | |  ██                ██  ██      ██    ██                      ██          ██  ██      ██    ██              | |
 *  | |  ██████████████    ██    ██    ██    ██    ██████            ██          ██    ██    ██    ██████████████  | |
 *  | |  ██                ██      ██  ██    ██          ██          ██          ██      ██  ██    ██              | |
 *  | |  ██                ██        ████    ██          ██          ██          ██        ████    ██              | |
 *  | |  ██████████████    ██          ██    ████████████        ██████████      ██          ██    ██████████████  | |
 *  \ \____________________________________________________________________________________________________________/ /
 *   \______________________________________________________________________________________________________________/
 */