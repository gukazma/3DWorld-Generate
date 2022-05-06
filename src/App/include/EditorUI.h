#pragma once
#include "Core/Base/PublicSingleton.h"
#include "Function/UI/UIInterface.h"
#include "Mainwindow.h"
#include <Function/Render/Interface/FrameBuffer.h>
namespace Stone
{
	class EditorUI : public UIInterface, public PublicSingleton<EditorUI>
	{
	public:
		EditorUI();
		~EditorUI();
		void run() override;

		void tick() override;
	private:
		MainWindow* m_Mainwindow;
		std::shared_ptr<FrameBuffer> m_FrameBuffer = nullptr;
	};
}