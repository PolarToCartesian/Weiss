---WS PIXEL SHADER SOURCE CODE--
---HLSL---
#define D3DCOMPILE_DEBUG 1

Texture2D tex : register(t0);

SamplerState splr : register(s0);

float4 main(float4 position : SV_POSITION, float2 uv : UV, float4 color : COLOR) : SV_TARGET
{
    return color;
    //return tex.Sample(splr, uv);
}
---SPIR-V---
#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 fragColor;

layout(location = 0) out vec4 outColor;

void main() {
    outColor = vec4(fragColor, 1.0);
}
---EOF---