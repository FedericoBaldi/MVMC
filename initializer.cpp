#include "initializer.h"
#include "GUI/Components/maindisplay.h"
#include "GUI/Components/maindisplayclone.h"
#include "mainwindow.h"
#include "GUI/Components/monitor.h"

Initializer::Initializer(QObject *parent) : QObject(parent)
{
  m_viewList.clear();
}

Initializer::~Initializer()
{
  m_handlerThread.quit();
}

void Initializer::start()
{
    m_dataHandler = new DataHandler();
    m_dataHandler->moveToThread(&m_handlerThread);
    m_handlerThread.start();
    bool connectionOK = QObject::connect(this, SIGNAL(dataHandlerSetUp_signal()),
                                         m_dataHandler, SLOT(setupDataHandler()), Qt::AutoConnection);
    assert(connectionOK);

    m_dataAdapater = new DataAdapter(m_dataHandler);
    emit dataHandlerSetUp_signal();

    m_viewList.append(new MainDisplay(m_dataAdapater));
    m_viewList.append(new MainDisplayClone(m_dataAdapater));
    m_mainWindow = new MainWindow(m_dataAdapater, m_viewList);
    m_mainWindow->show();
}
