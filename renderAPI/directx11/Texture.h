#pragma once

#include "internal/Include.h"
#include "../common/Include.h"
#include "../../common/Include.h"

#ifdef __WEISS__OS_WINDOWS

namespace WS       {
namespace Internal {
namespace D3D11    {

	typedef D3D11ObjectWrapper<ID3D11ShaderResourceView> D3D11TextureObjectWrapper;

	class D3D11Texture : public Texture,
						 public D3D11TextureObjectWrapper {
	private:
		D3D11DeviceObjectWrapper*        m_pDevice        = nullptr;
		D3D11DeviceContextObjectWrapper* m_pDeviceContext = nullptr;

		size_t m_slot = 0u;

		Microsoft::WRL::ComPtr<ID3D11Texture2D> m_texture2D;

		bool m_useMipmaps;

	public:
		D3D11Texture() = default;
		D3D11Texture(D3D11DeviceObjectWrapper& pDevice,
					 D3D11DeviceContextObjectWrapper* pDeviceContext,
					 const size_t width, const size_t height, const size_t slot, const bool useMipmaps);

		void Bind() const noexcept;

		virtual void Update(const Image& image) override;
	};

}; // D3D11
}; // Internal
}; // WS

#endif // __WEISS__OS_WINDOWS