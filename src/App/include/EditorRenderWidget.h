#pragma once
#include <glad/glad.h>
#include <qopenglwidget.h>
#include <memory>
#include <Function/Event/Input.h>
namespace Stone
{
	class FrameBuffer;
	class VertexArray;
	class Shader;
	class EditorRendererWidget : public QOpenGLWidget
	{
	public:
		EditorRendererWidget(QWidget* parent);
		~EditorRendererWidget();
		
		void initializeGL() override;
		void resizeGL(int w, int h) override;
		void paintGL() override;
		// Event handlers
		virtual void mousePressEvent(QMouseEvent* event) override;
		virtual void mouseReleaseEvent(QMouseEvent* event) override;
		virtual void mouseDoubleClickEvent(QMouseEvent* event) override;
		virtual void mouseMoveEvent(QMouseEvent* event) override;
		virtual void wheelEvent(QWheelEvent* event) override;


		std::shared_ptr<MousePos> m_MousePos;
		std::shared_ptr<MouseAngle> m_MouseAngle;
	private:
		void renderImGui();
	};
}