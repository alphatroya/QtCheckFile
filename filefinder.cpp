#include "filefinder.h"

#define textOk "                    OK"
#define textFail "                  FAIL"
#define SLASH "/"

FileFinder::FileFinder(QObject *parent) :
    QObject(parent)
{
    maskFiles = "*.txt";
    fileDirrectory = "C:/";
    searchWord = " ";
}

void FileFinder::findFiles(QDir& dir)
{
    QStringList filter;
    filter<<maskFiles;
    QStringList listFiles = dir.entryList(filter, QDir::Files);

    for(int i = 0; i < listFiles.length(); i++)
    {
        findAndShow(fileDirrectory, listFiles.at(i));
    }

}

void FileFinder::findAndShow(QString dir, QString fileName)
{
    QString fileAndDir = dir + SLASH + fileName;
    QFile file(fileAndDir);
    if(file.exists())
    {
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "Error openning file";
        } else {
            QString text = file.readAll();
            if (text == searchWord){
                emit result(fileName + textOk);
            } else {
                emit result(fileName + textFail);
            }
        }
    }

}

void FileFinder::setMaskFiles(QString word)
{
    maskFiles = word;
}

void FileFinder::setFileDirectory(QString word)
{
    if (word != "") fileDirrectory = word;
}

void FileFinder::setSearchWord(QString word)
{
    if (word != "") searchWord = word;
}
