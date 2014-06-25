#include <math.h>
#include <QFile>
#include <QString>
#include <QMessageBox>
#pragma once

class music
{
    const unsigned char maskByte = 254;
    unsigned char mask[8];
    const int maskSize = 8;
    int WriteByte(int position, unsigned char text, QFile &audio);
    unsigned char ReadByte(int position, QFile &audio);
public:
    void Write(QString audio, QString text);
    void Read(QString audio, QString text);
    music();
};
