#ifndef DCLOCK_H
#define DCLOCK_H
#include <QTimer>
#include <QObject>
#include <QQmlContext>
#include <QDebug>

class DClock : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int second READ second WRITE setSecond NOTIFY secondChanged)
    Q_PROPERTY(int minute READ minute WRITE setMinute NOTIFY minuteChanged)
    Q_PROPERTY(int hour READ hour WRITE setHour NOTIFY hourChanged)



public:
    explicit DClock(QObject *parent = nullptr);

    int second() const;
    int minute() const;
    int hour()   const;


    void setSecond(int second);
    void setMinute(int minute);
    void setHour(int hour);

signals:

    void secondChanged(int second);
    void minuteChanged(int minute);
    void hourChanged  (int hour);

public slots:

    void mySlot() ;

private:

    int m_second = 55;
    int m_minute = 59;
    int m_hour   = 23;
};

#endif // DCLOCK_H
