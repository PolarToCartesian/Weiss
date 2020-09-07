#define D3DCOMPILE_DEBUG 1

Texture2D tex : register(t0);

SamplerState splr : register(s0);

float4 main(float4 position : SV_POSITION, float2 uv : UV, float4 color : COLOR) : SV_TARGET
{
    //return float4(1.f, 0.f,0.f, 1.f);
    return color;
    //return tex.Sample(splr, uv);
}