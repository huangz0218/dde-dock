#include "pluginitemwrapper.h"

PluginItemWrapper::PluginItemWrapper(DockPluginInterface *plugin,
                                     QString uuid, QWidget * parent) :
    AbstractDockItem(parent),
    m_plugin(plugin),
    m_uuid(uuid)
{
    qDebug() << "PluginItemWrapper created " << m_plugin->name() << m_uuid;

//    setStyleSheet("PluginItemWrapper { background-color: red } ");

    if (m_plugin) {
        QWidget * item = m_plugin->getItem(uuid);
        setFixedSize(item->size());

        if (item) {
            setFixedSize(item->size());
            item->setParent(this);
            item->move(0, 0);

            emit widthChanged();
        }
    }
}

PluginItemWrapper::~PluginItemWrapper()
{
    qDebug() << "PluginItemWrapper destroyed " << m_plugin->name() << m_uuid;
}

QString PluginItemWrapper::uuid() const
{
    return m_uuid;
}
