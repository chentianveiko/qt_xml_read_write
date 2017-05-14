#include "configxmlreadwrite.h"

configXmlReadWrite::configXmlReadWrite(QTextBrowser *txt_dis)
{
    m_text_brodis = txt_dis;
}

bool configXmlReadWrite::read(QIODevice *device)
{
    setDevice(device);
    while(!atEnd())
    {
        readNext();
        if(isStartElement())
        {
            if(name() == "config")
            {
                read_data();
            }
        }
    }
    return !error();
}

void configXmlReadWrite::read_data()
{
    m_text_brodis->insertPlainText("Start to read data...\r\n");
    while(!atEnd())
    {
        readNext();
        if(isStartElement())
        {
            if(name() == "period")
            {
                read_period();
            }
            if(name() == "startweek")
            {
                read_startweek();
            }
            if(name() == "eventnumber")
            {
                read_eventnumber();
            }
        }
        if(isEndElement())
        {
            if(name() == "data")
            {
                m_text_brodis->insertPlainText("Now at the end of data element...\r\n");
                break;
            }
        }
    }
}

void configXmlReadWrite::read_startweek()
{
    m_text_brodis->insertPlainText("startweek is: "+readElementText() + "\r\n");
}

void configXmlReadWrite::read_eventnumber()
{
    m_text_brodis->insertPlainText("eventNumber is: "+readElementText() + "\r\n");
}

void configXmlReadWrite::read_period()
{
    m_text_brodis->insertPlainText("eventNumber is: \r\n");
    while(!atEnd())
    {
        readNext();
        if(isStartElement())
        {
            if(name() == "id")
            {
                read_id();
            }
            if(name() == "starttime")
            {
                read_starttime();
            }
            if(name() == "endtime")
            {
                read_endtime();
            }
            if(name() == "exception")
            {
                read_exception();
            }
            if(name() == "duration")
            {
                read_duration();
            }
            if(name() == "event")
            {
                read_event();
            }
        }
        if(isEndElement())
        {
            if(name() == "period")
            {
            qDebug()<<"Now at the end of period...";
            break;
            }
        }
    }
}

void configXmlReadWrite::read_id()
{
    m_text_brodis->insertPlainText("id is: "+readElementText() + "\r\n");
}

void configXmlReadWrite::read_starttime()
{
    m_text_brodis->insertPlainText("starttime is: "+readElementText() + "\r\n");
}

void configXmlReadWrite::read_endtime()
{
    m_text_brodis->insertPlainText("endtime is: "+readElementText() + "\r\n");
}

void configXmlReadWrite::read_exception()
{
    m_text_brodis->insertPlainText("Start to read exception...\r\n");
    while(!atEnd())
    {
        readNext();
        if(isStartElement())
        {
            if(name() == "subexception")
            {
                read_subexception();
            }
        }
        if(isEndElement())
        {
            if(name() == "exception")
            {
            m_text_brodis->insertPlainText("Now at the end of exception...\r\n");
            break;
            }
        }
    }
}

void configXmlReadWrite::read_subexception()
{
    m_text_brodis->insertPlainText("Start to read subexception...\r\n");
    while(!atEnd())
    {
        readNext();
        if(isStartElement())
        {
            if(name() == "id")
            {
                read_id();
            }
            if(name() == "starttime")
            {
                read_starttime();
            }
            if(name() == "endtime")
            {
                read_endtime();
            }
            if(name() == "description")
            {
                read_description();
            }
        }
        if(isEndElement())
        {
            if(name() == "subexception")
            {
            m_text_brodis->insertPlainText("Now at the end of subexception...\r\n");
            break;
            }
        }
    }
}

void configXmlReadWrite::read_description()
{
    m_text_brodis->insertPlainText("description is: "+readElementText() + "\r\n");
}

void configXmlReadWrite::read_duration()
{
    m_text_brodis->insertPlainText("duration is: "+readElementText() + "\r\n");
}

void configXmlReadWrite::read_event()
{
    m_text_brodis->insertPlainText("Start to read event...\r\n");
    while(!atEnd())
    {
        readNext();
        if(isStartElement())
        {
            if(name() == "id")
            {
                read_id();
            }
            if(name() == "offsettime")
            {
                read_offsettime();
            }
            if(name() == "eventdesc")
            {
                read_eventdesc();
            }
            if(name() == "lasthandle")
            {
                read_lasthandle();
            }
        }
        if(isEndElement())
        {
            if(name() == "event")
            {
            m_text_brodis->insertPlainText("Now at the end of event..\r\n");
            break;
            }
        }
    }
}

void configXmlReadWrite::read_offsettime()
{
    m_text_brodis->insertPlainText("offsettime is: "+readElementText() + "\r\n");
}

void configXmlReadWrite::read_eventdesc()
{
    m_text_brodis->insertPlainText("Start to read eventdesc...\r\n");
    while(!atEnd())
    {
        readNext();
        if(isStartElement())
         {
            if(name() == "eventname")
            {
                read_eventname();
            }
            if(name() == "prompt")
            {
                read_prompt();
            }
         }
        if(isEndElement())
        {
            if(name() == "eventdesc")
            {
                m_text_brodis->insertPlainText("Now at the end of eventdesc...\r\n");
                break;
            }
        }
    }
}

void configXmlReadWrite::read_eventname()
{
    m_text_brodis->insertPlainText("eventname is: "+readElementText() + "\r\n");
}

void configXmlReadWrite::read_prompt()
{
    m_text_brodis->insertPlainText("prompt is: "+readElementText() + "\r\n");
}

void configXmlReadWrite::read_lasthandle()
{
    m_text_brodis->insertPlainText("lasthandle is: "+readElementText() + "\r\n");
}

void configXmlReadWrite::read_unknow()
{

}

