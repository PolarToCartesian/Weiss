#include "Weiss.h"

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
namespace WS {

	/*
	 * // ///////////////////////--\\\\\\\\\\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||--------------------Rect--------------------|| \\
	 * // |\____________________________________________/| \\
	 * // \\\\\\\\\\\\\\\\\\\\\\\--/////////////////////// \\
	 */

#ifdef __WEISS__OS_WINDOWS

		Rect::Rect(const RECT& rect) WS_NOEXCEPT
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
		this->m_transform = Matf32::MakeTranslation(this->m_translation);
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

			WindowsImage::WindowsImage(WindowsImage&& other) WS_NOEXCEPT
			{
				this->m_width = other.m_width;
				this->m_height = other.m_height;
				this->m_nPixels = other.m_nPixels;

				this->m_buff = std::move(other.m_buff);
			}

			WindowsImage::WindowsImage(const WindowsImage& other) WS_NOEXCEPT
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
				this->m_deltaPosition = Veci16(0, 0, 0, 0);
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
								this->m_deltaPosition += Veci16(static_cast<int16_t>(ri.data.mouse.lLastX), static_cast<int16_t>(ri.data.mouse.lLastY), 0, 0);

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
		: Camera(descriptor.position, descriptor.rotation, descriptor.scale), m_fov(descriptor.fov), m_zNear(descriptor.zNear), m_zFar(descriptor.zFar)
	{
		auto recalculateAspectRatio = [this](const Vecu16& clientDims)
		{
			this->m_InvAspectRatio = static_cast<float>(clientDims.y) / clientDims.x;
		};

		recalculateAspectRatio({ pWindow->GetClientWidth(), pWindow->GetClientHeight() });

		pWindow->OnResize(recalculateAspectRatio);
	}

	void PerspectiveCamera::CalculateTransform() WS_NOEXCEPT
	{
		const Matf32 rotationMatrix = Matf32::MakeRotation(this->m_rotation * (-1));
		const Vecf32 focusPosition  = (FORWARD_VECTOR * rotationMatrix) + this->m_position;
		const Vecf32 upDirection    = UP_VECTOR * rotationMatrix;

		this->m_forwardVector = FORWARD_VECTOR * rotationMatrix;
		this->m_rightVector   = RIGHT_VECTOR   * rotationMatrix;

		this->m_transform = Matf32::MakeScaling(this->m_scale)
						  * Matf32::MakeLookAt(this->m_position, focusPosition, upDirection)
						  * Matf32::MakePerspective(this->m_zNear, this->m_zFar, this->m_fov, this->m_InvAspectRatio);
	}

	void PerspectiveCamera::HandleMouseMovements(Mouse& mouse, const float sensitivity) WS_NOEXCEPT
	{
		mouse.OnMouseMove([sensitivity, this, &mouse](const Vecu16 position, const Veci16 delta)
			{
				if (mouse.IsCursorInWindow()) {
					this->Rotate(Vecf32( sensitivity * delta.y, sensitivity * delta.x, 0.0f ));
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
		: Camera(descriptor.position, Vecf32{ 0.0f, descriptor.ratation, 0.0f }, descriptor.scale)
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
		this->m_transform = Matf32::MakeTranslation(this->m_position)
						  * Matf32::MakeRotationZ(this->m_rotation.z)
						  * Matf32::MakeScaling(Vecf32(this->m_scale.x * this->m_InvAspectRatio,
													   this->m_scale.y, this->m_scale.z, 1.0f));
	}

	void OrthographicCamera::HandleMouseMovements(Mouse& mouse, const float sensitivity) WS_NOEXCEPT
	{

	}

	void OrthographicCamera::HandleKeyboardInputs(Keyboard& keyboard, const float speed, const char forward, const char backward, const char left, const char right, const char up, const char down) WS_NOEXCEPT
	{
		if (keyboard.IsKeyDown(right))
			this->m_position.x += speed;
		if (keyboard.IsKeyDown(left))
			this->m_position.x -= speed;

		if (keyboard.IsKeyDown(up))
			this->m_position.y += speed;
		if (keyboard.IsKeyDown(down))
			this->m_position.y -= speed;
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

			VKFence& VKFence::operator=(VKFence&& other) WS_NOEXCEPT
			{
				std::swap(this->m_object, other.m_object);

				this->m_pDevice = std::move(other.m_pDevice);

				return *this;
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

				if (!fileStream.is_open())
					WS_THROW("Could Not Read Vertex Shader FIle");

				std::string   sourceCode((std::istreambuf_iterator<char>(fileStream)), (std::istreambuf_iterator<char>()));
				Microsoft::WRL::ComPtr<ID3DBlob> pErrorBlob;

				if (D3DCompile(sourceCode.c_str(), sourceCode.size(), NULL, NULL, NULL, "main", "vs_5_0", 0, 0, &pBlob, &pErrorBlob) != S_OK)
				{
					//std::cout << ((char*)pErrorBlob->GetBufferPointer()) << '\n';
					WS_THROW("Could Not Compile Vertex Shader");
				}

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

				if (!fileStream.is_open())
					WS_THROW("Could Not Read Pixel Shader FIle");

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

			D3D11VertexBuffer& D3D11VertexBuffer::operator=(D3D11VertexBuffer&& other) WS_NOEXCEPT
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

			D3D12SwapChain& D3D12SwapChain::operator=(D3D12SwapChain&& other) WS_NOEXCEPT
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

			D3D12DescriptorHeap& D3D12DescriptorHeap::operator=(D3D12DescriptorHeap&& other) WS_NOEXCEPT
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

			D3D12RenderTarget& D3D12RenderTarget::operator=(D3D12RenderTarget&& other) WS_NOEXCEPT
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

			D3D12RootSignature& D3D12RootSignature::operator=(D3D12RootSignature&& other) WS_NOEXCEPT
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

			D3D12DescriptorHeapManager& D3D12DescriptorHeapManager::operator=(D3D12DescriptorHeapManager&& other) WS_NOEXCEPT
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

			D3D12RenderPipeline::D3D12RenderPipeline(D3D12RenderPipeline&& other) WS_NOEXCEPT
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

			D3D12RenderPipeline& D3D12RenderPipeline::operator=(D3D12RenderPipeline&& other) WS_NOEXCEPT
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
	 * // //////////////-\\\\\\\\\\\\\\ \\
	 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
	 * // ||-------SceneObject-------|| \\
	 * // |\_________________________/| \\
	 * // \\\\\\\\\\\\\\-////////////// \\
	*/

 	SceneObject SceneObject::Load(const char* filename) WS_NOEXCEPT
	{ //TODO:: FINISH
		std::ifstream objectFile(filename);

		if (!objectFile.is_open())
			WS_THROW("Oject File Could Not Be Read/Opened");

		SceneObject newObject;

		char junk;
		std::string line;
		while (std::getline(objectFile, line)) {
			if (line.length() <= 2) continue;

			std::istringstream iss(line);

			if (line[0] == 'f') { // Face
				uint32_t i1, i2, i3;

				iss >> junk >> i1 >> i2 >> i3;

				newObject.indices.reserve(3u);
				newObject.indices.push_back(i1 - 1u);
				newObject.indices.push_back(i2 - 1u);
				newObject.indices.push_back(i3 - 1u);
			} else if (line[0] == 'v') { // Vertex Position
				if (line[1] == ' ') {
					RawVectorComponents<float, 4u> raw{0.0f, 0.0f, 0.0f, 1.0f};

					iss >> junk >> raw.x >> raw.y >> raw.z;

					newObject.vertices.push_back({raw, COLOR_F32_BLACK});
				}
			}
		}

		return newObject;
	}

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
 * // ////////////////////////////////--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\
 * // |/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\| \\
 * // ||--------------------STATIC MEMBER VARIABLES--------------------|| \\
 * // |\_______________________________________________________________/| \\
 * // \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--///////////////////////////////// \\
 */

// LOG Static Class
std::mutex                WS::LOG::m_sPrintMutex = std::mutex();

// VKRenderPass
std::vector<VkRenderPass> WS::Internal::VK::VKRenderPass::m_renderPasses = { };

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
