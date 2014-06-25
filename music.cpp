#include "music.h"


music::music()
{
    for(int i = 0; i < maskSize; i++)
    {
        double second = i;
        mask[i] = pow(2.0, second);
    }
}


void music::Write(QString audio, QString text)
{
    QFile tFile(text);
    tFile.open(QIODevice::ReadOnly);

    QFile aFile(audio);
    aFile.open(QIODevice::ReadWrite);

    int position = 44;
    char letter;
    int textLen;
    textLen = tFile.size() - 1;

    if(textLen > 255)
    {
        textLen = 255;
    }
    letter = textLen;

    position = WriteByte(position, letter, aFile);

    for(int i = 0; i < textLen; i++)
    {
        if(aFile.atEnd())
        {
            QMessageBox msgBox;
            msgBox.setText("Audio file is less than the required!");
            msgBox.exec();

            letter = i+1;
            WriteByte(44, letter, aFile);
            break;
        }
        else
        {
            tFile.read(&letter, 1);
            position = WriteByte(position, letter, aFile);
        }
    }
}


int music::WriteByte(int position, unsigned char text, QFile &audio)
{
    audio.seek(position);

    char buf;
    char fileBuf;

    for(int i = 0; i < maskSize; i++)
    {
        buf = text & mask[i];
        for(int j = 0; j < i; j++)
        {
            buf >>= 1;
        }

        audio.read(&fileBuf, 1);
        fileBuf &= maskByte;
        fileBuf |= buf;
        audio.seek(position);
        position++;
        audio.write(&fileBuf, 1);
    }

    return position;
}


void music::Read(QString audio, QString text)
{
    QFile tFile(text);
    tFile.open(QIODevice::WriteOnly);

    QFile aFile(audio);
    aFile.open(QIODevice::ReadOnly);

    int position = 44;
    unsigned char size;
    char letter;
    int textLen = 0;

    size = ReadByte(position, aFile);
    textLen |= size;


    for(int i = 0; i < textLen; i++)
    {
        position += 8;
        letter = ReadByte(position, aFile);
        tFile.write(&letter, 1);
    }
}


unsigned char music::ReadByte(int position, QFile &audio)
{
    audio.seek(position);

    unsigned char returnValue = 0;
    char buf;
    char fileBuf;

    for(int i = 0; i < maskSize; i++)
    {
        audio.read(&fileBuf, 1);

        buf = fileBuf & 1;
        for(int j = 0; j < i; j++)
        {
            buf <<= 1;
        }

        returnValue |= buf;
    }

    return returnValue;
}
