---WS VERTEX SHADER SOURCE CODE--
---HLSL---
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
---SPIR-V---
#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) out vec3 fragColor;

vec2 positions[3] = vec2[](
    vec2(0.0, -0.5),
    vec2(0.5, 0.5),
    vec2(-0.5, 0.5)
);

vec3 colors[3] = vec3[](
    vec3(1.0, 0.0, 0.0),
    vec3(0.0, 1.0, 0.0),
    vec3(0.0, 0.0, 1.0)
);

void main() {
    gl_Position = vec4(positions[gl_VertexIndex], 0.0, 1.0);
    fragColor = colors[gl_VertexIndex];
}
---EOF---