#ifndef CONFIGXMLREADWRITE_H
#define CONFIGXMLREADWRITE_H

#include <QtCore>
#include <QIODevice>
#include <QStringList>
#include <QTextBrowser>

class configXmlReadWrite : public QXmlStreamReader
{
public:
    configXmlReadWrite(QTextBrowser *txt_dis);
    bool read(QIODevice *device);

private:
    QTextBrowser *m_text_brodis;

    void read_data();
    void read_startweek();
    void read_eventnumber();
    void read_period();
    void read_id();
    void read_starttime();
    void read_endtime();
    void read_exception();
    void read_subexception();
    void read_description();
    void read_duration();
    void read_event();
    void read_offsettime();
    void read_eventdesc();
    void read_eventname();
    void read_prompt();
    void read_lasthandle();
    void read_unknow();
};

#endif // CONFIGXMLREADWRITE_H
