#include "Editor.h"
#include "EditorUI.h"
#include <Core/Base/macro.h>
#include <Engine.h>
#include <Function/Scene/Scene.h>
namespace Stone
{
	void Editor::initialize(int argc, char* argv[])
	{
		LOG_INFO("Initilaize Eidtor");
		m_QApp = std::make_unique<QApplication>(argc, argv);
		m_RunTimeEngine = &PublicSingleton<Engine>::getInstance();
		m_RunTimeEngine->setupUISurface(&PublicSingleton<EditorUI>::getInstance());
	}
	void Editor::run()
	{
		LOG_INFO("Runing");
		m_RunTimeEngine->m_UISurface->run();
		int qrnt = m_QApp->exec();
	}
}

