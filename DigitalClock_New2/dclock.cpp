#include "dclock.h"

DClock::DClock(QObject *parent) : QObject(parent)
{

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(mySlot())) ;
    timer->start(1000) ;

}

int DClock::second() const
{
    return m_second;
}

int DClock::minute() const
{
    return m_minute;
}

int DClock::hour() const
{
    return m_hour;
}

void DClock::setSecond(int second)
{
    if (m_second == second)
        return;

    m_second = second;
    emit secondChanged(m_second);
}

void DClock::setMinute(int minute)
{
    if (m_minute == minute)
        return;

    m_minute = minute;
    emit minuteChanged(m_minute);
}

void DClock::setHour(int hour)
{
    if (m_hour == hour)
        return;

    m_hour = hour;
    emit hourChanged(m_hour);
}

void DClock::mySlot()
{

int mySecond = m_second+1 ;
int myMinute = m_minute+1 ;
int myHour = m_hour +1 ;

setSecond(mySecond) ;

if(mySecond == 60){
  setSecond(0) ;
  setMinute(myMinute) ;

  if(myMinute == 60){
      setMinute(0);
      setHour(myHour);

      if(myHour == 24){
          setHour(0) ;
      };
  };
};

}
