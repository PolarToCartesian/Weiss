#define D3DCOMPILE_DEBUG 1

struct VSOUT
{
    float4 out_position : SV_POSITION;
    float2 out_uv : UV;
    float4 out_color : COLOR;
};

cbuffer testCB : register(b0)
{
    matrix transform;
};

VSOUT main(float4 position : POSITION, float4 uv : UV, float4 color : COLOR)
{
    VSOUT _out;
    _out.out_position = mul(position, transform);
    _out.out_color = color;
    _out.out_uv = uv.xy;

    return _out;
}