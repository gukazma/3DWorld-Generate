#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include <QLabel>
#include <QTimer>
#include "EditorRenderWidget.h"
#include <iostream>

#include <Function/Scene/Scene.h>
#include <Resource/Components/Mesh.h>
#include <Resource/Components/Transform.h>
#include <Resource/Data/Implement/VCG/VCGMesh.h>
namespace Stone
{
    MainWindow::MainWindow(QWidget* parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        m_DockManager = new ads::CDockManager(this);

        m_ViewportDock = new ads::CDockWidget("Viewport");
        m_RendererWidget = new EditorRendererWidget(this);
        m_ViewportDock->setWidget(m_RendererWidget);
        m_DockManager->addDockWidget(ads::TopDockWidgetArea, m_ViewportDock);


        connect(ui->actionImportMesh, &QAction::triggered, this, &MainWindow::importMesh);
    }

    MainWindow::~MainWindow()
    {
        delete ui;
        delete m_DockManager;
        //delete m_RendererWidget;
    }

    void MainWindow::importMesh()
    {
        auto testMesh = PublicSingletonInstance(Scene).CreateObject("testMesh");
        testMesh.AddComponent<MeshComponent<VCGMesh>>("D:/datas/ply/scene_mesh_refine.ply");
        testMesh.AddComponent<TransformComponent>();
    }
}

