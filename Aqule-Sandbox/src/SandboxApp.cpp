#include "Aqule.hpp"

class LayerTest : public Aq::Layer
{
public:
	LayerTest()
		: Layer("test")
	{

	}

	void OnUpdate() override
	{
		// AQ_INFO("Test Layer (update)");

        if (Aq::Input::IsKeyPressed(Aq::Key::A))
        	if (Aq::Input::IsKeyPressed(Aq::Key::W))
        		AQ_TRACE("Have Fun!!");

	}

	void OnEvent(Aq::Event& event) override
	{
		AQ_TRACE("x: {0}, y: {1}", Aq::Input::GetMousePosition().x, Aq::Input::GetMousePosition().y);
	}
};

class TriangleLayer : public Aq::Layer
{
public:
	TriangleLayer()
		: Layer("Triangle")
	{

	}

	void OnAttach() override
	{
	}

	void OnUpdate() override
	{
		// Draw the triangle !
		GLuint VertexArrayID;
		glGenVertexArrays(1, &VertexArrayID);
		glBindVertexArray(VertexArrayID);

		std::unique_ptr<Aq::Shader> shader = std::unique_ptr<Aq::Shader>(Aq::Shader::Create("Shader", "./Aqule-Sandbox/assets/shader/vert.shader", "./Aqule-Sandbox/assets/shader/frag.shader"));
		shader->Bind();

		static const GLfloat g_vertex_buffer_data[] = { 
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f,
		};

		GLuint vertexbuffer;
		glGenBuffers(1, &vertexbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);
		glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
		glDisableVertexAttribArray(0);

	}
};

class Sandbox : public Aq::Application
{
public:
    Sandbox()
    {
    	PushOverlay(new TriangleLayer());
    	// PushLayer(new LayerTest());
    }
    ~Sandbox()
    {
        
    }
};

Aq::Application* Aq::CreateApplication()
{
    return new Sandbox();
}