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
#include <cmath>
#include <future>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <memory>
#include <bitset>
#include <cstring>
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

		Rect(const RECT &rect) WS_NOEXCEPT;

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

	// ///////////////-\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |-------SIMD Operations-------| \\
	// |\___________________________/| \\
	// \\\\\\\\\\\\\\\-/////////////// \\

	template <typename _T>
	static inline GET_SIMD_TYPE<_T> SIMDAdd(const GET_SIMD_TYPE<_T>& vecA, const GET_SIMD_TYPE<_T>& vecB) WS_NOEXCEPT
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
	static inline GET_SIMD_TYPE<_T> SIMDSub(const GET_SIMD_TYPE<_T>& vecA, const GET_SIMD_TYPE<_T>& vecB) WS_NOEXCEPT
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
	static inline GET_SIMD_TYPE<_T> SIMDMul(const GET_SIMD_TYPE<_T>& vecA, const GET_SIMD_TYPE<_T>& vecB) WS_NOEXCEPT
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
	static inline GET_SIMD_TYPE<_T> SIMDDiv(const GET_SIMD_TYPE<_T>& vecA, const GET_SIMD_TYPE<_T>& vecB) WS_NOEXCEPT
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
		const _T& w) WS_NOEXCEPT
	{
		if constexpr (std::is_same_v<_T, float>)
			return _mm_set_ps(w, z, y, x);
		else if constexpr (std::is_same_v<_T, int32_t>)
			return _mm_set_epi32(w, z, y, x);
		else if constexpr (std::is_same_v<_T, int16_t>)
			return _mm_set_epi16(0, 0, 0, 0, w, z, y, x);
		else if constexpr (std::is_same_v<_T, double>)
			return _mm256_set_pd(w, z, y, x);
	}

	template <typename _T>
	static inline void SIMDStore(_T* src, const GET_SIMD_TYPE<_T>& sseVec) WS_NOEXCEPT
	{
		if constexpr (std::is_same_v<_T, float>)
			_mm_store_ps(src, sseVec);
		else if constexpr (std::is_same_v<_T, int32_t> || std::is_same_v<_T, int16_t>)
			_mm_store_si128((__m128i*)src, sseVec);
		else if constexpr (std::is_same_v<_T, double>)
			_mm256_store_pd(src, sseVec);
	}

	template <typename _T>
	static inline GET_SIMD_TYPE<_T> SIMDLoad(_T* src) WS_NOEXCEPT
	{
		if constexpr (std::is_same_v<_T, float>)
			return _mm_load_ps(src);
		else if constexpr (std::is_same_v<_T, int32_t> || std::is_same_v<_T, int16_t>)
			return _mm_load_si128((__m128i*)src);
		else if constexpr (std::is_same_v<_T, double>)
			return _mm256_load_pd(src);
	}

	template <typename _T, int INDEX>
	static inline _T SIMDExtractElement(const GET_SIMD_TYPE<_T>& sseVector) WS_NOEXCEPT
	{
		if constexpr (std::is_same_v<_T, float>) {
			const int l = _mm_extract_ps(sseVector, INDEX);
			return *reinterpret_cast<const _T*>(&l);
		} else if constexpr (std::is_same_v<_T, int32_t>) {
			const int l = _mm_extract_epi16(sseVector, INDEX);
			return *reinterpret_cast<const _T*>(&l);
		} else if constexpr (std::is_same_v<_T, int16_t>) {
			const int l = _mm_extract_epi16(sseVector, INDEX);
			return *reinterpret_cast<const _T*>(&l);
		} else if constexpr (std::is_same_v<_T, double>) {
			if constexpr (INDEX <= 1) {
				return _mm256_cvtsd_f64(_mm256_shuffle_pd(sseVector, sseVector,
					_MM_SHUFFLE(INDEX, INDEX, INDEX, INDEX)));
			} else {
				return _mm_cvtsd_f64(_mm_shuffle_pd(_mm256_extractf128_pd(sseVector, 1), // I am
					_mm256_extractf128_pd(sseVector, 1), // proud of
					_MM_SHUFFLE(INDEX, INDEX, INDEX, INDEX))); // this magic
			}
		}
	}

	template <typename _T>
	static inline _T SIMDDotProduct(const GET_SIMD_TYPE<_T>& a, const GET_SIMD_TYPE<_T>& b) WS_NOEXCEPT
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

	// ////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |----------RawVectorComponents<_T, _D>----------| \\
	// |\_____________________________________________/| \\
	// \\\\\\\\\\\\\\\\\\\\\\\\-//////////////////////// \\

	// Should be used when you don't wish to perform any math operation to the data (i.e just storing it)
	// If you wish to perform math operations, convert it to a Vector<_T> since it supports SIMD and then convert it back

	// _T : the type of every vector component
	// _D : the number of dimensions (i.e components) (max 4)
	template <typename _T, size_t _D>
	struct RawVectorComponents {  };

	// Template specialisation
	template <typename _T>
	struct RawVectorComponents<_T, 1u> { _T x; };

	template <typename _T>
	struct RawVectorComponents<_T, 2u> : RawVectorComponents<_T, 1u> { _T y; };

	template <typename _T>
	struct RawVectorComponents<_T, 3u> : RawVectorComponents<_T, 2u> { _T z; };

	template <typename _T>
	struct RawVectorComponents<_T, 4u> : RawVectorComponents<_T, 3u> { _T w; };

	template <typename _T, size_t _D>
	inline std::ostream& operator<<(std::ostream& stream, const RawVectorComponents<_T, _D>& raw) WS_NOEXCEPT
	{
		static_assert(_D <= 4);

		stream << "(";

		if constexpr (_D == 1u)
			stream << raw.x;
		else if constexpr (_D == 2u)
			stream << raw.x << ", " << raw.y;
		else if constexpr (_D == 3u)
			stream << raw.x << ", " << raw.y << ", " << raw.z;
		else
			stream << raw.x << ", " << raw.y << ", " << raw.z << ", " << raw.w;

		stream << ")";

		return stream;
	}

	// ///////////////--\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |----------Vector<_T>----------| \\
	// |\____________________________/| \\
	// \\\\\\\\\\\\\\\--/////////////// \\

	// Should be used for quick SIMD Enabled vector math
	// Can be converted into RawVectorComponents<_T, _D>

	// _T : the type of every vector component
	template <typename _T = _WS_TYPE_DOESNT_EXIST>
	struct Vector
	{
		union {
			GET_SIMD_TYPE<_T> m_sseVector; // Is a "_WS_TYPE_DOESNT_EXIST" if no intrinsic type can be created
			RawVectorComponents<_T, 4u> m_rawComponents; // Use to convert this 4 dimensional SIMD Enable Vector into any lower dimension vector.
			struct { _T x, y, z, w; };
			_T m_arr[4u];
		};

		inline Vector(const _T& x = 0, const _T& y = 0, const _T& z = 0, const _T& w = 0) WS_NOEXCEPT
		{
			this->Set(x, y, z, w);
		}

		inline Vector(const Vector<_T>& other) WS_NOEXCEPT
		{
			if constexpr (WS_CAN_PERFORM_SIMD(_T)) {
#ifndef __WEISS__DISABLE_SIMD
				this->m_sseVector = SIMDSet(other.x, other.y, other.z, other.w);
#endif
			} else {
				std::memcpy(&this->m_arr, &other.m_arr, sizeof(_T) * 4u);
			}
		}

#ifndef __WEISS__DISABLE_SIMD

		template <typename _T_2 = _T>
		inline Vector(const GET_SIMD_TYPE<_T_2>& other) WS_NOEXCEPT
		{
			static_assert(WS_CAN_PERFORM_SIMD(_T));

			if constexpr (std::is_same_v<_T, _T_2>) {
				this->m_sseVector = other;
			} else {
				this->m_sseVector = SIMDSet(static_cast<_T>(SIMDExtractElement<_T_2, 0u>(this->m_sseVector)),
					static_cast<_T>(SIMDExtractElement<_T_2, 1u>(this->m_sseVector)),
					static_cast<_T>(SIMDExtractElement<_T_2, 2u>(this->m_sseVector)),
					static_cast<_T>(SIMDExtractElement<_T_2, 3u>(this->m_sseVector)));
			}
		}

#endif

		template <typename _T_2, size_t _D_2>
		inline Vector(const RawVectorComponents<_T_2, _D_2>& raw) WS_NOEXCEPT
		{
			static_assert(_D_2 <= 4);

			if constexpr (_D_2 == 1)
				this->Set(raw.x);
			else if constexpr (_D_2 == 2)
				this->Set(raw.x, raw.y);
			else if constexpr (_D_2 == 3)
				this->Set(raw.x, raw.y, raw.z);
			else
				this->Set(raw.x, raw.y, raw.z, raw.w);
		}

		inline void Set(const _T& x, const _T& y = 0, const _T& z = 0, const _T& w = 0) WS_NOEXCEPT
		{
			if constexpr (WS_CAN_PERFORM_SIMD(_T)) {
#ifndef __WEISS__DISABLE_SIMD
				this->m_sseVector = SIMDSet<_T>(x, y, z, w);
#endif // #ifndef __WEISS__DISABLE_SIMD
			} else {
				this->x = x;
				this->y = y;
				this->z = z;
				this->w = w;
			}
		}

		[[nodiscard]] inline float GetLength() const WS_NOEXCEPT
		{
			if constexpr (WS_CAN_PERFORM_SIMD(_T)) {
#ifndef __WEISS__DISABLE_SIMD
				return std::sqrt(SIMDDotProduct<_T>(this->m_sseVector, this->m_sseVector));
#endif // #ifndef __WEISS__DISABLE_SIMD
			} else {
				return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
			}
		}


		inline void Normalize() WS_NOEXCEPT
		{
			this->operator/=(this->GetLength());
		}

		template <typename _T_2>
		inline void operator+=(const Vector<_T_2>& other) WS_NOEXCEPT
		{
			if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
#ifndef __WEISS__DISABLE_SIMD
				this->m_sseVector = SIMDAdd<_T>(this->m_sseVector, other.m_sseVector);
#endif // #ifndef __WEISS__DISABLE_SIMD
			} else {
				this->x += other.x;
				this->y += other.y;
				this->z += other.z;
				this->w += other.w;
			}
		}

		template <typename _T_2>
		inline void operator-=(const Vector<_T_2>& other) WS_NOEXCEPT
		{
			if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
#ifndef __WEISS__DISABLE_SIMD
				this->m_sseVector = SIMDSub<_T>(
					this->m_sseVector, other.m_sseVector);
#endif // #ifndef __WEISS__DISABLE_SIMD
			} else {
				this->x -= other.x;
				this->y -= other.y;
				this->z -= other.z;
				this->w -= other.w;
			}
		}

		template <typename _T_2>
		inline void operator*=(const Vector<_T_2>& other) WS_NOEXCEPT
		{
			if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
#ifndef __WEISS__DISABLE_SIMD
				this->m_sseVector = SIMDMul<_T>(this->m_sseVector, other.m_sseVector);
#endif // #ifndef __WEISS__DISABLE_SIMD
			} else {
				this->x *= other.x;
				this->y *= other.y;
				this->z *= other.z;
				this->w *= other.w;
			}
		}

		template <typename _T_2>
		inline void operator/=(const Vector<_T_2>& other) WS_NOEXCEPT
		{
			if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
#ifndef __WEISS__DISABLE_SIMD
				this->m_sseVector = SIMDDiv<_T>(this->m_sseVector, other.m_sseVector);
#endif // #ifndef __WEISS__DISABLE_SIMD
			} else {
				this->x /= other.x;
				this->y /= other.y;
				this->z /= other.z;
				this->w /= other.w;
			}
		}

		template <typename _T_2>
		inline bool operator==(const Vector<_T_2>& other) const WS_NOEXCEPT
		{
			if constexpr (std::is_same_v<_T, _T_2>) {
				return std::memcmp(this->m_arr, other.m_arr, 4u * sizeof(_T)) == 0;
			} else {
				return this->x == other.x && this->y == other.y &&
					this->z == other.z && this->w == other.w;
			}
		}

		template <typename _T_2>
		inline bool operator!=(const Vector<_T_2>& other) const WS_NOEXCEPT
		{
			if constexpr (std::is_same_v<_T, _T_2>) {
				return std::memcmp(this->m_arr, other.m_arr, 4u * sizeof(_T)) != 0;
			} else {
				return this->x != other.x || this->y != other.y ||
					this->z != other.z || this->w != other.w;
			}
		}

		template <typename _T_2, typename = std::enable_if_t<std::is_arithmetic_v<_T_2>, void>>
		inline void operator+=(const _T_2& n) WS_NOEXCEPT
		{
			this->operator+=(Vector<_T_2>(n, n, n, n));
		}

		template <typename _T_2>
		inline void operator-=(const _T_2& n) WS_NOEXCEPT
		{
			this->operator-=(Vector<_T_2>(n, n, n, n));
		}

		template <typename _T_2>
		inline void operator*=(const _T_2& n) WS_NOEXCEPT
		{
			this->operator*=(Vector<_T_2>(n, n, n, n));
		}

		template <typename _T_2>
		inline void operator/=(const _T_2& n) WS_NOEXCEPT
		{
			this->operator/=(Vector<_T_2>(n, n, n, n));
		}

		template <size_t _D>
		inline operator RawVectorComponents<_T, _D>() const WS_NOEXCEPT { return this->m_rawComponents; }

		template <typename _T_2>
		inline static Vector<_T_2> Normalized(const Vector<_T_2>& vec) WS_NOEXCEPT
		{
			Vector<_T> cp(vec);
			cp.Normalize();

			return cp;
		}

		template <typename _T_2, typename _T_3>
		inline static auto CrossProduct3D(const Vector<_T_2>& vecA, const Vector<_T_3>& vecB) WS_NOEXCEPT
			-> Vector<decltype(vecA.x + vecB.x)>
		{
			if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T_2, _T_3)) {
#ifndef __WEISS__DISABLE_SIMD
				const Vector<_T_2> tempA1(vecA.y, vecA.z, vecA.x, 0);
				const Vector<_T_2> tempB1(vecB.z, vecB.x, vecB.y, 0);
				const Vector<_T_2> tempA2(vecA.z, vecA.x, vecA.y, 0);
				const Vector<_T_2> tempB2(vecB.y, vecB.z, vecB.x, 0);

				return tempA1 * tempB1 - tempA2 * tempB2;
#endif // #ifndef __WEISS__DISABLE_SIMD
			} else {
				return Vector<decltype(vecA.x + vecB.x)>(
					vecA.y * vecB.z - vecA.z * vecB.y,
					vecA.z * vecB.x - vecA.x * vecB.z,
					vecA.x * vecB.y - vecA.y * vecB.x,
					0
					);
			}
		}

		template <typename _T_2, typename _T_3>
		static inline auto DotProduct(const Vector<_T_2>& a, const Vector<_T_3>& b) WS_NOEXCEPT
			-> decltype(a.x + b.x)
		{
			if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T_2, _T_3)) {
#ifndef __WEISS__DISABLE_SIMD
				return SIMDDotProduct<_T_2>(a.m_sseVector, b.m_sseVector);
#endif // #ifndef __WEISS__DISABLE_SIMD
			} else {
				return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
			}
		}
	};

	template <typename _T, typename _T_2>
	[[nodiscard]] inline auto operator+(const Vector<_T>& a,
		const Vector<_T_2>& b) WS_NOEXCEPT
		-> Vector<decltype(a.x + b.x)>
	{
		if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
#ifndef __WEISS__DISABLE_SIMD
			return Vector<_T>(SIMDAdd<_T>(a.m_sseVector, b.m_sseVector));
#endif // #ifndef __WEISS__DISABLE_SIMD
		} else {
			return Vector<decltype(a.x + b.x)>(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
		}
	}

	template <typename _T, typename _T_2>
	[[nodiscard]] inline auto operator-(const Vector<_T>& a, const Vector<_T_2>& b) WS_NOEXCEPT
		-> Vector<decltype(a.x - b.x)>
	{
		if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
#ifndef __WEISS__DISABLE_SIMD
			return Vector<_T>(SIMDSub<_T>(a.m_sseVector, b.m_sseVector));
#endif // #ifndef __WEISS__DISABLE_SIMD
		} else {
			return Vector<decltype(a.x - b.x)>(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
		}
	}

	template <typename _T, typename _T_2>
	[[nodiscard]] inline auto operator*(const Vector<_T>& a, const Vector<_T_2>& b) WS_NOEXCEPT
		-> Vector<decltype(a.x* b.x)>
	{
		if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
#ifndef __WEISS__DISABLE_SIMD
			return Vector<_T>(SIMDMul<_T>(a.m_sseVector, b.m_sseVector));
#endif // #ifndef __WEISS__DISABLE_SIMD
		} else {
			return Vector<decltype(a.x* b.x)>(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
		}
	}

	template <typename _T, typename _T_2>
	[[nodiscard]] inline auto operator/(const Vector<_T>& a, const Vector<_T_2>& b) WS_NOEXCEPT
		-> Vector<decltype(a.x / b.x)>
	{
		if constexpr (WS_CAN_SIMD_PERFORM_ARITHMETIC(_T, _T_2)) {
#ifndef __WEISS__DISABLE_SIMD
			return Vector<_T>(SIMDDiv<_T>(a.m_sseVector, b.m_sseVector));
#endif // #ifndef __WEISS__DISABLE_SIMD
		} else {
			return Vector<decltype(a.x / b.x)>(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
		}
	}

	template <typename _T, typename _T_2>
	inline auto operator+(const Vector<_T>& vec, const _T_2& n) WS_NOEXCEPT
		-> Vector<decltype(vec.x + n)>
	{
		return vec + Vector<_T_2>(n, n, n, n);
	}

	template <typename _T, typename _T_2>
	inline auto operator-(const Vector<_T>& vec, const _T_2& n) WS_NOEXCEPT
		-> Vector<decltype(vec.x - n)>
	{
		return vec - Vector<_T_2>(n, n, n, n);
	}

	template <typename _T, typename _T_2>
	inline auto operator*(const Vector<_T>& vec, const _T_2& n) WS_NOEXCEPT
		-> Vector<decltype(vec.x* n)>
	{
		return vec * Vector<_T_2>(n, n, n, n);
	}

	template <typename _T, typename _T_2>
	inline auto operator/(const Vector<_T>& vec, const _T_2& n) WS_NOEXCEPT
		-> Vector<decltype(vec.x / n)>
	{
		return vec / Vector<_T_2>(n, n, n, n);
	}

	template <typename _T>
	inline std::ostream& operator<<(std::ostream& stream, const Vector<_T>& vec) WS_NOEXCEPT
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

	// ///////////////--\\\\\\\\\\\\\\\ \\
	// [/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	// |----------Matrix<_T>----------| \\
	// |\____________________________/| \\
	// \\\\\\\\\\\\\\\--/////////////// \\

	/*
	 * Represents a row-major 4x4 matrix of "_T" values as shown below
	 * |-------------------|-------------------|-------------------|-------------------|
	 * | _T m00 (index 0)  | _T m01 (index 1)  | _T m02 (index 2)  | _T m03 (index 3)  |
	 * | _T m10 (index 4)  | _T m11 (index 5)  | _T m12 (index 6)  | _T m13 (index 7)  |
	 * | _T m20 (index 8)  | _T m21 (index 9)  | _T m22 (index 10) | _T m23 (index 11) |
	 * | _T m30 (index 12) | _T m31 (index 13) | _T m32 (index 14) | _T m33 (index 15) |
	 * |-------------------|-------------------|-------------------|-------------------|
	 */

	template <typename _T>
	class Matrix
	{
	private:
		_T m[16] = { 0 };

	public:
		Matrix() = default;

		inline Matrix(const _T* buff)                 WS_NOEXCEPT { std::memcpy(this->m, buff, sizeof(_T) * 16u); }

		inline Matrix(const std::array<_T, 16u>& arr) WS_NOEXCEPT { std::memcpy(this->m, arr.data(), sizeof(_T) * 16u); }

		inline Matrix(const Matrix<_T>& other) WS_NOEXCEPT { std::memcpy(this->m, other.m, sizeof(_T) * 16u); }

		inline _T& operator[](const size_t i) WS_NOEXCEPT { return this->m[i]; }

		inline const _T& operator[](const size_t i) const WS_NOEXCEPT { return this->m[i]; }

		inline _T& operator()(const size_t r, const size_t c) WS_NOEXCEPT { return this->m[r * 4u + c]; }

		inline const _T& operator()(const size_t r, const size_t c) const WS_NOEXCEPT { return this->m[r * 4u + c]; }

		// --- Static Functions --- //



		static inline Matrix<_T> MakeZeros()    WS_NOEXCEPT { return Matrix<_T>(); }

		static inline Matrix<_T> MakeIdentity() WS_NOEXCEPT {
			return Matrix<_T>(std::array<_T, 16u>{
				1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1
			});
		}

		static inline Matrix<_T> MakeRotationX(const float radX = 0) WS_NOEXCEPT
		{
			const _T sinX = std::sin(radX);
			const _T cosX = std::cos(radX);

			return Matrix<_T>(std::array<_T, 16u>{
				1, 0,    0,     0,
				0, cosX, -sinX, 0,
				0, sinX, cosX,  0,
				0, 0,    0,     1
			});
		}

		static inline Matrix<_T> MakeRotationY(const float radY = 0) WS_NOEXCEPT
		{
			const _T sinY = std::sin(radY);
			const _T cosY = std::cos(radY);

			return Matrix<_T>(std::array<_T, 16u>{
				cosY,  0, sinY, 0,
				0,     1, 0,    0,
				-sinY, 0, cosY, 0,
				0,     0, 0,    1
			});
		}

		static inline Matrix<_T> MakeRotationZ(const float radZ = 0) WS_NOEXCEPT
		{
			const _T sinZ = std::sin(radZ);
			const _T cosZ = std::cos(radZ);

			return Matrix<_T>(std::array<_T, 16u>{
				cosZ, -sinZ, 0, 0,
				sinZ, cosZ,  0, 0,
				0,    0,     1, 0,
				0,    0,     0, 1
			});
		}

		static inline Matrix<_T> MakeRotation(const float radX = 0, const float radY = 0, const float radZ = 0) WS_NOEXCEPT
		{
			return MakeRotationX(radX) * MakeRotationY(radY) * MakeRotationZ(radZ);
		}

		static inline Matrix<_T> MakeRotation(const Vector<_T>& radians) WS_NOEXCEPT
		{
			return Matrix<_T>::MakeRotation(radians.x, radians.y, radians.z);
		}

		static inline Matrix<_T> MakeTranslation(const float x, const float y, const float z) WS_NOEXCEPT
		{
			return Matrix<_T>(std::array<_T, 16u>{
				1,  0,  0,  0,
				0,  1,  0,  0,
				0,  0,  1,  0,
				-x, -y, -z, 1,
			});
		}

		static inline Matrix<_T> MakeTranslation(const Vector<_T>& translation) WS_NOEXCEPT
		{
			return Matrix<_T>::MakeTranslation(translation.x, translation.y, translation.z);
		}

		static inline Matrix<_T> MakePerspective(const float zNear, const float zFar, const float fovRad, const float aspectRatio)
		{
			return Matrix<_T>(std::array<_T, 16u>{
				aspectRatio * fovRad, 0,      0,                                0,
				0,                    fovRad, 0,                                0,
				0,                    0,      zFar / (zFar - zNear),            1,
				0,                    0,      (-zFar * zNear) / (zFar - zNear), 1,
			});
		}

		static inline Matrix<_T> MakeScaling(const float scaleX = 1.0f, const float scaleY = 1.0f, const float scaleZ = 1.0f, const float scaleW = 1.0f) WS_NOEXCEPT
		{
			return Matrix<_T>(std::array<_T, 16u>{
				scaleX, 0, 0, 0,
				0, scaleY, 0, 0,
				0, 0, scaleZ, 0,
				0, 0, 0, scaleW
			});
		}

		static inline Matrix<_T> MakeScaling(const Vecf32& scale) WS_NOEXCEPT
		{
			return Matrix<_T>::MakeScaling(scale.x, scale.y, scale.z, scale.w);
		}

		static inline Matrix<_T> MakeTransposed(const Matrix<_T>& mat) WS_NOEXCEPT
		{
			return Matrix<_T>(std::array<_T, 16u>{
				mat(0, 0), mat(1, 0), mat(2, 0), mat(3, 0),
				mat(0, 1), mat(1, 1), mat(2, 1), mat(3, 1),
				mat(0, 2), mat(1, 2), mat(2, 2), mat(3, 2),
				mat(0, 3), mat(1, 3), mat(2, 3), mat(3, 3)
			});
		}

		// Thanks to: https://stackoverflow.com/questions/349050/calculating-a-lookat-matrix
		static inline Matrix<_T> MakeLookAt(const Vector<_T>& cameraPosition, const Vector<_T>& focalPoint, const Vector<_T>& upDirection) WS_NOEXCEPT
		{
			const Vector<_T> zaxis = Vector<_T>::Normalized(focalPoint - cameraPosition);
			const Vector<_T> xaxis = Vector<_T>::Normalized(Vector<_T>::CrossProduct3D(upDirection, zaxis));
			const Vector<_T> yaxis = Vector<_T>::CrossProduct3D(zaxis, xaxis);

			const _T m30 = -Vector<_T>::DotProduct(xaxis, cameraPosition);
			const _T m31 = -Vector<_T>::DotProduct(yaxis, cameraPosition);
			const _T m32 = -Vector<_T>::DotProduct(zaxis, cameraPosition);

			return Matrix<_T>(std::array<_T, 16u>{
				xaxis.x, yaxis.x, zaxis.x, 0,
				xaxis.y, yaxis.y, zaxis.y, 0,
				xaxis.z, yaxis.z, zaxis.z, 0,
				m30,     m31,     m32,     1
			});
		}
	};

	template <typename _T, typename _T_2>
	inline auto operator*(const Matrix<_T>& matA, const Matrix<_T_2>& matB) WS_NOEXCEPT
		-> Matrix<decltype(matA[0] + matB[0])>
	{
		Matrix<decltype(matA[0] + matB[0])> matResult;

		for (size_t r = 0u; r < 4u; r++) {
			for (size_t c = 0u; c < 4u; c++) {
				const Vector<_T>   vecA = Vector<_T>(matA(r, 0), matA(r, 1), matA(r, 2), matA(r, 3));
				const Vector<_T_2> vecB = Vector<_T_2>(matB(0, c), matB(1, c), matB(2, c), matB(3, c));

				matResult(r, c) = Vector<>::DotProduct(vecA, vecB);
			}
		}

		return matResult;
	}

	template <typename _T>
	inline std::ostream& operator<<(std::ostream& stream, const Matrix<_T>& mat) WS_NOEXCEPT
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

	/*
	 * Multiplies a 1x4 vector with a 4x4 matrix like shown below :
								    |----------------------------------------|
								    | _T_2 m00; _T_2 m01; _T_2 m02; _T_2 m03 |
								    | _T_2 m10; _T_2 m11; _T_2 m12; _T_2 m13 |
	   |------------------------|   | _T_2 m20; _T_2 m21; _T_2 m22; _T_2 m23 |   |----------------------------|
	   | _T x; _T y; _T z; _T w | * | _T_2 m30; _T_2 m31; _T_2 m32; _T_2 m33 | = | decltype(x+m00) x, y, z, w |
	   |------------------------|   |----------------------------------------|   |----------------------------|
	 */

	template <typename _T, typename _T_2>
	inline auto operator*(const Vector<_T>& vec, const Matrix<_T_2>& mat) WS_NOEXCEPT
		-> Vector<decltype(vec.x + mat[0])>
	{
		return Vector<decltype(vec.x + mat[0])>(
			Vector<>::DotProduct(vec, Vector<_T_2>(mat(0, 0), mat(1, 0), mat(2, 0), mat(3, 0))),
			Vector<>::DotProduct(vec, Vector<_T_2>(mat(0, 1), mat(1, 1), mat(2, 1), mat(3, 1))),
			Vector<>::DotProduct(vec, Vector<_T_2>(mat(0, 2), mat(1, 2), mat(2, 2), mat(3, 2))),
			Vector<>::DotProduct(vec, Vector<_T_2>(mat(0, 3), mat(1, 3), mat(2, 3), mat(3, 3)))
		);
	}

	typedef Matrix<std::enable_if_t<std::numeric_limits<float>::is_iec559, float>> Matf32;

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

		Matf32 m_transform = Matf32::MakeIdentity();

	public:
		Transform() = default;

		[[nodiscard]] inline Vecf32 GetRotation()    const WS_NOEXCEPT { return this->m_rotation;    }
		[[nodiscard]] inline Vecf32 GetTranslation() const WS_NOEXCEPT { return this->m_translation; }

		inline void SetRotation   (const Vecf32 &rotation)    WS_NOEXCEPT { this->m_rotation    = rotation;    }
		inline void SetTranslation(const Vecf32 &translation) WS_NOEXCEPT { this->m_translation = translation; }

		inline void Rotate   (const Vecf32 &delta) WS_NOEXCEPT { this->m_rotation    += delta; }
		inline void Translate(const Vecf32 &delta) WS_NOEXCEPT { this->m_translation += delta; }

		[[nodiscard]] inline Matf32 GetTransform()           const WS_NOEXCEPT { return this->m_transform;                 }
		[[nodiscard]] inline Matf32 GetTransposedTransform() const WS_NOEXCEPT { return Matrix<float>::MakeTransposed(this->m_transform); }

		void CalculateTransform() WS_NOEXCEPT;
	};

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

		return Vecf32{
			U.y * V.z - U.z * V.y,
			U.z * V.x - U.x * V.z,
			U.x * V.y - U.y * V.x
		};
	}

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
		static inline void __Print(const LOG_TYPE logType, const T& message0, Args... args) WS_NOEXCEPT
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

	public:
		template <typename T, typename ...Args>
		static inline void Print(const LOG_TYPE logType,   const T& message0, Args... args) WS_NOEXCEPT
		{
			// Lock The Mutex
			std::lock_guard<std::mutex> lock(LOG::m_sPrintMutex);

			WS::LOG::__Print(logType, message0, args...);
		}

		template <typename T, typename ...Args>
		static inline void Println(const LOG_TYPE logType, const T& message0, Args... args) WS_NOEXCEPT
		{
			// Lock The Mutex
			std::lock_guard<std::mutex> lock(LOG::m_sPrintMutex);

			WS::LOG::__Print(logType, message0, args..., '\n');
		}

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

				WindowsImage(WindowsImage &&other) WS_NOEXCEPT;

				WindowsImage(const WindowsImage &other) WS_NOEXCEPT;

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

		inline void OnWheelTurn (const std::function<void(const int16_t)> &functor)              WS_NOEXCEPT { this->m_onWheelTurnFunctors.push_back(functor); }
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
		Vecu16 m_position      = Vecu16(0, 0, 0, 0);
		Veci16 m_deltaPosition = Veci16(0, 0, 0, 0);

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
		Matf32 m_transform = Matf32::MakeIdentity();

		Vecf32 m_position;
		Vecf32 m_rotation;

		Vecf32 m_scale = { 1, 1, 1, 1 };

	public:
		Camera() = default;

		Camera(const Vecf32& position, const Vecf32& rotation, const Vecf32& scale) : m_position(position), m_rotation(rotation), m_scale(scale) { }

		[[nodiscard]] inline Matf32 GetTransform()           const WS_NOEXCEPT { return this->m_transform;                         }
		[[nodiscard]] inline Matf32 GetTransposedTransform() const WS_NOEXCEPT { return Matf32::MakeTransposed(this->m_transform); }

		[[nodiscard]] inline const Vecf32& GetPosition() const WS_NOEXCEPT { return this->m_position; }
		[[nodiscard]] inline const Vecf32& GetRotation() const WS_NOEXCEPT { return this->m_rotation; }

		inline void Rotate     (const Vecf32& delta)    WS_NOEXCEPT { this->m_rotation += delta;   }
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

		const float fov    = 90.0f;
		const float zNear  = 0.1f;
		const float zFar   = 1000.0f;
		const Vecf32 scale = { 1, 1, 1, 1 };
	};

	class PerspectiveCamera : public Camera
	{
	private:
		const Vecf32 UP_VECTOR      = Vecf32(0.0f, 1.0f, 0.0f);
		const Vecf32 FORWARD_VECTOR = Vecf32(0.0f, 0.0f, 1.0f);
		const Vecf32 RIGHT_VECTOR   = Vecf32(1.0f, 0.0f, 0.0f);

		Vecf32 m_forwardVector = FORWARD_VECTOR;
		Vecf32 m_rightVector   = RIGHT_VECTOR;

		float m_fov = 0.0f, m_InvAspectRatio = 0.0f, m_zNear = 0.0f, m_zFar = 0.0f;

		Vecf32 scale{ 1, 1, 1 };

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
		const float  ratation = 0.0f;
		const Vecf32 scale    = { 1, 1, 1, 1 };
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
			template <typename _T>
			class VKObjectWrapper {
			protected:
				_T m_object = VK_NULL_HANDLE;

			public:
				VKObjectWrapper() = default;

				VKObjectWrapper<_T>& operator=(VKObjectWrapper<_T>&& other) WS_NOEXCEPT;

				inline operator _T& () WS_NOEXCEPT { return this->m_object; }

				inline operator _T() const WS_NOEXCEPT { return this->m_object; }

				inline _T& GetRef() WS_NOEXCEPT { return this->m_object; }

				inline _T* GetPtr() WS_NOEXCEPT { return &this->m_object; }

				inline const _T* GetPtr() const WS_NOEXCEPT { return &this->m_object; }

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

				[[nodiscard]] inline Vecu16 GetDimensions() const WS_NOEXCEPT { return this->m_dimensions; }

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

				[[nodiscard]] inline VKPhysicalDeviceData GetPhysicalDeviceData() const WS_NOEXCEPT { return this->m_physicalDeviceData; }

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

				VKFence& operator=(VKFence&& other) WS_NOEXCEPT;

				inline void Wait() const WS_NOEXCEPT
				{
					if (VK_FAILED(vkWaitForFences(*this->m_pDevice, 1u, &this->m_object, VK_TRUE, UINT64_MAX)))
						WS_THROW("[VULKAN] Failed To Wait For Fence");
				}

				inline void Reset() const WS_NOEXCEPT
				{
					if (VK_FAILED(vkResetFences(*this->m_pDevice, 1u, &this->m_object)))
						WS_THROW("[VULKAN] Failed To Reset Fence");
				}

				inline void WaitAndReset() const WS_NOEXCEPT
				{
					this->Wait();
					this->Reset();
				}

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

				[[nodiscard]] inline VkSemaphore        GetFrameBufferFetchedSemaphore() const WS_NOEXCEPT { return this->m_frameBufferFetchedSemaphore; }
				[[nodiscard]] inline VkFramebuffer      GetCurrentFrameBuffer()          const WS_NOEXCEPT { return this->m_frameBuffers[this->m_currentImageIndex]; }
				[[nodiscard]] inline VkExtent2D         GetImageExtent()                 const WS_NOEXCEPT { return this->m_imageExtent2D; }
				[[nodiscard]] inline VkSurfaceFormatKHR GetFormat()                      const WS_NOEXCEPT { return this->m_surfaceFormat; }

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
			 * // ////////////////////////-\\\\\\\\\\\\\\\\\\\\\\\\ \\
			 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
			 * // ||------------------VKTexture------------------|| \\
			 * // |\_____________________________________________/| \\
			 * // \\\\\\\\\\\\\\\\\\\\\\\\-//////////////////////// \\
			 */

			class VKTexture {

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

				[[nodiscard]] inline VkSemaphore GetSubmittedSemaphore() const WS_NOEXCEPT { return this->m_submitedSemaphore; }
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
			template <typename _T>
			class D3D11ObjectWrapper
			{
			protected:
				_T *m_pObject = nullptr;

			public:
				D3D11ObjectWrapper() = default;

				/* This function overloads the assignement operator with an r-value reference to itself
				* It copies the pointer from the "other" and sets it to nullptr.
				* This is done to ensure that the resource isn't freed while this object is being created.
				* (Preventing a "use after free")
				*/
				D3D11ObjectWrapper<_T> &operator=(D3D11ObjectWrapper<_T> &&other);

				virtual ~D3D11ObjectWrapper();

				inline _T*  Get()    WS_NOEXCEPT { return this->m_pObject;  }
				inline _T** GetPtr() WS_NOEXCEPT { return &this->m_pObject; }

				inline _T* operator->() WS_NOEXCEPT { return this->m_pObject; }
				inline operator _T*  () WS_NOEXCEPT { return this->m_pObject; }
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

				D3D11VertexBuffer &operator=(D3D11VertexBuffer &&other) WS_NOEXCEPT;

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
			template <typename _T>
			class D3D12ObjectWrapper
			{
			protected:
				_T* m_pObject = nullptr;

			public:
				D3D12ObjectWrapper() = default;

				/* This function overloads the assignement operator with an r-value reference to itself
				* It copies the pointer from the "other" and sets it to nullptr.
				* This is done to ensure that the resource isn't freed while this object is being created.
				* (Preventing a "use after free")
				*/
				D3D12ObjectWrapper& operator=(D3D12ObjectWrapper<_T> &&other) WS_NOEXCEPT;

				~D3D12ObjectWrapper();

				[[nodiscard]] inline _T*  operator->() WS_NOEXCEPT { return this->m_pObject;  }
				[[nodiscard]] inline _T*  Get()        WS_NOEXCEPT { return this->m_pObject;  }
				[[nodiscard]] inline _T** GetPtr()     WS_NOEXCEPT { return &this->m_pObject; }

				[[nodiscard]] inline operator IUnknown* () const WS_NOEXCEPT { return (IUnknown *)this->m_pObject; }
				[[nodiscard]] inline operator _T*       () const WS_NOEXCEPT { return this->m_pObject;             }
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

				D3D12SwapChain &operator=(D3D12SwapChain &&other) WS_NOEXCEPT;

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

				D3D12DescriptorHeap &operator=(D3D12DescriptorHeap &&other) WS_NOEXCEPT;
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

				D3D12RenderTarget &operator=(D3D12RenderTarget &&other) WS_NOEXCEPT;
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

				D3D12RootSignature &operator=(D3D12RootSignature &&other) WS_NOEXCEPT;
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

				inline void OffsetCurrent(const UINT numDescriptors, const UINT incrementSize) WS_NOEXCEPT
				{
					this->m_cpuHandles.m_current.Offset(numDescriptors, incrementSize);
					this->m_gpuHandles.m_current.Offset(numDescriptors, incrementSize);
				}
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

				D3D12DescriptorHeapManager& operator=(D3D12DescriptorHeapManager&& other) WS_NOEXCEPT;

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

				D3D12RenderPipeline(D3D12RenderPipeline &&other) WS_NOEXCEPT;

				D3D12RenderPipeline(D3D12Device &pDevice, const RenderPipelineDesc &pipelineDesc,
									std::vector<ConstantBuffer *> &pConstantBuffers, std::vector<Texture *> pTextures,
									std::vector<D3D12TextureSampler *> pTextureSamplers, D3D12DescriptorHeapManager& descriptorHeapManager) WS_NOEXCEPT;

				D3D12RenderPipeline &operator=(D3D12RenderPipeline &&other) WS_NOEXCEPT;

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

#ifdef __WEISS__OS_WINDOWS

	template <RenderAPIName _R_API_NAME>
	using GET_TEXTURE_TYPE = typename std::conditional_t<_R_API_NAME == RenderAPIName::DIRECTX11, Internal::D3D11::D3D11Texture,
							 typename std::conditional_t<_R_API_NAME == RenderAPIName::DIRECTX12, Internal::D3D12::D3D12Texture,
							 typename std::conditional_t<_R_API_NAME == RenderAPIName::VULKAN,    Internal::VK::VKTexture, _WS_TYPE_DOESNT_EXIST>>>;

#else

	template <RenderAPIName _R_API_NAME>
	using GET_TEXTURE_TYPE = typename std::conditional_t<_R_API_NAME == RenderAPIName::VULKAN, Internal::VK::VKTexture, _WS_TYPE_DOESNT_EXIST>;

#endif

	/*
	 * // ///////////--\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||-------Vertex-------|| \\
	 * // |\____________________/| \\
	 * // \\\\\\\\\\\--/////////// \\
	 */

	 struct Vertex {
		 RawVectorComponents<float, 4u> position;
		 Colorf32 diffuseColor;
	 };

	/*
	 * // //////////////-\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||-------SceneObject-------|| \\
	 * // |\_________________________/| \\
	 * // \\\\\\\\\\\\\\-////////////// \\
	*/

	struct SceneObject {
		std::vector<Vertex>   vertices;
		std::vector<uint32_t> indices;

		Transform transform;

	public:
		static SceneObject Load(const char* filename) WS_NOEXCEPT;
	};

	/*
	 * // //////////////-\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||--------SceneNode--------|| \\
	 * // |\_________________________/| \\
	 * // \\\\\\\\\\\\\\-////////////// \\
	 */

	struct SceneNode
	{
		Transform transform;
		std::vector<std::unique_ptr<SceneNode>> pNodes;
		std::vector<std::unique_ptr<SceneObject>> pObjects;

		void Draw(RenderAPIHandle& apiHandle, const Matf32& currentTransform = Matf32::MakeIdentity()) const WS_NOEXCEPT;
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
		SceneNode m_rootNode;

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

/*
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
