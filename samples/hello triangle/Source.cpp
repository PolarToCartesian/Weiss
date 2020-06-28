//#define __WEISS__DISABLE_SIMD

#include <Weiss.h>

#pragma comment(lib, "WeissEngine.lib")

using namespace WS;

struct Vertex
{
    Vecf32 position;
    RawVectorComponents<float, 2u> uv;
    Colorf32 color;
};

struct TestCB
{
    Matf32 transform;
};

int WS::WeissEntryPoint(int argc, char** argv)
{
    WIN_ENABLE_CONSOLE();

    try
    {
        WindowDescriptor desc = {1920u, 1080u, 0u, 0u, "test"};

        Window window(desc);

        RenderAPIHandle renderAPI = RenderAPI::Create(RenderAPIName::DIRECTX12);

        TestCB cbuff;

        std::vector<RenderPipelineDesc> pipelineDescs{RenderPipelineDesc{
            "samples/hello triangle/vert.src.ws",
            {{"POSITION", ShaderInputElementType::VECTOR_4D_FLOAT_32},
             {"UV",       ShaderInputElementType::VECTOR_2D_FLOAT_32},
             {"COLOR",    ShaderInputElementType::VECTOR_4D_FLOAT_32}},
            "samples/hello triangle/frag.src.ws",
            {0u},
            {},
            {},
            PrimitiveTopology::TRIANGLES}
        };

        renderAPI->InitRenderAPI(&window, 144u);

        renderAPI->CreateConstantBuffer(sizeof(TestCB), 0u);
        //renderAPI->CreateTexture(image, 0u, false);
        //renderAPI->CreateTextureSampler(TextureFilter::POINT, 0u);

        renderAPI->InitPipelines(pipelineDescs);

        std::array<Vertex, 3u> vertices{
            Vertex{{+0.0f, +1.0f, 0.0f, 1.0f}, {0.5f, 0.0f}, {1.0f, 0.0f, 0.0f, 1.0f}},
            Vertex{{+1.0f, -1.0f, 0.0f, 1.0f}, {1.0f, 1.0f}, {0.0f, 1.0f, 0.0f, 1.0f}},
            Vertex{{-1.0f, -1.0f, 0.0f, 1.0f}, {0.0f, 1.0f}, {0.0f, 0.0f, 1.0f, 1.0f}},
        };

        std::array<uint32_t, 3u> indices{0u, 1u, 2u};

        Drawable drawable{
            0u, renderAPI->CreateVertexBuffer(vertices.size(), sizeof(Vertex)),
            renderAPI->CreateIndexBuffer(indices.size())
        };

        PerspectiveCamera cam(&window, {Vecf32{0.0f, 0.0f, -2.0f}, Vecf32{}, WS::HALF_PI, 0.01f, 1000.f, Vecf32{0.2f, 0.2f, 0.2f, 0.2f}});
        //OrthographicCamera cam(window, { Vecf32{0.0f, 0.0f, 0.0f, 1.0f}, 0.0f, Vecf32{0.2f,0.2f,0.2f} });

        cbuff.transform = cam.GetTransposedTransform();

        renderAPI->GetVertexBuffer(drawable.vertexBufferIndex).Set(vertices);
        renderAPI->GetIndexBuffer(drawable.indexBufferIndex.value()).Set(indices);
        renderAPI->GetConstantBuffer(0).Set(cbuff);
        renderAPI->GetVertexBuffer(drawable.vertexBufferIndex).Update();
        renderAPI->GetIndexBuffer(drawable.indexBufferIndex.value()).Update();

        cam.HandleMouseMovements(window.GetMouse(), 0.001f);

        while (window.IsRunning())
        {
            window.Update();

            cam.HandleKeyboardInputs(window.GetKeyboard(), 0.1f, 'W', 'S', 'A', 'D',
                                     VK_SPACE, VK_SHIFT);

            cam.CalculateTransform();
            renderAPI->GetConstantBuffer(0).Set(cam.GetTransposedTransform());
            renderAPI->GetConstantBuffer(0).Update();
            //--//
            renderAPI->BeginDrawing();
            renderAPI->Draw(drawable, indices.size());
            renderAPI->EndDrawing();

            renderAPI->Present(true);
        }
    } catch (const std::runtime_error &e) {
           WS::LOG::Print(LOG_TYPE::LOG_ERROR,
                          "\n--------------------------------Weiss Exception "
                          "Catpure--------------------------------\n\n",
                          "");
           WS::LOG::Println(LOG_TYPE::LOG_ERROR, e.what());
           WS::LOG::Print(LOG_TYPE::LOG_ERROR,
                          "\n--------------------------------Weiss Exception "
                          "Catpure--------------------------------\n\n");
        
        WS_ERROR_MESSAGE(e.what());
    }

    std::cin.get();

    return 0;
}