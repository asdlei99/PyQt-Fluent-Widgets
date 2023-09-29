#pragma once

#include <QObject>

#define signalBus (SignalBus::instance())

class SignalBus : public QObject
{
    Q_OBJECT

public:
    SignalBus(const SignalBus&) = delete;
    SignalBus& operator=(const SignalBus&) = delete;

    static SignalBus& instance()
    {
        static SignalBus bus;
        return bus;
    }

signals:
    void switchToSampleCard(const QString& routeKey, int index);
    void micaEnabledChanged(bool isEnabled);
    void supported();

private:
    SignalBus() {}
};